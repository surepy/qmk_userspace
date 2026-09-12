/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// part of jonavin's rgb_matrix_map.h, GPL - http://www.gnu.org/licenses/
enum led_location_map {
    LED_ESC,   // 0, ESC, k13
    LED_GRV,   // 1, ~, k16
    LEB_TAB,   // 2, Tab, k11
    LED_CAPS,  // 3, Caps, k21
    LED_LSFT,  // 4, Sh_L, k00
    LED_LCTL,  // 5, Ct_L, k06
    LED_F1,    // 6, F1, k26
    LED_1,     // 7, 1, k17
    LED_Q,     // 8, Q, k10
    LED_A,     // 9, A, k12
    LED_Z,     // 10, Z, k14
    LED_LWIN,  // 11, Win_L, k90
    LED_F2,    // 12, F2, k36
    LED_2,     // 13, 2, k27
    LED_W,     // 14, W, k20
    LED_S,     // 15, S, k22
    LED_X,     // 16, X, k24
    LED_LALT,  // 17, Alt_L, k93
    LED_F3,    // 18, F3, k31
    LED_3,     // 19, 3, k37
    LED_E,     // 20, E, k30
    LED_D,     // 21, D, k32
    LED_C,     // 22, C, k34
    LED_F4,    // 23, F4, k33
    LED_4,     // 24, 4, k47
    LED_R,     // 25, R, k40
    LED_F,     // 26, F, k42
    LED_V,     // 27, V, k44
    LED_F5,    // 28, F5, k07
    LED_5,     // 29, 5, k46
    LED_T,     // 30, T, k41
    LED_G,     // 31, G, k43
    LED_B,     // 32, B, k45
    LED_SPC,   // 33, SPACE, k94
    LED_F6,    // 34, F6, k63
    LED_6,     // 35, 6, k56
    LED_Y,     // 36, Y, k51
    LED_H,     // 37, H, k53
    LED_N,     // 38, N, k55
    LED_F7,    // 39, F7, k71
    LED_7,     // 40, 7, k57
    LED_U,     // 41, U, k50
    LED_J,     // 42, J, k52
    LED_M,     // 43, M, k54
    LED_F8,    // 44, F8, k76
    LED_8,     // 45, 8, k67
    LED_I,     // 46, I, k60
    LED_K,     // 47, K, k62
    LED_COMM,  // 48, ,, k64
    LED_RALT,  // 49, Alt_R, k95
    LED_F9,    // 50, F9, ka6
    LED_9,     // 51, 9, k77
    LED_O,     // 52, O, k70
    LED_L,     // 53, L, k72
    LED_DOT,   // 54, ., k74
    LED_FN,    // 55, FN, k92
    LED_F10,   // 56, F10, ka7
    LED_0,     // 57, 0, k87
    LED_P,     // 58, P, k80
    LED_SCLN,  // 59, ;, k82
    LED_SLSH,  // 60, ?, k85
    LED_F11,   // 61, F11, ka3
    LED_MINS,  // 62, -, k86
    LED_LBRC,  // 63, [, k81
    LED_QUOT,  // 64, ", k83
    LED_RCTL,  // 65, Ct_R, k04
    LED_F12,   // 66, F12, ka5
    LED_L1,    // 67, LED, l01
    LED_R1,    // 68, LED, l11
    LED_INS,   // 69, Prt, k97  -- remapped to INS
    LED_L2,    // 70, LED, l02
    LED_R2,    // 71, LED, l12
    LED_DEL,   // 72, Del, k65
    LED_L3,    // 73, LED, l03
    LED_R3,    // 74, LED, l13
    LED_PGUP,  // 75, PgUp, k15
    LED_L4,    // 76, LED, l04
    LED_R4,    // 77, LED, l14
    LED_EQL,   // 78, =, k66
    LED_RIGHT, // 79, Right, k05
    LED_L5,    // 80, LED, l05
    LED_R5,    // 81, LED, l15
    LED_END,   // 82, End, k75
    LED_L6,    // 83, LED, l06
    LED_R6,    // 84, LED, l16
    LED_BSPC,  // 85, BSpc, ka1
    LED_PGDN,  // 86, PgDn, k25
    LED_L7,    // 87, LED, l07
    LED_R7,    // 88, LED, l17
    LED_RBRC,  // 89, ], k61
    LED_RSFT,  // 90, Sh_R, k91
    LED_L8,    // 91, LED, l08
    LED_R8,    // 92, LED, l18
    LED_BSLS,  // 93, \, ka2
    LED_UP,    // 94, Up, k35
    LED_LEFT,  // 95, Left, k03
    LED_ENT,   // 96, Enter, ka4
    LED_DOWN   // 97, Down, k73
};

