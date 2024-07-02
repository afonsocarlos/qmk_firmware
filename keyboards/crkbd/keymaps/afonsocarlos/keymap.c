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

#include <ctype.h>
#include "keycodes.h"
#include "modifiers.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

#include "definitions/keycodes.h"
#include "features/accents.h"
#include "features/achordion.h"
#include "features/os_toggle.h"
#include "features/shortcuts.h"
#include "layers.h"

#define ALT_SPC LALT_T(KC_SPC)
#define ALT_DEL RALT_T(KC_DEL)
#define LTOSL_NUMS LT(_NUMS,OSL(_FUNC_ACCENTS))
#define NAV_BSPC LT(_NAV,KC_BSPC)

void matrix_scan_user(void) {
  achordion_task();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
CTL_T(KC_ESC),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CTL_T(KC_QUOT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI, LTOSL_NUMS, ALT_SPC,     LT(_GAME_NUMPAD,KC_ENT), NAV_BSPC, ALT_DEL
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
                                          KC_LGUI, _______,  KC_LALT,     KC_ENT, LT(_SYS,KC_BSPC), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,DF(_BASE), DF(_NAV),
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
CTL_T(KC_CAPS), KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, RCTL_T(KC_NUM),
   //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT, XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(_SYS),  KC_LALT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MRWD, XXXXXXX, KC_MFFD, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_PSCR, KC_BRIU,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_LALT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  // Extra one shot layer for accessing Function and accents keys
  [_FUNC_ACCENTS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ACIR, KC_ATIL, KC_ACUT, KC_ECIR, KC_ECUT, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_OCIR, KC_OTIL, KC_OCUT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_CEDL, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TO(_BASE),  KC_LALT,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  // Extra layer for Numpad and Gaming keys
  [_GAME_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_F5,                       KC_NUM,   KC_P7,   KC_P8,   KC_P9, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_RCTL,    KC_A,    KC_S,    KC_D,    KC_F, XXXXXXX,                      XXXXXXX,   KC_P4,   KC_P5,   KC_P6, XXXXXXX, DF(_GAME_NUMPAD),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_P1,   KC_P2,   KC_P3, XXXXXXX, DF(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX,  ALT_SPC,    _______,   KC_P0, KC_PDOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_MAINTENANCE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,  EE_CLR,  TG_WIN, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,TG_LINUX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  TG_MAC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case ALT_SPC:  // ALT + TAB and ALT + U.
            if (other_keycode == KC_TAB ||
                other_keycode == NAV_BSPC ||
                other_keycode == KC_U ||
                other_keycode == KC_DOT) {
                return true;
            }
            return false;
    }

    return true;
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case ALT_SPC:
            return 100;  // Bypass Achordion for these keys.
    }

    return 500;  // Otherwise use a timeout of 800 ms.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_accents(keycode, record)) { return false; }
    if (!process_shortcuts(keycode, record)) { return false; }
    if (!process_os_toggle(keycode, record)) { return false; }

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


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Disable automatic hold action when another key is pressed for CTL_T(KC_QUOT) (ABAB)
        case CTL_T(KC_QUOT):
            return false;
        default:
            return true;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_QUOT):
            // Immediately select the hold action when another key is tapped (ABBA).
            return true;
        default:
            return false;
    }
}

const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_PIPE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &pipe_key_override,
    NULL // Null terminate the array of overrides!
};
