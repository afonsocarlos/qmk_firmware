#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KC_ATIL = SAFE_RANGE, // ã direct key
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

    // Combo codes
    MC_CLTAB,
    MC_CLWIN,
    MC_CUT,
    MC_COPY,
    MC_FCREL,
    MC_FIND,
    MC_LOCK,
    MC_OPTAB,
    MC_OPWIN,
    MC_PASTE,
    MC_REDO,
    MC_RELOD,
    MC_RETAB,
    MC_SELEC,
    MC_UNDO,

    // Toggle codes
    TG_LINUX,
    TG_MAC,
    TG_WIN,
};

