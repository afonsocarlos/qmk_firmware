#include QMK_KEYBOARD_H

enum combos {
  QW_CLTAB,
  QWE_CLWIN,
  ER_RELOD,
  WER_FCREL,
  RT_OPTAB,
  ERT_RETAB,
  AS_SAVE,
  LCTL_A_SELEC,
  DF_FIND,
  L_SCLN_LOCK,
  LSFT_Z_REDO,
  ZX_UNDO,
  XV_CUT,
  XC_COPY,
  CV_PASTE,
  XCV_PASTE_PRIMARY,
  NM_OPWIN,
  GUI_DEL_MAINTENANCE,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM qw_combo[]      = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM qwe_combo[]     = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo []     = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM wer_combo[]     = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rt_combo []     = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM ert_combo[]     = {KC_E, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM as_combo[]      = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM lctl_a_selec[]  = {CTL_T(KC_ESC), KC_A, COMBO_END};
const uint16_t PROGMEM df_combo[]      = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_scln_combo[]  = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM lsft_z_combo[]  = {KC_LSFT, KC_Z, COMBO_END};
const uint16_t PROGMEM zx_combo[]      = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM xc_combo[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xcv_combo[]     = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cv_combo[]      = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_combo[]      = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM nm_combo[]      = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM gui_del_combo[] = {OSM(MOD_LGUI), ALT_DEL, COMBO_END};


combo_t key_combos[] = {
  [QW_CLTAB] = COMBO(qw_combo, MC_CLTAB),
  [QWE_CLWIN] = COMBO(qwe_combo, MC_CLWIN),
  [ER_RELOD] = COMBO(er_combo, MC_RELOD),
  [WER_FCREL] = COMBO(wer_combo, MC_FCREL),
  [RT_OPTAB] = COMBO(rt_combo, MC_OPTAB),
  [ERT_RETAB] = COMBO(ert_combo, MC_RETAB),
  [AS_SAVE] = COMBO(as_combo, MC_SAVE),
  [LCTL_A_SELEC] = COMBO(lctl_a_selec, MC_SELEC),
  [DF_FIND] = COMBO(df_combo, MC_FIND),
  [L_SCLN_LOCK] = COMBO(l_scln_combo, MC_LOCK),
  [LSFT_Z_REDO] = COMBO(lsft_z_combo, MC_REDO),
  [ZX_UNDO] = COMBO(zx_combo, MC_UNDO),
  [XC_COPY] = COMBO(xc_combo, MC_COPY),
  [XCV_PASTE_PRIMARY] = COMBO(xcv_combo, S(KC_INS)),
  [CV_PASTE] = COMBO(cv_combo, MC_PASTE),
  [XV_CUT] = COMBO(xv_combo, MC_CUT),
  [NM_OPWIN] = COMBO(nm_combo, MC_OPWIN),
  [GUI_DEL_MAINTENANCE] = COMBO(gui_del_combo, TG(_MAINTENANCE)),
};

