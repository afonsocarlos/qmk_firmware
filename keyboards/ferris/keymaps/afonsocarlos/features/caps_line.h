#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "action.h"

bool process_caps_line(uint16_t keycode, keyrecord_t* record);
bool caps_line_press_user(uint16_t keycode);
bool is_caps_line_on(void);
