This is a WIP bone layout for the keyboardio atreus using qmk.

**Bone** is a multi layered keyboard layout for german, where character placement has
been optimised so that fingers have to travel less. The base layer of this layout on a regular sized
keyboard can be found in `bone.svg`. The layout entails a symbol layer and a navigation/numpad layer
which are recreated in my layout as well.

Because German umlauts are used, the layout expects that the system has a German keyboard layout set, like with

    setxkbmap de nodeadkeys

in a linux/xorg environment.

The **Atreus** is a 40% (it has about 44 keys, which are about 40% of the ~100 keys sported by a
regular sized keyboard) fully programmable keyboard, sold by keyboardio. It is powered by an ATmega32U4
which means I can program it using qmk, and that some firmware size management considerations have to be made.

The key placement suggests (for me) a finger to key assignment like so:

                                 index
    ┌───────────────┬───────┬───────────────┐
    │   R       R   │   M   │   I       I   │
    ├───────┐       │       │               │
    │   P   │   R   │   M   │   •       I   │
    │       │       │       │               └───────┐
    │   P   │   R   │   M   │   I       I       I   │
    │       │       │       ├───────────────────────┤
    │  P H  │   R   │   M   │   T       •       T   │
    └───────┴───────┴───────┴───────────────────────┘
     pinky    ring    middle          thumb

          H: a key you could press with the palm

This is for the left hand, the right hand is symmetrical.

The layout makes use of one-shot modifiers and layer switches, which is made possible by
[this](https://github.com/qmk/qmk_firmware/pull/16174) code.

Low profile keycaps and low weight springs/switches open up the possibility for same finger combos.
