/* Copyright 2017 Wunder
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
#include "xd75.h"

#define _ADJBS1 LT(_ADJUST, KC_BSPC)
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

#define _L_NAV TT(_NAVIGATION)
#define _L_SYM1 LT(_SYMBOL, KC_BSPC)
#define _L_SYM2 LT(_SYMBOL, KC_ENT)

#define _S_BSPC SFT_T(KC_BSPC)
#define _S_TAB RSFT(KC_TAB)

#define _SC_TAB RSFT(RCTL(KC_TAB))

#define _T_QWRT TG(_QUERTY)

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
enum xd75_layers {
	_COLEMAK,
  _QUERTY,
	_SYMBOL,
	_NAVIGATION,
	_ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak base
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | [      | `      | ]      | 6      | 7      | 8      | 9      | 0      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | F      | P      | G      | HOME   | PRTSCR | END    | J      | L      | U      | Y      | ;      | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BACKSP | A      | R      | S      | T      | D      | PG UP  | UP     | PG DN  | H      | N      | E      | I      | O      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | _      | Z      | X      | C      | V      | B      | LEFT   | DOWN   | RIGHT  | K      | M      | ,      | .      | /      | \      |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | CTRL   | OS     | ALT    | CTRL   | SHIFT  | BACKSP | DELETE | CAPS   | SHIFT  | ENTER  | SPACE  | FN     | MENU   | INS    | CTRL   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

	[_COLEMAK] = LAYOUT(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC, KC_GRV,  KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, 
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_HOME, KC_PSCR, KC_END,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, 
		KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_PGUP, KC_UP,   KC_PGDN, KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, 
		KC_UNDS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LEFT, KC_DOWN, KC_RGHT, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _L_SYM1, KC_DEL,  KC_CAPS, KC_RSFT, _L_SYM2, KC_SPC,  _L_NAV,  KC_APP,  KC_INS,  KC_RCTL),

  [_QUERTY] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
 
	[_SYMBOL] = LAYOUT( 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_TILD, KC_GRV,  KC_MINS, KC_PLUS, KC_UNDS, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _ADJBS1, _______, _______, _______, _ADJBS1, _______, _______, _______, _______, _______),

	[_NAVIGATION] = LAYOUT(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    KILLCLR, ALL,     KILL,    SAVE,    YANK,    _C_UP,   _______, _______, _______, _C_LEFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _C_RGHT,
    _______, UNDO,    KILL,    SAVE,    YANK,    _C_DOWN, _______, _______, _______, _G_TAB,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
		_______, _______, CUT,     COPY,    PASTE,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

  [_ADJUST] = LAYOUT(
		_C_S_E,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, 
		XXXXXXX, _T_QWRT, XXXXXXX, XXXXXXX, XXXXXXX, _D_STA1, XXXXXXX, XXXXXXX, XXXXXXX, _D_STA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_PLA1, XXXXXXX, XXXXXXX, XXXXXXX, _D_PLA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_STOP, XXXXXXX, XXXXXXX, XXXXXXX, _D_STOP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, _C_A_D,  XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),
 
};

//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
//{
//  // MACRODOWN only works in this function
//      switch(id) {
//        case 0:
//          if (record->event.pressed) {
//            register_code(KC_RSFT);
//            #ifdef BACKLIGHT_ENABLE
//              backlight_step();
//            #endif
//          } else {
//            unregister_code(KC_RSFT);
//          }
//        break;
//      }
//    return MACRO_NONE;
//};

// Used to send ctrl-key while ignoring shift which is useful on the navigation layer
// because holding down shift to select is commonly done.
void mod_unshift(uint16_t kc_mod, uint16_t keycode) {
  uint8_t mods_bkp = keyboard_report->mods;
  del_mods(MOD_LSFT & MOD_RSFT);

  if (kc_mod) {
    // registering a keypress seems to work better than add_mods
    register_code(kc_mod);
  }
  register_code(keycode);
  unregister_code(keycode);
  if (kc_mod) {
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
      return true;  // Process all other keycodes normally
  }
}
