#include "sendstring_german.h"
#include QMK_KEYBOARD_H
//https://github.com/qmk/qmk_firmware/pull/16174
#include "flow.h"
#define TWO_CHAR_FN(fname, char1, char2)                                       \
  void fname(tap_dance_state_t *state, void *user_data) {                      \
    if (state->count == 1)                                                     \
      SEND_STRING(char1);                                                      \
    else {                                                                     \
      SEND_STRING(char2);                                                      \
      reset_tap_dance(state);                                                  \
    }                                                                          \
  }

enum { TD_DLRPC };
TWO_CHAR_FN(dollarpercent, "$", "%")

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [TD_DLRPC]    = ACTION_TAP_DANCE_FN(dollarpercent),
};
// clang-format on

// flow from daliusd
const uint16_t flow_config[FLOW_COUNT][2] = {
    {MO(0), KC_LSFT},
    {MO(2), KC_LALT},
    {MO(2), KC_LGUI},
    {MO(2), KC_LCTL},
    {MO(2), KC_LSFT},
};

enum custom_keycodes {
    K_NAV=SAFE_RANGE,
    K_SYM
};
const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {K_SYM, 1},
    {K_NAV, 2},
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // Row 1
        KC_J, KC_D, KC_U, KC_A, KC_X, /* mid */
        KC_P, KC_H, KC_L, KC_M, KC_W,
        // Row 2
        KC_C, KC_T, KC_I, KC_E, KC_O, /* mid */
        KC_B, KC_N, KC_R, KC_S, KC_G,
        // Row 3
        KC_F, KC_V, DE_UDIA, DE_ADIA, DE_ODIA, KC_ESC, /* mid */
        KC_ENT, DE_Y, DE_Z, KC_COMMA, KC_DOT, KC_K,
        // Row 4
        KC_LEFT, KC_UP, DE_SS, KC_LGUI, KC_LSFT, K_SYM, /* mid */
	K_NAV, KC_SPC, KC_TAB, KC_Q, KC_DOWN, KC_RIGHT),
    [1] = LAYOUT(
        // Row 1
        DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, /* mid */
        DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR,
        // Row 2
        DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, /* mid */
        DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,
        // Row 3
        DE_HASH, DE_DLR, DE_PIPE, DE_TILD, DE_GRV, KC_NO, /* mid */
        KC_NO, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN,
        // Row 4
        DE_SECT, KC_NO, RSA(KC_S), KC_TRNS, KC_NO, KC_TRNS,  /* mid */
        MO(3), DE_EURO, KC_NO, KC_NO, KC_NO, KC_NO),
    [2] = LAYOUT(
        // Row 1
        KC_HOME, KC_PGUP, KC_UP, KC_PGDN, KC_END, KC_NO, KC_7, KC_8, KC_9,
        DE_COLN,
        // Row 2
        KC_BACKSPACE, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, DE_LBRC, KC_4, KC_5,
        KC_6, KC_0,
        // Row 3
        OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_NO,
        KC_NO, KC_NO, DE_RBRC, KC_1, KC_2, KC_3, KC_DOT,
        // Row 4
        KC_PSCR, KC_NO, KC_LALT, KC_LCTL, KC_NO, KC_TRNS, KC_E, DE_MINS,
        DE_LPRN, TD(TD_DLRPC), DE_RPRN, DE_PLUS),
    [3] = LAYOUT(
        // Row 1
        KC_PWR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F12,
        // Row 2
        KC_VOLU, KC_MUTE, KC_NO, KC_BRIU, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6,
        KC_F10,
        // Row 3
        KC_VOLD, KC_NO, KC_NO, KC_BRID, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1,
        KC_F2, KC_F3, KC_F11,
        // Row 4
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,
        KC_NO, KC_NO)};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;
    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
