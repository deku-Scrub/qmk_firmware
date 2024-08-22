/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    BASE,  // default layer
    NUMB,  // numbers
    SYMB,  // symbols
    UPPR,  // shift
    EXTD,  // extend
    //MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    TOGM,
    TOGS,
    GOEX,
    STAB,
    LPRP,
    LARA,
    LSRS,
    LVRV,
};

enum {
    TD_PGDN_END,
    TD_PGUP_HOME,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PGDN_END] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, KC_END),
    [TD_PGUP_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, KC_HOME),
};

enum combos {
  WM_COMBO, // toggle window manager.
  EX_COMBO, // toggle extend mode.
  ENT_COMBO, // enter.
  TAB_COMBO, // tab.
  BSPC_COMBO, // backspace.
  WMCY_COMBO, // window manager cycle.
  WMMN_COMBO, // window manager monacle.
  WMBR_COMBO, // window manager bar.
  LSRS_COMBO,
  LVRV_COMBO,
  COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM dk_combo[] = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM ascln_combo[] = {KC_A, KC_SCLN, COMBO_END};
combo_t key_combos[] = {
    [WM_COMBO] = COMBO(df_combo, TOGM),
    [EX_COMBO] = COMBO(hj_combo, GOEX),
    [ENT_COMBO] = COMBO(lscln_combo, LARA),
    [TAB_COMBO] = COMBO(kl_combo, STAB),
    [BSPC_COMBO] = COMBO(jk_combo, LPRP),
    [WMCY_COMBO] = COMBO(dk_combo, LGUI(KC_K)),
    [WMMN_COMBO] = COMBO(fj_combo, LGUI(KC_F)),
    [LSRS_COMBO] = COMBO(op_combo, LSRS),
    [LVRV_COMBO] = COMBO(ui_combo, LVRV),
    // TODO: LGUI(KC_SPC) does not work.
    [WMBR_COMBO] = COMBO(ascln_combo, LGUI(KC_Q)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LCTL,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         OSM(MOD_LGUI),    OSL(NUMB), OSL(SYMB), OSL(UPPR), KC_SPC, RCTL_T(KC_ESC)
                                      //`--------------------------'  `--------------------------'
  ),

  [NUMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, S(KC_SLSH), KC_SCLN, KC_COLN, KC_EQL, XXXXXXX,                      XXXXXXX, KC_PIPE, KC_COMM, KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         VRSN,   TO(NUMB), OSL(SYMB), KC_EQL,  KC_SPC,  TO(BASE)
                                      //`--------------------------'  `--------------------------'
  ),

  [SYMB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_GRV, KC_UNDS, KC_BSLS, XXXXXXX, KC_BSPC, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, KC_DQUO, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_QUOT, KC_ENT, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LABK, XXXXXXX,                      XXXXXXX, KC_RABK, XXXXXXX, XXXXXXX, KC_TILD, XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         VRSN,   OSL(NUMB), TO(SYMB), KC_UNDS,  KC_SPC,  TO(BASE)
                                      //`--------------------------'  `--------------------------'
  ),

  [UPPR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T),                     S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), KC_BSPC, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G),                     S(KC_H), S(KC_J), S(KC_K), S(KC_L),S(KC_SCLN),KC_ENT, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B),                     S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT), S(KC_SLSH), XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         VRSN,   OSL(NUMB), OSL(SYMB), TO(UPPR),  KC_SPC, TO(BASE)
                                      //`--------------------------'  `--------------------------'
  ),

  [EXTD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, C(KC_RGHT), XXXXXXX, C(KC_R), C(KC_T),                  C(KC_C), C(KC_Z), A(KC_LEFT), A(KC_RGHT), C(KC_V), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, C(S(KC_T)), C(KC_W), XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, C(KC_L), XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_LEFT),                  C(KC_PGDN), C(KC_PGUP), TD(TD_PGDN_END), TD(TD_PGUP_HOME), C(KC_F), XXXXXXX, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         VRSN,    XXXXXXX, XXXXXXX,    TOGS,     XXXXXXX, KC_ESC
                                      //`--------------------------'  `--------------------------'
  )
};

bool toggle_key(bool state, uint16_t key) {
    if (state) {
        register_code(key);
    }
    else {
        unregister_code(key);
    }
    return !state;
}

bool is_mod_on = false;
bool is_lsft_on = false;
bool is_extend_on = false;
uint16_t prev_keycode = VRSN;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode != VRSN) {
        prev_keycode = keycode;
    }

    if (record->event.pressed) {
        switch (keycode) {
        case TOGM:
            is_mod_on = toggle_key(is_mod_on, KC_LGUI);
            //return false;
            break;
        case GOEX:
            if (is_extend_on) {
                unregister_code(KC_LSFT);
                layer_move(BASE);
            }
            else {
                layer_move(EXTD);
            }
            is_lsft_on = false;
            is_extend_on = !is_extend_on;
            //return false;
            break;
        case TOGS:
            is_lsft_on = toggle_key(is_lsft_on, KC_LSFT);
            //return false;
            break;
        case LVRV:
            if (IS_LAYER_ON(SYMB)) {
                tap_code16(KC_LABK);
                tap_code16(KC_RABK);
            }
            else {
                tap_code(KC_U);
                tap_code(KC_I);
            }
            return false;
        case LSRS:
            if (IS_LAYER_ON(SYMB)) {
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
            }
            else {
                tap_code(KC_O);
                tap_code(KC_P);
            }
            return false;
        case LPRP:
            if (IS_LAYER_ON(SYMB)) {
                tap_code16(KC_LPRN);
                tap_code16(KC_RPRN);
                return false;
            }
            else {
                tap_code(KC_BSPC);
            }
            break;
        case LARA:
            if (IS_LAYER_ON(SYMB)) {
                tap_code16(KC_LBRC);
                tap_code16(KC_RBRC);
                return false;
            }
            else {
                tap_code(KC_ENT);
            }
            break;
        case STAB:
            if (IS_LAYER_ON(UPPR)) {
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            else {
                tap_code(KC_TAB);
            }
            break;
        case VRSN:
            tap_code16(prev_keycode);
            return false;
            //break;
            //switch (prev_keycode) {
                //case TOGM:
                    //is_mod_on = toggle_key(is_mod_on, KC_LGUI);
                    ////return false;
                    //break;
                //default:
                    //tap_code(prev_keycode);
                    //break;
            //}
        }
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
