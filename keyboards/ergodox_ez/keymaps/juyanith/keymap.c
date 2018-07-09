#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _ADJBSP LT(_ADJUST, KC_BSPC)

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

#define _L_NAV LT(_NAVIGATION, KC_ENT)
#define _L_SYM LT(_SYMBOL, KC_SPC)

#define _S_BSPC SFT_T(KC_BSPC)
#define _S_TAB RSFT(KC_TAB)

#define _T_SYM TG(_SYMBOL)

#define _SC_TAB RSFT(RCTL(KC_TAB))

#define _HYPER ALL_T(KC_NO)
#define _MEH MEH_T(KC_NO)

enum juyanith_layers {
	_COLEMAK,
	_SYMBOL,
	_NAVIGATION,
	_ADJUST
};

enum custom_keycodes {
	EPRM = SAFE_RANGE,
	VRSN,
	RGB_SLD,
  	COPY,
	CUT,
	PASTE,
	UNDO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Keymap 0: Basic layer
	 *
	 * ,--------------------------------------------------.           ,--------------------------------------------------.
	 * |    `   |   1  |   2  |   3  |   4  |   5  | ESC  |           | PANIC|   6  |   7  |   8  |   9  |   0  |   -    |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |   Tab  |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |   ;  |   =    |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |    [   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '    |
	 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
	 * |    ]   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |   /  |   \    |
	 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |  OS  | PAUS | PRSC | Alt  | Ctrl |                                       |  L1  | Meta | Menu | Ins  |  OS  |
	 *   `----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,-------------.
	 *                                        | Del  |      |       |      | Tab  |
	 *                                 ,------|------|------|       |------+--------+------.
	 *                                 |      |      |      |       |      |        |      |
	 *                                 | Shift| Bksp |------|       |------| Enter  |Space |
	 *                                 |      |      | End  |       | Home |        |      |
	 *                                 `--------------------'       `----------------------'
	 */
	[_COLEMAK] = LAYOUT_ergodox(  // layer 0 : default
		// left hand
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    _T_SYM,
		KC_LBRC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
		KC_RBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _HYPER,
		KC_PRSC, KC_PAUS, KC_LGUI, KC_LALT, _C_DEL, 
													 KC_DEL,  _______,
		                                                      _______,
											_S_BSPC, KC_BSPC, KC_END,
		// right hand
		_C_A_D,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
		_T_SYM,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL, 
		         KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, 
		_MEH,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
		                  _L_NAV,  _______, KC_APP,  KC_INS,  KC_RGUI,
		_______, KC_TAB,
		_______,
		KC_HOME, KC_ENT,  _L_SYM
    ),
	/* Keymap 1: Symbol Layer
	 *
	 * ,---------------------------------------------------.           ,--------------------------------------------------.
	 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
	 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
	 * |         |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   =    |
	 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |         |   !  |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |   "    |
	 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |         |   ~  |   `  |   -  |   +  |   _  |      |           |      |   {  |   }  |   <  |   >  |   ?  |   |    |
	 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |       |      |      |      |      |                                       |      |      |      |      |      |
	 *   `-----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,-------------.
	 *                                        |      |      |       |      |      |
	 *                                 ,------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 |      |      |------|       |------|      |      |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 `--------------------'       `--------------------'
	 */
	// SYMBOLS
	[_SYMBOL] = LAYOUT_ergodox(
		// left hand
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,
		KC_DOT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,
		KC_LBRC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
		KC_RBRC, KC_TILD, KC_GRV,  KC_MINS, KC_PLUS, KC_UNDS, _______,
		_______, _______, _______, _______, _______,
													 _______, _______,
		                                                      _______,
											_ADJBSP, _______, _______,
		// right hand
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		_______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, 
		         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO, 
		_______, KC_LCBR, KC_RCBR, KC_LABK, KC_RABK, KC_QUES, KC_PIPE, 
		                  _______, _______, _______, _______, _______,
		_______, _______,
		_______,
		_______, _______, _______
    ),
	/* Keymap 2: Movement keys
	 *
	 * ,--------------------------------------------------.           ,--------------------------------------------------.
	 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * | KClear |      |      | Kill | Yank | Pup  |------|           |------|WLeft | Left | Down |  Up  |Right | WRight |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        | Undo | Cut  | Copy |Paste | Pdn  |      |           |      |      | Home | Pgdn | Pgup | End  |        |
	 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |      |      |      |      |      |                                       |      |      |      |      |      |
	 *   `----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,-------------.
	 *                                        |      |      |       |      |      |
	 *                                 ,------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 |      |      |------|       |------|      |      |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 `--------------------'       `--------------------'
	 */
	// Navigation layer
	[_NAVIGATION] = LAYOUT_ergodox(
		// left hand
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,
		KC_INS,  _S_TAB,  _SC_TAB, _C_TAB,  KC_TAB,  _C_UP,
		_______, UNDO,    CUT,     COPY,    PASTE,   _C_DOWN, _______,
		_______, _______, _______, _______, _______,
													 _______, _______,
		                                                      _______,
											_______, _______, _______,
		// right hand
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, 
		         _C_LEFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _C_RGHT, 
		_______, _G_TAB,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, 
		                  _______, _______, _______, _______, _______,
		_______, _______,
		_______,
		_______, _______, _______
    ),
		/* Keymap 3: Adjust
	 *
	 * ,--------------------------------------------------.           ,--------------------------------------------------.
	 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
	 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	 * |        |      |      |      |      |M1Strt|      |           |      |M2Strt|      |      |      |      |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      |      |      |M1Play|------|           |------|M2Play|      |      |      |      |        |
	 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	 * |        |      |      |      |      |MStop |      |           |      |MStop |      |      |      |      |        |
	 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	 *   |      |      |      |      | CAE  |                                       | CAD  |      |      |      |      |
	 *   `----------------------------------'                                       `----------------------------------'
	 *                                        ,-------------.       ,-------------.
	 *                                        |      |      |       |      |      |
	 *                                 ,------|------|------|       |------+------+------.
	 *                                 |      |      |      |       |      |      |      |
	 *                                 |      |      |------|       |------|      |      |
	 *                                 |      |      |      |       |      |      |      |
	 *                                 `--------------------'       `--------------------'
	 */
	// Adjust layer
	[_ADJUST] = LAYOUT_ergodox(
		// left hand
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_STA1, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_PLA1,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _D_STOP, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _C_S_E,
													 XXXXXXX, XXXXXXX,
		                                                      XXXXXXX,
											_______, XXXXXXX, XXXXXXX,
		// right hand
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, _D_STA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		         _D_PLA2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		XXXXXXX, _D_STOP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
		                  _C_A_D,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX,
		XXXXXXX,
		XXXXXXX, XXXXXXX, _______
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_SYMBOL)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
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
		case EPRM:
		  if (record->event.pressed) {
			eeconfig_init();
		  }
		  return false;
		  break;
		  
		case VRSN:
		  if (record->event.pressed) {
			SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		  }
		  return false;
		  break;
		  
		case RGB_SLD:
		  if (record->event.pressed) {
			#ifdef RGBLIGHT_ENABLE
			  rgblight_mode(1);
			#endif
		  }
		  return false;
		  break;

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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
