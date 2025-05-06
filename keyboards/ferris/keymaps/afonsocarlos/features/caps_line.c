#include "caps_line.h"
#include "quantum_keycodes.h"
#include "timer.h"
#include "action_tapping.h"

#include "keymap.h"

static bool caps_line_active = false;

void caps_line_on(void) {
    if (caps_line_active) {
        return;
    }

    tap_code(KC_CAPS_LOCK);
    caps_line_active = true;
}

void caps_line_off(void) {
    if (!caps_line_active) {
        return;
    }

    tap_code(KC_CAPS_LOCK);
    caps_line_active = false;
}

void caps_line_toggle(void) {
    if (caps_line_active) {
        caps_line_off();
    } else {
        caps_line_on();
    }
}

bool is_caps_line_on(void) {
    return caps_line_active;
}

bool process_caps_line(uint16_t keycode, keyrecord_t* record) {
    // Double tapping left shift turns on Caps Word.
    //
    // NOTE: This works with OSM_LSFT and one-shot left shift. It
    // wouldn't make sense with mod-tap or Space Cadet shift since
    // double tapping would of course trigger the tapping action.
    if (record->event.pressed) {
        static bool     tapped = false;
        static uint16_t timer  = 0;
        if (keycode == OSM_LSFT) {
            if (tapped && !timer_expired(record->event.time, timer)) {
                // Left shift was double tapped, activate Caps Word.
                caps_line_toggle();
            }
            tapped = true;
            timer  = record->event.time + GET_TAPPING_TERM(keycode, record);
        } else {
            tapped = false; // Reset when any other key is pressed.
        }
    }

    if (caps_line_press_user(keycode)) {
        return true;
    }

    caps_line_off();
    return true;
}

__attribute__((weak)) bool caps_line_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_ESC:
        case LTNAV_ENT:
        case KC_TAB:
            return false; // Deactivate Caps Word.
        default:
            return true;
    }
}
