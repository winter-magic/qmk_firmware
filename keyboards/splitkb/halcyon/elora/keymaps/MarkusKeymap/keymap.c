// Copyright 2025 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"
#include "print.h"

#include "leader_key.h"


enum layers {
    _BASE = 0,
    _NAV,
	_MOUSE,
	_SYM,
	_NUM,
	_FUN
};


#define DE_UE KC_LBRC 
#define DE_AE KC_QUOT 
#define DE_OE KC_SCLN 

#define DE_PLUS KC_RBRC
#define DE_MINUS KC_SLSH
#define DE_MAL LSFT(KC_RBRC)
#define DE_EQUAL LSFT(KC_0)

#define DE_RKLAMMERL LSFT(KC_8) //R Runde Klammer L Links
#define DE_RKLAMMERR LSFT(KC_9)
#define DE_EKLAMMERL RALT(KC_8) //E Eckige
#define DE_EKLAMMERR RALT(KC_9)
#define DE_GKLAMMERR RALT(KC_0)	//G Geschweifte
#define DE_GKLAMMERL RALT(KC_7)

#define DE_KLEINER KC_NUBS	
#define DE_GROESSER LSFT(KC_NUBS)
#define DE_FSLASH LSFT(KC_7)
#define DE_BSLASH RALT(KC_MINS)

#define DE_UND LSFT(KC_6)
#define DE_ODER RALT(KC_NUBS)
//#define DE_EURO RALT(KC_E) schon definiert
#define DE_DOLLAR LSFT(KC_4)
#define DE_PROZENT LSFT(KC_5)

#define DE_AUSRUFEZ LSFT(KC_1)
#define DE_HASH KC_NUHS
//#define DE_AT RALT(KC_Q) schon definiert
#define DE_DHKOMMA LSFT(KC_2) //Doppelhochkomma
#define DE_SHKOMMA KC_EQL
#define DE_PARAGRAPH LSFT(KC_3)
#define DE_DRUCK KC_PSCR 

#define DE_CIRCLE LSFT(KC_GRV)
#define DE_CIRCUMFLEX KC_GRV
#define DE_TILDE RALT(KC_RBRC)

#define LAYERLOCK QK_LAYER_LOCK

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case DE_A ... DE_Z:
        case DE_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}



const uint16_t PROGMEM cut[] = {DE_Y, DE_X, COMBO_END};
const uint16_t PROGMEM copy[] = {DE_X, DE_C, COMBO_END};
const uint16_t PROGMEM paste[] = {DE_C, DE_V, COMBO_END};

combo_t key_combos[] = {
    COMBO(cut, LCTL(DE_X)),
    COMBO(copy, LCTL(DE_C)),
    COMBO(paste, LCTL(DE_V)),	
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R', 
		'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L', '*', '*', '*', '*', 'R', 'R', 'R', 'R', 'R', 'R', 
                       '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
    );
	

/*void keyboard_post_init_user(void){
	wait_ms(500);
}*/

enum {
    TD_TAB_ESC,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};

static bool pseudo_gui = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record){
	
	if (leader_sequence_active()) {
        return true;
    }
	switch (keycode) {
		case LGUI_T(DE_A):
			if( record-> event.pressed){
				if (record -> tap.count ==0){
					// Hold -> aktiviere Pseudo GUI
					pseudo_gui = true;
					return false; // NICHT automatisch echte GUI senden
				}
			}
			else {
				pseudo_gui = false;
			}
			break;
	
	if (pseudo_gui && record-> event.pressed){
		switch (keycode){
			case DE_L:
				// Win + L blockieren nur L senden
				tap_code(DE_L);
				return false;
			default: 
				//Alle anderen Shotcuts -> echt ausführen
				register_code(KC_LGUI);
				tap_code(keycode);
				unregister_code(KC_LGUI);
				return false;
		}
	}
			
	switch (keycode)
		case LT(_MOUSE,KC_BSPC):
		case LT(_NUM,KC_BSPC):
			if(record->event.pressed && record->tap.count){
				uint8_t mods = get_mods();
				uint8_t weak_mods = get_weak_mods();
				uint8_t osm = get_oneshot_mods();
				if ((mods | weak_mods |osm) & MOD_MASK_SHIFT){
					del_mods(MOD_MASK_SHIFT);
					del_weak_mods(MOD_MASK_SHIFT);
					del_oneshot_mods(MOD_MASK_SHIFT);
					tap_code(KC_DEL);
					if (mods & MOD_MASK_SHIFT){
						add_mods(MOD_MASK_SHIFT);
					}
					if (weak_mods & MOD_MASK_SHIFT){
						add_weak_mods(MOD_MASK_SHIFT);
					}
					if (osm & MOD_MASK_SHIFT){
						add_oneshot_mods(MOD_MASK_SHIFT);
					}
					return false;
				}
			}
			break;
				
	  }
	return true;  // Continue default handling.
}

