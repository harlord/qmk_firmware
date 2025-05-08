/* Copyright 2021 weteor
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


/*
 
 make beekeeb/3w6hs:default:flash
 
 qmk flash -kb beekeeb/3w6hs -km default
 
 make beekeeb/3w6hs:default
 
 
 qmk console
 qmk monitor
 qmk clean
 */

#include QMK_KEYBOARD_H
#include "layers.h"
#include "g/keymap_combo.h"

// homerrows
#define LHR_A LSFT_T(KC_A)
#define LHR_R LCTL_T(KC_R)
#define LHR_S LALT_T(KC_S)
#define LHR_T LGUI_T(KC_T)
#define LHR_G KC_G
#define RHR_M KC_M
#define RHR_N RGUI_T(KC_N)
#define RHR_E RALT_T(KC_E)
#define RHR_I RCTL_T(KC_I)
#define RHR_O RSFT_T(KC_O)

// raise symbols
#define LRA_PIPE LSFT_T(KC_PIPE)
#define LRA_LBRC LCTL_T(KC_LCBR)
#define LRA_RBRC LALT_T(KC_RCBR)
#define LRA_TILD LGUI_T(KC_A)
#define RRA_COLN RGUI_T(KC_COLN)
#define RRA_LT RALT_T(KC_LT)
#define RRA_GT RCTL_T(KC_GT)
#define RRA_QUES RSFT_T(KC_QUES)


#define RRAL_SLASH RALT_T(KC_SLASH)

#define RLO_UP KC_UP
#define RLO_8 KC_8

enum custom_keycodes {
    TILDE_A = SAFE_RANGE,
    TILDE_E,
    TILDE_I,
    TILDE_O,
    TILDE_U,
    TILDE_NN,
};

// all this shit is because I need keep acivatede the homerrow layer eve oanother mod is press and release meanwhile a mod is pressed
bool IS_PRESS_HR_LS_BK = false;
bool IS_PRESS_HR_LG_DE = false;
bool IS_PRESS_HR_LC_SP = false;
bool IS_PRESS_HR_LA_ES = false;

bool IS_TAP_HR_LS_BK = false;
bool IS_TAP_HR_LG_DE = false;
bool IS_TAP_HR_LC_SP = false;
bool IS_TAP_HR_LA_ES = false;

bool IS_TAP_TH_LOWER = false;
bool IS_TAP_TH_RAISE = false;

int pressCounter(void) {
    int c = 0;
    if (IS_PRESS_HR_LS_BK) {
        //uprintf("pressCounter: IS_PRESS_HR_LS_BK \n");
        c++;
    }
    if (IS_PRESS_HR_LG_DE) {
        //uprintf("pressCounter: IS_PRESS_HR_LG_DE \n");
        c++;
    }
    if (IS_PRESS_HR_LC_SP) {
        //uprintf("pressCounter: IS_PRESS_HR_LC_SP \n");
        c++;
    }
    if (IS_PRESS_HR_LA_ES) {
        //uprintf("pressCounter: IS_PRESS_HR_LA_ES \n");
        c++;
    }
    return c;
}

void handleHomerowLayer(bool pressedDown) {
    int count = pressCounter();
    if (count == 1 && pressedDown) {
        layer_on(_HOMEROW);
    } else if (count == 0 && !pressedDown) {
        layer_off(_HOMEROW);
    }
}

