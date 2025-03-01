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

The key placement suggests a finger to key assignment like so:

                 middle
          ring  ┌─────┐
          ┌─────┤  M  ├─────┐ index
    ┌─────┘  R  │     │  I  └─────┐
    │  R        │  •  │        I  │
    ├─────┐  •  │     │  •        │
    │  •  │     │  M  │        I  └─────┐
    │     │  R  │     │  I           I† │
    │  P  │     │  M  ├─────┐  I  ┌─────┤
    │     │  R† ├─────┤  T  └─────┘  T  │
    │H  P†├─────┘     └─────┐  •  ┌─────┘
    └─────┘                 └─────┘ thumb
     pinky

          • : home positions
          † : assign seldom tasks
          H : a key you could press with the palm

Low profile keycaps and low weight springs/switches open up the possibility for same finger combos, which the layout makes
heavy use of.
