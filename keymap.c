#include "keymap_german.h"
#include QMK_KEYBOARD_H

enum layers { lBONE, lSYMB, lN_N, lMED, lSTENO, lHOLL };
enum custom_keycodes { K_NAV = SAFE_RANGE, K_SYM };
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
#include "flow.h"
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return update_flow(keycode, record->event.pressed, record->event.key);
}
void matrix_scan_user(void) { flow_matrix_scan(); }
const uint16_t flow_config[FLOW_COUNT][2] = {
    {MO(2), KC_LALT},
    {MO(2), KC_LGUI},
    {MO(2), KC_LCTL},
    {MO(2), KC_LSFT},
};
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {K_SYM, lSYMB},
    {K_NAV, lN_N},
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [lBONE] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   KC_J,     KC_D,     KC_U,     KC_A,     KC_X,                                 KC_P,     KC_H,     KC_L,     KC_M,     KC_W, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   KC_C,     KC_T,     KC_I,     KC_E,     KC_O,                                 KC_B,     KC_N,     KC_R,     KC_S,     KC_G, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   KC_F,     KC_V,     _UE_,     _AE_,     _OE_,     DF(lSTENO),       XXXXXXX,  DE_Y,     DE_Z,     KC_COMM,  KC_DOT,   KC_K, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   KC_LGUI,  KC_LCTL,  DE_SS,    QK_REP,   _SFT_,    K_SYM,            K_NAV,    KC_SPC,   QK_AREP,  KC_Q,     KC_LCTL,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lSYMB] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   DE_AT,    DE_UNDS,  DE_LBRC,  DE_RBRC,  DE_CIRC,                              DE_EXLM,  DE_LABK,  DE_RABK,  DE_EQL,   DE_AMPR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   DE_BSLS,  DE_SLSH,  DE_LCBR,  DE_RCBR,  DE_ASTR,                              DE_QUES,  DE_LPRN,  DE_RPRN,  DE_MINS,  DE_COLN, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   DE_HASH,  DE_DLR,   DE_PIPE,  DE_TILD,  DE_GRV,   XXXXXXX,          XXXXXXX,  DE_PLUS,  DE_PERC,  DE_DQUO,  DE_QUOT,  DE_SCLN, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  RSA(KC_S),XXXXXXX,  XXXXXXX,  TG(lSYMB),        OSL(lMED),DE_EURO,  DE_SECT,  XXXXXXX,  XXXXXXX,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lN_N] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_END,                               KC_X,     KC_7,     KC_8,     KC_9,     XXXXXXX, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,                               DE_LBRC,  KC_4,     KC_5,     KC_6,     KC_0, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   _ALT_,    _GUI_,    _SFT_,    _CTL_,    XXXXXXX,  XXXXXXX,          KC_PSCR,  DE_RBRC,  KC_1,     KC_2,     KC_3,     KC_DOT, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  OSL(lMED),        TG(lN_N), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
  [lMED] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   KC_PWR,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                              XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F12, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   KC_VOLU,  XXXXXXX, DF(lHOLL), XXXXXXX,  KC_BRIU,                              XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F10, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   KC_VOLD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BRID, XXXXXXX,           XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F11, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG(lMED),         TG(lMED), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX), 
//└─────────┴─────────┴─────────┴─────────┴─────────┴────────┘        └─────────┴─────────┴─────────┴─────────┴─────────┴────────┘
 [lSTENO] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┐                           ┌─────────┬─────────┬─────────┬─────────┬────────┐
   XXXXXXX,  XXXXXXX,  STN_N1,   STN_N2,   XXXXXXX,                              STN_N3,   STN_N4,   XXXXXXX,  XXXXXXX,  XXXXXXX, 
//├─────────┼─────────┼─────────┼─────────┼─────────┤                           ├─────────┼─────────┼─────────┼─────────┼────────┤
   STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST2,                              STN_FR,   STN_PR,   STN_LR,   STN_TR,   STN_DR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST3, DF(lBONE),         XXXXXXX,  STN_RR,   STN_BR,   STN_GR,   STN_SR,   STN_ZR, 
//├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤        ├─────────┼─────────┼─────────┼─────────┼─────────┼────────┤
   XXXXXXX,  XXXXXXX,  XXXXXXX,  STN_A,    STN_O,    XXXXXXX,          STN_E,    STN_U,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX), 
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
