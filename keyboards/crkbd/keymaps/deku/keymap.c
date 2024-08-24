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

// Steps for flashing:
//   0) Ubuntu: sudo apt install -y git python3-pip
//      Arch: sudo pacman --needed --noconfirm -S git python-pip libffi
//   1) git clone https://github.com/deku-Scrub/qmk_firmware
//   2) cd qmk_firmware
//   3) qmk setup --home /home/deku/code/qmk_firmware
//   4) qmk compile -kb crkbd -km deku
//   5) press reset button on the left half
//   6) qmk flash -kb crkbd -km deku
#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    BASE,  // default layer
    NUMB,  // numbers
    SYMB,  // symbols
    EXTD,  // extend
    //MDIA,  // media keys
};


const key_override_t gui_esc_key_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, TO(BASE));
const key_override_t alt_esc_key_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, TO(BASE));
const key_override_t ctrl_esc_key_override = ko_make_basic(MOD_MASK_CTRL, KC_ESC, TO(BASE));
const key_override_t shift_esc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, TO(BASE));

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &gui_esc_key_override,
    &shift_esc_key_override,
    &alt_esc_key_override,
    &ctrl_esc_key_override,
    NULL // Null terminate the array of overrides!
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // M qwert   yuiop B
    // T asdfg   hjkl; R
    // C zxcvb   nm,./ C
    //  A Nl Sl  Sh S E
  [BASE] = LAYOUT_split_3x6_3(
  OSM(MOD_LGUI), KC_Q, KC_W, KC_E, KC_R, KC_T,
                           KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
  KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G,
                           KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
  OSM(MOD_LCTL), KC_Z, KC_X, KC_C, KC_V, KC_B,
                           KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_LCTL),
  OSM(MOD_LALT), OSL(NUMB), OSL(SYMB),
                           OSM(MOD_LSFT), KC_SPC, KC_ESC
  ),

    // M !@#$%   ^&*-+ B
    // T 12345   67890 R
    // C ?;:=X   X|,./ C
    //  A Nl Sl  = S Bl
  [NUMB] = LAYOUT_split_3x6_3(
  OSM(MOD_LGUI), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_BSPC,
  KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5,
                      KC_6, KC_7, KC_8, KC_9, KC_0, KC_ENT,
  OSM(MOD_LCTL), S(KC_SLSH), KC_SCLN, KC_COLN, KC_EQL, XXXXXXX,
                      XXXXXXX, KC_PIPE, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_LCTL),
  OSM(MOD_LALT), OSL(NUMB), OSL(SYMB),
                      A(KC_EXLM), KC_SPC, TO(BASE)
  ),

    // M XXXXX   X`_\X B
    // T "{[(X   X)]}' R
    // C IXX<X   Q>XX~ C // I is shift+insert, Q is EXTD layer
    //  A Nl Sl  _ S Bl
  [SYMB] = LAYOUT_split_3x6_3(
  OSM(MOD_LGUI), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                XXXXXXX, KC_GRV, KC_UNDS, KC_BSLS, XXXXXXX, KC_BSPC,
  KC_TAB, KC_DQUO, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX,
                XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_QUOT, KC_ENT,
  OSM(MOD_LCTL), S(KC_INS), XXXXXXX, XXXXXXX, KC_LABK, XXXXXXX,
                OSL(EXTD), KC_RABK, XXXXXXX, XXXXXXX, KC_TILD, OSM(MOD_LCTL),
  OSM(MOD_LALT), OSL(NUMB), OSL(SYMB),
                KC_UNDS, KC_SPC, TO(BASE)
  ),

    // M X X X   End  X    Home X  Ins X  X B
    // T X X Del PgDo X    Le   Do Up  Ri X R
    // C X X X   X    PgUp X    X  X   X  X C
    //  A Nl Sl  Sh S Bl
  [EXTD] = LAYOUT_split_3x6_3(
  OSM(MOD_LGUI), XXXXXXX, XXXXXXX, XXXXXXX, KC_END, XXXXXXX,
                   KC_HOME, XXXXXXX, KC_INS, XXXXXXX, XXXXXXX, KC_BSPC,
  KC_TAB, XXXXXXX, XXXXXXX, KC_DEL, KC_PAGE_DOWN, XXXXXXX,
                   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, KC_ENT,
  OSM(MOD_LCTL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAGE_UP,
                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OSM(MOD_LCTL),
  OSM(MOD_LALT), OSL(NUMB), OSL(SYMB),
                   OSM(MOD_LSFT), KC_SPC, TO(BASE)
  )
};

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
