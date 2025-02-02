import QtQuick
import QtQuick.Controls

// import QGroundControl.Palette
// import QGroundControl.ScreenTools

Text {
    property color textColor

    font.pointSize: 16
    // font.family:    "Siegra"
    color:          textColor == "" ? qgcPal.text : textColor
    antialiasing:   true

    // QGCPalette { id: qgcPal; colorGroupEnabled: enabled }
}

