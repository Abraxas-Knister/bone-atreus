#include "action.h"
#include "action_layer.h"
#include "keycodes.h"
#include "keymap_german.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include <stdbool.h>
#include <stdint.h>
#include QMK_KEYBOARD_H

enum layers { lBONE, lSYMB, lNUM, lSTENO };
enum custom_keycodes {
  K_STN_1 = SAFE_RANGE, // combo: back to base from steno
  K_STN_2,              //
  KC_SS,                // DE_SS but it becomes RSA(KC_S) when shifted
  KC_00,                // double zero
  KC_FN,                // numbers -> function (shift)
  KC_KP                 // numbers -> keypad   (lock)
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

bool fndown = false;
bool kpadon = false;
void tap_fn(uint16_t keycode) {
  uint16_t got[] = {KC_1, KC_2, KC_3, KC_4, KC_5,  KC_6,
                    KC_7, KC_8, KC_9, KC_0, KC_DOT};
  uint8_t ret[] = {KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5, KC_F6,
                   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11};
  for (int i = 0; i < 11; ++i)
    if (got[i] == keycode) {
      tap_code(ret[i]);
      break;
    }
}
void tap_kp(uint16_t keycode) {
  uint16_t got[] = {KC_1, KC_2, KC_3, KC_4, KC_5,  KC_6,
                    KC_7, KC_8, KC_9, KC_0, KC_DOT};
  uint8_t ret[] = {KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5,  KC_KP_6,
                   KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_DOT};
  for (int i = 0; i < 11; ++i)
    if (got[i] == keycode) {
      tap_code(ret[i]);
      break;
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();
  switch (keycode) {
  case KC_FN:
    if (record->event.pressed)
      fndown = true;
    else
      fndown = false;
    return false;
  case KC_KP:
    if (record->event.pressed)
      kpadon = !kpadon;
    return false;
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
  case KC_1:
  case KC_2:
  case KC_3:
  case KC_4:
  case KC_5:
  case KC_6:
  case KC_7:
  case KC_8:
  case KC_9:
  case KC_0:
  case KC_DOT:
    if (fndown) {
      if (record->event.pressed)
        tap_fn(keycode);
      return false;
    }
    if (kpadon) {
      if (record->event.pressed)
        tap_kp(keycode);
      return false;
    }
    return true;
  case KC_00:
    if (record->event.pressed) {
      if (fndown) {
        tap_code(KC_F12);
        return false;
      }
      SEND_STRING("00");
    }
    return false;
  default:
    return true;
  }
}
layer_state_t layer_state_set_user(layer_state_t state) {
  if (IS_LAYER_OFF_STATE(state, lNUM)) {
    kpadon = false;
    fndown = false;
  }
  return state;
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
   QK_REP,   QK_AREP,  KC_SS,   OSL(lSYMB),_SFT_,    _ALT_,            _CTL_,    KC_SPC,   QK_REP,   KC_Q,     K_STN_1,  K_STN_2), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lSYMB] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   DE_AT,    DE_UNDS,  DE_LBRC,  DE_RBRC,  DE_CIRC,                              DE_EXLM,  DE_LABK,  DE_RABK,  DE_EQL,   DE_AMPR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   DE_BSLS,  DE_SLSH,  DE_LCBR,  DE_RCBR,  DE_ASTR,                              DE_QUES,  DE_LPRN,  DE_RPRN,  DE_MINS,  DE_COLN, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   DE_HASH,  DE_DLR,   DE_PIPE,  DE_TILD,  DE_GRV,   XXXXXXX,          XXXXXXX,  DE_PLUS,  DE_PERC,  DE_DQUO,  DE_QUOT,  DE_SCLN, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  DE_EURO,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX,           _CTL_,   _ALT_,    DE_SECT,  XXXXXXX,  XXXXXXX,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lNUM] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   XXXXXXX,  KC_PGUP,  KC_UP,    KC_PGDN,  XXXXXXX,                              XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_00, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,                               XXXXXXX,  KC_4,     KC_5,     KC_6,     KC_0, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   KC_FN,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_KP,            QK_LLCK,  XXXXXXX,  KC_1,     KC_2,     KC_3,     KC_DOT, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _GUI_,    _ALT_,            _CTL_,     _SFT_,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lSTENO] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  STN_ST3,                              STN_ST4,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  STN_S1,   STN_TL,   STN_PL,   STN_HL,                               STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST1,          STN_ST2,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  XXXXXXX,  STN_N1,   STN_A,    STN_O,            STN_E,    STN_U,    STN_N2,   XXXXXXX,  K_STN_1,  K_STN_2)
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

