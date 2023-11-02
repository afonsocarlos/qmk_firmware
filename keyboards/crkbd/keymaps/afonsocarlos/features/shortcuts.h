#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "os_toggle.h"

bool process_shortcuts(uint16_t keycode, keyrecord_t *record);
