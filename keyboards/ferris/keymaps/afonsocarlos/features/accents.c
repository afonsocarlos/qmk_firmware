#include "accents.h"
#include "definitions/keycodes.h"
#include "quantum.h"

bool process_accents(uint16_t keycode, keyrecord_t* record) {
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
        case CTL_T(KC_ACIR):
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
