import QtQuick
import QtQuick.Layouts              1.12

import QGroundControl               1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.Vehicle       1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.Templates     1.0 as T



Rectangle {
    readonly property var       activeVehicle:  QGroundControl.multiVehicleManager.activeVehicle
    property var ecu

    // height:             rowLayout.height
    // width:              ScreenTools.defaultFontPixelWidth * 35
    gradient: Gradient {
        orientation: Gradient.Horizontal;
        GradientStop { position: 0.6;                                   color: "#c8414a4c" }
        GradientStop { position: 1;                                     color: "transparent" }
    }
    radius:             ScreenTools.defaultFontPixelWidth / 2

    ColumnLayout{


        RowLayout{
            Layout.leftMargin:      ScreenTools.defaultFontPixelWidth
            Layout.rightMargin:     ScreenTools.defaultFontPixelWidth


            LabelVahid{
                text: "speed: "
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
            }
            LabelVahid{
                text: ecu? ecu.speed :"-"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
                font.letterSpacing: 3
            }
            LabelVahid{
                text:       " rpm"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*0.9
                textColor: "white"

            }

        }

        RowLayout{
            Layout.leftMargin:      ScreenTools.defaultFontPixelWidth
            Layout.rightMargin:     ScreenTools.defaultFontPixelWidth


            LabelVahid{
                text: "battery Voltage: "
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
            }
            LabelVahid{
                text: ecu? ecu.batteryVoltage :"-"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
                font.letterSpacing: 3
            }
            LabelVahid{
                text:       " V"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*0.9
                textColor: "white"

            }

        }

        RowLayout{
            Layout.leftMargin:      ScreenTools.defaultFontPixelWidth
            Layout.rightMargin:     ScreenTools.defaultFontPixelWidth


            LabelVahid{
                text: "runTime: "
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
            }
            LabelVahid{
                text: ecu? ecu.runTime :"-"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
                font.letterSpacing: 3
            }
            LabelVahid{
                text:       " S"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*0.9
                textColor: "white"

            }

        }

        RowLayout{
            Layout.leftMargin:      ScreenTools.defaultFontPixelWidth
            Layout.rightMargin:     ScreenTools.defaultFontPixelWidth


            LabelVahid{
                text: "fuelConsumed: "
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
            }
            LabelVahid{
                text: ecu? ecu.fuelConsumed :"-"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*3.5
                textColor: "white"
                font.letterSpacing: 3
            }
            LabelVahid{
                text:       " S"
                anchors.margins: ScreenTools.defaultFontPixelWidth
                font.pointSize: ScreenTools.defaultFontPixelWidth*0.9
                textColor: "white"

            }

        }





    }

}