bool process_tap_hold(uint16_t keycode, keyrecord_t *record) {
    if (record->tap.count > 0) {
        if (record->event.pressed) {
            tap_code16(keycode);      // Send the keycode on tap
        }
        return false;
    }
    return true;  // Skip further processing
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uprintf("process_record_user Keycode: %d, Pressed: %d\n", keycode, record->event.pressed);
    switch (keycode) {
            ///
            ///TILDE BEGIN
            ///
            ///try to show the layer for tilde a on tap or press or hold or anyway.
        case KC_A:
            if (record->event.pressed) {
                uprintf("show _TILDESHIFTA: down \n");
                layer_on(_TILDESHIFTA);
            } else{
                layer_off(_TILDESHIFTA);
            }
            return true;
        case TILDE_A:
            if (record->event.pressed) {
                uprintf("TILDE_A from _TILDESHIFTA layer: down \n");
                tap_code16(KC_BSPC);
                tap_code16(A(KC_E));
                tap_code16(KC_A);
                layer_off(_TILDESHIFTA);
            }
            return false;
        case KC_E:
            if (record->event.pressed) {
                uprintf("show _TILDESHIFTE: down \n");
                layer_on(_TILDESHIFTE);
            }else{
                layer_off(_TILDESHIFTE);
            }
            return true;
        case TILDE_E:
            if (record->event.pressed) {
                uprintf("TILDE_E from _TILDESHIFTE layer: down \n");
                tap_code16(KC_BSPC);
                tap_code16(A(KC_E));
                tap_code16(KC_E);
                layer_off(_TILDESHIFTE);
            }
            return false;
        case KC_I:
            if (record->event.pressed) {
                uprintf("show _TILDESHIFTI: down \n");
                layer_on(_TILDESHIFTI);
            }else{
                layer_off(_TILDESHIFTI);
            }
            return true;
        case TILDE_I:
            if (record->event.pressed) {
                uprintf("TILDE_I from _TILDESHIFTI layer: down \n");
                tap_code16(KC_BSPC);
                tap_code16(A(KC_E));
                tap_code16(KC_I);
                layer_off(_TILDESHIFTI);
            }
            return false;
        case KC_O:
            if (record->event.pressed) {
                uprintf("show _TILDESHIFTO: down \n");
                layer_on(_TILDESHIFTO);
            }else{
                layer_off(_TILDESHIFTO);
            }
            return true;
        case TILDE_O:
            if (record->event.pressed) {
                uprintf("TILDE_O from _TILDESHIFTO layer: down \n");
                tap_code16(KC_BSPC);
                tap_code16(A(KC_E));
                tap_code16(KC_O);
                layer_off(_TILDESHIFTO);
            }
            return false;
        case KC_U:
            if (record->event.pressed) {
                uprintf("show _TILDESHIFTU: down \n");
                layer_on(_TILDESHIFTU);
            }else{
                layer_off(_TILDESHIFTU);
            }
            return true;
        case TILDE_U:
            if (record->event.pressed) {
                uprintf("TILDE_U from _TILDESHIFTU layer: down \n");
                tap_code16(KC_BSPC);
                tap_code16(A(KC_E));
                tap_code16(KC_U);
                layer_off(_TILDESHIFTU);
            }
            return false;
        case KC_N:
            if (record->event.pressed) {
                uprintf("show _TILDESHIFTENNE: down \n");
                layer_on(_TILDESHIFTENNE);
            }else{
                layer_off(_TILDESHIFTENNE);
            }
            return true;
        case TILDE_NN:
            if (record->event.pressed) {
                uprintf("TILDE_NN from _TILDESHIFTENNE layer: down \n");
                tap_code16(KC_BSPC);
                tap_code16(A(KC_N));
                tap_code16(KC_N);
                layer_off(_TILDESHIFTENNE);
            }
            return false;
            ///
            ///TILDE END
            ///
            
            
        case HR_LS_BK: // Custom keycode
            uprintf("HR_LS_BK HR_LS_BK first\n");
            if (record->tap.count == 0) {
                uprintf("HR_LS_BK record->tap.count == 0\n");        // On hold.
                if (record->event.pressed) {
                    uprintf("HR_LS_BK record->event.pressed\n"); // On press.
                    IS_PRESS_HR_LS_BK = true;
                    handleHomerowLayer(true);
                    register_mods(MOD_LSFT);
                } else { // On release.
                    uprintf("HR_LS_BK !IS_PRESS_HR_LS_BK else\n");
                    IS_PRESS_HR_LS_BK = false;
                    IS_TAP_HR_LS_BK = false;
                    handleHomerowLayer(false);
                    unregister_mods(MOD_LSFT);
                }
                uprintf("HR_LS_BK record->event.pressed else\n");
                return false;  // Skip default handling.
            } else if (record->tap.count > 0) { // Detect tap behavior
                if (record->event.pressed) {
                    uprintf("HR_LS_BK: Tap down (key pressed briefly)\n");
                    IS_TAP_HR_LS_BK = true;
                    // Handle tap down logic here (e.g., activate layer or perform action)
                } else {
                    uprintf("HR_LS_BK: Tap up (key released after tap)\n");
                    IS_TAP_HR_LS_BK = false;
                    // Handle tap up logic here (e.g., deactivate layer or finalize action)
                }
            }
            // On tap, continue default handling to act as KC_.
            return true;
            
        case HR_LG_DE: // Custom keycode
            uprintf("HR_LG_DE HR_LG_DE first\n");
            if (record->tap.count == 0) {
                uprintf("HR_LG_DE record->tap.count == 0\n");        // On hold.
                if (record->event.pressed) {
                    uprintf("HR_LG_DE record->event.pressed\n"); // On press.
                    IS_PRESS_HR_LG_DE = true;
                    handleHomerowLayer(true);
                    register_mods(MOD_LGUI);
                } else { // On release.
                    uprintf("HR_LG_DE !IS_PRESS_HR_LG_DE else\n");
                    IS_PRESS_HR_LG_DE = false;
                    IS_TAP_HR_LG_DE = false;
                    handleHomerowLayer(false);
                    unregister_mods(MOD_LGUI);
                }
                uprintf("HR_LG_DE record->event.pressed else\n");
                return false;  // Skip default handling.
            } else if (record->tap.count > 0) { // Detect tap behavior
                if (record->event.pressed) {
                    uprintf("HR_LG_DE: Tap down (key pressed briefly)\n");
                    IS_TAP_HR_LG_DE = true;
                    // Handle tap down logic here (e.g., activate layer or perform action)
                } else {
                    uprintf("HR_LG_DE: Tap up (key released after tap)\n");
                    IS_TAP_HR_LG_DE = false;
                    // Handle tap up logic here (e.g., deactivate layer or finalize action)
                }
            }
            // On tap, continue default handling to act as KC_.
            return true;
            
        case HR_LC_SP: // Custom keycode
            uprintf("HR_LC_SP HR_LC_SP first\n");
            if (record->tap.count == 0) {
                uprintf("HR_LC_SP record->tap.count == 0\n");        // On hold.
                if (record->event.pressed) {
                    uprintf("HR_LC_SP record->event.pressed\n"); // On press.
                    IS_PRESS_HR_LC_SP = true;
                    handleHomerowLayer(true);
                    register_mods(MOD_LCTL);
                } else { // On release.
                    uprintf("HR_LC_SP !IS_PRESS_HR_LC_SP else\n");
                    IS_PRESS_HR_LC_SP = false;
                    IS_TAP_HR_LC_SP = false;
                    handleHomerowLayer(false);
                    unregister_mods(MOD_LCTL);
                }
                uprintf("HR_LC_SP record->event.pressed else\n");
                return false;  // Skip default handling.
            } else if (record->tap.count > 0) { // Detect tap behavior
                if (record->event.pressed) {
                    uprintf("HR_LC_SP: Tap down (key pressed briefly)\n");
                    IS_TAP_HR_LC_SP = true;
                    // Handle tap down logic here (e.g., activate layer or perform action)
                } else {
                    uprintf("HR_LC_SP: Tap up (key released after tap)\n");
                    IS_TAP_HR_LC_SP = false;
                    // Handle tap up logic here (e.g., deactivate layer or finalize action)
                }
            }
            // On tap, continue default handling to act as KC_.
            return true;
            
        case HR_LA_ES: // Custom keycode
            uprintf("HR_LA_ES HR_LA_ES first\n");
            if (record->tap.count == 0) {
                uprintf("HR_LA_ES record->tap.count == 0\n");        // On hold.
                if (record->event.pressed) {
                    uprintf("HR_LA_ES record->event.pressed\n"); // On press.
                    IS_PRESS_HR_LA_ES = true;
                    handleHomerowLayer(true);
                    register_mods(MOD_LALT);
                } else { // On release.
                    uprintf("HR_LA_ES !IS_PRESS_HR_LA_ES else\n");
                    IS_PRESS_HR_LA_ES = false;
                    IS_TAP_HR_LA_ES = false;
                    handleHomerowLayer(false);
                    unregister_mods(MOD_LALT);
                }
                uprintf("HR_LA_ES record->event.pressed else\n");
                return false;  // Skip default handling.
            }
            
            else if (record->tap.count > 0) { // Detect tap behavior
                if (record->event.pressed) {
                    uprintf("HR_LA_ES: Tap down (activating _TILDE for one-shot)\n");
                    IS_TAP_HR_LA_ES = true;
                    ////layer_on(_TILDE); // Activate the _TILDE layer
                    // Handle tap down logic here (e.g., activate layer or perform action)
                } else {
                    uprintf("HR_LA_ES: Tap up (deactivating _TILDE one-shot)\n");
                    IS_TAP_HR_LA_ES = false;
                    // Handle tap up logic here (e.g., deactivate layer or finalize action)
                }
                return false; // Skip default handling, support custom handle for tap
            }
            
            // On tap, continue default handling to act as KC_.
            return false;
            
        case LRA_PIPE:
            return process_tap_hold(KC_PIPE, record);
        case LRA_LBRC:
            return process_tap_hold(KC_LCBR, record);
        case LRA_RBRC:
            return process_tap_hold(KC_RCBR, record);
        case LRA_TILD:
            return process_tap_hold(KC_TILD, record);
        case RRA_COLN:
            return process_tap_hold(KC_COLN, record);
        case RRA_LT:
            return process_tap_hold(KC_LT, record);
        case RRA_GT:
            return process_tap_hold(KC_GT, record);
        case RRA_QUES:
            return process_tap_hold(KC_QUES, record);
    }
    
    return true;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    
    if (IS_TAP_TH_RAISE || IS_TAP_TH_LOWER || IS_TAP_HR_LS_BK || IS_TAP_HR_LG_DE || IS_TAP_HR_LC_SP || IS_TAP_HR_LA_ES || pressCounter() > 0) {
        uprintf("combo_should_trigger IS_TAP_TH_RAISE:%d, IS_TAP_TH_LOWER:%d, IS_TAP_HR_LS_BK:%d, IS_TAP_HR_LG_DE:%d, IS_TAP_HR_LC_SP:%d, IS_TAP_HR_LA_ES:%d,  pressCounterz: %d \n",IS_TAP_TH_RAISE, IS_TAP_TH_LOWER, IS_TAP_HR_LS_BK, IS_TAP_HR_LG_DE, IS_TAP_HR_LC_SP, IS_TAP_HR_LA_ES, pressCounter());
        return true;
    } else {
        uprintf("combo_should_trigger not activated else \n");
    }
    switch (combo_index) {
        case HR_LS_BK:
        case HR_LC_SP:
        case TH_LOWER:
        case TH_RAISE:
            return true;
            
        case C_HR_AZ:
        case C_HR_RX:
        case C_HR_SC:
        case C_HR_TD:
        case C_HR_GV:
        case C_HR_MK:
        case C_HR_NH:
        case C_HR_ECOMM:
        case C_HR_IDOT:
        case C_HR_OSLSH:
            
            //numbers
        case C_HR_AQ:
        case C_HR_RW:
        case C_HR_SF:
        case C_HR_TP:
        case C_HR_GB:
        case C_HR_MJ:
        case C_HR_NL:
        case C_HR_EU:
        case C_HR_IY:
        case C_HR_OQUOT:
            
            //actions
        case C_HR_WF:
        case C_HR_FP:
        case C_HR_PB:
        case C_HR_XC:
        case C_HR_CD:
        case C_HR_DV:
            if (
                layer_state_cmp(layer_state | default_layer_state, _RAISE) ||
                layer_state_cmp(layer_state | default_layer_state, _LOWER) ||
                layer_state_cmp(layer_state | default_layer_state, _HOMEROW)||
                //layer_state_cmp(layer_state | default_layer_state, _TILDE) ||
                layer_state_cmp(layer_state | default_layer_state, _FUNC)
                ){
                    return true;
                }
            
            //navigations
        case C_HR_HCOMM:
        case C_HR_HE:
        case C_HR_EDOT:
        case C_HR_COMMDOT:
            if (
                layer_state_cmp(layer_state | default_layer_state, _LOWER) ||
                layer_state_cmp(layer_state | default_layer_state, _FUNC) ||
                layer_state_cmp(layer_state | default_layer_state, _NAVALPHA)
                ){
                    return true;
                }
    }
    return false;
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case C_HR_AZ:
        case C_HR_RX:
        case C_HR_SC:
        case C_HR_TD:
        case C_HR_GV:
        case C_HR_MK:
        case C_HR_NH:
        case C_HR_ECOMM:
        case C_HR_IDOT:
        case C_HR_OSLSH:
            
            //numbers
        case C_HR_AQ:
        case C_HR_RW:
        case C_HR_SF:
        case C_HR_TP:
        case C_HR_GB:
        case C_HR_MJ:
        case C_HR_NL:
        case C_HR_EU:
        case C_HR_IY:
        case C_HR_OQUOT:
            
        case C_HR_WF:
        case C_HR_FP:
        case C_HR_PB:
        case C_HR_XC:
        case C_HR_CD:
        case C_HR_DV:
            
        case HR_LS_BK:
        case HR_LC_SP:
        case TH_LOWER:
        case TH_RAISE:
            return 199;
            
        case C_HR_HCOMM:
        case C_HR_HE:
        case C_HR_EDOT:
        case C_HR_COMMDOT:
            return 100;
    }
    return 50;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_LS_BK:
            return 200;
        case HR_LG_DE:
            return 200;
        case HR_LC_SP:
            return 200;
        case HR_LA_ES:
            return 200;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_LS_BK:
            if (layer_state_cmp(layer_state | default_layer_state, _ALPHA_COLEMAK_DH)) {
                return 40;
            }
            break;
        case HR_LG_DE:
            if (layer_state_cmp(layer_state | default_layer_state, _ALPHA_COLEMAK_DH) ){
                return 40;
            }
            break;
        case HR_LC_SP:
            if (layer_state_cmp(layer_state | default_layer_state, _ALPHA_COLEMAK_DH)) {
                return 40;
            }
            break;
        case HR_LA_ES:
            if (layer_state_cmp(layer_state | default_layer_state, _ALPHA_COLEMAK_DH)) {
                return 40;
            }
            break;
        case KC_ESC:
            return 1;
        case TH_LOWER:
            if (layer_state_cmp(layer_state | default_layer_state, _ALPHA_COLEMAK_DH)) {
                return 40;
            }
            break;
        case TH_RAISE:
            if (layer_state_cmp(layer_state | default_layer_state, _ALPHA_COLEMAK_DH)) {
                return 40;
            }
            break;
        default:
            return 200;
            
    }
    return 200;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_LS_BK:
            // Immediately select the hold action when another key is pressed.
            return true;
        case HR_LG_DE:
            // Immediately select the hold action when another key is pressed.
            return true;
        case HR_LA_ES:
            // Immediately select the hold action when another key is pressed.
            return false;
        case HR_LC_SP:
            return false;
        case TH_LOWER:
        case TH_RAISE:
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_LC_SP:
            // Immediately select the hold action when another key is tapped.
            return true;
        case LT(_NAVALPHA, KC_SLSH):
            return true;
        case HR_LS_BK:
            return false;
        case HR_LG_DE:
            return false;
        case HR_LA_ES:
            return true;
        default:
            // Immediately select the hold action when another key is tapped.
            return false;
    }
}

