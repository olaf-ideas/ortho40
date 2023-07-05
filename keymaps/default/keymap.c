// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum KeyboardLayers {
	QWERTY,
	LOWER,
	RAISE,
	SPECIAL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ESC│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │TAB│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │SFT│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ENT│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │CTL│ALT│WIN│DEL│LOW│SPC│BSP│RAI│ ← │ ↑ | ↓ │ → │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
	[QWERTY] = LAYOUT_ortho_4x12(
		KC_ESC,  KC_Q,    KC_W,   KC_E,   KC_R,      KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_TAB,  KC_A,    KC_S,   KC_D,   KC_F,      KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,      KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
		KC_LCTL, KC_LALT, KC_APP, KC_DEL, MO(LOWER), KC_SPC,  KC_BSPC, MO(RAISE), KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
	),
	[LOWER] = LAYOUT_ortho_4x12(
		KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,     KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
		KC_NO,  KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_UNDS,     KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
		KC_NO,  KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,  KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   MO(SPECIAL), KC_NO,   KC_NO,   KC_NO,   KC_NO
	),
	[RAISE] = LAYOUT_ortho_4x12(
		KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,        KC_5,    KC_6,    KC_7,    KC_8,   KC_9,    KC_0,    KC_NO,
		KC_NO,  KC_F1, KC_F2, KC_F3, KC_F4,       KC_F5,   KC_F6,   KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_NO,  KC_F7, KC_F8, KC_F9, KC_F10,      KC_F11,  KC_F12,  KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
		KC_NO,  KC_NO, KC_NO, KC_NO, MO(SPECIAL), KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO
	),
	[SPECIAL] = LAYOUT_ortho_4x12(
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	),
};

layer_state_t layer_state_set_user(layer_state_t state) {
	if (layer_state_cmp(state, LOWER)) {
		rgblight_sethsv_at(HSV_WHITE, 5);
	}
	else {
		rgblight_sethsv_at(HSV_RED, 5);
	}

	return state;
}

#ifdef OLED_ENABLE

bool oled_task_user(void) {
	oled_write_P(PSTR("tescik v2"), false);
	return false;
}

#endif

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
	[QWERTY]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
	[LOWER]   = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
	[RAISE]   = { ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
	[SPECIAL] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};

#endif
