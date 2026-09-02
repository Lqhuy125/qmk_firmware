#include "media_control.h"
#include QMK_KEYBOARD_H

static bool muted = false;
static uint8_t volume_level = 50; // 0..100

void volume_up_5(void)
{
    if (volume_level < 100) {
        volume_level += 5;
    }

    tap_code(KC_VOLU);
}

void volume_down_5(void)
{
    if (volume_level > 0) {
        volume_level -= 5;
    }

    tap_code(KC_VOLD);
}

void volume_mute_toggle(void)
{
    muted = !muted;
    tap_code(KC_MUTE);
}