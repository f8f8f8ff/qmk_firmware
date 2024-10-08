#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
};

enum {
    TD_MNXT_MPRV = 0,
    TD_MPLY_MSEL
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMBR  MO(_NUM)
#define ESC_CR LCTL_T(KC_ESC)
#define NXT_PRV TD(TD_MNXT_MPRV)
#define PLY_SEL TD(TD_MPLY_MSEL)
#define KY_ZMIN LCTL(KC_EQL)
#define KY_ZOUT LCTL(KC_MINS)
#define KY_ZRST LCTL(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  ESC_CR,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  NUMBR,   KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  KC_LEAD, _______, _______, _______, _______, _______, _______, _______, NXT_PRV, KC_VOLD, KC_VOLU, PLY_SEL \
),

[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, NXT_PRV, KC_VOLD, KC_VOLU, PLY_SEL \
),

[_ADJUST] = LAYOUT( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_DEL, \
  _______, _______, BL_TOGG, BL_STEP, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, _______, \
  _______, _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_NUM , _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

[_NUM] = LAYOUT( \
  KY_ZMIN, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_BSPC , _______, _______, _______, _______, _______, _______, \
  KY_ZOUT, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, _______, _______, _______, _______, _______, _______, \
  KY_ZRST, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, KC_PAST, _______, _______, _______, _______, _______, _______, \
  _______, KC_P0  , KC_P0  , KC_PDOT, KC_PENT, _______, _______, _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MNXT_MPRV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
    [TD_MPLY_MSEL] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MSEL)
};

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
}
