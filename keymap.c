#include "keymap_german.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0]=LAYOUT(
    // Row 1
    KC_J,   KC_D,  KC_U,    KC_A,    KC_X, 
    KC_P,   KC_H,  KC_L,    KC_M,    KC_W,    
    // Row 2
    KC_C,   KC_T,  KC_I,    KC_E,    KC_O, 
    KC_B,   KC_N,  KC_R,    KC_S,    KC_G,   
    // Row 3
    KC_F,   KC_V,  DE_UDIA, DE_ADIA, DE_ODIA,  KC_NO,   
    KC_SCRL,DE_Y,  DE_Z,    KC_COMM, KC_DOT,   KC_K,   
    // Row 4
    KC_ESC, DE_QUOT,DE_SS,OSL(1), OSM(MOD_LSFT),LT(2,KC_BSPC), 
    LGUI_T(KC_TAB),LCTL_T(KC_SPC), LALT_T(KC_SLSH),KC_Q,LSFT(KC_COMM),KC_ENT 
  ),
[1] = LAYOUT(
    // Row 1
    DE_AT,     DE_UNDS,  DE_LBRC,    DE_RBRC,  DE_CIRC,
    DE_EXLM,   DE_LABK,  DE_RABK,    DE_EQL,   DE_AMPR,  
    // Row 2
    DE_BSLS,   DE_SLSH,  DE_LCBR,    DE_RCBR,  DE_ASTR,
    DE_QUES,   DE_LPRN,  DE_RPRN,    DE_MINS,  DE_COLN,  
    // Row 3
    DE_HASH,   DE_DLR,   DE_PIPE,    DE_TILD,  DE_GRV,   KC_NO,    
    KC_NO,     DE_PLUS,  DE_PERC,    DE_DQUO,  DE_QUOT,  DE_SCLN,  
    // Row 4
    DE_SECT,  KC_NO,    RSA(KC_S),  KC_TRNS,  KC_NO,    KC_NO,
    DE_EURO,   KC_LCTL,  MO(3),      KC_NO,    KC_NO,    KC_NO 
  ),
[2] = LAYOUT(
    // Row 1
    KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO,
    KC_NO, KC_7, KC_8, KC_9, DE_COLN,
    // Row 2
    KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_LGUI,
    DE_DLR, KC_4, KC_5, KC_6, KC_DOT,
    // Row 3
    KC_NO, KC_HOME, KC_INS, KC_END, LGUI(KC_LSFT), KC_NO,
    KC_NO, DE_LPRN, KC_1, KC_2, KC_3, DE_RPRN,
    // Row 4
    KC_PSCR, KC_NO, KC_LALT, KC_LCTL, KC_NO, KC_TRNS,
    KC_E, DE_MINS, DE_LBRC, KC_0, DE_RBRC, DE_PLUS
  ),
[3] = LAYOUT(
    // Row 1
    KC_PWR, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F7, KC_F8, KC_F9, KC_F12,
    // Row 2
    KC_VOLU, KC_MUTE, KC_NO, KC_BRIU, KC_NO,
    KC_NO, KC_F4, KC_F5, KC_F6, KC_F10, 
    // Row 3
    KC_VOLD, KC_NO, KC_NO, KC_BRID, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F11,
    // Row 4
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
  )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
