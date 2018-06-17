#include "signum.h"

#define _ADJBSP LT(_ADJUST, KC_BSPC)

#define _C_A_D LALT(LCTL(KC_DEL))
#define _C_DEL CTL_T(KC_DEL)
#define _C_TAB RCTL(KC_TAB)
#define _C_UP LCTL(KC_UP)
#define _C_DOWN LCTL(KC_DOWN)
#define _C_LEFT RCTL(KC_LEFT)
#define _C_RGHT RCTL(KC_RGHT)

#define _G_TAB RGUI(KC_TAB)

#define _L_NAV LT(_NAVIGATION, KC_ENT)
#define _L_SYM LT(_SYMBOL, KC_SPC)

#define _S_BSPC SFT_T(KC_BSPC)
#define _S_TAB RSFT(KC_TAB)

#define _SC_TAB RSFT(RCTL(KC_TAB))

enum signum_keycodes {
	COPY  = SAFE_RANGE,
	CUT,
	PASTE,
	UNDO
};

enum signum_layers {
	_COLEMAK,
	_SYMBOL,
	_NAVIGATION,
	_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = KEYMAP(
		KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, 
		KC_LBRC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, 
		KC_RBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, 
		KC_LGUI, KC_PAUS, KC_PSCR, KC_LALT, _C_DEL,  _S_BSPC,      _L_SYM, _L_NAV,   KC_BSPC, KC_DEL,  KC_APP,  KC_ESC),

	[_SYMBOL] = KEYMAP(
		KC_DOT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, 
		KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO, 
		KC_RBRC, KC_TILD, KC_GRV,  KC_MINS, KC_PLUS, KC_UNDS,      KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_QUES, KC_PIPE, 
		_______, _______, _______, _______, _______, _ADJBSP,      _______, _______, _______, _______, _______, _______),

	[_NAVIGATION] = KEYMAP(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		KC_INS,  _S_TAB,  _SC_TAB, _C_TAB,  KC_TAB,  _C_UP,        _C_LEFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _C_RGHT, 
		_______, UNDO,    CUT,     COPY,    PASTE,   _C_DOWN,      _G_TAB,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, 
		_______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______),

	[_ADJUST] = KEYMAP(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _C_A_D,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)

};

// Used to send ctrl-key while ignoring shift which is useful on the navigation layer 
// because holding down shift to select is commonly done.
void ctrl_unshift(uint16_t keycode) {
	uint8_t mods_bkp = keyboard_report->mods;
	del_mods(MOD_LSFT & MOD_RSFT);
	register_code(KC_RCTRL); // registering a keypress here works better than add_mods
	register_code(keycode);
	unregister_code(keycode); 
	unregister_code(KC_RCTRL);
	set_mods(mods_bkp);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case COPY:
			if (record->event.pressed) {
				ctrl_unshift(KC_C);
			}
			return false;
			break;

		case CUT:
			if (record->event.pressed) {
				ctrl_unshift(KC_X);
			}
			return false;
			break;

		case PASTE:
			if (record->event.pressed) {
				ctrl_unshift(KC_V);
			}
			return false;
			break;
			
		case UNDO:
			if (record->event.pressed) {
				ctrl_unshift(KC_Z);
			}
			return false;
			break;

		default:
			return true; // Process all other keycodes normally
	}
}