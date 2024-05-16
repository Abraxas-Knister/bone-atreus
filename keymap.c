#include QMK_KEYBOARD_H
#include "keymap_german.h"

// flow from daliusd
// https://github.com/qmk/qmk_firmware/pull/16174
#include "flow.h"
const uint16_t flow_config[FLOW_COUNT][2] = {
    {MO(2), KC_LALT},
    {MO(2), KC_LGUI},
    {MO(2), KC_LCTL},
    {MO(2), KC_LSFT},
};

enum custom_keycodes { K_NAV = SAFE_RANGE, K_SYM };
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {K_SYM, 1},
    {K_NAV, 2},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!update_flow(keycode, record->event.pressed, record->event.key))
    return false;
  return true;
}

void matrix_scan_user(void) { flow_matrix_scan(); }

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

// clang-format off
// My actual layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT(
#define _AE_ DE_ADIA
#define _OE_ DE_ODIA
#define _UE_ DE_UDIA
#define _SFT_ OSM(MOD_LSFT)
//┌────────┬───────┬────────┬────────┬───────┐                            ┌────────┬────────┬─────────┬────────┬────────┐
    KC_J,    KC_D,   KC_U,    KC_A,    KC_X,                                KC_P,    KC_H,    KC_L,    KC_M,    KC_W,
//├────────┼───────┼────────┼────────┼───────┤                            ├────────┼────────┼─────────┼────────┼────────┤
    KC_C,    KC_T,   KC_I,    KC_E,    KC_O,                                KC_B,    KC_N,    KC_R,    KC_S,    KC_G,
//├────────┼───────┼────────┼────────┼───────┼────────┐          ┌────────┼────────┼────────┼─────────┼────────┼────────┤
    KC_F,    KC_V,   _UE_,    _AE_,    _OE_,  KC_LGUI,            KC_TAB,   DE_Y,    DE_Z,    KC_COMM, KC_DOT,  KC_K,
//├────────┼───────┼────────┼────────┼───────┼────────┤          ├────────┼────────┼────────┼─────────┼────────┼────────┤
    KC_ESC,  TG(3),  DE_SS,   QK_AREP, _SFT_,  K_SYM,             K_NAV,    KC_SPC,  QK_REP,  KC_Q,    KC_NO,   KC_ENT),
//└────────┴───────┴────────┴────────┴───────┴────────┘          └────────┴────────┴────────┴─────────┴────────┴────────┘
 [1] = LAYOUT(
//┌────────┬──────────┬──────────┬─────────┬─────────┐                  ┌────────┬────────┬────────┬────────┬────────┐
    DE_AT,   DE_UNDS,  DE_LBRC,   DE_RBRC,  DE_CIRC,                     DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR,
//├────────┼──────────┼──────────┼─────────┼─────────┤                  ├────────┼────────┼────────┼────────┼────────┤
    DE_BSLS, DE_SLSH,  DE_LCBR,   DE_RCBR,  DE_ASTR,                     DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,
//├────────┼──────────┼──────────┼─────────┼─────────┼──────┐    ┌──────┼────────┼────────┼────────┼────────┼────────┤
    DE_HASH, DE_DLR,   DE_PIPE,   DE_TILD,  DE_GRV,   KC_NO,      KC_NO, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN,
//├────────┼──────────┼──────────┼─────────┼─────────┼──────┤    ├──────┼────────┼────────┼────────┼────────┼────────┤
    DE_SECT, KC_NO,    RSA(KC_S), KC_NO,    KC_NO,    TG(1),      OSL(3), DE_EURO, KC_NO,   KC_NO,   KC_NO,   KC_NO),
//└────────┴──────────┴──────────┴─────────┴─────────┴──────┘    └──────┴────────┴────────┴────────┴────────┴────────┘
 [2] = LAYOUT(
#define _ALT_ OSM(MOD_LALT)
#define _GUI_ OSM(MOD_LGUI)
#define _CTL_ OSM(MOD_LCTL)
//┌────────┬──────────┬─────────┬─────────┬─────────┐                  ┌────────┬────────┬────────┬────────┬────────┐
    KC_HOME, KC_PGUP,  KC_UP,     KC_PGDN,  KC_END,                      KC_X,    KC_7,    KC_8,    KC_9,    DE_COLN,
//├────────┼──────────┼─────────┼─────────┼─────────┤                  ├────────┼────────┼────────┼────────┼────────┤
    KC_BSPC, KC_LEFT,  KC_DOWN,   KC_RGHT,  KC_DEL,                      DE_LBRC, KC_4,    KC_5,    KC_6,    KC_0,
//├────────┼──────────┼─────────┼─────────┼─────────┼──────┐    ┌──────┼────────┼────────┼────────┼────────┼────────┤
    _ALT_,   _GUI_,    _SFT_,     _CTL_,    DE_DLR,  DE_PERC,   KC_PSCR, DE_RBRC, KC_1,    KC_2,    KC_3,    KC_DOT,
//├────────┼──────────┼─────────┼─────────┼─────────┼──────┤    ├──────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   DE_ASTR,  DE_SLSH,  DE_MINS,   DE_PLUS, OSL(3),     TG(2),  KC_SPC,  DE_LPRN, KC_COMM, DE_RPRN, KC_E),
//└────────┴──────────┴─────────┴─────────┴─────────┴──────┘    └──────┴────────┴────────┴────────┴────────┴────────┘
  [3] = LAYOUT(
//┌────────┬──────────┬─────────┬────────┬───────┐                         ┌──────┬───────┬────────┬─────────┬─────────┐
    KC_PWR,  KC_WH_L,  KC_WH_U,  KC_WH_D, KC_WH_R,                          KC_NO, KC_F7,   KC_F8,  KC_F9,    KC_F12,
//├────────┼──────────┼─────────┼────────┼───────┤                         ├──────┼───────┼────────┼─────────┼─────────┤
    KC_VOLU, KC_LGUI,  KC_LSFT,  KC_LCTL, KC_BRIU,                          KC_NO, KC_F4,   KC_F5,  KC_F6,    KC_F10,
//├────────┼──────────┼─────────┼────────┼───────┼──────┐           ┌──────┼──────┼───────┼────────┼─────────┼─────────┤
    KC_VOLD, KC_NO,    KC_NO,    KC_NO,   KC_BRID, KC_NO,            KC_NO, KC_NO, KC_F1,   KC_F2,  KC_F3,    KC_F11,
//├────────┼──────────┼─────────┼────────┼───────┼──────┤           ├──────┼──────┼───────┼────────┼─────────┼─────────┤
    KC_MUTE, KC_NO,    KC_NO,    KC_BTN2, KC_BTN1, TG(3),            TG(3), KC_NO, KC_MS_L, KC_MS_D,KC_MS_U,  KC_MS_R)
//└────────┴──────────┴─────────┴────────┴───────┴──────┘           └──────┴──────┴───────┴────────┴─────────┴─────────┘
};
// clang-format on
