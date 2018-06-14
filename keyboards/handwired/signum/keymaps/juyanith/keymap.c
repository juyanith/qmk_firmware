#include "signum.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
		KEYMAP(
		KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, 
		KC_LBRC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, 
		KC_RBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, 
		TO(1),   KC_ESC,  KC_LGUI, KC_LALT, MT(MOD_LCTL, KC_DEL), MT(MOD_LSFT, KC_BSPC), LT(2, KC_SPC), LT(1, KC_ENT), KC_BSPC, KC_DEL,  KC_APP,  TO(2)  ),

	KEYMAP(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		KC_PSCR, RSFT(KC_TAB), RSFT(RCTL(KC_TAB)), RCTL(KC_TAB), KC_TAB,  LCTL(KC_UP), RCTL(KC_LEFT), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, RCTL(KC_RGHT), 
		KC_INS,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_DOWN), RGUI(KC_TAB), KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PAUS, 
		TO(0),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

	KEYMAP(
		KC_DOT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, 
		KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO, 
		KC_RBRC, KC_TILD, KC_GRV,  KC_MINS, KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_QUES, KC_PIPE, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(0)  )

};
