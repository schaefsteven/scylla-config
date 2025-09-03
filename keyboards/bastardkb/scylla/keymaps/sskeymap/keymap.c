/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

enum layer_names {
    test,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [main] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_DQUO,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   KC_LGUI, KC_LALT, XXXXXXX,    XXXXXXX,  KC_SPC, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           XXXXXXX, XXXXXXX,     KC_ESC,  KC_ENT
    ),

    //[top] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
         //KC_ESC, KC_BSPC,  KC_SPC,  KC_ENT, XXXXXXX, KC_CIRC,       KC_DLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(gaming),
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
         //KC_GRV, KC_TILD, KC_LCBR, KC_LBRC, KC_LPRN, KC_LABK,      KC_RABK, KC_RPRN, KC_RBRC, KC_RCBR, KC_AMPR, KC_PIPE,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, KC_EXLM,   KC_AT, KC_HASH, KC_UNDS, KC_MINS,      KC_PLUS,  KC_EQL, KC_ASTR, KC_PERC, KC_BSLS, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   //_______, _______, _______,    MO(emoji), _______, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                         //MO(sw_top), _______,      _______, _______
    //),

    //[front] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
         //KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,       KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
         //KC_NUM,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,        KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, KC_PSCR, KC_SCRL, KC_PAUS,  KC_INS,  KC_DEL,      KC_HOME,  KC_END, KC_PGUP, KC_PGDN,  KC_APP, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   //_______, _______, MO(emoji),    _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                            //_______, _______,      _______, _______
    //),

    //[swap] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
          //KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //KC_DQUO,    KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, KC_SCLN,    KC_L,    KC_K,    KC_J,    KC_H,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, KC_SLSH,  KC_DOT, KC_COMM,    KC_M,    KC_N,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   //_______, _______, MO(sw_top),   _______, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                            //_______, _______,      _______, _______
    //),

    //[sw_top] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
     //DF(gaming), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DLR,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //KC_PIPE, KC_AMPR, KC_RCBR, KC_RBRC, KC_RPRN, KC_RABK,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______,    KC_0,    KC_9,    KC_8,    KC_7,    KC_6,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, KC_BSLS, KC_PERC, KC_ASTR,  KC_EQL, KC_PLUS,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   //_______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                            //_______, _______,      XXXXXXX, XXXXXXX
    //),

    //[emoji] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, XXXXXXX, XXXXXXX, XXXXXXX,    KC_E, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   //_______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                            //_______, _______,      XXXXXXX, XXXXXXX
    //),

    //[ultra] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
        //_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   //_______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                            //_______, _______,      XXXXXXX, XXXXXXX
    //),

    //[gaming] = LAYOUT_split_4x6_5(
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
           //KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_0,      DF(main), DF(main), DF(main), DF(main), DF(main), DF(main),
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
         //KC_TAB,    KC_G,    KC_Q,    KC_W,    KC_E,    KC_R,      DF(main), DF(main), DF(main), DF(main), DF(main), DF(main),
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
           //KC_T, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,      DF(main), DF(main), DF(main), DF(main), DF(main), DF(main),
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
           //KC_9,    KC_8,    KC_Z,    KC_X,    KC_C,    KC_V,      DF(main), DF(main), DF(main), DF(main), DF(main), DF(main),
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                   //KC_LALT,  KC_SPC,    KC_6,      DF(main), DF(main), DF(main),
    //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                            //KC_LCTL,    KC_7,      DF(main), DF(main)
    //),

};
