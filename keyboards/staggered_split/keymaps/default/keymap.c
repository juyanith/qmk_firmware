#include QMK_KEYBOARD_H

#define _ADJBS1 LT(_ADJUST, KC_DEL)
#define _ADJBS2 LT(_ADJUST, KC_ENT)

#define _C_A_D LALT(LCTL(KC_DEL))
#define _C_S_E LSFT(LCTL(KC_ESC))
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

#define _L_NAV LT(_NAVIGATION, KC_SPC)
#define _L_SYM1 LT(_SYMBOL, KC_DEL)
#define _L_SYM2 LT(_SYMBOL, KC_ENT)

#define _S_BSPC SFT_T(KC_BSPC)
#define _S_TAB RSFT(KC_TAB)

#define _SC_TAB RSFT(RCTL(KC_TAB))

#define _T_QWRT TG(_QUERTY)

#define _SHIFT_ KC_SFTENT

extern keymap_config_t keymap_config;

// Macros
enum {
  ALL = SAFE_RANGE,
	COPY,
	CUT,
	KILL,
	KILLCLR,
	PASTE,
  SAVE,
	UNDO,
	YANK,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_ortho_5x12(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
		KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                                              KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
		KC_UNDS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                              KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
		                  KC_LGUI, KC_LALT, KC_LCTL, _SHIFT_, _L_SYM1, KC_BSPC,       KC_DEL,  _L_SYM2, _L_NAV,  KC_RALT, KC_APP, KC_INS),

	[_QUERTY] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______, _______,
		_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
		_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
		_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
		                  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______),

	[_SYMBOL] = LAYOUT_ortho_5x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
		_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
		KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
		_______, KC_TILD, KC_GRV,  KC_UNDS, KC_LCBR, KC_LBRC,                                           KC_RBRC, KC_RCBR, KC_MINS, KC_PLUS, KC_EQL,  _______,
		                  _______, _______, _______, _______, _ADJBS1, _______,       _______, _ADJBS2, _______, _______, _______, _______),

	[_NAVIGATION] = LAYOUT_ortho_5x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
		_______, ALL,     KILL,    SAVE,    YANK,    _C_UP,                                             _C_LEFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _C_RGHT,
    KILLCLR, UNDO,    CUT,     COPY,    PASTE,   _C_DOWN,                                           _G_TAB,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
		                  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______),

	[_ADJUST] = LAYOUT_ortho_5x12(
    _C_S_E,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _C_A_D,
		XXXXXXX, _T_QWRT, XXXXXXX, XXXXXXX, XXXXXXX, _D_STA1,                                           _D_STA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_PLA1,                                           _D_PLA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_STOP,                                           _D_STOP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, RESET,         KC_PSCR, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX)

};

// #ifdef AUDIO_ENABLE
// float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
// float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
// float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
// #endif

// void persistent_default_layer_set(uint16_t default_layer) {
//   eeconfig_update_default_layer(default_layer);
//   default_layer_set(default_layer);
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case QWERTY:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(tone_qwerty);
//         #endif
//         persistent_default_layer_set(1UL<<_QWERTY);
//       }
//       return false;
//       break;
//     case COLEMAK:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(tone_colemak);
//         #endif
//         persistent_default_layer_set(1UL<<_COLEMAK);
//       }
//       return false;
//       break;
//     case DVORAK:
//       if (record->event.pressed) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(tone_dvorak);
//         #endif
//         persistent_default_layer_set(1UL<<_DVORAK);
//       }
//       return false;
//       break;
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case ADJUST:
//       if (record->event.pressed) {
//         layer_on(_ADJUST);
//       } else {
//         layer_off(_ADJUST);
//       }
//       return false;
//       break;
//   }
//   return true;
// }
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
      case ALL:
        if (record->event.pressed) {
          mod_unshift(KC_RCTRL, KC_A);
        }
        return false;
        break;

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
				mod_unshift(0, KC_END);
				mod_unshift(0, KC_RIGHT);
				register_code(KC_RSFT);
				register_code(KC_UP);
				unregister_code(KC_UP);
				unregister_code(KC_RSFT);
				mod_unshift(KC_RCTRL, KC_X);
			}
			return false;
			break;

		case KILLCLR:
			if (record->event.pressed) {
				register_code(KC_RSFT);
				register_code(KC_RCTRL);
				register_code(KC_RALT);
				register_code(KC_DEL);
				unregister_code(KC_DEL);
				unregister_code(KC_RALT);
				unregister_code(KC_RCTRL);
				unregister_code(KC_RSFT);
			}
			return false;
			break;

		case PASTE:
			if (record->event.pressed) {
				mod_unshift(KC_RCTRL, KC_V);
			}
			return false;
			break;

    case SAVE:
      if (record->event.pressed) {
        mod_unshift(KC_RCTRL, KC_S);
      }
      return false;
      break;

		case UNDO:
			if (record->event.pressed) {
				mod_unshift(KC_RCTRL, KC_Z);
			}
			return false;
			break;

		case YANK:
			if (record->event.pressed) {
				register_code(KC_RSFT);
				register_code(KC_RCTRL);
				register_code(KC_V);
				unregister_code(KC_V);
				unregister_code(KC_RCTRL);
				unregister_code(KC_RSFT);
				mod_unshift(KC_RCTRL, KC_V);
			}
			return false;
			break;

		default:
			return true; // Process all other keycodes normally
	}
}
