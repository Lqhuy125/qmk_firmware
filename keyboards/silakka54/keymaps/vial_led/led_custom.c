#include "led_custom.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
    {
        {21,22,23,24,25,26},
        {20,19,18,17,16,15},
        {14,13,12,11,10, 9},
        { 8, 7, 6, 5, 4, 3},
        {NO_LED,NO_LED,NO_LED,0,1,2},

        {48,49,50,51,52,53},
        {47,46,45,44,43,42},
        {41,40,39,38,37,36},
        {35,34,33,32,31,30},
        {NO_LED,NO_LED,NO_LED,27,28,29}
    },

    {
        {  0,  0},{ 20,  0},{ 40,  0},{ 60,  0},{ 80,  0},{100,  0},
        {  0, 16},{ 20, 16},{ 40, 16},{ 60, 16},{ 80, 16},{100, 16},
        {  0, 32},{ 20, 32},{ 40, 32},{ 60, 32},{ 80, 32},{100, 32},
        {  0, 48},{ 20, 48},{ 40, 48},{ 60, 48},{ 80, 48},{100, 48},
        { 40, 64},{ 60, 64},{ 80, 64},

        {124,  0},{144,  0},{164,  0},{184,  0},{204,  0},{224,  0},
        {124, 16},{144, 16},{164, 16},{184, 16},{204, 16},{224, 16},
        {124, 32},{144, 32},{164, 32},{184, 32},{204, 32},{224, 32},
        {124, 48},{144, 48},{164, 48},{184, 48},{204, 48},{224, 48},
        {144, 64},{164, 64},{184, 64}
    },

    {
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT
    }
};

static uint16_t rainbow_hue = 0;

void led_init_user(void)
{
    rgb_matrix_enable();
}

bool rgb_matrix_indicators_user(void)
{
    for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {

        HSV hsv = {
            .h = (rainbow_hue / 256 +
                 (i * 255 / RGB_MATRIX_LED_COUNT)) & 0xFF,
            .s = 255,
            .v = rgb_matrix_get_val()
        };

        RGB rgb = hsv_to_rgb(hsv);

        rgb_matrix_set_color(i,
                             rgb.r,
                             rgb.g,
                             rgb.b);
    }

    return false;
}

void housekeeping_task_user(void)
{
    static uint32_t timer = 0;

    if (timer_elapsed32(timer) > 30) {
        timer = timer_read32();
        rainbow_hue += 256;
    }
}

#endif