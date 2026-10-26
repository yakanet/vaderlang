# Assets of the raycaster

Every picture here is a binary PPM file (P6, 8 bits per sample), and every sound
a WAV file. They are read when the program is compiled (`engine/textures.vader`
for the pictures, `raycaster.vader` for the sounds), so the program carries them
and opens no file.

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
| `Metal021.ppm` | steel (`s`), and the plate of the exit switch (`X`) |
| `PaintedMetal006.ppm` | green metal (`g`) |
| `PaintedMetal004.ppm` | red metal (`x`) |
| `Concrete034.ppm` | concrete (`c`) |
| `CorrugatedSteel005.ppm` | corrugated steel (`z`) |
| `MetalPlates014.ppm` | doors (`D`): the engine paints a frame, handles and hazard stripes over it |
| `MetalPlates006.ppm` | floor |
| `Concrete031.ppm` | ceiling |

## Sprites: Freedoom, BSD licence

`sprites/` holds the things standing on the floor, the zombie, the pistol, and
what a shot leaves (blood, a puff on the wall), from
[Freedoom](https://freedoom.github.io), under the BSD-style licence in
`sprites/COPYING.adoc`, which applies to these files and must travel with them.
The file names are Freedoom's sprite names. Magenta (`#FF00FF`) marks where a
sprite is transparent.

| file | used for |
|---|---|
| `bar1a0.ppm` | barrel (`B`) |
| `col1a0.ppm` | column (`C`) |
| `colua0.ppm` | light column (`U`) |
| `tlmpa0.ppm` | lamp (`L`) |
| `tgrna0.ppm` | torch (`T`) |
| `clipa0.ppm` | clip, ten bullets (`A`) |
| `stima0.ppm` | stimpack, ten health (`S`) |
| `media0.ppm` | medikit, twenty-five health (`H`) |
| `possa1.ppm` to `possd8.ppm` | the zombie (`Z`) walking: four steps, each seen from eight sides (`1` facing the eye, then round it to its left) |
| `posse1.ppm`, `possf1.ppm` | the zombie aiming, then firing |
| `possg1.ppm` | the zombie hit |
| `possh0.ppm` to `possl0.ppm` | the zombie falling, the last one its body |
| `pisga0.ppm` | the pistol at rest |
| `pisgb0.ppm`, `pisgc0.ppm` | the pistol's recoil |
| `pisfa0.ppm` | the pistol's flash, drawn over `pisgb0.ppm` for the shot |
| `bludc0.ppm`, `bludb0.ppm`, `bluda0.ppm` | a zombie bleeding where a bullet struck |
| `puffa0.ppm` to `puffd0.ppm` | a bullet striking a wall: the spark, then the smoke |

## Patches: Freedoom, BSD licence

`patches/` holds pictures the engine draws over a wall texture, from Freedoom,
under the same licence, copied beside them as `patches/COPYING.adoc`. The file
names are Freedoom's patch names; magenta marks where they are transparent.

| file | used for |
|---|---|
| `exit1.ppm` | the EXIT sign above the exit switch (`X`) |
| `sw2s0.ppm`, `sw2s1.ppm` | the exit switch's panel, off then thrown |

## Sounds: Freedoom, BSD licence

`sounds/` holds Freedoom's sounds, 8-bit mono WAV files, under the same licence,
copied beside them as `sounds/COPYING.adoc`.

| file | played when |
|---|---|
| `dspistol.wav` | the player or a zombie fires |
| `dsposit1.wav` | a zombie sees the player |
| `dspopain.wav` | a zombie is hit |
| `dspodth1.wav` | a zombie falls |
| `dsplpain.wav` | the player is hit |
| `dspldeth.wav` | the player falls |
| `dsdoropn.wav`, `dsdorcls.wav` | a door opens, shuts |
| `dsitemup.wav` | the player picks something up |
| `dsswtchx.wav` | the player throws the exit switch |

## Levels

`levels/` holds the levels as text, one character per cell. What each character
stands for is `LEGEND` in `engine/level.vader`. A level is read and checked when
the program is compiled: one that does not parse stops the build, naming the
file, the row and the column, and so does one without exactly one exit switch,
which ends it. They are played in the order `LEVELS` lists them in that file:
`hangar.txt`, then `depot.txt`.
