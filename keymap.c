#include QMK_KEYBOARD_H

#define KX_LOCK LGUI(LCTL(KC_Q))
#define KX_SFCP TD(TD_LSFT_CAPS)

enum layer_names {
    _BASE = 0,
    _NUMS,
    _SYSTEM
};

enum {
    TD_LSFT_CAPS
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

// Force white RGB on startup
void keyboard_post_init_user(void) {
    rgblight_enable();                          // Enable RGB
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);  // Set to solid color mode
    rgblight_sethsv(0, 0, 51);                 // Set to white with brightness at 20%
}

// Change RGB color based on layer while preserving brightness
// Add console debug output for layer changes
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_val = rgblight_get_val();
    uint8_t layer = get_highest_layer(state);

    // Console output for debugging/HUD
    switch (layer) {
        case _BASE:
            rgblight_sethsv(0, 0, current_val);
            uprintf("LAYER:BASE\n");
            break;
        case _NUMS:
            rgblight_sethsv(15, 255, current_val);
            uprintf("LAYER:NUMS\n");
            break;
        case _SYSTEM:
            rgblight_sethsv(170, 255, current_val);
            uprintf("LAYER:SYSTEM\n");
            break;
    }
    return state;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
        KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,      KC_HOME,           KC_PGUP,   KC_Y,      KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,     KC_G,      KC_END,            KC_PGDN,   KC_H,      KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KX_SFCP,   KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                                    KC_N,      KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                                              KC_LCTL,  KC_LGUI,   KC_SPC,            KC_ENT,    MO(_NUMS), MO(_SYSTEM)
    ),

    [_NUMS] = LAYOUT_split_3x6_3_ex2(
        KC_NO,     KC_NO,   KC_UP,   KC_NO,   KC_NO,    KC_NO,      KC_NO,            KC_NO,   KC_7,      KC_8,    KC_9,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,    KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,    KC_NO,      KC_NO,            KC_NO,   KC_4,      KC_5,    KC_6,    KC_LBRC, KC_RBRC, KC_NO,
        KX_SFCP,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,                                 KC_1,      KC_2,    KC_3,    KC_GRV,  KC_BSLS, KC_NO,
                                              KC_LCTL,  QK_LLCK,    KC_SPC,           KC_ENT,  KC_NO,     KC_0
    ),

    [_SYSTEM] = LAYOUT_split_3x6_3_ex2(
        KC_NO,     KC_NO,   KC_VOLU, KC_NO,   RGB_TOG, KC_NO,      KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KX_LOCK, KC_NO,
        KC_NO,     KC_MRWD, KC_VOLD, KC_MFFD, RGB_VAI, KC_BRIU,    KC_NO,             KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_SLEP, KC_NO,
        KC_NO,     KC_NO,   KC_MUTE, KC_NO,   RGB_VAD, KC_BRID,                                KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                              KC_NO,   QK_LLCK,    KC_NO,             QK_BOOT, KC_NO,     KC_NO
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_NUMS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_SYSTEM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
