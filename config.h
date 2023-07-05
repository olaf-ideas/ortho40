// Copyright 2023 Olaf Surgut (@olaf-ideas)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define OLED_DISPLAY_128X32
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

#define RGB_DI_PIN GP12
#define RGBLED_NUM 48
#define WS2812_PIO_USE_PIO1

#define RGBLIGHT_LAYERS

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
