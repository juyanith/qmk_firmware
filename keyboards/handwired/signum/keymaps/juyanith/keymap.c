#include "signum.h"

#define _C_A_D LALT(LCTL(KC_DEL))
#define _C_DEL CTL_T(KC_DEL)
#define _C_BSPC CTL_T(KC_BSPC)
#define _S_BSPC SFT_T(KC_BSPC)
#define _ADJBSP LT(_ADJUST, KC_DEL)
#define _ADJDEL LT(_ADJUST, KC_DEL)
#define _S_TAB RSFT(KC_TAB)
#define _SC_TAB RSFT(RCTL(KC_TAB))
#define _C_TAB RCTL(KC_TAB)
#define _C_UP LCTL(KC_UP)
#define _C_DOWN LCTL(KC_DOWN)
#define _C_LEFT RCTL(KC_LEFT)
#define _C_RGHT RCTL(KC_RGHT)
#define _G_TAB RGUI(KC_TAB)

#define TO_LOWR TO(_SYMBOL)
#define TO_RAIS TO(_NAVIGATION)

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#ifndef TAPPING_TERM
#define TAPPING_TERM 200
#endif

enum signum_keycodes {
	COPY  = SAFE_RANGE,
	CUT,
	PASTE,
	M_SYMBL, 
	M_NAV,
	UNDO
};

enum signum_layers {
	_BASE,
	_SYMBOL,
	_NAVIGATION,
	_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = KEYMAP(
		KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, 
		KC_LBRC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, 
		KC_RBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, 
		_______, KC_ESC,  KC_LGUI, KC_LALT, _C_DEL,  _S_BSPC,      M_SYMBL, M_NAV,   KC_BSPC, KC_DEL,  KC_APP,  _______),

	[_SYMBOL] = KEYMAP(
		KC_DOT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, 
		KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO, 
		KC_RBRC, KC_TILD, KC_GRV,  KC_MINS, KC_PLUS, KC_UNDS,      KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_QUES, KC_PIPE, 
		_______, _______, _______, _______, _C_BSPC, _ADJDEL,      _______, _______, _______, _______, _______, _______),

	[_NAVIGATION] = KEYMAP(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		KC_PSCR, _S_TAB,  _SC_TAB, _C_TAB,  KC_TAB,  _C_UP,        _C_LEFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _C_RGHT, 
		KC_INS,  UNDO,    CUT,     COPY,    PASTE,   _C_DOWN,      _G_TAB,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PAUS, 
		_______, _______, _______, _______, _C_DEL,  KC_LSFT,      _______, _______, _______, _______, _______, _______),

	[_ADJUST] = KEYMAP(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _C_A_D,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)

};

static bool layer_interrupted[] = { false, false, false, false };
static uint16_t layer_timers[] = { 0, 0, 0, 0 };

void layer_mod_pressed(int layer,uint16_t keycode, uint16_t kc_shifted) {
	layer_interrupted[layer] = false;
	layer_timers[layer] = timer_read();
	layer_on(layer);
}

void layer_mod_released(int layer, uint16_t keycode, uint16_t kc_shifted) {
	layer_off(layer);
	if (!layer_interrupted[layer] && timer_elapsed(layer_timers[layer]) < TAPPING_TERM) {
		if (keyboard_report->mods & MODS_SHIFT_MASK) {
			register_code (kc_shifted);
			unregister_code(kc_shifted);
		} else { 
			register_code (keycode);
			unregister_code(keycode);
		}
		layer_interrupted[layer] = true;
	}
}

static bool shift_removed = false;

void unshift_pressed(uint16_t keycode) {
	shift_removed = keyboard_report->mods & MODS_SHIFT_MASK;
	if (shift_removed) {
		del_mods(MOD_LSFT);
	}
	register_code(keycode);
}

void unshift_released(uint16_t keycode) {
	if (shift_removed) {
		add_mods(MOD_LSFT);
	}
	unregister_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case COPY:
			if (record->event.pressed) {
				add_mods(MOD_LCTL);
				unshift_pressed(KC_C);
			} else {
				unshift_released(KC_C);
				del_mods(MOD_LCTL);
			}
			return false;
			break;

		case CUT:
			if (record->event.pressed) {
				add_mods(MOD_LCTL);
				unshift_pressed(KC_X);
			} else {
				unshift_released(KC_X);
				del_mods(MOD_LCTL);
			}
			return false;
			break;

		case PASTE:
			if (record->event.pressed) {
				add_mods(MOD_LCTL);
				unshift_pressed(KC_V);
			} else {
				unshift_released(KC_V);
				del_mods(MOD_LCTL);
			}
			return false;
			break;
			
		case UNDO:
			if (record->event.pressed) {
				add_mods(MOD_LCTL);
				unshift_pressed(KC_Z);
			} else {
				unshift_released(KC_Z);
				del_mods(MOD_LCTL);
			}
			return false;
			break;
			
		case M_NAV: 
			if (record->event.pressed) {
				layer_mod_pressed(_NAVIGATION, KC_ENT, KC_SPC);
			} else {
				layer_mod_released(_NAVIGATION, KC_ENT, KC_SPC);
			}
			return false;

		case M_SYMBL: 
			if (record->event.pressed) {
				// Remove and preserve shift modifier.
				shift_removed = keyboard_report->mods & MODS_SHIFT_MASK;
				if (shift_removed) del_mods(MOD_LSFT);
				
				layer_mod_pressed(_SYMBOL, KC_SPC, KC_ENT);
			} else {
				if (shift_removed) add_mods(MOD_LSFT);
				
				layer_mod_released(_SYMBOL, KC_SPC, KC_ENT);
			}
			return false;

		default:
			layer_interrupted[_ADJUST] = true;
			layer_interrupted[_BASE] = true;
			layer_interrupted[_NAVIGATION] = true;
			layer_interrupted[_SYMBOL] = true;
			return true; // Process all other keycodes normally
	}
}