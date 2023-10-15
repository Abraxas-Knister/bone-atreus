This is a WIP bone layout for the keyboardio atreus.

    qmk flash -e AVR_CFLAGS="-Wno-array-bounds" /path/to/bone-atreus.json  

will flash it. Of course qmk needs to be installed and working first. 

Requires a keymap equivalent to

    setxkbmap de nodeadkeys

This will of course make it impossible to enter accents for eg french. Until I use it, I'll not bother thinking about this.
     

Because I'm lazy, I'll not be using QMK to the fullest potential and write a config header, so it should pretty much stay this one JSON file created with config.qmk.fm forever.

features:
- easy palm esc and return keys
- One shot thumb shift 
- one shot layer toggle for symbols layer
- sybols layer is quite packed
- LGUI+SHIFT on number pad, because i3-wm uses that to move windows between workspaces
- gaming layer for Metroidvania
- gaming layer for 3D
- Media keys layer

Symbols layer is unfortunately unreadable in config, because it uses QWERTY Naming scheme for the keys but a QWERTZ mapping. On top of that some RALT/RALT+SHIFT mappings are used. 

left hand:

    @ _ [ ] ^ 
    \ / { } *
    # $ | ~ ` ¬
    § € ẞ X ø °

`X` is the symbol layer key. It needs to be present, because it can be held pressed to be active for more than one keypress
right hand:

      ! < > = &
      ? ( ) - :
    ± + % " ' ;
    Y Z ħ „ “ ”    

`Y` and `Z` are ctrl+bspc and ctrl+del respectively, they don't fit on the sybol layer, because they aren't symbols, but they are convenient, so what.