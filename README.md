# Drone Hook Capability

A 3D-printable, servo-driven payload hook for the underside of a quadrotor drone, designed in Autodesk Fusion.

**Servo at 0° = closed, servo at 90° = open.**

- **Closed (0°):** the long J-hook hangs straight down. The payload ring sits at the bottom of the hook, directly under the servo shaft, so the weight does not twist the servo. A fixed keeper bar closes the hook's mouth so the ring can't bounce out.
- **Open (90°):** the hook swings sideways, away from the keeper, with its mouth facing down. The load slides off at about 60° into the swing.
- **Grabbing:** lower the drone with the hook at 90°, move over the loop, then go to 0° to trap it.
- **Electronics box:** hangs under the extended mount plate on the servo side, outside the hook's swing. The boards sit on the removable bottom lid.

## Repository contents

| Path | What it is |
| --- | --- |
| `stl/` | All 10 printable parts, already turned to their print orientation |
| `firmware/hook_test/hook_test.ino` | Arduino test sketch: closed → open → closed |
| `cad/` | Fusion archive (`.f3d`) and STEP of the full assembly |

## Printed parts

No supports needed. Every part fits a 256 × 256 mm bed. PETG is recommended for the hook, housing, bushing and fasteners; PLA is fine for the box and lid.

| # | File | Qty | Size on bed (mm) | Print orientation | Settings |
| --- | --- | --- | --- | --- | --- |
| 1 | `1_Mount_Plate.stl` | 1 | 171 × 98 × 6 | Flat, hex pockets up | 3 walls, 25% infill |
| 2 | `2_Housing.stl` | 1 | 58 × 69 × 97 | Top flange on the bed, keeper up; add a brim | 4 walls, 40% gyroid |
| 3 | `3_Hook.stl` | 1 | 91 × 39 × 10 | On its side, horn pocket and drive pegs up | 5 walls, 60% infill |
| 4 | `4_Pivot_Bushing_M12.stl` | 1 | 18 × 16 × 20 | Hex flange on the bed | 0.12 mm layers, 100% infill |
| 5 | `5_Electronics_Box.stl` | 1 | 90 × 121 × 34 | Closed top on the bed | 3 walls, 20% infill |
| 6 | `6_Electronics_Lid_Board_Tray.stl` | 1 | 90 × 121 × 18 | Flat, rail and pocket up | 3 walls, 20% infill |
| 7 | `7_M6x16_Bolt_print_x12.stl` | 12 (+2 spare) | 12 × 10 × 20 | Standing, head down | 0.12 mm layers, 100% infill |
| 8 | `8_M6_Nut_print_x12.stl` | 12 (+2 spare) | 12 × 10 × 5 | Flat | 0.12 mm layers, 100% infill |
| 9 | `9_Servo_Snap_Pin_print_x4.stl` | 4 (+2 spare) | 8 × 12 × 3.5 | On its flat side | 100% infill |
| 10 | `10_Servo_Horn_print.stl` | 1 (+1 spare) | 25 × 25 × 5.8 | Flat, hub up | PETG, 0.12 mm layers, 100% infill |

The M6 and M12 threads are modelled with 0.2 mm of clearance. **Print one bolt and one nut first as a test.** If they're tight, scale the bolt to 98% in X and Y; if loose, 101%. The M12 thread inside the housing prints sideways, so screw the bushing in and out a few times to clean it up.

## Parts to buy

| Item | Qty | Used for |
| --- | --- | --- |
| Standard servo, 40.7 × 19.7 mm body (MG996R, DS3218 or similar), with its horn centre screw | 1 | Drives the hook. Only the centre screw from the servo's bag is used: it's the one metal screw on the hook. |
| Mini breadboard, 170 tie-points (47 × 35 mm) | 1 | Wiring |
| Arduino Nano or ESP32 DevKit (up to 55 × 28 mm) | 1 | Controller |
| 5–6 V servo supply, 3 A or more (BEC or buck converter) | 1 | Servo power. Don't run the servo from the controller's 5 V pin. |
| M3 screws from your drone kit | 6 | Plate to drone frame (Ø3.4 mm holes) |
| Zip ties, ≤ 4 mm wide | 2 | Hold the controller on its rail |
| Double-sided foam tape, jumper wires | — | Breadboard mounting, wiring |

**Tools:** 10 mm wrench or pliers (fingers work too), long thin Phillips screwdriver, hairdryer (to warm the horn hub), flush cutters.

## Assembly

Work in this order: housing on the plate first, then the hook, then the servo, then the electronics. Set the servo to 0° before it goes in.

### A. Housing to plate
1. Drop 4 printed bolts head-first into the 4 hex pockets near the housing end of the plate (top side), threads pointing down. The pockets stop the heads turning.
2. Lower the housing's 4 corner ears over the bolts from below. Spin a printed nut onto each bolt under the ear, finger-tight, then a quarter turn more.

