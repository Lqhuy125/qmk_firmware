#include "ProcessTask.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case RGB_BRI_DEC:
            rainbow_brightness_down();
            return false;

        case RGB_BRI_INC:
            rainbow_brightness_up();
            return false;

        case RGB_SPD_DEC:
            rainbow_speed_down();
            return false;

        case RGB_SPD_INC:
            rainbow_speed_up();
            return false;
        case RGB_TOGGLE:
            rgb_led_toggle();
            return false;
        
        case VOL_DOWN:
            volume_down_5();
            return false;

        case VOL_UP:
            volume_up_5();
            return false;

        case VOL_MUTE:
            volume_mute_toggle();
            return false;
    }

    return true;
}

void led_init_user(void)
{
    uint8_t cfg = eeconfig_read_user();

    rgb_apply_config(cfg);
}