enum custom_keycodes { FN_BHOP = QK_USER, FN_NUL_A, FN_NUL_D };

#define LAYER_BASE 0
#define LAYER_BHOP 1
#define LAYER_AUTOTAPSTRAFE 2
#define LAYER_NULLMOVE 3
#define LAYER_DISABLE_WINKEY 4
#define LAYER_FN_1 5

#define TG_TSRF TG(LAYER_AUTOTAPSTRAFE)
#define TG_BHOP TG(LAYER_BHOP)
#define TG_DISW TG(LAYER_DISABLE_WINKEY)
#define TG_NVMT TG(LAYER_NULLMOVE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       Insert
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [LAYER_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_INS,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(LAYER_FN_1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [LAYER_BHOP] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            FN_BHOP,                            _______, _______, _______, _______, _______, _______
    ),

    [LAYER_AUTOTAPSTRAFE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [LAYER_NULLMOVE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,FN_NUL_A, _______,FN_NUL_D, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),


    [LAYER_DISABLE_WINKEY] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,

        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, XXXXXXX, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

	[LAYER_FN_1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,  KC_F23,  KC_F24, _______,          _______,

        _______, RM_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_F13,
        _______, _______, RM_VALU, _______, _______, TG_TSRF, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          KC_F14,
        _______, _______, RM_VALD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, RM_HUEU, _______, _______, TG_BHOP, _______, TG_NVMT, _______, _______, _______,          _______, RM_NEXT, _______,
        _______, TG_DISW, _______,                            _______,                            _______, _______, _______, RM_SPDD, RM_PREV, RM_SPDU
    )

};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]           = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_BHOP]           = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_AUTOTAPSTRAFE]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_NULLMOVE]       = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_DISABLE_WINKEY] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [LAYER_FN_1]           = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
// clang-format on
#endif

#ifndef TAP_STRAFE_INTERVAL_MS
#    define TAP_STRAFE_INTERVAL_MS 20
#endif

#ifndef TAP_STRAFE_INTERVAL_VARIANCE_MS
#    define TAP_STRAFE_INTERVAL_VARIANCE_MS 0
#endif

#ifndef TAP_STRAFE_PRESS_MS
#    define TAP_STRAFE_PRESS_MS 10
#endif

#if TAP_STRAFE_INTERVAL_MS <= (TAP_STRAFE_PRESS_MS + TAP_STRAFE_INTERVAL_VARIANCE_MS)
#    error "The minimum tap-strafe interval must be longer than TAP_STRAFE_PRESS_MS"
#endif

static bool a_held             = false;
static bool d_held             = false;
static bool physical_w_held    = false;
static bool left_shift_held    = false;
static bool injected_w_pressed = false;

static uint16_t tap_strafe_timer          = 0;
static uint16_t tap_strafe_interval       = TAP_STRAFE_INTERVAL_MS;
static uint16_t tap_strafe_random_state   = 0xA361;

static uint16_t next_tap_strafe_interval(void) {
#if TAP_STRAFE_INTERVAL_VARIANCE_MS > 0
    // Mix human key timing into a small xorshift generator. This is timing
    // variance, not cryptographic randomness.
    tap_strafe_random_state ^= timer_read();
    tap_strafe_random_state ^= tap_strafe_random_state << 7;
    tap_strafe_random_state ^= tap_strafe_random_state >> 9;
    tap_strafe_random_state ^= tap_strafe_random_state << 8;

    const uint16_t range = (TAP_STRAFE_INTERVAL_VARIANCE_MS * 2) + 1;
    return TAP_STRAFE_INTERVAL_MS - TAP_STRAFE_INTERVAL_VARIANCE_MS +
           (tap_strafe_random_state % range);
#else
    return TAP_STRAFE_INTERVAL_MS;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool was_strafing = a_held || d_held;

    switch (keycode) {
        case FN_NUL_A:
            if (record->event.pressed) {
                register_code(KC_A);
                if (d_held) {
                    unregister_code(KC_D);
                }
            } else {
                unregister_code(KC_A);
                if (d_held) {
                    register_code(KC_D);
                }
            }
            // Fall through to update the physical A state.
        case KC_A:
            a_held = record->event.pressed;
            break;

        case FN_NUL_D:
            if (record->event.pressed) {
                register_code(KC_D);
                if (a_held) {
                    unregister_code(KC_A);
                }
            } else {
                unregister_code(KC_D);
                if (a_held) {
                    register_code(KC_A);
                }
            }
            // Fall through to update the physical D state.
        case KC_D:
            d_held = record->event.pressed;
            break;

        case KC_W:
            physical_w_held = record->event.pressed;

            if (physical_w_held && injected_w_pressed) {
                // W is already present in the report. Transfer ownership to
                // the physical key without unregistering it.
                injected_w_pressed = false;
            }

            tap_strafe_timer    = timer_read();
            tap_strafe_interval = next_tap_strafe_interval();
            break;

        // Experimental: Disable tap-strafe while Shift is held for long-range fights.
        case KC_LSFT:
            left_shift_held     = record->event.pressed;
            tap_strafe_timer    = timer_read();
            tap_strafe_interval = next_tap_strafe_interval();
            break;
    }

    // Make the first injected W happen on the next matrix scan.
    if (!was_strafing && (a_held || d_held)) {
        tap_strafe_interval = next_tap_strafe_interval();
        tap_strafe_timer    = timer_read() - tap_strafe_interval;
    }

    return true;
}

