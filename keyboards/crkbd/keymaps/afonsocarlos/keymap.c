/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define LTOSL_NUMS LT(_NUMS,OSL(_FUNC_ACCENTS))
#define ALT_SPC LALT_T(KC_SPC)
#define NAV_BSPC LT(_NAV,KC_BSPC)

enum custom_layers {
    _BASE,
    _NUMS,
    _NAV,
    _FUNC_ACCENTS,
    _SYS,
};

enum custom_keycodes {
    KC_ATIL = SAFE_RANGE, // ã direct key
    KC_ACUT, // á direct key
    KC_ACIR, // â direct key
    KC_CEDL, // ç direct key
    KC_ECUT, // é direct key
    KC_ECIR, // ê direct key
    KC_OTIL, // õ direct key
    KC_OCUT, // ó direct key
    KC_OCIR, // ô direct key
    KC_CENT,  // ¢ direct key
    KC_EURO,  // € direct key
};

enum combos {
  ZX_UNDO ,
  XC_COPY ,
  CV_PASTE,
  XV_PASTE_PRIMARY,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};


combo_t key_combos[] = {
  [ZX_UNDO] = COMBO(zx_combo, C(KC_Z)),
  [XC_COPY] = COMBO(xc_combo, C(KC_INS)),
  [CV_PASTE] = COMBO(cv_combo, RCS(KC_V)),
  [XV_PASTE_PRIMARY] = COMBO(xv_combo, S(KC_INS)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
CTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CTL_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI, LTOSL_NUMS, ALT_SPC,     KC_ENT, NAV_BSPC, RALT_T(KC_DEL)
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_GRV, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
CTL_T(KC_TILD),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, RCTL_T(KC_EQL),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_CENT, KC_EURO, XXXXXXX,                      KC_QUES, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_LALT,     KC_ENT, MO(_SYS), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, DF(_BASE), DF(_NAV),
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
CTL_T(KC_CAPS), KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, KC_RCTL,
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(_SYS),  KC_LALT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC_ACCENTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ACIR, KC_ATIL, KC_ACUT, KC_ECUT, KC_ECIR, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_OCIR, KC_OTIL, KC_OCUT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,KC_CEDL, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TO(_BASE),  KC_LALT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_LALT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};


bool process_special_characters(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        // ã key
        case KC_ATIL:
            tap_code16(RALT(KC_A));
            tap_code16(KC_TILD);
            return false;
        // á key
        case KC_ACUT:
            tap_code16(RALT(KC_A));
            tap_code16(KC_QUOT);
            return false;
        // â key
        case KC_ACIR:
            tap_code16(RALT(KC_A));
            tap_code16(KC_CIRC);
            return false;
        // ç key
        case KC_CEDL:
            tap_code16(RALT(KC_C));
            tap_code16(KC_COMM);
            return false;
        // é key
        case KC_ECUT:
            tap_code16(RALT(KC_E));
            tap_code16(KC_QUOT);
            return false;
        // ê key
        case KC_ECIR:
            tap_code16(RALT(KC_E));
            tap_code16(KC_CIRC);
            return false;
        // õ key
        case KC_OTIL:
            tap_code16(RALT(KC_O));
            tap_code16(KC_TILD);
            return false;
        // ó key
        case KC_OCUT:
            tap_code16(RALT(KC_O));
            tap_code16(KC_QUOT);
            return false;
        // ô key
        case KC_OCIR:
            tap_code16(RALT(KC_O));
            tap_code16(KC_CIRC);
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_special_characters(keycode, record)) { return false; }

    switch (keycode) {
        case LTOSL_NUMS:
            if (record->tap.count && record->event.pressed) {
                set_oneshot_layer(_FUNC_ACCENTS, ONESHOT_START);
                return false;
            }
            break;
        case CTL_T(KC_TILD):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TILD);
                return false;
            }
            break;
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (keycode != LTOSL_NUMS && !IS_MODIFIER_KEYCODE(keycode)) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
}

const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_PIPE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &pipe_key_override,
    NULL // Null terminate the array of overrides!
};
