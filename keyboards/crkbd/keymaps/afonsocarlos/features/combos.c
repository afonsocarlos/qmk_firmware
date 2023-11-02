#include QMK_KEYBOARD_H

#include "layers.h"

enum combos {
  DF_FIND,
  L_SCLN_FIND,
  LSFT_Z_UNDO ,
  ZX_REDO ,
  XC_COPY ,
  CV_PASTE,
  XV_PASTE_PRIMARY,
  GUI_DEL_MAINTENANCE,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM df_combo[]      = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_scln_combo[]  = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM lsft_z_combo[]  = {KC_LSFT, KC_Z, COMBO_END};
const uint16_t PROGMEM zx_combo[]      = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_combo[]      = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_combo[]      = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM gui_del_combo[] = {KC_LGUI, ALT_DEL, COMBO_END};


combo_t key_combos[] = {
  [DF_FIND] = COMBO(df_combo, MC_FIND),
  [L_SCLN_FIND] = COMBO(l_scln_combo, MC_LOCK),
  [LSFT_Z_UNDO] = COMBO(lsft_z_combo, MC_UNDO),
  [ZX_REDO] = COMBO(zx_combo, MC_REDO),
  [XC_COPY] = COMBO(xc_combo, MC_COPY),
  [CV_PASTE] = COMBO(cv_combo, MC_PASTE),
  [XV_PASTE_PRIMARY] = COMBO(xv_combo, S(KC_INS)),
  [GUI_DEL_MAINTENANCE] = COMBO(gui_del_combo, TG(_MAINTENANCE)),
};

