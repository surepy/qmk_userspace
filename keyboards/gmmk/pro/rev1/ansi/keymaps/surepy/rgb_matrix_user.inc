// REQ: Transgender pride flag: light blue, pink, white, pink, light blue.
// The GMMK Pro's RGB coordinates use a vertical range of 0..64.
RGB_MATRIX_EFFECT(TRANS_FLAG)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool TRANS_FLAG(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    const uint8_t brightness = rgb_matrix_config.hsv.v;

    for (uint8_t i = led_min; i < led_max; i++) {
        const uint8_t y = g_led_config.point[i].y;
        rgb_t           color;

        if (y < 13 || y >= 52) {
            color = (rgb_t){0x5B, 0xCE, 0xFA}; // Light blue
        } else if (y < 26 || y >= 39) {
            color = (rgb_t){0xF5, 0xA9, 0xB8}; // Pink
        } else {
            color = (rgb_t){0xFF, 0xFF, 0xFF}; // White
        }

        rgb_matrix_set_color(
            i,
            scale8(color.r, brightness),
            scale8(color.g, brightness),
            scale8(color.b, brightness)
        );
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
