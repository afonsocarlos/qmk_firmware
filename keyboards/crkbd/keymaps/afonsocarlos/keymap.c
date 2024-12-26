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

#include "keymap.h"
#include "definitions/keycodes.h"
#include "features/accents.h"
#include "features/achordion.h"
#include "features/caps_line.h"
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
  XXXXXXX,        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  XXXXXXX,      HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         KC_M,  HOME_N,  HOME_E,  HOME_I,   HOME_O, XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  XXXXXXX,        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT,  KC_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                    XXXXXXX, LT(_NUMS,KC_TAB), LT(_MOUSE_FUNC,KC_SPC),     LT(_NAV,KC_ENT), OSM(MOD_LSFT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  XXXXXXX,LGUI_T(KC_Q),    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  XXXXXXX,
//|----+-------+-------------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  XXXXXXX,LCTL_T(KC_A),    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,  XXXXXXX,
//|----+------+--------+-----+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  XXXXXXX,LSFT_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        OSM(MOD_LGUI), LTOSL_NUMS, ALT_SPC,     LT(_GAME_NUMPAD,KC_ENT), NAV_BSPC, ALT_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUMS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX,   KC_7,    KC_8,    KC_9, XXXXXXX,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_TILD, KC_GRV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX,LGUI_T(KC_0),LALT_T(KC_4),LCTL_T(KC_5),LSFT_T(KC_6),XXXXXXX,        XXXXXXX,KC_RSFT,KC_RCTL,KC_RALT,KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX,   KC_1,    KC_2,    KC_3, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LABK, KC_RABK, KC_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      XXXXXXX, _______,  KC_LALT,     KC_ENT, OSM(MOD_LSFT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_F12,   KC_F7,   KC_F8, KC_F9, XXXXXXX,                                               KC_HOME, KC_PGDN, KC_PGUP,  KC_END, QK_LLCK, XXXXXXX,
   //|--------|------+--------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
       XXXXXXX, LGUI_T(KC_F11),LALT_T(KC_F4),LCTL_T(KC_F5),LSFT_T(KC_F6), XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_RCTL, XXXXXXX,
   //|--------|------+--------+--------+--------+--------|                                            |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_F10,   KC_F1,   KC_F2, KC_F3, XXXXXXX,                                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, XXXXXXX,
   //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_TAB, LT(_SYS,KC_SPC),     _______, OSM(MOD_LSFT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MRWD, XXXXXXX, KC_MFFD, KC_PSCR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, BT_PRF1, BT_PRF2, BT_PRF3, BT_PRF4, BT_UNPR,                      KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_TOG, RGB_HUI,  TG_WIN,  TG_MAC, TG_LINUX,                     KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX, KC_BRID, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______,  KC_LALT,     KC_ENT, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  // Extra one shot layer for accessing Function and accents keys
  [_MOUSE_FUNC] = LAYOUT_split_3x6_3(
   //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   //|--------|--------+--------+--------+--------+ -------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
   //|--------|--------+--------+--------+--------+ -------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN3, KC_BTN5, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, _______,     LT(_SYS,KC_ENT),  OSM(MOD_LSFT), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  // Extra layer for Numpad and Gaming keys
  [_GAME_NUMPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,   KC_F5,                       KC_NUM,   KC_7,   KC_8,   KC_9, QK_LLCK, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+-------+-------+-------+--------+--------|
      KC_RCTL,    KC_A,    KC_S,    KC_D,    KC_F, XXXXXXX,                      KC_PLUS,   KC_4,   KC_5,   KC_6, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+-------+-------+-------+--------+--------|
      KC_LSFT,    KC_1,    KC_2,    KC_3,    KC_4, XXXXXXX,                      KC_ASTR,   KC_1,   KC_2,   KC_3, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX,  KC_SPC,    _______,   KC_PDOT, KC_0
                                      //`--------------------------'  `--------------------------'
  ),
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
    if (!process_caps_line(keycode, record)) { return false; }

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

void caps_word_set_user(bool active) {
    if (active) {
        autoshift_disable();
    }
    else {
        autoshift_enable();
    }
}

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (keycode != LTOSL_NUMS && keycode != CTL_T(KC_ACIR) && !IS_MODIFIER_KEYCODE(keycode)) {
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

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case GUI_T(KC_A):
        case KC_SLSH:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_SLSH:
            register_code16((!shifted) ? KC_SLSH : KC_PIPE);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
            register_code16(keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_SLSH:
            unregister_code16((!shifted) ? KC_SLSH : KC_PIPE);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            // unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
            unregister_code16(keycode);
    }
}

const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_PIPE);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &pipe_key_override
};
