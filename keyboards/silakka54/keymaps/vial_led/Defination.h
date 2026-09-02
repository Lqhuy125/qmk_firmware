#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    /* LED */
    RGB_BRI_DEC = SAFE_RANGE,
    RGB_BRI_INC,
    RGB_SPD_DEC,
    RGB_SPD_INC,
    RGB_TOGGLE,

    /* MEDIA */
    VOL_MUTE,
    VOL_UP,
    VOL_DOWN
};