//[_TILDE] = LAYOUT_split_3x5_3
//(
// LALT(KC_1), LALT(KC_W), LALT(KC_F), LALT(KC_P), LALT(KC_B),                  LALT(KC_J), LALT(KC_L), TILDE_U,       LALT(KC_Y),   LALT(KC_QUOT),
// TILDE_A,    LALT(KC_R), LALT(KC_S), LALT(KC_T), LALT(KC_G),                  LALT(KC_M), TILDE_NN,   TILDE_E,       TILDE_I,      TILDE_O,
// LALT(KC_Z), LALT(KC_X), LALT(KC_C), LALT(KC_D), LALT(KC_V),                  LALT(KC_K), LALT(KC_H), LALT(KC_COMM), LALT(KC_DOT), LSFT(LALT(KC_SLSH)),
//            LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), KC_ESC
// ),


//[_TILDE] = LAYOUT_split_3x5_3
//(
// LALT(KC_1),   KC_W,    KC_F,    KC_P, KC_B,                                          KC_J,    KC_L,     TILDE_U,    KC_Y,    KC_QUOT,
// TILDE_A,      KC_R,    KC_S,    KC_T, KC_G,                                          KC_M,    TILDE_NN, TILDE_E,    TILDE_I, TILDE_O,
// KC_Z,         KC_X,    KC_C,    KC_D, KC_V,                                          KC_K,    KC_H,     KC_COMM,    KC_DOT,  LSFT(LALT(KC_SLSH)),
//            LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), KC_ESC
// ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA_COLEMAK_DH] = LAYOUT_split_3x5_3
    (
     KC_Q,         KC_W,    KC_F,    KC_P, KC_B,                                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
     KC_A,         KC_R,    KC_S,    KC_T, KC_G,                                          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
     KC_Z,         KC_X,    KC_C,    KC_D, KC_V,                                          KC_K,    KC_H,    KC_COMM, KC_DOT,  MO(_NAVALPHA),
     HR_LG_DE, HR_LS_BK, TH_LOWER,                     TH_RAISE, HR_LC_SP, HR_LA_ES
     ),
    
    
    
    [_HOMEROW] = LAYOUT_split_3x5_3
    (
     KC_Q,        KC_W,   KC_F,   KC_P,   KC_B,                                                KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
     LHR_A,       LHR_R,  LHR_S,  LHR_T,  LHR_G,                                               RHR_M,   RHR_N,   RHR_E,   RHR_I,   RHR_O,
     KC_Z,        KC_X,   KC_C,   KC_D,   KC_V,                                                KC_K,    KC_H,    KC_COMM, KC_DOT,  LT(_NAVALPHA, KC_SLSH),
     LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), LALT_T(KC_ESC)
     ),
    
    [_ALPHA_QWERTY] = LAYOUT_split_3x5_3
    (
     KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,                                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
     KC_A,         KC_S,    KC_D,    KC_F,    KC_G,                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
     KC_Z,         KC_X,    KC_C,    KC_V,    KC_B,                                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
     LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), LALT_T(KC_ESC)
     ),
    
    [_NAVALPHA] = LAYOUT_split_3x5_3
    (
     KC_Q,        KC_W,   KC_F,   KC_P,   KC_B,                                                KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
     LHR_A,       LHR_R,  LHR_S,  LHR_T,  LHR_G,                                               RHR_M,   RHR_N,   RLO_UP,   RHR_I,   RHR_O,
     KC_Z,        KC_X,   KC_C,   KC_D,   KC_V,                                                KC_K,    KC_LEFT, KC_DOWN, KC_RGHT,  RRAL_SLASH,
     LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), LALT_T(KC_ESC)
     ),
    
    [_RAISE] = LAYOUT_split_3x5_3
    (
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                                            KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN,  KC_RPRN,
     LRA_PIPE, LRA_LBRC, LRA_RBRC, LRA_TILD, KC_UNDS,                                       KC_PPLS, RRA_COLN, RRA_LT,  RRA_GT,   RRA_QUES,
     KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV, KC_MINUS,                                           KC_EQL, KC_SCLN, KC_COMM, KC_DOT,   RRAL_SLASH,
     LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), LALT_T(KC_ESC)
     ),
    
    [_LOWER] = LAYOUT_split_3x5_3
    (
     KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                                              KC_6,     KC_7,    RLO_8,    KC_9,     KC_0,
     KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,KC_CAPS,                                           CW_TOGG,  KC_RGUI, RLO_UP,   KC_RCTL,  KC_RSFT,
     KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV, KC_MINUS,                                          KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT,  RRAL_SLASH,
     LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), LALT_T(KC_ESC)
     ),
    
    [_FUNC] = LAYOUT_split_3x5_3
    (
     KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,                                             KC_F6,    KC_F7,   KC_F8,    KC_F9,    KC_F10,
     KC_RSFT, KC_RCTL, KC_LALT, KC_LGUI,KC_F11,                                            KC_F12,   KC_RGUI, RLO_UP,   KC_RCTL,  KC_RSFT,
     KC_BSLS, KC_LBRC, KC_RBRC, KC_GRV, KC_MINUS,                                          KC_EQL, KC_LEFT, KC_DOWN,  KC_RGHT,  RRAL_SLASH,
     LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), LALT_T(KC_ESC)
     ),
    
    [_ADJUST] = LAYOUT_split_3x5_3
    (
     KC_NO, KC_NO, KC_NO, C(KC_MINUS),   C(S(KC_MINUS)),                            KC_KB_VOLUME_UP,   KC_MPRV, KC_MPLY, KC_MNXT,    KC_NO,
     KC_NO, KC_F2, KC_NO, S(A(KC_F12)),  S(A(KC_H)),                                KC_KB_VOLUME_DOWN, KC_RGUI, RLO_UP,  KC_RCTL,    KC_RSFT,
     KC_NO, KC_NO, KC_NO, S(A(KC_DOWN)), KC_NO,                                     KC_KB_MUTE,        C(KC_BRID), C(KC_BRIU), KC_BRID, KC_BRIU,
     LGUI_T(KC_DEL), LSFT_T(KC_BSPC), TH_LOWER,     TH_RAISE, LCTL_T(KC_SPC), LALT_T(KC_ESC)
     ),
    
    [_CFG] = LAYOUT_split_3x5_3
    (
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX,DF(_ALPHA_COLEMAK_DH), DF(_ALPHA_QWERTY),
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, _______, XXXXXXX,     TH_RAISE, _______, XXXXXXX
     ),
    
    [_TILDESHIFTA] = LAYOUT_split_3x5_3
    (
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS, TILDE_A, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
     ),
    
    [_TILDESHIFTE] = LAYOUT_split_3x5_3
    (
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS, TILDE_E, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
     ),
    
    [_TILDESHIFTI] = LAYOUT_split_3x5_3
    (
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS, TILDE_I, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
     ),
    
    [_TILDESHIFTO] = LAYOUT_split_3x5_3
    (
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS, TILDE_O, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
     ),
    
    [_TILDESHIFTU] = LAYOUT_split_3x5_3
    (
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS, TILDE_U, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
     ),
    
    [_TILDESHIFTENNE] = LAYOUT_split_3x5_3
    (
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,                                          KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,
     KC_TRNS, TILDE_NN, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
     ),
    
};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
}

