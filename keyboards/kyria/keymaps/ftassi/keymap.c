/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "features/casemodes.h"

enum layers {
    _QWERTY = 0,
    _NUMBERS,
    _SYMBOL,
    _NAV,
    _I3WM,
    _ADJUST
};

enum custom_keycodes {
    CAPSWRD = SAFE_RANGE,
};
//I3wm keycodes
#define NEXT_WS G(S(KC_O))
#define RESIZE G(KC_R)
#define SCRAT G(C(KC_A))
#define MSCRAT G(C(KC_M))
#define FLOAT G(S(KC_F))
#define TERM G(KC_ENT)
#define APP G(KC_SPC)
#define BROWSER G(S(KC_ENT))
#define CMD G(S(KC_SPC))
#define NAME G(S(KC_Z))
#define ORIENTATION G(KC_BSPC)
#define FILES G(S(KC_N))
#define L_MODE G(KC_T)
#define FULL G(KC_F)
#define SLEEP G(S(KC_S))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |Alt/ESC |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |Alt  |\ |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl ' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift| AltGr|  |LEADER|CAPSWRD|   N  |   M  | ,  < | . >  | /  ? |Shift- _|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Down | Del  | Tab  | Esc  | Enter|  | I3wm | Space| Symb| Alt  |  Up  |
 *                        |Adjust|      | Numb |      |      |  | BS   |      | Del |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      LALT_T(KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    LALT_T(KC_BSLS),
      LCTL_T(KC_BSPC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LCTL_T(KC_QUOT),
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT, OSM(MOD_RALT) , KC_LEAD, CAPSWRD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_MINS),
              LT(_ADJUST, KC_DOWN), KC_DEL, LT(_NUMBERS, KC_TAB), KC_ESC, KC_ENT, LT(_I3WM, KC_BSPC) , KC_SPC, MO(_SYMBOL), KC_LALT, KC_UP
      ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  \   |                              |      |  _   |  <   |  >   |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Space  |  %   |  ^   |  [   |  ]   |  ~   |  ;   |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  :   |  =   |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
*/
    [_SYMBOL] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_BSLS,                                     KC_PIPE, KC_UNDS, KC_LT  , KC_GT  , _______, _______,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, _______,
      KC_SPC , KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_SCLN, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, _______,
                                 _______, _______, _______, KC_COLN, KC_EQL,  _______,  _______, _______, _______, _______
    ),
/*
 * Num Layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1 ! |  2 @ |  3 # |  4 $ |  5 % |                              |  /   |  7 & |  8 * |  9 ( |  -   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |                              |  *   |  4 $ |  5 % |  6 ^ |  +   | Space  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |  0 ) |  1 ! |  2 @ |  3 # |  =   | Enter  |
 * `----------------------+------+------+------+      +------|  |------+      +------+------+------+----------------------'
 *                        |      |      |      |      |      |  |  .   |  ,   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NUMBERS] = LAYOUT(
      _______,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                     KC_PSLS,  KC_7  ,  KC_8  ,  KC_9  , KC_PMNS, _______,
      _______,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,                                     KC_PAST,  KC_4  ,  KC_5  ,  KC_6  , KC_PLUS, KC_SPC ,
      _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX,  KC_0  ,  KC_1  ,  KC_2  ,  KC_3  , KC_PEQL, KC_ENT ,
                                 _______, _______, _______, _______, _______, KC_DOT, KC_COMM, _______, _______, _______
    ),
/*
 * Adjust Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
*  |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|      | CapsLk |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      | HOME | PGDN | PGUP | END  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      KC_MPLY, KC_VOLU, _______, _______, _______, _______,                                     _______ , _______, _______, _______  , _______, _______,
      KC_MPRV, KC_VOLD, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_CAPS,
      KC_MNXT, KC_MUTE, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * I3wm Layer
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * | Quit   | WS1  | WS2  | WS3  | WS4  | WS5  |                              |      |Resize|Orient|      |      | SLEEP  |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |Monitor | WS6  | WS7  | WS8  | WS9  | WS0  |                              | Left | Down | Up   | Right|      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |Rest  |Files |L.mode|Scratc|      | Term | Brow |  |      |      |      |2Scrat|Float |Full  |  ?   |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      | Sett | App  | Cmd  |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
     [_I3WM] = LAYOUT(
       G(S(KC_Q)), G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                             _______, RESIZE, ORIENTATION, XXXXXXX, XXXXXXX, SLEEP,
       NEXT_WS, G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0),                             G(KC_LEFT), G(KC_DOWN), G(KC_UP), G(KC_RIGHT), _______, _______,
       _______, G(C(KC_R)), FILES, L_MODE, SCRAT, XXXXXXX,  TERM, BROWSER, XXXXXXX, XXXXXXX, XXXXXXX, MSCRAT, FLOAT, FULL, G(S(KC_QUES)), _______,  
                                  XXXXXXX,  XXXXXXX, G(KC_C), APP , CMD , XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
     ),
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, _______, RGB_SAI, RGB_HUI, RGB_VAI, _______,                                     _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______,
                                 _______, _______, _______, _______, _______, G(KC_C), _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMBOL, _NUMBERS, _NAV);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _I3WM:
            oled_write_P(PSTR("I3wm\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode){
    case LT(_NUMBERS, KC_TAB):
      return TAPPING_TERM - 50;
    case LT(_SYMBOL, KC_TAB):
      return TAPPING_TERM - 50;
    default:
      return TAPPING_TERM;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CAPSWRD:
            if(record->event.pressed) {
                enable_caps_word();
            }
            return false;
        default:
            return true;
    }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_BSPC) {
            enable_xcase_with(KC_UNDS);
        }
        SEQ_ONE_KEY(KC_LSFT) {
            enable_xcase_with(OSM(MOD_LSFT));
        }
    }
}
