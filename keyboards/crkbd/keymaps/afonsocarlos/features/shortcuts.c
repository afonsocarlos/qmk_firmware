#include QMK_KEYBOARD_H

#include "shortcuts.h"

bool process_shortcuts(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    bool isMacOS = is_macos();
    bool isLinux = is_linux();

    switch (keycode) {

        // Find
        case MC_FIND:
            if (isMacOS) {
                tap_code16(G(KC_F));
            } else {
                tap_code16(C(KC_F));
            }
            return false;

        // Undo
        case MC_UNDO:
            if (isMacOS) {
                tap_code16(G(KC_Z));
            } else {
                tap_code16(C(KC_Z));
            }
            return false;

        // Undo
        case MC_REDO:
            if (isMacOS) {
                tap_code16(S(G(KC_Z)));
            } else {
                tap_code16(S(C(KC_Z)));
            }
            return false;

        // Copy
        case MC_COPY:
            if (isMacOS) {
                tap_code16(G(KC_C));
            }else if (isLinux) {
                tap_code16(S(C(KC_C)));
            } else {
                tap_code16(C(KC_C));
            }
            return false;

        // Paste
        case MC_PASTE:
            if (isMacOS) {
                tap_code16(G(KC_V));
            }else if (isLinux) {
                tap_code16(S(C(KC_V)));
            } else {
                tap_code16(C(KC_V));
            }
            return false;

        // Lock
        case MC_LOCK:
            if (isMacOS) {
                tap_code16(G(C(KC_Q)));
            } else {
                tap_code16(G(KC_L));
            }
            return false;

    }

    return true;
}