void matrix_scan_user(void) {
    const bool should_tap_strafe = layer_state_is(LAYER_AUTOTAPSTRAFE) &&
                                   (a_held || d_held) && !left_shift_held;

    if (!should_tap_strafe || physical_w_held) {
        if (injected_w_pressed) {
            // Never unregister W when the physical key owns it.
            if (!physical_w_held) {
                unregister_code(KC_W);
            }
            injected_w_pressed = false;
        }
        return;
    }

    const uint16_t elapsed = timer_elapsed(tap_strafe_timer);

    if (injected_w_pressed) {
        if (elapsed >= TAP_STRAFE_PRESS_MS) {
            unregister_code(KC_W);
            injected_w_pressed = false;
        }
    } else if (elapsed >= tap_strafe_interval) {
        tap_strafe_interval = next_tap_strafe_interval();
        tap_strafe_timer    = timer_read();
        register_code(KC_W);
        injected_w_pressed = true;
    }
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPS, RGB_RED);
    }

    // overlay: fn key hints
    if (layer_state_is(LAYER_FN_1)) {
        // clear the rgb
        rgb_matrix_set_color_all(0, 0, 0);

        rgb_matrix_set_color(LED_LEFT, RGB_BLUE);
        rgb_matrix_set_color(LED_RIGHT, RGB_BLUE);
        rgb_matrix_set_color(LED_UP, RGB_BLUE);
        rgb_matrix_set_color(LED_DOWN, RGB_BLUE);

        // rgb brightness ig
        rgb_matrix_set_color(LED_W, RGB_BLUE);
        rgb_matrix_set_color(LED_S, RGB_BLUE);

        // on/off
        rgb_matrix_set_color(LED_1, RGB_RED);

        // reset
        rgb_matrix_set_color(LED_BSLS, RGB_RED);

        // f-keys
        // 1 KC_MYCM,  2 KC_WHOM, 3 KC_CALC, 4 KC_MSEL, 6 KC_MPRV, 7 KC_MPLY, 8 KC_MNXT,
        rgb_matrix_set_color(LED_F1, RGB_BLUE);
        rgb_matrix_set_color(LED_F2, RGB_BLUE);
        rgb_matrix_set_color(LED_F3, RGB_BLUE);
        rgb_matrix_set_color(LED_F4, RGB_BLUE);

        rgb_matrix_set_color(LED_F6, RGB_GREEN);
        rgb_matrix_set_color(LED_F7, RGB_RED);
        rgb_matrix_set_color(LED_F8, RGB_YELLOW);

        // discord-mute.
        rgb_matrix_set_color(LED_DEL, RGB_YELLOW);
        // discord-deafen
        rgb_matrix_set_color(LED_PGUP, RGB_RED);
        
        rgb_matrix_set_color(LED_F12, RGB_RED);
        
        rgb_matrix_set_color(LED_F11, RGB_BLUE);

        if (layer_state_cmp(layer_state, LAYER_BHOP)) {
            rgb_matrix_set_color(LED_B, RGB_RED);
        } else {
            rgb_matrix_set_color(LED_B, RGB_BLUE);
        }

        if (layer_state_cmp(layer_state, LAYER_NULLMOVE)) {
            rgb_matrix_set_color(LED_M, RGB_RED);
        } else {
            rgb_matrix_set_color(LED_M, RGB_BLUE);
        }

        if (layer_state_cmp(layer_state, LAYER_AUTOTAPSTRAFE)) {
            rgb_matrix_set_color(LED_T, RGB_RED);
        } else {
            rgb_matrix_set_color(LED_T, RGB_BLUE);
        }

        if (layer_state_cmp(layer_state, LAYER_DISABLE_WINKEY)) {
            rgb_matrix_set_color(LED_LWIN, RGB_RED);
        } else {
            rgb_matrix_set_color(LED_LWIN, RGB_BLUE);
        }

    }
    return false;
}
#endif // RGB_MATRIX_ENABLE

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
#endif
}
