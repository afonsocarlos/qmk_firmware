#include <stdint.h>
#include "definitions/keycodes.h"
#include "combos.h"

bool first_press;
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case C_swapwin_combo:
            if (pressed) {
                first_press = true;
                register_mods(MOD_LALT);
            } else {
                unregister_mods(MOD_LALT);
            }
            break;
        case C_swaptab_combo:
            if (pressed) {
                first_press = true;
                register_mods(MOD_LCTL);
            } else {
                unregister_mods(MOD_LCTL);
            }
            break;
    }
}

bool process_combo_key_release(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    if (!first_press) {
        return false;
    }

    switch (combo_index) {
        case C_swapwin_combo:
            first_press = false;
            switch (keycode) {
                case KC_P:
                    tap_code16(S(KC_TAB));
                    return false;
                case KC_B:
                    tap_code(KC_TAB);
                    return false;
            }
        case C_swaptab_combo:
            first_press = false;
            switch (keycode) {
                case HOME_T:
                    tap_code16(S(KC_TAB));
                    return false;
                case KC_G:
                    tap_code(KC_TAB);
                    return false;
            }
    }
    return false;
}

bool process_combo_key_repress(uint16_t combo_index, combo_t *combo, uint8_t key_index, uint16_t keycode) {
    switch (combo_index) {
        case C_swapwin_combo:
            switch (keycode) {
                case KC_P:
                    tap_code16(S(KC_TAB));
                    return true;
                case KC_B:
                    tap_code(KC_TAB);
                    return true;
            }
        case C_swaptab_combo:
            switch (keycode) {
                case HOME_T:
                    tap_code16(S(KC_TAB));
                    return true;
                case KC_G:
                    tap_code(KC_TAB);
                    return true;
            }
    }
    return false;
}

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case HOME_A...HOME_O:
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}
#endif
