#pragma once

#include "quantum_keycodes.h"

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,

    HOME_A,
    HOME_R,
    HOME_S,
    HOME_T,

    HOME_N,
    HOME_E,
    HOME_I,
    HOME_O,

    SMTD_KEYCODES_END,

    // Accent keys
    KC_ATIL, // ã direct key
    KC_ACUT, // á direct key
    KC_ACIR, // â direct key
    KC_CEDL, // ç direct key
    KC_ECUT, // é direct key
    KC_ECIR, // ê direct key
    KC_OTIL, // õ direct key
    KC_OCUT, // ó direct key
    KC_OCIR, // ô direct key
    KC_CENT,  // ¢ direct key
    KC_EURO,  // € direct key

    // Composite keys
    KC_DCLN, // Double colon
    KC_FARW, // Fat Arrow
    KC_TARW, // Thin Arrow

    // Combo codes
    MC_DELWRD,
    MC_CLWIN,
    MC_LOCK,
    MC_CUT,
    MC_COPY,
    MC_PASTE,

    // Toggle codes
    NUMWORD,
    TG_LINUX,
    TG_MAC,
    TG_WIN,
};

