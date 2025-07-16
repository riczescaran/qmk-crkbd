# QMK Corne (CRKBD) Keymap

This contains a custom QMK keymap for the Corne keyboard v4.1 (CRKBD). The keymap is designed for a 3x6+3 split keyboard with additional keys and RGB underglow support.

## Features

- **4 Layers**: BASE, NUMS, MEDIA, SYSTEM (with bootloader access)
- **RGB Underglow**: Layer-based color indication with brightness preservation
- **4 Encoders**: RGB control mappings
- **Media Keys**: Volume, brightness, and playback controls
- **Arrow Keys**: Dedicated cluster on base layer
- **Mouse Keys** and **N-Key Rollover** support
- **Tap Dance**: Double-tap shift for caps lock functionality
- **Momentary Layer Access**: Hold-to-activate layer switching

## Layer Overview

**RGB Colors by Layer:**
- **Layer 0 (BASE)**: White
- **Layer 1 (NUMS)**: Orange  
- **Layer 2 (MEDIA)**: Red
- **Layer 3 (SYSTEM)**: Blue

### Layer 0 (BASE)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  Q  │  W  │  E  │  R  │  T  │ ←   │   │ ↑   │  Y  │  U  │  I  │  O  │  P  │BSPC │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  A  │  S  │  D  │  F  │  G  │ →   │   │ ↓   │  H  │  J  │  K  │  L  │  ;  │  '  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│SHIFT│  Z  │  X  │  C  │  V  │  B  │     │   │     │  N  │  M  │  ,  │  .  │  /  │MO(2)│
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │CTRL │ GUI │ SPC*│     │   │     │ ENT*│MO(1)│ ALT │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

### Layer 1 (NUMS)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │  1  │  2  │  3  │  4  │  5  │     │   │     │  6  │  7  │  8  │  9  │  0  │BSPC │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │     │     │     │     │     │     │   │     │     │     │     │  [  │  ]  │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│SHIFT│     │     │     │     │     │     │   │     │     │     │  -  │  =  │  \  │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │CTRL │ GUI │ SPC*│     │   │     │ ENT*│     │ ALT │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

### Layer 2 (MEDIA)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │MUTE │FF   │   │BRI+ │RGB  │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │VOL+ │RW   │   │BRI- │RGB+ │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │VOL- │     │   │     │RGB- │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │ SPC*│     │   │     │ ENT*│     │     │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

### Layer 3 (SYSTEM)
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│TO(0)│     │     │     │     │     │     │   │     │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │   │     │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │   │     │     │     │     │     │     │     │
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │BOOT │     │   │     │BOOT │     │     │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

**Access:** Press `Space + Enter` simultaneously from any layer to jump directly to SYSTEM.

**Layer Navigation:**
- **MO(1)**: Hold to momentarily access NUMS layer
- **MO(2)**: Hold to momentarily access MEDIA layer
- **SPC+ENT Combo**: Direct access to SYSTEM layer

**Key Functions:**
- **`QK_BOOT`** (thumb keys): Enter bootloader mode for firmware flashing
- **`TO(0)`** (top-left): Return to BASE layer


## RGB Underglow

Dynamic RGB underglow changes color based on the active layer. The system preserves brightness levels when switching layers and automatically starts in solid white mode.

![Demo Underglow](demo/underglow.gif)

*The demo above shows the RGB underglow changing colors when switching between layers - from white (BASE) to orange (NUMS) to red (MEDIA), providing visual feedback for the current active layer.*

## Encoder Configuration

Four encoders are supported with the following mappings:
- **Encoder 1**: Volume (down/up)
- **Encoder 2**: Media (previous/next)
- **Encoder 3**: RGB Brightness (down/up)
- **Encoder 4**: Arrow Keys (right/left)

## Configuration

- **Tapping Term**: 500ms
- **RGB Timeout**: 5 minutes
- **Encoder Resolution**: 4
- **Dynamic Layers**: 4
- **Key Combos**: Space + Enter → SYSTEM layer
- **Tap Dance**: Double-tap shift → Caps Lock

## Installation

1. Check QMK setup here: https://docs.qmk.fm/#/newbs_getting_started


2. Copy the keymap folder to your QMK keymaps directory.

3. Compile the keymap:
   ```bash
   qmk compile -kb crkbd -km your_keymap_name
   ```

4. Enter into bootloader mode. You can do this by holding the BOOT button at the back of the keyboard and inserting a USB cable into the USB port.

5. Flash to your keyboard:
   ```bash
   qmk flash -kb crkbd -km your_keymap_name
   ```

## Customization

The keymap is designed to be easily customizable:

- **RGB colors** can be modified in the `layer_state_set_user()` function
- **Encoder mappings** can be adjusted in the `encoder_map` array
- **Tapping terms** and other timing can be adjusted in `config.h`
- **Tap Dance actions** can be modified in the `tap_dance_actions` array
- **Layer switching** can be changed from momentary (MO) to toggle (TO) in the keymap

## Hammerspoon Integration

This project includes a Hammerspoon script (`.hammerspoon/init.lua`) that provides real-time layer monitoring and visual feedback on macOS:

![Hammerspoon Demo](demo/hammerspoon.gif)

*The demo above shows the Hammerspoon toast notifications appearing when switching keyboard layers, providing visual feedback on your screen that matches the RGB underglow colors.*

### Features
- **Layer Change Notifications**: Displays toast notifications when switching between keyboard layers
- **Visual Feedback**: Color-coded toasts matching the RGB underglow colors
- **QMK Console Monitoring**: Automatically monitors QMK console output for layer changes
- **Hotkey Testing**: Keyboard shortcuts for testing layer notifications

### Setup
1. Install [Hammerspoon](https://www.hammerspoon.org/)
2. Copy the `.hammerspoon/init.lua` file to your Hammerspoon config directory
3. Reload Hammerspoon configuration
4. The script will automatically start monitoring when Hammerspoon loads

### Hotkeys
- `Cmd+Alt+Ctrl+T`: Test toast notification
- `Cmd+Alt+Ctrl+1-4`: Simulate layer changes (BASE, NUMS, MEDIA, SYSTEM)
- `Cmd+Alt+Ctrl+R`: Restart QMK console monitoring
- `Cmd+Alt+Ctrl+S`: Stop QMK console monitoring