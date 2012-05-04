import QtQuick 1.0
import Qt3D 1.0
import Qt3D.Shapes 1.0

Viewport{
    width: 800
    height: 800
    picking: true
    blending: true
    Item3D{
        id: body
        y: -1
        scale: 0.01
        mesh: Mesh{source: "body.3ds"}
        Item3D{
            id: head
            y: 160
            scale: 1.5
            onClicked: nodding.running=true
            mesh: Mesh{source: "head.3ds"}
            Item3D{
                id: hair
                mesh: Mesh{source: "hair.3ds"}
                effect: Effect{
                    color: "gold"
                }
            }
            Cube{
                id: axis
                scale: 10
                y: -45
                x: -15*1000
            }
            transform: [
                Rotation3D{
                    id: nod
                    angle: 0
                    axis: Qt.vector3d(1,0,0)
                    origin: Qt.vector3d(0, -30, 0)
                }
            ]
            SequentialAnimation{
                id: nodding
                loops: 2
                running: false
                NumberAnimation { target: nod; property: "angle"; to: -10; duration: 100 }
                NumberAnimation { target: nod; property: "angle"; to: 20; duration: 300; easing.type: Easing.InCubic }
                NumberAnimation { target: nod; property: "angle"; to: -10; duration: 300 }
            }
        }
        Item3D{
            id: leftArm
            mesh: Mesh{source: "arm.3ds"}
            scale: 0.7
            y: 90
            x: -30
            onClicked: wing1.running=wing2.running=true
            transform: [
                Rotation3D{
                id: armWing1
                origin: Qt.vector3d(-15, -45)
                axis: Qt.vector3d(0, 0, 1)
                angle: 0
                }
            ]
            SequentialAnimation{
                id: wing1
                loops: 3
                running: false
                NumberAnimation { target: armWing1; property: "angle"; to: 0; duration: 100 }
                NumberAnimation { target: armWing1; property: "angle"; to: 70; duration: 500; easing.type: Easing.OutCubic }
                NumberAnimation { target: armWing1; property: "angle"; to: 0; duration: 500 }
            }
            Item3D{
                id: leftShank
                mesh: Mesh{source: "arm.3ds"}
                scale: 1
                x: -80
            }
        }
        Item3D{
            id: rightArm
            mesh: Mesh{source: "arm.3ds"}
            scale: 0.7
            y: 90
            x: 30
            onClicked: wing2.running=wing1.running=true
            Item3D{
                id: rightShank
                mesh: Mesh{source: "arm.3ds"}
                scale: 1
                x: -80
            }
            transform:[
                Rotation3D{
                    angle: 180
                    axis: Qt.vector3d(0,0,1)
                },
                Rotation3D{
                id: armWing2
                origin: Qt.vector3d(15, 45)
                axis: Qt.vector3d(0, 0, 1)
                angle: 0
                }
            ]
            SequentialAnimation{
                id: wing2
                loops: 3
                running: false
                NumberAnimation { target: armWing2; property: "angle"; to: 0; duration: 100 }
                NumberAnimation { target: armWing2; property: "angle"; to: -70; duration: 500; easing.type: Easing.OutCubic }
                NumberAnimation { target: armWing2; property: "angle"; to: 0; duration: 500 }
            }
        }

    }
}
