# QMK Corne (CRKBD) Keymap

This contains a custom QMK keymap for the Corne keyboard v4.1 (CRKBD). The keymap is designed for a 3x6+3 split keyboard with additional keys and RGB underglow support.

## Features

- **6 Layers**: BASE, NUMS, MEDIA, SYSTEM (with bootloader access), and 2 additional customizable layers (for future use)
- **RGB Underglow**: Layer-based color indication with brightness preservation
- **Encoder Support**: 4 encoders with RGB control mappings
- **Media Keys**: Volume, mute, fast forward, rewind, and brightness controls
- **Arrow Keys**: Dedicated arrow key cluster on the base layer
- **Mouse Keys**: Basic mouse functionality support
- **NKRO**: N-Key Rollover support

## Layer Overview

### Layer 0 (BASE) - White RGB
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│ ESC │  Q  │  W  │  E  │  R  │  T  │ ←   │   │ ↑   │  Y  │  U  │  I  │  O  │  P  │BSPC │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │  A  │  S  │  D  │  F  │  G  │ →   │   │ ↓   │  H  │  J  │  K  │  L  │  ;  │  '  │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│SHIFT│  Z  │  X  │  C  │  V  │  B  │     │   │     │  N  │  M  │  ,  │  .  │  /  │TO(1)│
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │CTRL │ GUI │ SPC │     │   │     │ ENT │ GUI │ ALT │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

### Layer 1 (NUMS) - Orange RGB
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│  `  │  1  │  2  │  3  │  4  │  5  │     │   │     │  6  │  7  │  8  │  9  │  0  │BSPC │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│ TAB │     │     │     │     │     │     │   │     │     │     │     │  [  │  ]  │TO(0)│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│SHIFT│     │     │     │     │     │     │   │     │     │     │  -  │  =  │  \  │TO(2)│
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │CTRL │ GUI │ SPC │     │   │     │ ENT │ GUI │CTRL │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

### Layer 2 (MEDIA) - Red RGB
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │MUTE │FF   │   │BRI+ │RGB  │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │VOL+ │RW   │   │BRI- │RGB+ │     │     │     │     │TO(1)│
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│TO(3)│     │     │     │     │VOL- │     │   │     │RGB- │     │     │     │     │TO(0)│
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │     │     │   │     │     │     │     │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

### Layer 3 (SYSTEM) - Blue RGB
```
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │     │   │     │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │   │     │     │     │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │     │     │   │     │     │     │     │     │     │TO(0)│
└─────┴─────┴─────┼─────┼─────┼─────┤     │   │     ├─────┼─────┼─────┼─────┴─────┴─────┘
                  │     │     │BOOT │     │   │     │BOOT │     │     │
                  └─────┴─────┴─────┘     │   │     └─────┴─────┴─────┘
```

The SYSTEM layer is designed for system-level functions and bootloader access. It's intentionally isolated from normal typing layers to prevent accidental activation of critical functions.

**How to Access:**
- From BASE layer: `TO(1)` → NUMS → `TO(2)` → MEDIA → `TO(3)` → SYSTEM
- To return: Press `TO(0)` (bottom-right corner) to return directly to BASE layer

**Key Functions:**
- **`QK_BOOT`** (thumb keys): Puts the keyboard into bootloader mode for firmware flashing
- **`TO(0)`** (bottom-right): Returns to BASE layer
- **All other keys**: Disabled to prevent accidental inputs

**Usage Notes:**
- Use this layer when you need to flash new firmware or troubleshoot the keyboard
- The bootloader keys are positioned on both thumb keys for easy access
- Once in bootloader mode, you can flash firmware using QMK tools

### Layers 4-5 - Blue RGB
Currently undefined and available for customization.

## RGB Underglow

The keymap includes dynamic RGB underglow that changes color based on the active layer:

- **Layer 0 (BASE)**: White
- **Layer 1 (NUMS)**: Orange
- **Layer 2 (MEDIA)**: Red
- **Layer 3 (SYSTEM)**: Blue
- **Layers 4-5**: Blue

The RGB system preserves brightness levels when switching layers and automatically starts in solid white mode.

![Demo](demo.gif)

*The demo above shows the RGB underglow changing colors when switching between layers - from white (BASE) to orange (NUMS) to red (MEDIA), providing visual feedback for the current active layer.*

## Encoder Configuration

Four encoders are supported with RGB control mappings:
- **Encoder 1**: RGB Mode (forward/reverse)
- **Encoder 2**: RGB Hue (increase/decrease)
- **Encoder 3**: RGB Brightness (increase/decrease)
- **Encoder 4**: RGB Saturation (increase/decrease)

## Configuration

### Key Settings
- **Tapping Term**: 200ms
- **RGB Timeout**: 5 minutes
- **Encoder Resolution**: 4
- **Dynamic Layers**: 6

### Features Enabled
- RGB Underglow
- Encoder Map
- Extra Keys (Media/Consumer)
- Mouse Keys
- N-Key Rollover

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

- **Layers 4-5** are currently empty and ready for your custom layouts
- **RGB colors** can be modified in the `layer_state_set_user()` function
- **Encoder mappings** can be adjusted in the `encoder_map` array
- **Tapping terms** and other timing can be adjusted in `config.h`
- **Hammerspoon toast styling** can be modified in the `showToast()` and `showStatusToast()` functions

## Hammerspoon Integration

This project includes a Hammerspoon script (`.hammerspoon/init.lua`) that provides real-time layer monitoring and visual feedback on macOS:

### Features
- **Layer Change Notifications**: Displays toast notifications when switching between keyboard layers
- **Visual Feedback**: Color-coded toasts matching the RGB underglow colors:
  - BASE layer: Dark glass effect
  - NUMS layer: Orange glass effect  
  - MEDIA layer: Red glass effect
  - SYSTEM layer: Blue glass effect
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