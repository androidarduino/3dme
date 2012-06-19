import QtQuick 1.1
import Qt3D 1.0
import Qt3D.Shapes 1.0

Viewport{
    width: 800
    height: 800
    Item3D{
        id: z_axis
        Repeater{
            model: 20
            AxisLine{
                x: index*0.2-2
                color: "red"
            }
        }
    }
    Item3D{
        id: y_axis
        Repeater{
            model: 1
            AxisLine{
                color: "blue"
                thickness: 3
            }
        }
        transform: Rotation3D{
            angle: 90
            axis: Qt.vector3d(1,0,0)
        }
    }
    Item3D{
        id: x_axis
        Repeater{
            model: 20
            AxisLine{
                x: index*0.2-2
                color: "green"
            }
        }
        transform: Rotation3D{
            angle: 90
            axis: Qt.vector3d(0,1,0)
        }
    }
}


