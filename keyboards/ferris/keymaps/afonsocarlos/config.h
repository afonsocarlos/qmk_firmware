/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_TERM 170

#define MAX_DEFERRED_EXECUTORS 10
#define SMTD_GLOBAL_SEQUENCE_TERM 600
#define SMTD_GLOBAL_RELEASE_TERM 20

#define AUTO_SHIFT_REPEAT
#define NO_AUTO_SHIFT_NUMERIC

#define COMBO_TERM 25
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_PROCESS_KEY_RELEASE
#define COMBO_PROCESS_KEY_REPRESS
#define COMBO_MUST_TAP_PER_COMBO

#ifndef OS_DETECTION_ENABLE
#define OS_DETECTION_ENABLE
#endif // !OS_DETECTION_ENABLE

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA     12
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      2
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

#define RGBLIGHT_LAYERS
#define RGBLIGHT_DEFAULT_HUE 180
#define RGBLIGHT_DEFAULT_SAT 255
#define SPLIT_LAYER_STATE_ENABLE
#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE
#undef RGBLIGHT_SLEEP

#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT
