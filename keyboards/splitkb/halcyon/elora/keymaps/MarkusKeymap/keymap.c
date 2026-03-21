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
#define DE_SHKOMMA LSFT(KC_NUHS)
#define DE_PARAGRAPH LSFT(KC_3)
#define DE_DRUCK KC_PSCR 

#define DE_CIRCLE LSFT(KC_GRV)
#define DE_CIRCUMFLEX KC_GRV
#define DE_TILDE RALT(KC_RBRC)

#define LAYERLOCK QK_LAYER_LOCK


#define ALT_L LALT_T(DE_L)
#define NAV_ENTER LT(_NAV, KC_ENTER)

#define AUSRUFEZ_GUI  LT(0, KC_F13)   
#define MAL_ALT  LT(0, KC_F14)  
#define FSLASH_SFT  LT(0, KC_F15)   
#define EQUAL_CTL  LT(0, KC_F16)   
#define HASH_CTL LT(0, KC_F17)   
#define RKLAMMERL_SFT LT(0, KC_F18)
#define RKLAMMERR_ALT LT(0, KC_F19)
#define BSLASH_GUI LT(0, KC_F20)
   


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


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case LT(_SYM,KC_SPACE):
            return true;   // ← HIER aktivieren
		case LT(_NUM, KC_BSPC):
            return true;   // ← HIER aktivieren
		case LT(_NAV,KC_ENTER):
            return true;   // ← HIER aktivieren
		case LT(_MOUSE,KC_BSPC):
            return true;   // ← HIER aktivieren

        default:
            return false;  // ← überall sonst aus
    }
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    switch (keycode) {
        case LT(_SYM, KC_SPACE):
        case LT(_NUM, KC_BSPC):
        case LT(_NAV, KC_ENTER):
        case LT(_MOUSE, KC_BSPC):
            return 0;  // Flow Tap deaktiviert → Hold möglich
        default:
            return FLOW_TAP_TERM;  // Für Homerow-Mods normal aktiv
    }
}


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R', 
		'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R', 
        'L', 'L', 'L', 'L', 'L', 'L', '*', '*', '*', '*', 'R', 'R', 'R', 'R', 'R', 'R', 
                       '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'
    );
	
/*
enum {
    TD_TAB_ESC,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};
*/
enum {
    SOFT_GUI = SAFE_RANGE,
};

static bool process_sym_hrm(keyrecord_t *record, uint16_t tap_key, uint8_t mod_bit) {
    if (record->tap.count && record->event.pressed) {
        tap_code16(tap_key);
    } else if (!record->tap.count) {
        if (record->event.pressed) {
            register_mods(mod_bit);
        } else {
            unregister_mods(mod_bit);
        }
    }
    return false;
}

static bool soft_gui_active = false;
static uint8_t soft_gui_L_count = 0;