bool leader_add_user(uint16_t keycode) {
    return my_leader_add_user(keycode);
}


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// /*
//  * BASE
//  *4
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */

    [_BASE] = LAYOUT(
     KC_ESC ,KC_1        , KC_2       ,KC_3        , KC_4             ,  KC_5           ,                                                      KC_6             ,   KC_7     ,KC_8        ,  KC_9      ,KC_0         , DE_SS ,
     KC_TAB ,DE_Q        ,DE_W        ,DE_E        , DE_R             ,  DE_T           ,                                                      DE_Z             ,   DE_U     ,DE_I        ,DE_O        ,DE_P         , DE_UE ,
     DB_TOGG,LGUI_T(DE_A),LALT_T(DE_S),LSFT_T(DE_D),LCTL_T(DE_F)      ,  DE_G           ,                                                      DE_H             ,RCTL_T(DE_J),RSFT_T(DE_K),LALT_T(DE_L),RGUI_T(DE_OE), DE_AE ,
     KC_LSFT,DE_Y        , DE_X       ,DE_C        , DE_V             ,  DE_B           , KC_DEL, DE_DRUCK      ,KC_INSERT, CW_TOGG         ,DE_N             ,DE_M        ,DE_COMM     ,DE_DOT      ,DE_MINS      ,KC_RSFT,
                                       RM_TOGG     ,LT(_MOUSE,KC_BSPC),LT(_NAV,KC_ENTER),QK_LEAD,TD(TD_TAB_ESC) , QK_REP  ,LT(_NUM, KC_BSPC),LT(_SYM,KC_SPACE),MO(_FUN)    ,RM_TOGG
    ),

    [_NAV] = LAYOUT(
      _______, _______, _______  , _______  , _______ , _______,                                       _______ , _______  , _______ , _______, _______, _______,
      _______, _______,_______   ,_______   ,_______  , _______,                                       KC_PGUP , KC_HOME  , KC_UP   , KC_END , _______, _______,
      _______, KC_LGUI, KC_LALT  , KC_LSFT  , KC_LCTL , _______,                                       KC_PGDN , KC_LEFT  , KC_DOWN , KC_RGHT, _______, _______,
      _______, _______, _______  ,_______   ,_______  , _______, _______,LAYERLOCK, LAYERLOCK,_______ ,_______ ,LCTL(DE_W), KC_BSPC , _______, _______, _______,
                                   _______  , _______ , _______, _______, _______ , _______  ,_______ ,_______ , _______  , _______
    ),
	
	[_MOUSE] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                       _______, MS_ACL0  , MS_ACL1  , MS_ACL2  , _______, _______,
      _______, _______, _______, _______, _______, _______,                                       MS_WHLU, MS_BTN1  , MS_UP    , MS_BTN2  , _______, _______,
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                                       MS_WHLD, MS_LEFT  , MS_DOWN  , MS_RGHT  , MS_BTN3, _______,
      _______, _______, _______, _______, _______, _______, _______,LAYERLOCK,LAYERLOCK, _______,_______ ,LCTL(DE_V),LCTL(DE_C),LCTL(DE_X), _______, _______,
                                 _______, _______, _______, _______, _______ , _______ , _______, _______, _______  , _______
    ),
	
	[_SYM] = LAYOUT(
      _______,_______    , _______  , _______    , _______    , _______  ,                                     _______      , _______    , _______    , _______  , _______     , _______,
      _______,DE_SHKOMMA ,DE_KLEINER,DE_GROESSER ,DE_MINUS    ,DE_ODER   ,                                     DE_CIRCUMFLEX,DE_GKLAMMERL,DE_GKLAMMERR, DE_DOLLAR, DE_EURO     , _______,
      _______,DE_AUSRUFEZ, DE_MAL   ,DE_FSLASH   ,DE_EQUAL    ,DE_UND    ,                                     DE_HASH      ,DE_RKLAMMERL,DE_RKLAMMERR, DE_BSLASH, DE_CIRCLE   , _______,
      _______,DE_TILDE   , DE_PLUS  ,DE_EKLAMMERL,DE_EKLAMMERR,DE_PROZENT, _______, _______, _______, _______, DE_AT        , DE_DHKOMMA , DE_COMM    , DE_DOT   , DE_PARAGRAPH, _______,
                                        _______  , _______    , _______  , _______, _______, _______, _______, _______      , _______    , _______
    ),

    [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______ ,_______ ,                                       _______, _______, _______, _______, _______ , _______,
      _______, _______, DE_7   , DE_8   , DE_9    ,_______ ,                                       _______, DE_PLUS,DE_MINUS, DE_MAL ,DE_FSLASH, _______,
      _______, DE_0   , DE_4   , DE_5   , DE_6    ,_______ ,                                       _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI , _______,
      _______, _______, DE_1   , DE_2   , DE_3    ,_______ , _______,LAYERLOCK,LAYERLOCK, _______,_______ , _______, _______, _______, _______ , _______,
                                 _______, _______ , _______, _______, _______ , _______ , _______, _______, _______, _______
    ),
	
	[_FUN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______ , _______,
      _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F12 ,                                       _______, _______, _______, _______, _______ , _______,
      _______, _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,                                       _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI , _______,
      _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F10 , _______,LAYERLOCK,LAYERLOCK, _______,_______ , _______, _______, _______, _______ , _______,
                                 _______, _______, _______, _______, _______ , _______ , _______, _______, _______, _______
    ),

};