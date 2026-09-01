#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    RGB_BRI_DEC = SAFE_RANGE,
    RGB_BRI_INC,
    RGB_SPD_DEC,
    RGB_SPD_INC,
    RGB_TOGGLE
};

/* Macro to save cfg brightness led eeprom */
#define RGB_CFG_ENABLE      0x80
#define RGB_CFG_LEVEL_MASK  0x07

void led_init_user(void);

void rainbow_speed_up(void);

void rainbow_speed_down(void);

void rainbow_brightness_up(void);

void rainbow_brightness_down(void);

bool led_process_record_user(
    uint16_t keycode,
    keyrecord_t *record
);