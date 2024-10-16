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
#endif

// combos
const uint16_t PROGMEM C_comdot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM C_zcom[] = {DE_Z, KC_COMM, COMBO_END};
const uint16_t PROGMEM C_vue[] = {KC_V, DE_UDIA, COMBO_END};
const uint16_t PROGMEM C_ueae[] = {DE_UDIA, DE_ADIA, COMBO_END};
const uint16_t PROGMEM C_12[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM C_23[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM C_45[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM C_56[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM C_78[] = {KC_7, KC_8, COMBO_END};
const uint16_t PROGMEM C_89[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM C_60[] = {KC_6, KC_0, COMBO_END};
const uint16_t PROGMEM C_3D[] = {KC_3, KC_DOT, COMBO_END};
const uint16_t PROGMEM C_123[] = {KC_1, KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM C_456[] = {KC_4, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM C_789[] = {KC_7, KC_8, KC_9, COMBO_END};

combo_t key_combos[] = {
    COMBO(C_comdot, KC_ENT), COMBO(C_zcom, KC_BSPC), COMBO(C_vue, KC_TAB),
    COMBO(C_ueae, KC_ESC),   COMBO(C_12, KC_BSPC),   COMBO(C_23, KC_ENT),
    COMBO(C_45, DE_PLUS),    COMBO(C_56, DE_MINS),   COMBO(C_78, DE_ASTR),
    COMBO(C_89, DE_SLSH),    COMBO(C_60, DE_LPRN),   COMBO(C_3D, DE_RPRN),
    COMBO(C_123, DE_COLN),   COMBO(C_456, DE_DLR),   COMBO(C_789, DE_PERC)};

// redefine keycodes for visibility
#define _AE_ DE_ADIA
#define _OE_ DE_ODIA
#define _UE_ DE_UDIA
#define _SFT_ OSM(MOD_LSFT)
#define _ALT_ OSM(MOD_LALT)
#define _GUI_ OSM(MOD_LGUI)
#define _CTL_ OSM(MOD_LCTL)
enum layers { lBONE, lSYMB, lN_N, lMED };

// matrix for keymap
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [lBONE] = LAYOUT(
//┌────────┬───────┬────────┬────────┬───────┐                             ┌────────┬────────┬─────────┬────────┬────────┐
    KC_J,    KC_D,    KC_U,   KC_A,    KC_X,                                 KC_P,    KC_H,    KC_L,    KC_M,    KC_W,
//├────────┼───────┼────────┼────────┼───────┤                             ├────────┼────────┼─────────┼────────┼────────┤
    KC_C,    KC_T,    KC_I,   KC_E,    KC_O,                                 KC_B,    KC_N,    KC_R,    KC_S,    KC_G,
//├────────┼───────┼────────┼────────┼───────┼────────┐             ┌──────┼────────┼────────┼─────────┼────────┼────────┤
    KC_F,    KC_V,    _UE_,   _AE_,    _OE_,  KC_NO,                 KC_NO,  DE_Y,    DE_Z,    KC_COMM, KC_DOT,  KC_K,
//├────────┼───────┼────────┼────────┼───────┼────────┤             ├──────┼────────┼────────┼─────────┼────────┼────────┤
    KC_LGUI, KC_LCTL, DE_SS,  QK_REP,  _SFT_,  K_SYM,                K_NAV,  KC_SPC, QK_AREP,  KC_Q,    KC_LCTL, KC_NO),
//└────────┴───────┴────────┴────────┴───────┴────────┘             └──────┴────────┴────────┴─────────┴────────┴────────┘
 [lSYMB] = LAYOUT(
//┌────────┬──────────┬──────────┬─────────┬─────────┐                     ┌────────┬────────┬────────┬────────┬────────┐
    DE_AT,   DE_UNDS,  DE_LBRC,   DE_RBRC,  DE_CIRC,                        DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR,
//├────────┼──────────┼──────────┼─────────┼─────────┤                     ├────────┼────────┼────────┼────────┼────────┤
    DE_BSLS, DE_SLSH,  DE_LCBR,   DE_RCBR,  DE_ASTR,                        DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,
//├────────┼──────────┼──────────┼─────────┼─────────┼──────┐       ┌──────┼────────┼────────┼────────┼────────┼────────┤
    DE_HASH, DE_DLR,   DE_PIPE,   DE_TILD,  DE_GRV,   KC_NO,         KC_NO, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN,
//├────────┼──────────┼──────────┼─────────┼─────────┼──────┤       ├──────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_NO,    RSA(KC_S), KC_NO,    KC_NO,  TG(lSYMB),    OSL(lMED), DE_EURO,DE_SECT, KC_NO,   KC_NO,   KC_NO),
//└────────┴──────────┴──────────┴─────────┴─────────┴──────┘       └──────┴────────┴────────┴────────┴────────┴────────┘
 [lN_N] = LAYOUT(
//┌────────┬──────────┬─────────┬─────────┬─────────┐                     ┌────────┬────────┬────────┬────────┬────────┐
    KC_HOME, KC_PGUP,  KC_UP,     KC_PGDN,  KC_END,                         KC_NO,   KC_7,    KC_8,   KC_9,    KC_NO,
//├────────┼──────────┼─────────┼─────────┼─────────┤                     ├────────┼────────┼────────┼────────┼────────┤
    KC_BSPC, KC_LEFT,  KC_DOWN,   KC_RGHT,  KC_DEL,                         DE_LBRC, KC_4,    KC_5,   KC_6,    KC_0,
//├────────┼──────────┼─────────┼─────────┼─────────┼──────┐       ┌──────┼────────┼────────┼────────┼────────┼────────┤
    _ALT_,   _GUI_,    _SFT_,     _CTL_,    KC_NO,  KC_NO,         KC_PSCR, DE_RBRC, KC_1,    KC_2,   KC_3,    KC_DOT,
//├────────┼──────────┼─────────┼─────────┼─────────┼──────┤       ├──────┼────────┼────────┼────────┼────────┼────────┤
    KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,  OSL(lMED),    TG(lN_N), KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO),
//└────────┴──────────┴─────────┴─────────┴─────────┴──────┘       └──────┴────────┴────────┴────────┴────────┴────────┘
  [lMED] = LAYOUT(
//┌────────┬──────────┬─────────┬────────┬───────┐                        ┌──────┬───────┬────────┬─────────┬─────────┐
    KC_PWR,  KC_NO,    KC_NO,    KC_NO,   KC_NO,                           KC_NO, KC_F7,   KC_F8,  KC_F9,    KC_F12,
//├────────┼──────────┼─────────┼────────┼───────┤                        ├──────┼───────┼────────┼─────────┼─────────┤
    KC_VOLU, KC_LGUI,  KC_LSFT,  KC_LCTL, KC_BRIU,                         KC_NO, KC_F4,   KC_F5,  KC_F6,    KC_F10,
//├────────┼──────────┼─────────┼────────┼───────┼──────┐          ┌──────┼──────┼───────┼────────┼─────────┼─────────┤
    KC_VOLD, KC_NO,    KC_NO,    KC_NO,   KC_BRID, KC_NO,           KC_NO, KC_NO, KC_F1,   KC_F2,  KC_F3,    KC_F11,
//├────────┼──────────┼─────────┼────────┼───────┼──────┤          ├──────┼──────┼───────┼────────┼─────────┼─────────┤
    KC_MUTE, KC_NO,    KC_NO,    KC_NO,   KC_NO,   TG(lMED),     TG(lMED), KC_NO, KC_NO,   KC_NO,  KC_NO,    KC_NO)
//└────────┴──────────┴─────────┴────────┴───────┴──────┘          └──────┴──────┴───────┴────────┴─────────┴─────────┘
};
// clang-format on
