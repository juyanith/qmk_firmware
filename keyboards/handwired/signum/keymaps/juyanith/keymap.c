#define _ADJBSP LT(_ADJUST, KC_BSPC)

#define _C_A_D LALT(LCTL(KC_DEL))
#define _C_DEL CTL_T(KC_DEL)
#define _C_TAB RCTL(KC_TAB)
#define _C_UP LCTL(KC_UP)
#define _C_DOWN LCTL(KC_DOWN)
#define _C_LEFT RCTL(KC_LEFT)
#define _C_RGHT RCTL(KC_RGHT)

#define _D_PLA1 DYN_MACRO_PLAY1
#define _D_PLA2 DYN_MACRO_PLAY2
#define _D_STA1 DYN_REC_START1
#define _D_STA2 DYN_REC_START2
#define _D_STOP DYN_REC_STOP

#define _G_TAB RGUI(KC_TAB)

#define _L_NAV LT(_NAVIGATION, KC_ENT)
#define _L_SYM LT(_SYMBOL, KC_SPC)

#define _S_BSPC SFT_T(KC_BSPC)
#define _S_TAB RSFT(KC_TAB)

#define _SC_TAB RSFT(RCTL(KC_TAB))

#define _T_QWRT TG(_QUERTY)

#define _TD_ABR TD(ANGLE_BRACKETS)
#define _TD_SBR TD(SQUARE_BRACKETS)
#define _TD_CBR TD(CURLY_BRACES)
#define _TD_PRN TD(PARENTHESES)

#include "signum.h"

// Macros
enum {
	COPY  = SAFE_RANGE,
	CUT,
	KILL,
	PASTE,
	UNDO,
	DYNAMIC_MACRO_RANGE
};

// NOTE: Must be after definition of DYNAMIC_MACRO_RANGE
#include "dynamic_macro.h"

// Layers
enum {
	_COLEMAK,
	_QUERTY,
	_SYMBOL,
	_NAVIGATION,
	_ADJUST
};

//Tapdance
enum {
	ANGLE_BRACKETS,
	CURLY_BRACES,
	PARENTHESES,
    SQUARE_BRACKETS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_COLEMAK] = KEYMAP(
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, 
		KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, 
		KC_UNDS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, 
		KC_LGUI, KC_PAUS, KC_PSCR, KC_LALT, _C_DEL,  _S_BSPC,      _L_SYM, _L_NAV,   KC_BSPC, KC_DEL,  KC_APP,  KC_ESC),
		
	[_QUERTY] = KEYMAP(
		_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, 
		_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, 
		_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, 
		_______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______),

	[_SYMBOL] = KEYMAP(
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, 
		_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, _TD_PRN, KC_RPRN, _______, 
		_______, KC_TILD, KC_GRV,  KC_MINS, KC_PLUS, KC_UNDS,      _TD_CBR, _TD_SBR, _TD_ABR, _______, _______, _______, 
		_______, _______, _______, _______, _______, _ADJBSP,      _______, _______, _______, _______, _______, _______),

	[_NAVIGATION] = KEYMAP(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		KILL,    _S_TAB,  _SC_TAB, _C_TAB,  KC_TAB,  _C_UP,        _C_LEFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _C_RGHT, 
		_______, UNDO,    CUT,     COPY,    PASTE,   _C_DOWN,      _G_TAB,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, 
		_______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______),

	[_ADJUST] = KEYMAP(
		XXXXXXX, _T_QWRT, XXXXXXX, XXXXXXX, XXXXXXX, _D_STA1,      _D_STA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_PLA1,      _D_PLA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_STOP,      _D_STOP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _C_A_D)

};

// Used to send ctrl-key while ignoring shift which is useful on the navigation layer 
// because holding down shift to select is commonly done.
void mod_unshift(uint16_t kc_mod, uint16_t keycode) {
	uint8_t mods_bkp = keyboard_report->mods;
	del_mods(MOD_LSFT & MOD_RSFT);
	
	if (kc_mod)
	{
		// registering a keypress seems to work better than add_mods 
		register_code(kc_mod); 
	}
	register_code(keycode);
	unregister_code(keycode);
	if (kc_mod)
	{
		unregister_code(kc_mod);
	}
	
	// restore mod state
	set_mods(mods_bkp);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
	
	switch (keycode) {
		case COPY:
			if (record->event.pressed) {
				mod_unshift(KC_RCTRL, KC_C);
			}
			return false;
			break;

		case CUT:
			if (record->event.pressed) {
				mod_unshift(KC_RCTRL, KC_X);
			}
			return false;
			break;

		case KILL:
			if (record->event.pressed) {
				mod_unshift(0, KC_HOME);
				register_code(KC_RSFT);
				register_code(KC_DOWN);
				unregister_code(KC_DOWN);
				unregister_code(KC_RSFT);
				mod_unshift(KC_RCTRL, KC_X);
			}
			return false;
			break;

		case PASTE:
			if (record->event.pressed) {
				mod_unshift(KC_RCTRL, KC_V);
			}
			return false;
			break;
			
		case UNDO:
			if (record->event.pressed) {
				mod_unshift(KC_RCTRL, KC_Z);
			}
			return false;
			break;

		default:
			return true; // Process all other keycodes normally
	}
}

void dance_angle_brackets_finished (qk_tap_dance_state_t *state, void *user_data) {
	register_code(KC_RSFT);
	if (state->count == 1) {
		register_code(KC_COMMA);
	} else {
		register_code(KC_DOT);
	}
}

void dance_angle_brackets_reset (qk_tap_dance_state_t *state, void *user_data) {
	unregister_code(KC_RSFT);
	if (state->count == 1) {
		unregister_code(KC_COMMA);
	} else {
		unregister_code(KC_DOT);
	}
}

void dance_curly_braces_finished (qk_tap_dance_state_t *state, void *user_data) {
	register_code(KC_RSFT);
	if (state->count == 1) {
		register_code(KC_LBRC);
	} else {
		register_code(KC_RBRC);
	}
}

void dance_curly_braces_reset (qk_tap_dance_state_t *state, void *user_data) {
	unregister_code(KC_RSFT);
	if (state->count == 1) {
		unregister_code(KC_LBRC);
	} else {
		unregister_code(KC_RBRC);
	}
}

void dance_parentheses_finished (qk_tap_dance_state_t *state, void *user_data) {
	register_code(KC_RSFT);
	if (state->count == 1) {
		register_code(KC_9);
	} else {
		register_code(KC_0);
	}
}

void dance_parentheses_reset (qk_tap_dance_state_t *state, void *user_data) {
	unregister_code(KC_RSFT);
	if (state->count == 1) {
		unregister_code(KC_9);
	} else {
		unregister_code(KC_0);
	}
}

void dance_square_brackets_finished (qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		register_code(KC_LBRC);
	} else {
		register_code(KC_RBRC);
	}
}

void dance_square_brackets_reset (qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		unregister_code(KC_LBRC);
	} else {
		unregister_code(KC_RBRC);
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[ANGLE_BRACKETS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_angle_brackets_finished, dance_angle_brackets_reset),
	[CURLY_BRACES] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_curly_braces_finished, dance_curly_braces_reset),
	[PARENTHESES] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_parentheses_finished, dance_parentheses_reset),
	[SQUARE_BRACKETS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_square_brackets_finished, dance_square_brackets_reset),
};