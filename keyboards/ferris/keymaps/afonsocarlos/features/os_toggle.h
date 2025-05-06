#pragma once

#include "action.h"
#include "os_detection.h"

typedef struct {
    os_variant_t type;
} os_t;

bool is_macos(void);
bool is_linux(void);
bool process_os_toggle(uint16_t keycode, keyrecord_t *record);
