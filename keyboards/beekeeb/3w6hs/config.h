// Copyright 2023 beekeeb
// Copyright 2021 weteor
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 10

#define MATRIX_ROWS_PER_SIDE (MATRIX_ROWS / 2)
#define MATRIX_COLS_PER_SIDE (MATRIX_COLS / 2)

#define MATRIX_ROW_PINS_L { GP7, GP8, GP9, GP10}
#define MATRIX_COL_PINS_L { GP11, GP12, GP13, GP14, GP15 }

#define MATRIX_ROW_PINS_R { P10, P11, P12, P05 }
#define MATRIX_COL_PINS_R { P06, P13, P14, P01, P00 }

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1

///
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define QUICK_TAP_TERM 200
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD // Allow early hold detection
#define PERMISSIVE_HOLD_PER_KEY
#define COMBO_SHOULD_TRIGGER

#define ENABLE_DEBUG
#define ENABLE_DEBUG_MATRIX
#define ENABLE_DEBUG_KEYPAD
#define COMBO_TERM 50
#define COMBO_TERM_PER_COMBO
#define COMBO_BUFFER_LENGTH 4
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_MUST_HOLD_MODS

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

