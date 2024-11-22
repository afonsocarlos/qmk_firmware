#include <stdint.h>

enum combos {
  QW_CLTAB,
  QWF_CLWIN,
  LCTL_R_RELOD,
  LCTL_RS_FCREL,
  AR_SELEC,
  ST_OPTAB,
  RST_RETAB,
  RS_SAVE,
  WF_FIND,
  LU_LOCK,
  ZX_UNDO,
  ZXC_REDO,
  XD_CUT,
  XC_COPY,
  CD_PASTE,
  XCD_PASTE_PRIMARY,
  NE_OPWIN,
  GUI_DEL_MAINTENANCE,
  QWERT_LAYOUT,
  ARST_LAYOUT,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM qw_combo[]      = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM qwf_combo[]     = {KC_Q, KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM lctl_r_combo [] = {CTL_T(KC_ESC), KC_R, COMBO_END};
const uint16_t PROGMEM lctl_rs_combo[] = {CTL_T(KC_ESC), KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM st_combo []     = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rst_combo[]     = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rs_combo[]      = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM ar_selec[]      = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM wf_combo[]      = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM lu_combo[]      = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM zx_combo[]      = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM zxc_combo[]     = {KC_Z, KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xc_combo[]      = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xcd_combo[]     = {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM cd_combo[]      = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM xd_combo[]      = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM ne_combo[]      = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM gui_del_combo[] = {OSM(MOD_LGUI), ALT_DEL, COMBO_END};
const uint16_t PROGMEM qwert_combo[]   = {KC_Q, KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM arst_combo[]    = {KC_A, KC_R, KC_S, KC_T, COMBO_END};


combo_t key_combos[] = {
  [QW_CLTAB] = COMBO(qw_combo, MC_CLTAB),
  [QWF_CLWIN] = COMBO(qwf_combo, MC_CLWIN),
  [LCTL_R_RELOD] = COMBO(lctl_r_combo, MC_RELOD),
  [LCTL_RS_FCREL] = COMBO(lctl_rs_combo, MC_FCREL),
  [AR_SELEC] = COMBO(ar_selec, MC_SELEC),
  [ST_OPTAB] = COMBO(st_combo, MC_OPTAB),
  [RST_RETAB] = COMBO(rst_combo, MC_RETAB),
  [RS_SAVE] = COMBO(rs_combo, MC_SAVE),
  [WF_FIND] = COMBO(wf_combo, MC_FIND),
  [LU_LOCK] = COMBO(lu_combo, MC_LOCK),
  [ZX_UNDO] = COMBO(zx_combo, MC_UNDO),
  [ZXC_REDO] = COMBO(zxc_combo, MC_REDO),
  [XC_COPY] = COMBO(xc_combo, MC_COPY),
  [XCD_PASTE_PRIMARY] = COMBO(xcd_combo, S(KC_INS)),
  [CD_PASTE] = COMBO(cd_combo, MC_PASTE),
  [XD_CUT] = COMBO(xd_combo, MC_CUT),
  [NE_OPWIN] = COMBO(ne_combo, MC_OPWIN),
  [GUI_DEL_MAINTENANCE] = COMBO(gui_del_combo, TG(_MAINTENANCE)),
  [QWERT_LAYOUT] = COMBO(qwert_combo, DF(_QWERTY)),
  [ARST_LAYOUT] = COMBO(arst_combo, DF(_BASE)),
};
