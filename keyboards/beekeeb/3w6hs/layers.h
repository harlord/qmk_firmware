// layers.h
#ifndef LAYERS_H
#define LAYERS_H

// Define your layer enum here
enum layers {
    _ALPHA_COLEMAK_DH,
    _HOMEROW,
    _ALPHA_QWERTY,
    _NAVALPHA,
    _RAISE,
    _LOWER,
    _CFG,
    _FUNC,
    _ADJUST,
    _TILDESHIFTA,
    _TILDESHIFTE,
    _TILDESHIFTI,
    _TILDESHIFTO,
    _TILDESHIFTU,
    _TILDESHIFTENNE,
    _NUMBERS,
};

#endif // LAYERS_H

//thumbs mods
#define HR_LS_BK LSFT_T(KC_BSPC)
#define HR_LG_DE LGUI_T(KC_DEL)
#define HR_LC_SP LCTL_T(KC_SPC)
#define HR_LA_ES LALT_T(KC_ESC)

#define TH_LOWER LT(_LOWER, KC_TAB)
#define TH_RAISE LT(_RAISE, KC_ENT)
