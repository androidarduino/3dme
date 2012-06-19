// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import Qt3D 1.0

Rectangle{
    width: 1000
    height: 800
Rectangle{
    id: leftpane
    width: 200
    height: 800
    color: "silver"
    Grid{
        columns: 2
	spacing: 10
        Text{
	width: 80
	text: "Name"
	}
	TextEdit{
	width: 100
	text: "arm.qml"
	}
        Text{
	width: 80
	text: "Mesh"
	}
	TextEdit{
	width: 100
	text: "head.3ds"
	}
}
}
Viewport {
    id: preview
    anchors.left: leftpane.right
    width: 800
    height: 800
    Coordinates{}
    Item3D{
	scale: 0.01
	mesh: Mesh{
		source: "head.3ds"
		}
	}
}
}
