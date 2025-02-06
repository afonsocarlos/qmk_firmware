#include "quantum.h"

#include "definitions/keycodes.h"
#include "os_toggle.h"
#include "shortcuts.h"

#define OS_TAP(macro_key, mac_tap_key, linux_tap_key)             \
    case macro_key:                                               \
        if (record->event.pressed) {                              \
            tap_code16(is_macos() ? mac_tap_key : linux_tap_key); \
            return false;                                         \
        }

#define OS_REGISTER(macro_key, mac_tap_key, linux_tap_key)                 \
    case macro_key:                                                        \
        if (record->event.pressed) {                                       \
            if (record->tap.count > 0) { /* It's a tap */                  \
                tap_code16(is_macos() ? mac_tap_key : linux_tap_key);      \
            } else { /* It's a hold */                                     \
                register_code16(is_macos() ? mac_tap_key : linux_tap_key); \
            }                                                              \
            return false;                                                  \
        }                                                                  \
        unregister_code16(is_macos() ? mac_tap_key : linux_tap_key);       \
        return true;

bool process_shortcuts(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Close Window
        OS_TAP(MC_CLWIN, G(KC_Q), A(KC_F4))

        // Lock
        OS_TAP(MC_LOCK, G(C(KC_Q)), G(KC_L))

        // Cut
        OS_TAP(MC_CUT, G(KC_X), C(KC_X))

        // Copy
        OS_TAP(MC_COPY, G(KC_C), C(KC_C))

        // Paste
        OS_TAP(MC_PASTE, G(KC_V), C(KC_V))

        // Delete word
        OS_REGISTER(MC_DELWRD, A(KC_BSPC), C(KC_BSPC))
    }

    return true;
}
