#pragma once

#include QMK_KEYBOARD_H

#include "os_detection.h"
#include "../definitions/keycodes.h"

typedef struct {
    os_variant_t type;
} os_t;

bool is_macos(void);
bool is_linux(void);
bool process_os_toggle(uint16_t keycode, keyrecord_t *record);
