#include "quantum.h"

#include "definitions/keycodes.h"
#include "os_toggle.h"
#include "shortcuts.h"

bool process_shortcuts(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    bool isMacOS = is_macos();
    bool isLinux = is_linux();

    switch (keycode) {
        // Close Tab
        case MC_CLTAB:
            if (isMacOS) {
                tap_code16(G(KC_W));
            } else {
                tap_code16(C(KC_W));
            }
            return false;

        // Close Window
        case MC_CLWIN:
            if (isMacOS) {
                tap_code16(S(G(KC_W)));
            } else {
                tap_code16(A(KC_F4));
            }
            return false;

        // Reload
        case MC_RELOD:
            if (isMacOS) {
                tap_code16(G(KC_R));
            } else {
                tap_code16(C(KC_R));
            }
            return false;

        // Force Reload
        case MC_FCREL:
            if (isMacOS) {
                tap_code16(S(G(KC_R)));
            } else {
                tap_code16(S(C(KC_R)));
            }
            return false;

        // Open Tab
        case MC_OPTAB:
            if (isMacOS) {
                tap_code16(G(KC_T));
            } else {
                tap_code16(C(KC_T));
            }
            return false;

        // Reopen Tab
        case MC_RETAB:
            if (isMacOS) {
                tap_code16(S(G(KC_T)));
            } else {
                tap_code16(S(C(KC_T)));
            }
            return false;

        // Save (Also TMuX prefix)
        case MC_SAVE:
            tap_code16(C(KC_S));
            return false;

        // Select all
        case MC_SELEC:
            if (isMacOS) {
                tap_code16(G(KC_A));
            } else {
                tap_code16(C(KC_A));
            }
            return false;

        // Find
        case MC_FIND:
            if (isMacOS) {
                tap_code16(G(KC_F));
            } else {
                tap_code16(C(KC_F));
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

        // Cut
        case MC_CUT:
            if (isMacOS) {
                tap_code16(G(KC_X));
            } else {
                tap_code16(C(KC_X));
            }
            return false;

        // Copy
        case MC_COPY:
            if (isMacOS) {
                tap_code16(G(KC_C));
            } else {
                tap_code16(C(KC_C));
            }
            return false;

        // Paste
        case MC_PASTE:
            if (isMacOS) {
                tap_code16(G(KC_V));
            } else if (isLinux) {
                tap_code16(S(C(KC_V)));
            } else {
                tap_code16(C(KC_V));
            }
            return false;

        // Open Window
        case MC_OPWIN:
            if (isMacOS) {
                tap_code16(G(KC_N));
            } else {
                tap_code16(C(KC_N));
            }
            return false;
    }

    return true;
}
