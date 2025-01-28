#include "keymap_german.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum layers { lBONE, lSYMB, lN_N, lMED, lSTENO, lHOLL };
enum custom_keycodes {
  K_STN_1 = SAFE_RANGE, // combo: back to base from steno
  K_STN_2,              //
  KC_SS                 // DE_SS but it becomes RSA(KC_S) when shifted
};
#define _AE_ DE_ADIA
#define _OE_ DE_ODIA
#define _UE_ DE_UDIA
#define _SFT_ OSM(MOD_LSFT)
#define _ALT_ OSM(MOD_LALT)
#define _GUI_ OSM(MOD_LGUI)
#define _CTL_ OSM(MOD_LCTL)

/* combos:
 *   combos.def uses the above, so only include this here
 */
#include "g/keymap_combo.h"

// flow from daliusd
// https://github.com/qmk/qmk_firmware/pull/16174
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();
  switch (keycode) {
  case KC_SS:
    if (record->event.pressed) {
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
        del_oneshot_mods(MOD_MASK_SHIFT);
        unregister_mods(MOD_MASK_SHIFT);
        SEND_STRING(SS_RALT("S"));
        register_mods(mods);
      } else
        tap_code(DE_SS);
    }
    return false;
  }
  return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [lBONE] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   KC_J,     KC_D,     KC_U,     KC_A,     KC_X,                                 KC_P,     KC_H,     KC_L,     KC_M,     KC_W, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   KC_C,     KC_T,     KC_I,     KC_E,     KC_O,                                 KC_B,     KC_N,     KC_R,     KC_S,     KC_G, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   KC_F,     KC_V,     _UE_,     _AE_,     _OE_,    LGUI(KC_X),        KC_SCRL,  DE_Y,     DE_Z,     KC_COMM,  KC_DOT,   KC_K, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  KC_SS,   OSL(lSYMB),_SFT_,    QK_REP,           QK_REP,   KC_SPC,   QK_AREP,  KC_Q,     K_STN_1,  K_STN_2), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lSYMB] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   DE_AT,    DE_UNDS,  DE_LBRC,  DE_RBRC,  DE_CIRC,                              DE_EXLM,  DE_LABK,  DE_RABK,  DE_EQL,   DE_AMPR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   DE_BSLS,  DE_SLSH,  DE_LCBR,  DE_RCBR,  DE_ASTR,                              DE_QUES,  DE_LPRN,  DE_RPRN,  DE_MINS,  DE_COLN, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   DE_HASH,  DE_DLR,   DE_PIPE,  DE_TILD,  DE_GRV,   XXXXXXX,          XXXXXXX,  DE_PLUS,  DE_PERC,  DE_DQUO,  DE_QUOT,  DE_SCLN, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,          _CTL_,    _ALT_,    DE_SECT,  DE_EURO,  XXXXXXX,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
  [lMED] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   XXXXXXX,  XXXXXXX,  KC_VOLU,  KC_BRIU,  XXXXXXX,                              XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F12, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  KC_VOLD,  KC_BRID,  DF(lHOLL),                            XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F10, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  KC_MUTE,  XXXXXXX,  XXXXXXX,  KC_PWR,           XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F11, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSCR,  XXXXXXX,          XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lSTENO] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  STN_ST3,                              STN_ST4,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  STN_S1,   STN_TL,   STN_PL,   STN_HL,                               STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST1,          STN_ST2,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  XXXXXXX,  STN_N1,   STN_A,    STN_O,            STN_E,    STN_U,    STN_N2,   XXXXXXX,  K_STN_1,  K_STN_2), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lHOLL] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                              XXXXXXX,  XXXXXXX,  KC_UP,    XXXXXXX,  KC_I, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  KC_D,     KC_X,     KC_S,     XXXXXXX,                              XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_RIGHT, XXXXXXX, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  KC_A,     XXXXXXX,  XXXXXXX, DF(lBONE),         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_Z,     XXXXXXX,          XXXXXXX,  KC_C,     XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_ENT),
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
};
// clang-format on
#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {};
#endif

// I'm not using MAGIC to swap any mods
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) { return keycode; }
uint8_t mod_config(uint8_t mod) { return mod; }
#endif
