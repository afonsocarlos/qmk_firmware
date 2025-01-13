#include "quantum.h"
#include "layers.h"

#ifdef RGBLIGHT_ENABLE
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 1, HSV_GREEN},
    {16, 2, HSV_GREEN},
    {19, 1, HSV_GREEN},
    {10, 1, HSV_YELLOW},
    {15, 1, HSV_YELLOW},
    {18, 1, HSV_YELLOW},
    {12, 1, HSV_ORANGE},
    {20, 1, HSV_ORANGE},
    {35, 2, HSV_GREEN},
    {37, 2, HSV_GREEN},
    {43, 2, HSV_GREEN},
    {45, 2, HSV_GREEN}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM maintenance_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 21, HSV_OFF},
    {33, 21, HSV_OFF},
    {0, 6, HSV_RED},
    {23, 2, HSV_RED},
    {27, 6, HSV_RED},
    {14, 1, HSV_GREEN},
    {41, 1, HSV_GREEN}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM func_accents_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2,  HSV_WHITE},
    {17, 2, HSV_WHITE},
    {23, 2, HSV_WHITE},
    {36, 2, HSV_WHITE},
    {44, 2, HSV_WHITE},
    {50, 2, HSV_WHITE}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM game_numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {16, 1, HSV_ORANGE},
    {18, 2, HSV_ORANGE},
    {22, 1, HSV_ORANGE},
    {37, 11, HSV_ORANGE}
);
// Light LEDs 0 to 6 (bottom LEFT hand LEDs) white when caps lock is active.
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_WHITE}       // Light 3 LEDs, starting with LED 3
);
// Light LEDs 27 to 33 (bottom RIGHT hand LEDs) white when num lock is active.
const rgblight_segment_t PROGMEM numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {27, 7, HSV_WHITE}       // Light 3 LEDs, starting with LED 3
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM custom_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    nav_layer,
    maintenance_layer,          // Overrides nav layers
    func_accents_layer, // Overrides maintenance layers
    game_numpad_layer,  // Overrides func_accents layers
    capslock_layer,     // Overrides game_numpad layer
    numlock_layer      // Overrides caps lock indicator
);

enum rgb_layers {
    NAV_LAYER,
    MAINTENANCE_LAYER,
    FUNC_ACCENTS_LAYER,
    GAME_NUMPAD_LAYER,
    CAPSLOCK_INDICATOR,
    NUMLOCK_INDICATOR,
};


bool is_layer_active(layer_state_t state, uint8_t layer) {
    return layer_state_cmp(state, layer) || (default_layer_state & ((layer_state_t)1 << layer)) != 0;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(CAPSLOCK_INDICATOR, led_state.caps_lock);
    rgblight_set_layer_state(NUMLOCK_INDICATOR, led_state.num_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(NAV_LAYER, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(GAME_NUMPAD_LAYER, layer_state_cmp(state, _GAME_NUMPAD));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(NAV_LAYER, is_layer_active(state, _NAV));
    rgblight_set_layer_state(MAINTENANCE_LAYER, is_layer_active(state, _MAINTENANCE));
    rgblight_set_layer_state(FUNC_ACCENTS_LAYER, is_layer_active(state, _MOUSE));
    rgblight_set_layer_state(GAME_NUMPAD_LAYER, is_layer_active(state, _GAME_NUMPAD));
    return state;
}

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = custom_rgb_layers;
}
#endif
