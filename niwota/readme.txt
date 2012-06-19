armDesigner:

1. Arm designer designs a component that can be used in the actor, with axis point, color, etc.
2. Properties: x, y, z; rx, ry, rz; zx, zy, zz; ax, ay, az; color, texture.
3. User can view from any angle, or return to specific angle, eg. facing, back, left, right, top, bottom, 45 degree.
4. User can drag the object to change its position, rotation, zoom, axis position depending on which editing mode is selected.
5. User can also type values in the value box to change position, rotation ,zoom, axis position
6. User can select color to change the color value
7. User can type texture name to change the texture value
8 .User can type mesh name to load a new mesh

1. na
2. the properties should all have a delegate in the program
3. there should be at least 7 buttons, by clicking on them, user can view the model from facing, back, left, right, top, bottom, 45 degree
4. there should be at least 5 radio buttons to choose the current editing mode: viewing, position, rotation, zoom, axis position. there should also be some kind of machenism to let people choose what axis is being changed, by default it maps to the three buttons on the mouse
5. there should be at least 4 sets of values with captions representing position ,rotation, zoom, axis position respectively
6. there should be a color chooser button to let user choose the color of the item
7. there should be a texture name edit box to let user change the texture file name
8. there should be a mesh file name edit box to let user change the mesh file name

button grouping logics:

1. view group: facing, back, top, buttom, 45 degree
2. position group: caption, value edit
3. rotation group: caption, value edit
4. zoom group: caption, value edit
5. axis group: caption, value edit
6. misc group: caption, color chooser, caption, texture, caption, mesh

each group above should be radio selectable, selecting one of them should disable the rest.

use a layout to manage the following groups and put them into a flickr item.


