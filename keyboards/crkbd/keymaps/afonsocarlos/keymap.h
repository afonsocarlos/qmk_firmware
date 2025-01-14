#pragma once

#include QMK_KEYBOARD_H

#include "layers.h"

#define HOME_0 LGUI_T(KC_0)
#define HOME_4 LALT_T(KC_4)
#define HOME_5 LCTL_T(KC_5)
#define HOME_6 LSFT_T(KC_6)
#define HOME_F4 LALT_T(KC_F4)
#define HOME_F5 LCTL_T(KC_F5)
#define HOME_F6 LSFT_T(KC_F6)

#define LTMOUS_SPC LT(_MOUSE,KC_SPC)
#define LTNUMWORD LT(_NUMS,NUMWORD)
#define LTNAV_ENT LT(_NAV,KC_ENT)
#define OSM_LSFT OSM(MOD_LSFT)
