
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects
import QtQuick.Dialogs

import QGroundControl
import QGroundControl.Controls
import QGroundControl.ScreenTools
import QGroundControl.Palette
import Vahid.Utility
Item {

    QGCPalette {
        id:                 qgcPal  // Note how id does not use an underscore
        colorGroupEnabled:  enabled
    }
    Rectangle {
        anchors.fill: parent
        width:  _rectWidth
        height: _rectHeight
        color:  qgcPal.window   // Use QGC palette colors for everything, no hardcoded colors
    }


    ColumnLayout {
        property var _linkManager: QGroundControl.linkManager
        property var editingConfig
        height: 260
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: ScreenTools.defaultFontPixelWidth / 2
        // anchors.fill:           parent
        anchors.leftMargin:  ScreenTools.defaultFontPixelWidth / 2
        anchors.rightMargin: ScreenTools.defaultFontPixelWidth / 2

        Component {
            id: linkDialogComponent

            QGCPopupDialog {
                title:                  qsTr("Connection")
                buttons:                Dialog.Ok | Dialog.Cancel

                property var originalConfig
                property var editingConfig
                onAccepted: {
                    QGroundControl.linkManager.endCreateConfiguration(editingConfig)

                    if (editingConfig.link) {
                        editingConfig.link.disconnect()
                        editingConfig.linkChanged()
                    } else {
                        QGroundControl.linkManager.createConnectedLink(editingConfig)
                        ECUController.init()

                    }
                }

                GridLayout {
                    columns:        2
                    // rowSpacing:     10
                    // columnSpacing:  10

                    QGCLabel { text: qsTr("Serial Port") }
                    QGCComboBox {
                        id:                     commPortCombo
                        Layout.preferredWidth:  200
                        enabled:                QGroundControl.linkManager.serialPorts.length > 0

                        onActivated: (index) => {
                                         if (index != -1) {
                                             if (index >= QGroundControl.linkManager.serialPortStrings.length) {
                                                 // This item was adding at the end, must use added text as name
                                                 editingConfig.portName = commPortCombo.textAt(index)
                                             } else {
                                                 editingConfig.portName = QGroundControl.linkManager.serialPorts[index]
                                             }
                                         }
                                     }

                        Component.onCompleted: {
                            var index = -1
                            var serialPorts = [ ]
                            if (QGroundControl.linkManager.serialPortStrings.length !== 0) {
                                for (var i=0; i<QGroundControl.linkManager.serialPortStrings.length; i++) {
                                    serialPorts.push(QGroundControl.linkManager.serialPortStrings[i])
                                }
                                if (editingConfig.portDisplayName === "" && QGroundControl.linkManager.serialPorts.length > 0) {
                                    editingConfig.portName = QGroundControl.linkManager.serialPorts[0]
                                }
                                index = serialPorts.indexOf(editingConfig.portDisplayName)
                                if (index === -1) {
                                    serialPorts.push(editingConfig.portName)
                                    index = serialPorts.indexOf(editingConfig.portName)
                                }
                            }
                            if (serialPorts.length === 0) {
                                serialPorts = [ qsTr("None Available") ]
                                index = 0
                            }
                            commPortCombo.model = serialPorts
                            commPortCombo.currentIndex = index
                        }
                    }

                    QGCLabel { text: qsTr("Baud Rate") }
                    QGCComboBox {
                        id:                     baudCombo
                        Layout.preferredWidth:  200
                        model:                  QGroundControl.linkManager.serialBaudRates

                        onActivated: (index) => {
                                         if (index != -1) {
                                             editingConfig.baud = parseInt(QGroundControl.linkManager.serialBaudRates[index])
                                         }
                                     }

                        Component.onCompleted: {
                            var baud = "115200"
                            if(editingConfig != null) {
                                baud = editingConfig.baud.toString()
                            }
                            var index = baudCombo.find(baud)
                            if (index === -1) {
                                console.warn(qsTr("Baud rate name not in combo box"), baud)
                            } else {
                                baudCombo.currentIndex = index
                            }
                        }
                    }
                }

            }
        }


        QGCButton {
            text: qsTr("add link")
            onClicked: {
                var editingConfig = QGroundControl.linkManager.createConfiguration(LinkConfiguration.TypeSerial, "")
                linkDialogComponent.createObject(mainWindow, { editingConfig: editingConfig, originalConfig: null }).open()
            }
        }
        QGCButton {
            id:     flameoutBtn
            text: "Stop Engine"
            onClicked: ECUController.flameout()
        }




        GridLayout {
            id:     gridLayout
            columns:  2
            Layout.fillWidth: true
            Layout.fillHeight:  true

            Repeater {
                model: ECUController.vehicleComponents
                    RowLayout {
                        Layout.leftMargin: ScreenTools.defaultFontPixelWidth
                        Layout.rightMargin: ScreenTools.defaultFontPixelWidth
                        Layout.alignment: Qt.AlignVCenter

                        spacing: ScreenTools.defaultFontPixelWidth

                        LabelVahid {
                            text: modelData.name
                            anchors.margins: ScreenTools.defaultFontPixelWidth
                            font.pointSize: ScreenTools.defaultFontPixelWidth * 2
                            textColor: qgcPal.textField
                        }
                        LabelVahid {
                            text: modelData.value.toFixed(2)
                            anchors.margins: ScreenTools.defaultFontPixelWidth
                            font.pointSize: ScreenTools.defaultFontPixelWidth * 2
                            textColor: qgcPal.textField
                        }
                        LabelVahid {
                            text: modelData.unit
                            anchors.margins: ScreenTools.defaultFontPixelWidth
                            font.pointSize: ScreenTools.defaultFontPixelWidth
                            textColor: qgcPal.textField
                        }
                    }
                }

        }


        Rectangle {
            id: separator
            Layout.preferredHeight: 2
            Layout.fillWidth: true
            Layout.rightMargin: 10
            Layout.leftMargin:  10
            color: qgcPal.textColors
        }


        RowLayout {
            id: menu

            // Layout.preferredHeight: 100
            // Layout.fillWidth: true

            Repeater {
                model: ECUController.vehicleCkeck

                Rectangle {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: 55
                    color: modelData.value ? "green" : "red"
                    radius: ScreenTools.buttonBorderRadius

                    Label {
                        anchors.centerIn: parent
                        text: modelData.name
                        font.pixelSize:  modelData.name.length > 10  ?   13 :  15
                        font.italic: true
                        horizontalAlignment: Text.AlignHCenter
                        wrapMode:   modelData.name.length > 10  ?   Text.WordWrap : Text.NoWrap
                        width:      parent.width * 0.9
                    }
                }

            }
        }

    }
}

