/* Copyright 2023 Wyatt Raphael <wyatt.s.raphael@gmail.com>
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

enum layers {
    QWERTY = 0,
    NAV,
    SYM,
    FUNCTION,
    GAME
};

// Aliases for readability
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: QWERTY
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        | Game | LGUI | LAlt/| Space| Nav  |  | Sym  | Space| RAlt/| RGUI | Menu |
     *                        |      |      | Enter|      |      |  |      |      | Enter|      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [QWERTY] = LAYOUT(
      KC_TAB,  KC_Q, KC_W, KC_E,  KC_R,    KC_T,                                         KC_Y,           KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
      CTL_ESC, KC_A, KC_S, KC_D,  KC_F,    KC_G,                                         KC_H,           KC_J,    KC_K,    KC_L,   KC_SCLN, CTL_QUOT,
      KC_LSFT, KC_Z, KC_X, KC_C,  KC_V,    KC_B,    KC_LBRC, KC_CAPS,    MO(3), KC_RBRC, KC_N,           KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                           DF(4), KC_LGUI, ALT_ENT, KC_SPC,  MO(1),      MO(2), KC_SPC,  RALT_T(KC_ENT), KC_RGUI, KC_APP
    ),
    /*
     * Nav Layer: Media, navigation
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              | Home | PgDn | PgUp | End  | VolUp| Delete |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |  GUI |  Alt | Ctrl | Shift|      |                              |   ←  |   ↓  |   ↑  |   →  | VolDn| Insert |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |ScLck |  |      |      | Pause|M Prev|M Play|M Next|VolMut| PrtSc  |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_HOME,  KC_PGDN, KC_PGUP, KC_END,  KC_VOLU, KC_DEL,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                     KC_LEFT,  KC_DOWN, KC_LEFT, KC_RGHT, KC_VOLD, KC_INS,
      _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, KC_PAUSE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    /*
     * Sym Layer: Numbers and symbols
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
	[SYM] = LAYOUT(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
      KC_PIPE, KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR,  KC_RBRC, KC_UNDS, KC_COMM, KC_DOT,  KC_SLSH, KC_QUES,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    /*
     * Function Layer: Function keys
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |  F9  | F10  | F11  | F12  |      |                              |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |  F5  |  F6  |  F7  |  F8  |      |                              |      | Shift| Ctrl |  Alt |  GUI |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |  F1  |  F2  |  F3  |  F4  |      |      |      |  |      |      |      |      |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
	[FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, _______,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , _______,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    /*
     * Base Layer: Gaming, WASD is a little too staggered
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |  Tab   |   1  |   Q  |   W  |   E  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |Ctrl/Esc|   2  |   A  |   S  |   D  |   F  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | LShift |   3  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |QWERTY| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| RAlt/| RGUI | Menu |
     *                        |      |      | Enter|      |      |  |      |      | Enter|      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [GAME] = LAYOUT(
      KC_TAB,  KC_1, KC_Q, KC_W,  KC_E,    KC_T,                                         KC_Y,           KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
      CTL_ESC, KC_2, KC_A, KC_S,  KC_D,    KC_F,                                         KC_H,           KC_J,    KC_K,    KC_L,   KC_SCLN, CTL_QUOT,
      KC_LSFT, KC_3, KC_X, KC_C,  KC_V,    KC_B,    KC_LBRC, KC_CAPS,    MO(3), KC_RBRC, KC_N,           KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                           DF(0), KC_LGUI, ALT_ENT, KC_SPC,  MO(1),      MO(2), KC_SPC,  RALT_T(KC_ENT), KC_RGUI, KC_APP
    )
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
