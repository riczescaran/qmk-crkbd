#include QMK_KEYBOARD_H

enum layer_names {
    _BASE = 0,
    _NUMS,
    _MEDIA,
    _LAYER3,
    _LAYER4,
    _LAYER5
};

// Force white RGB on startup
void keyboard_post_init_user(void) {
    rgblight_enable();                    // Enable RGB
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);  // Set to solid color mode
    rgblight_sethsv(0, 0, 200);          // Set to white (H:0, S:0, V:200)
}

// Change RGB color based on layer while preserving brightness
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_val = rgblight_get_val();  // Get current brightness

    switch (get_highest_layer(state)) {
        case _BASE:
            rgblight_sethsv(0, 0, current_val);      // White - preserve brightness
            break;
        case _NUMS:
            rgblight_sethsv(15, 255, current_val);   // Orange - preserve brightness
            break;
        case _MEDIA:
            rgblight_sethsv(0, 255, current_val);    // Red - preserve brightness
            break;
        case _LAYER3:
        case _LAYER4:
        case _LAYER5:
            rgblight_sethsv(170, 255, current_val);  // Blue - preserve brightness
            break;
    }
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_ex2(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LEFT,     KC_UP,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_RGHT,     KC_DOWN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TO(1),
                                            KC_LCTL, KC_LGUI, KC_SPC,      KC_ENT,  KC_RGUI, KC_RALT
    ),

    [_NUMS] = LAYOUT_split_3x6_3_ex2(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,       KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_EQL,  TO(2),
                                            KC_LCTL, KC_LGUI, KC_SPC,      KC_ENT,  KC_RGUI, KC_RCTL
    ),

    [_MEDIA] = LAYOUT_split_3x6_3_ex2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MUTE, KC_MFFD,     KC_BRIU, RGB_TOG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLU, KC_MRWD,     KC_BRID, RGB_VAI, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLD,                       RGB_VAD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(0),
                                            KC_NO,   KC_NO,   QK_BOOT,     QK_BOOT, KC_NO,   KC_NO
    ),

    [_LAYER3] = LAYOUT_split_3x6_3_ex2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO
    ),

    [_LAYER4] = LAYOUT_split_3x6_3_ex2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO
    ),

    [_LAYER5] = LAYOUT_split_3x6_3_ex2(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_NUMS]   = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_MEDIA]  = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_LAYER3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD) },
    [_LAYER4] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },
    [_LAYER5] = { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) }
};
#endif
