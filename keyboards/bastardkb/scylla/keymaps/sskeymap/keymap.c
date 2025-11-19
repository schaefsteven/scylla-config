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
 *
 *
 * TODO:
 * emoji layer
 * other numpad keys
 *
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
    UD_EM1 = SAFE_RANGE,
    UD_PHF,
    UD_PHU,
    UD_IP1,
    UD_KVM1,
    UD_KVM2,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    // MACROS
    case UD_EM1:
        if (record->event.pressed) {
            SEND_STRING("schaefsteven@gmail.com");
        }
        break;

    case UD_PHF:
        if (record->event.pressed) {
            SEND_STRING("(906) 291-0614");
        }
        break;

    case UD_PHU:
        if (record->event.pressed) {
            SEND_STRING("9062910614");
        }
        break;

    case UD_IP1:
        if (record->event.pressed) {
            SEND_STRING("192.168.1.");
        }
        break;

    case UD_KVM1:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "1" SS_DELAY(100) SS_TAP(X_LGUI));
        }
        break;

    case UD_KVM2:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL) "2");
        }
        break;

    // DOUBLE SHIFT FOR CAPS LOCK
    case KC_LSFT:
        if (record->event.pressed) {
            if (get_mods() & MOD_BIT(KC_RSFT)) {
                tap_code(KC_CAPS);
            }
        }
        break;

    case KC_RSFT:
        if (record->event.pressed) {
            if (get_mods() & MOD_BIT(KC_LSFT)) {
                tap_code(KC_CAPS);
            }
        }
        break;

    }
    return true;


};

enum layer_names {
    main,
    swap,
    top,
    sw_top,
    ultra,
    sw_ult,
    front,
    emoji,
    lspc,
    gaming,
    gtop,
    gmain,
};

enum unicode_names {
    ROCKET, // 🚀
};

const uint32_t PROGMEM unicode_map[] = {
    [ROCKET] = 0x1F680, // 🚀
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
                              KC_LGUI, MT(MOD_LALT, KC_SPC), MO(top),    MO(front),  KC_SPC, KC_BSPC,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                 MO(swap), MO(ultra),     KC_ESC,  KC_ENT
            ),

            // SWAP
            [swap] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                KC_DQUO,    KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, KC_SCLN,    KC_L,    KC_K,    KC_J,    KC_H,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, KC_SLSH,  KC_DOT, KC_COMM,    KC_M,    KC_N,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, MO(sw_top),   XXXXXXX, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    _______, MO(sw_ult),   _______, _______
            ),

            // TOP
            [top] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_GRV, KC_TILD, KC_LCBR, KC_LBRC, KC_LPRN, KC_LABK,      KC_RABK, KC_RPRN, KC_RBRC, KC_RCBR, KC_AMPR, KC_PIPE,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
  MT(MOD_LSFT, KC_CIRC), KC_EXLM,   KC_AT, KC_HASH, KC_UNDS, KC_MINS,      KC_PLUS,  KC_EQL, KC_ASTR, KC_PERC, KC_BSLS, MT(MOD_RSFT, KC_DLR),
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, _______,    MO(emoji), _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                 MO(sw_top), _______,      _______, _______
            ),

            // SWAP TOP
            [sw_top] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_F12,  KC_F11,  KC_F10,   KC_F9,   KC_F8,   KC_F7,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                KC_PIPE, KC_AMPR, KC_RCBR, KC_RBRC, KC_RPRN, KC_RABK,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______,    KC_0,    KC_9,    KC_8,    KC_7,    KC_6,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, KC_BSLS, KC_PERC, KC_ASTR,  KC_EQL, KC_PLUS,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, _______,      XXXXXXX, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    _______, XXXXXXX,      _______, _______
            ),

            // ULTRA
            [ultra] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_ESC,  UD_IP1,  UD_PHU,  UD_PHU,  UD_EM1, DF(gaming),   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_DEL,  KC_INS, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, KC_BSPC, KC_PSCR,  KC_ENT,  KC_SPC, TG(lspc),     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, UD_KVM1, UD_KVM2, XXXXXXX, DM_PLY1, DM_PLY2,      DM_REC1, DM_REC2, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, XXXXXXX,      XXXXXXX, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                 MO(sw_ult), _______,      DM_RSTP, _______
            ),

            // SWAP ULTRA
            [sw_ult] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, XXXXXXX, KC_HOME,   KC_UP,  KC_END, KC_PGUP,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, XXXXXXX,      XXXXXXX, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    _______, _______,      _______, _______
            ),

            // FRONT
            [front] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, _______, _______, _______, _______, _______,      KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PENT, KC_PDOT,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_NUM,   KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,        KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______,  KC_APP, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX,      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, MO(emoji),    _______, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    _______, _______,      _______, _______
            ),

            // EMOJI (TOP + FRONT)
            [emoji] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, XXXXXXX, XXXXXXX, XXXXXXX, UM(ROCKET), XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    _______, _______,      XXXXXXX, XXXXXXX
            ),

            // OVERLAY WITH LEFT SIDE SPACE KEY
            [lspc] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, _______, _______, _______, _______, KC_LALT,      _______, _______, _______, _______, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______,  KC_SPC, _______,      _______, _______, _______,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    _______, _______,      _______, _______
            ),

            // GAMING BASE LAYER WITH WASD MOVED
            [gaming] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_ESC,  KC_F13,    KC_T,    KC_G,    KC_B,    KC_H,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(main),
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_TAB,    KC_M,    KC_Q,    KC_W,    KC_E,    KC_R,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_DQUO,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                KC_LCTL, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_F14,  KC_F15,    KC_Z,    KC_X,    KC_C,    KC_V,         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           KC_LALT,  KC_SPC, MO(gtop),   MO(front),  KC_SPC, KC_BSPC,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    KC_RCTL, MO(gmain),     KC_ESC,  KC_ENT
            ),

            // TOP LAYER FOR GAMING MODE
            [gtop] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(main),
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                           _______, _______, _______,      XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                    _______, _______,      XXXXXXX, XXXXXXX
            ),

            // MOMENTARY MAIN LAYER TO ACCESS FROM GAMING LAYER
            [gmain] = LAYOUT_split_4x6_5(
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                 KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_DQUO,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                              KC_LGUI, MT(MOD_LALT, KC_SPC), MO(top),    MO(front),  KC_SPC, KC_BSPC,
            //|--------+--------+--------+--------+--------+--------|    |--------+--------+--------+--------+--------+--------|
                                                   MO(swap), _______,     KC_ESC,  KC_ENT
            ),
};
