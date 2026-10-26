# Assets of the raycaster

Every picture here is a binary PPM file (P6, 8 bits per sample). The engine reads
them when the program is compiled (`engine/textures.vader`), so the program
carries their pixels and opens no file.

## Textures: ambientCG, CC0

`textures/` holds the walls, the floor and the ceiling, 128 by 128 pixels each.
They are the colour maps of materials from [ambientCG](https://ambientcg.com),
released under **CC0 1.0** (public domain dedication), scaled down from their
1024-pixel versions. The file names are the materials' names on ambientCG.

| file | used for |
|---|---|
| `Bricks106A.ppm` | stone (`#`) |
| `Bricks105.ppm` | brick (`b`) |
| `MetalPlates013.ppm` | rusty plates (`r`) |
| `Metal021.ppm` | steel (`s`) |
| `PaintedMetal006.ppm` | green metal (`g`) |
| `PaintedMetal004.ppm` | red metal (`x`) |
| `Concrete034.ppm` | concrete (`c`) |
| `CorrugatedSteel005.ppm` | corrugated steel (`z`) |
| `MetalPlates014.ppm` | doors (`D`): the engine paints a frame, handles and hazard stripes over it |
| `MetalPlates006.ppm` | floor |
| `Concrete031.ppm` | ceiling |

## Sprites: Freedoom, BSD licence

`sprites/` holds the things standing on the floor, from
[Freedoom](https://freedoom.github.io), under the BSD-style licence in
`sprites/COPYING.adoc`, which applies to these five files and must travel with
them. The file names are Freedoom's sprite names. Magenta (`#FF00FF`) marks
where a sprite is transparent.

| file | used for |
|---|---|
| `bar1a0.ppm` | barrel (`B`) |
| `col1a0.ppm` | column (`C`) |
| `colua0.ppm` | light column (`U`) |
| `tlmpa0.ppm` | lamp (`L`) |
| `tgrna0.ppm` | torch (`T`) |

## Levels

`levels/` holds the levels as text, one character per cell. What each character
stands for is `LEGEND` in `engine/level.vader`. A level is read and checked when
the program is compiled: one that does not parse stops the build, naming the
file, the row and the column.
