#pragma once

// Higher than QMK's 5 ms default to better reject switch chatter. The eager
// per-key algorithm in rules.mk keeps key-down latency low.
// #define DEBOUNCE 8
// this would be deboune 8 if my keyboard isnt old
#define DEBOUNCE 15

// One synthetic W cycle starts every 17..23 ms. W remains pressed for 10 ms.
#define TAP_STRAFE_INTERVAL_MS 20
#define TAP_STRAFE_INTERVAL_VARIANCE_MS 3
#define TAP_STRAFE_PRESS_MS 10