### B. Hook on its pivot
3. Drop the printed servo horn into the round pocket on the hook, **hub facing out**, so the hook's 2 pegs go through the 2 holes in the disc. No screws: the pegs carry the turning force.
4. Lower the hook into the slot between the two housing cheeks: horn side toward the rectangular servo pocket, mouth facing the long keeper bar.
5. On the plain cheek (the one with the round boss), screw the **threaded bushing** in by hand, pin first, until its hex flange sits on the boss. Hand-tight only.
6. Swing the hook by hand from straight down (0°) to sideways (90°). It must move freely without rubbing.

### C. Servo
7. Do the direction check (below) first, then leave the servo powered at **0°** and unplug it.
8. Set the hook to hang straight down (closed).
9. Slide the servo into the side pocket, **output shaft first**, with the shaft at the end nearest the open side (away from the keeper). Warm the horn hub with a hairdryer, then push firmly until the metal spline presses into the printed horn and the tabs sit flat on the housing. The spline cuts its own grooves in the hub.
10. Push a printed **snap pin** through each of the 4 tab holes until it clicks. The pins are one-way: to remove the servo, pull them with pliers and use fresh ones.
11. Push the long screwdriver through the hole in the bushing and drive the horn's **centre screw** into the servo spline.

### D. Electronics box
12. Press a printed nut into the hex pocket on top of each of the box's 4 corner ears.
13. Drop the last 4 printed bolts head-first into the hex pockets at the box end of the plate. Hold the box under the plate, notched wall facing the servo, so the bolts pass through the box ceiling. From inside the box, spin a nut onto each.
14. On the lid: stick the breadboard into its pocket. Sit the controller on the raised rail, header pins hanging either side, USB port at the end of the rail. Strap it down with 2 zip ties through the rail slots.
15. Wire up. Feed the servo cable through the notch on the servo-side wall and power leads through the notch on the far wall.
16. Close the lid and screw 4 printed bolts up through it into the nuts in the ears. Slide the board along the rail if the USB port doesn't line up with its hole.

### E. Mount on the drone
17. Bolt the plate to the drone frame through the 6 plain Ø3.4 mm holes.
18. Check the ~75 mm swing zone on the open side is clear of landing gear, battery and wires.
19. The box shifts weight ~7 cm toward the servo side, so rebalance with battery position.

## Wiring

| Servo wire | Connects to |
| --- | --- |
| Signal (orange/yellow) | Controller pin D6 |
| + (red) | + of the 5–6 V servo supply |
| − (brown/black) | − of the servo supply **and** a GND pin on the controller |

A 470 µF capacitor across the servo supply on the breadboard helps stop jitter.

### Direction check (before step 9)
1. Fit a horn on the bare servo, run `firmware/hook_test/hook_test.ino`, and watch the spline end-on.
2. Going 0° → 90°, the servo must turn **clockwise** as you look at the spline. That swings the hook away from the keeper.
3. If it turns counter-clockwise, set `CLOSED = 180` and `OPEN = 90` in the sketch.

## Pre-flight checks

- [ ] All 12 printed bolts snug, all 4 snap pins clicked in; hook swings 0° → 90° freely with the servo unplugged
- [ ] At 0° the hook hangs straight down and the keeper closes the mouth (gap ~2 mm)
- [ ] Hang a test ring at 0° and shake the drone: the ring stays on
- [ ] Command 90°: the ring drops off cleanly every time (try 5 times)
- [ ] Load test: hang twice the planned payload at 0° for 1 minute, with no cracking and no hard servo buzzing
- [ ] Open-side swing zone clear of landing gear, battery and wires
- [ ] Lid secure, wires strain-relieved, USB port reachable
- [ ] Drone balanced with the box fitted

## Troubleshooting

| Problem | Likely cause | Fix |
| --- | --- | --- |
| Hook binds or rubs | Bushing pin or hook bore printed tight | Open the hook's Ø10.4 bore with a 10.5 mm drill by hand |
| Servo won't push onto the printed horn | Press-fit hub cold or printed small | Warm it with a hairdryer; if still stuck, open the bore with a 5.6 mm drill by hand |
| Horn slips on the spline | Horn worn from refitting, or printed in PLA | Print a fresh horn in PETG, 100% infill, and tighten the centre screw |
| Bushing hard to screw in | Sideways-printed M12 thread is rough | Run the bushing in and out a few times |
| Printed nut won't go on, or strips | Printer tolerance | Scale the bolt to 98% XY (tight) or 101% (loose); 0.12 mm layers, 100% infill |
| Printed bolt snaps | PLA, or overtightened | Reprint in PETG; finger-tight plus a quarter turn |
| Snap pin won't click in or falls out | Barb printed small or worn | Print fresh pins in PETG; never reuse a pulled pin |
| Hook not quite straight down at 0° | Spline pressed in one tooth off | Fit a fresh horn with the servo at 0° and the hook hanging straight |
| Ring doesn't drop at 90° | Servo not reaching a full 90° | Try `OPEN = 100` |
| Servo jitters or controller resets | Servo powered from the controller, or no shared ground | Separate 5–6 V supply, join grounds, add the 470 µF capacitor |
| Hook swings toward the keeper | Servo turns the other way | `CLOSED = 180`, `OPEN = 90` |
