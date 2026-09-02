#pragma once

#include QMK_KEYBOARD_H
#include "Defination.h"
#include "media_control.h"
#include "led_custom.h"

bool led_process_record_user(
    uint16_t keycode,
    keyrecord_t *record
);

extern void led_init_user(void);

extern void rainbow_brightness_up(void);
extern void rainbow_brightness_down(void);
extern void rainbow_speed_up(void);
extern void rainbow_speed_down(void);
extern void rgb_led_toggle(void);
extern void rgb_apply_config(uint8_t cfg);

extern void volume_up_5(void);
extern void volume_down_5(void);
extern void volume_mute_toggle(void);