// A variable to store the previous state of the matrix
static matrix_row_t previous_matrix[MATRIX_ROWS];

void matrix_scan_user(void) {
    // Example: Log every key currently pressed.
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        // Get the current state of the row
        matrix_row_t current_row = matrix_get_row(row);
        
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            // Check if the key state has changed
            bool was_pressed = previous_matrix[row] & (1 << col);
            bool is_pressed = current_row & (1 << col);
            
            if (!was_pressed && is_pressed) {
                // Key Pressed (Key Down Event)
                //uprintf("Key Down: row %d, col %d\n", row, col);
                //if (matrix_is_on(row, col)) {
                if (row == 7 && col == 1) { // thumbs - space
                    IS_TAP_HR_LC_SP = true;
                } else if (row == 7 && col == 2) { // thumbs - escape
                    IS_TAP_HR_LA_ES = true;
                } else if (row == 3 && col == 3) { // thumbs - bak space
                    //uprintf("Key Up IS_TAP_HR_LS_BK = true: row %d, col %d\n", row, col);
                    IS_TAP_HR_LS_BK = true;
                } else if (row == 3 && col == 2) { // thumbs - delete
                    IS_TAP_HR_LG_DE = true;
                } else if (row == 7 && col == 0) { // thumbs - lower
                    IS_TAP_TH_LOWER = true;
                } else if (row == 3 && col == 4) { // thumbs - raise
                    IS_TAP_TH_RAISE = true;
                }
                
                // uprintf("Key pressed at row: %d, col: %d\n", row, col);
                //}
            }
            
            if (was_pressed && !is_pressed) {
                // Key Released (Key Up Event)
                //uprintf("Key Up: row %d, col %d\n", row, col);
                //if (matrix_is_on(row, col)) {
                if (row == 7 && col == 1) { // thumbs - space
                    IS_TAP_HR_LC_SP = false;
                } else if (row == 7 && col == 2) { // thumbs - escape
                    IS_TAP_HR_LA_ES = false;
                } else if (row == 3 && col == 3) { // thumbs - bak space
                    //uprintf("Key Up IS_TAP_HR_LS_BK = false: row %d, col %d\n", row, col);
                    IS_TAP_HR_LS_BK = false;
                } else if (row == 3 && col == 2) { // thumbs - delete
                    IS_TAP_HR_LG_DE = false;
                } else if (row == 7 && col == 0) { // thumbs - lower
                    IS_TAP_TH_LOWER = false;
                } else if (row == 3 && col == 4) { // thumbs - raise
                    IS_TAP_TH_RAISE = false;
                }
                
                // uprintf("Key pressed at row: %d, col: %d\n", row, col);
                //}
            }
        }
        
        // Update the previous row state
        previous_matrix[row] = current_row;
    }
}
