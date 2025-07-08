#pragma once

// RGB Underglow settings
#define RGBLIGHT_TIMEOUT 300000      // 5 minutes timeout
#define RGBLIGHT_SLEEP              // Turn off when sleeping

// RGB Underglow step values
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Enable solid color AND rainbow swirl for ripple effect
#define RGBLIGHT_EFFECT_STATIC_LIGHT
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

// Force RGB to start in solid mode
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT

// Encoder settings
#define ENCODER_RESOLUTION 4

// Layer count
#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// Tapping term
#define TAPPING_TERM 200

// Mouse key settings
#define MOUSEKEY_DELAY 5
#define MOUSEKEY_INTERVAL 10
#define MOUSEKEY_MOVE_DELTA 5
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_DELAY 10
#define MOUSEKEY_WHEEL_INTERVAL 80
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