static bool alt_l_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	if (leader_sequence_active()) {
        return true;
    }

    // Soft-GUI wird durch den Mod-Tap aktiviert/deaktiviert
    if (keycode == SOFT_GUI) {
        if (record->event.pressed) {
            soft_gui_active = true;
            soft_gui_L_count = 0;  // wichtig: L-Zähler zurücksetzen
        } else {
            soft_gui_active = false;
        }
        return false;
    }

    // Wenn Soft-GUI aktiv:
    if (soft_gui_active) {

        // -------------------------
        // Sonderfall: Win+L blockieren
        // -------------------------
        if (keycode == KC_L && record->event.pressed) {

            soft_gui_L_count++;

            // Nur das *erste* L blockieren
            if (soft_gui_L_count == 1) {
                tap_code(KC_A);
                tap_code(KC_L);
                return false;
            }

            // Ab dem zweiten L → NICHT blockieren
            // einfach „L“ normal ausgeben
            // (keine GUI gedrückt)
            return true;
        }

        // -------------------------
        // Andere Soft-GUI-Kombinationen → echtes Win+Key
        // -------------------------
        if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(keycode);
        } else {
            unregister_code(keycode);
            unregister_code(KC_LGUI);
        }

        return false;
    }

   switch (keycode){
		case AUSRUFEZ_GUI:  return process_sym_hrm(record, DE_AUSRUFEZ, MOD_BIT(KC_LGUI));
		case MAL_ALT:  return process_sym_hrm(record, DE_MAL,      MOD_BIT(KC_LALT));
		case FSLASH_SFT:  return process_sym_hrm(record, DE_FSLASH,   MOD_BIT(KC_LSFT));
		case EQUAL_CTL:  return process_sym_hrm(record, DE_EQUAL,    MOD_BIT(KC_LCTL));
		case HASH_CTL: return process_sym_hrm(record, DE_HASH,     MOD_BIT(KC_RCTL));
		case RKLAMMERL_SFT: return process_sym_hrm(record, DE_RKLAMMERL,MOD_BIT(KC_RSFT));
		case RKLAMMERR_ALT: return process_sym_hrm(record, DE_RKLAMMERR,MOD_BIT(KC_LALT));
		case BSLASH_GUI: return process_sym_hrm(record, DE_BSLASH,   MOD_BIT(KC_RGUI));
		case LT(_MOUSE,KC_BSPC):
		case LT(_NUM,KC_BSPC):
			if(record->event.pressed && record->tap.count >0){
				uint8_t mods = get_mods();
				uint8_t weak_mods = get_weak_mods();
				uint8_t osm = get_oneshot_mods();
				if ((mods | weak_mods |osm) & MOD_MASK_SHIFT){
					del_mods(MOD_MASK_SHIFT);
					del_weak_mods(MOD_MASK_SHIFT);
					del_oneshot_mods(MOD_MASK_SHIFT);
					
					register_code16(KC_DEL);
                    unregister_code16(KC_DEL);
					
					set_mods(mods);
					set_weak_mods(weak_mods);
					set_oneshot_mods(osm);
					return false;	
				}
			}
			break;
		case ALT_L:
            if (record->event.pressed) {
                alt_l_held = true;
            } else {
                alt_l_held = false;
            }
            break;

        case NAV_ENTER:
            if (record->event.pressed && alt_l_held) {
                // Alt+Enter ausführen
                register_mods(MOD_LALT);
                tap_code(KC_ENTER);
                unregister_mods(MOD_LALT);

                return false; // normales Enter verhindern
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

    [_BASE] = LAYOUT(
     KC_ESC ,KC_1             , KC_2       ,KC_3        , KC_4             ,  KC_5   ,                                             KC_6             ,   KC_7     ,KC_8        ,  KC_9,KC_0         , DE_SS ,
     KC_TAB ,DE_Q             ,DE_W        ,DE_E        , DE_R             ,  DE_T   ,                                             DE_Z             ,   DE_U     ,DE_I        ,DE_O  ,DE_P         , DE_UE ,
     _______,MT(SOFT_GUI,DE_A),LALT_T(DE_S),LSFT_T(DE_D),LCTL_T(DE_F)      ,  DE_G   ,                                             DE_H             ,RCTL_T(DE_J),RSFT_T(DE_K),ALT_L ,RGUI_T(DE_OE), DE_AE ,
     KC_LSFT,DE_Y             , DE_X       ,DE_C        , DE_V             ,  DE_B   , KC_DEL,DE_DRUCK,KC_INSERT, _______         ,DE_N             ,DE_M        ,DE_COMM     ,DE_DOT,DE_MINS      ,KC_RSFT,
                                            RM_TOGG     ,LT(_MOUSE,KC_BSPC),NAV_ENTER,QK_LEAD,KC_TAB  , KC_ESC  ,LT(_NUM, KC_BSPC),LT(_SYM,KC_SPACE),MO(_FUN)    ,RM_TOGG
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
      _______, _______, _______, RM_NEXT, DT_UP  , _______,                                       MS_WHLU, MS_BTN1  , MS_UP    , MS_BTN2  , _______, _______,
      _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, DT_PRNT,                                       MS_WHLD, MS_LEFT  , MS_DOWN  , MS_RGHT  , MS_BTN3, _______,
      _______, _______, _______, RM_PREV, DT_DOWN, _______, _______,LAYERLOCK,LAYERLOCK, _______,_______ ,LCTL(DE_V),LCTL(DE_C),LCTL(DE_X), _______, _______,
                                 _______, _______, _______, _______, _______ , _______ , _______, _______, _______  , _______
    ),
	
	[_SYM] = LAYOUT(  
      _______,_______     , _______  , _______    , _______     , _______  ,                                 _______      , _______     , _______     , _______  , _______     , _______,
      _______,DE_SHKOMMA  ,DE_KLEINER,DE_GROESSER ,DE_MINUS     ,DE_ODER   ,                                 DE_CIRCUMFLEX,DE_GKLAMMERL ,DE_GKLAMMERR , DE_DOLLAR, DE_EURO     , _______,
      _______,AUSRUFEZ_GUI,MAL_ALT   ,FSLASH_SFT  ,EQUAL_CTL    ,DE_UND    ,                                 HASH_CTL     ,RKLAMMERL_SFT,RKLAMMERR_ALT,BSLASH_GUI,DE_CIRCLE    , _______,
      _______,DE_TILDE    ,DE_PLUS   ,DE_EKLAMMERL,DE_EKLAMMERR ,DE_PROZENT,_______,_______,_______,_______, DE_AT        , DE_DHKOMMA  , DE_COMM     , DE_DOT   , DE_PARAGRAPH, _______,
                                         _______  , _______     , _______  ,_______,_______,_______,_______, _______      , _______     , _______
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