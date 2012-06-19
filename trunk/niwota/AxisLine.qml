import QtQuick 1.1
import Qt3D 1.0
import Qt3D.Shapes 1.0

Cube{
    property alias color: e1.color
    property int thickness: 1
    property int length: 4
    transform: Scale3D{
        scale: Qt.vector3d(0.005*thickness, 0.005*thickness, length)
    }
    effect: Effect{
        id: e1
        color: "yellow"
    }
}

