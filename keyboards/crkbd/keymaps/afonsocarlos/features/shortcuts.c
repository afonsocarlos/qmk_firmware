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
        // Delete word
        case MC_DELWRD:
            if (isMacOS) {
                tap_code16(A(KC_BSPC));
            } else {
                tap_code16(C(KC_BSPC));
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

        // Lock
        case MC_LOCK:
            if (isMacOS) {
                tap_code16(G(C(KC_Q)));
            } else {
                tap_code16(G(KC_L));
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
    }

    return true;
}
