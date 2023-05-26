/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// For STT_CUSTOM_GRADIENT
HSV stt_gradient_0 = {205, 250, 255};
HSV stt_gradient_100 = {140, 215, 125};
bool stt_reflected_gradient = false;
uint8_t stt_gp_i = 0;

typedef struct {
    HSV gradient_0;
    HSV gradient_1;
    bool reflected;
} STT_CUSTOM_PRESETS;

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = USER00,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    STT_G0_HUI,                 //Custom gradient color 1 hue increase
    STT_G0_HUD,                 //Custom gradient color 1 hue decrease
    STT_G0_SAI,                 //Custom gradient color 1 saturation increase
    STT_G0_SAD,                 //Custom gradient color 1 saturation decrease
    STT_G0_VAI,                 //Custom gradient color 1 value increase
    STT_G0_VAD,                 //Custom gradient color 1 value decrease
    STT_G100_HUI,               //Custom gradient color 2 hue increase
    STT_G100_HUD,               //Custom gradient color 2 hue decrease
    STT_G100_SAI,               //Custom gradient color 2 saturation increase
    STT_G100_SAD,               //Custom gradient color 2 saturation decrease
    STT_G100_VAI,               //Custom gradient color 2 value increase
    STT_G100_VAD,               //Custom gradient color 2 value decrease
    STT_GRADIENT_PRESETS,       //Gradient presets
    STT_REFLECTED_GRADIENT,     //Toggle between linear and reflected gradient
    STT_GRADIENT_FLIP,          //Flip the gradient colors
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
                                                                                                                                                            KC_VOLD, KC_VOLU,
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_all(
                                                                                                                                                            RGB_VAD, RGB_VAI,
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,            RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_all(
                                                                                                                                                            KC_VOLD, KC_VOLU,
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_all(
                                                                                                                                                            RGB_VAD, RGB_VAI,
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  STT_GRADIENT_PRESETS,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
};

// clang-format on

#if defined(VIA_ENABLE) && defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]    = {{ 8, 5 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 7, 5 }};

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void matrix_scan_user(void) {
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t color_adj_step = 5;
    STT_CUSTOM_PRESETS stt_gradient_presets[] = {
        {{205, 250, 255}, {140, 215, 125}, false },
        {{41, 255, 255}, {233, 245, 255}, false },
        {{45, 245, 155}, {160, 255, 80}, false },
        {{173, 245, 40}, {41, 255, 205}, true },
        {{32, 255, 165}, {217, 185, 70}, false },
        {{240, 255, 145}, {115, 255, 245}, true },
        {{118, 255, 255}, {242, 255, 255}, false },
        {{118, 255, 255}, {242, 255, 255}, false },
        {{212, 0, 0}, {223, 235, 165}, true },
    };
    uint8_t stt_gp_length = sizeof(stt_gradient_presets)/sizeof(stt_gradient_presets[0]);

    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        case STT_G0_HUI:
            if (record->event.pressed) {
                stt_gradient_0.h += color_adj_step;
                dprintf("Gradient 0 HSV: %d, %d, %d\n", stt_gradient_0.h, stt_gradient_0.s, stt_gradient_0.v);
            }
            return false;
        case STT_G0_HUD:
            if (record->event.pressed) {
                stt_gradient_0.h -= color_adj_step;
                dprintf("Gradient 0 HSV: %d, %d, %d\n", stt_gradient_0.h, stt_gradient_0.s, stt_gradient_0.v);
            }
            return false;
        case STT_G0_SAI:
            if (record->event.pressed) {
                stt_gradient_0.s = (stt_gradient_0.s + color_adj_step * 2 <= 255) ? stt_gradient_0.s + color_adj_step * 2 : 255;
                dprintf("Gradient 0 HSV: %d, %d, %d\n", stt_gradient_0.h, stt_gradient_0.s, stt_gradient_0.v);
            }
            return false;
        case STT_G0_SAD:
            if (record->event.pressed) {
                stt_gradient_0.s = (stt_gradient_0.s - color_adj_step * 2 >= 0) ? stt_gradient_0.s - color_adj_step * 2 : 0;
                dprintf("Gradient 0 HSV: %d, %d, %d\n", stt_gradient_0.h, stt_gradient_0.s, stt_gradient_0.v);
            }
            return false;
        case STT_G0_VAI:
            if (record->event.pressed) {
                stt_gradient_0.v = (stt_gradient_0.v + color_adj_step * 2 <= 255) ? stt_gradient_0.v + color_adj_step * 2 : 255;
                dprintf("Gradient 0 HSV: %d, %d, %d\n", stt_gradient_0.h, stt_gradient_0.s, stt_gradient_0.v);
            }
            return false;
        case STT_G0_VAD:
            if (record->event.pressed) {
                stt_gradient_0.v = (stt_gradient_0.v - color_adj_step * 2 >= 0) ? stt_gradient_0.v - color_adj_step * 2 : 0;
                dprintf("Gradient 0 HSV: %d, %d, %d\n", stt_gradient_0.h, stt_gradient_0.s, stt_gradient_0.v);
            }
            return false;
        case STT_G100_HUI:
            if (record->event.pressed) {
                stt_gradient_100.h += color_adj_step;
                dprintf("Gradient 100 HSV: %d, %d, %d\n", stt_gradient_100.h, stt_gradient_100.s, stt_gradient_100.v);
            }
            return false;
        case STT_G100_HUD:
            if (record->event.pressed) {
                stt_gradient_100.h -= color_adj_step;
                dprintf("Gradient 100 HSV: %d, %d, %d\n", stt_gradient_100.h, stt_gradient_100.s, stt_gradient_100.v);
            }
            return false;
        case STT_G100_SAI:
            if (record->event.pressed) {
                stt_gradient_100.s = (stt_gradient_100.s + color_adj_step * 2 <= 255) ? stt_gradient_100.s + color_adj_step * 2 : 255;
                dprintf("Gradient 100 HSV: %d, %d, %d\n", stt_gradient_100.h, stt_gradient_100.s, stt_gradient_100.v);
            }
            return false;
        case STT_G100_SAD:
            if (record->event.pressed) {
                stt_gradient_100.s = (stt_gradient_100.s - color_adj_step * 2 >= 0) ? stt_gradient_100.s - color_adj_step * 2 : 0;
                dprintf("Gradient 100 HSV: %d, %d, %d\n", stt_gradient_100.h, stt_gradient_100.s, stt_gradient_100.v);
            }
            return false;
        case STT_G100_VAI:
            if (record->event.pressed) {
                stt_gradient_100.v = (stt_gradient_100.v + color_adj_step * 2 <= 255) ? stt_gradient_100.v + color_adj_step * 2 : 255;
                dprintf("Gradient 100 HSV: %d, %d, %d\n", stt_gradient_100.h, stt_gradient_100.s, stt_gradient_100.v);
            }
            return false;
        case STT_G100_VAD:
            if (record->event.pressed) {
                stt_gradient_100.v = (stt_gradient_100.v - color_adj_step * 2 >= 0) ? stt_gradient_100.v - color_adj_step * 2 : 0;
                dprintf("Gradient 100 HSV: %d, %d, %d\n", stt_gradient_100.h, stt_gradient_100.s, stt_gradient_100.v);
            }
            return false;
        case STT_GRADIENT_PRESETS:
            if (record->event.pressed) {
                stt_gp_i = (stt_gp_i + stt_gp_length ) % stt_gp_length;

                stt_gradient_0 = stt_gradient_presets[stt_gp_i].gradient_0;
                stt_gradient_100 = stt_gradient_presets[stt_gp_i].gradient_1;
                stt_reflected_gradient = stt_gradient_presets[stt_gp_i].reflected;

                stt_gp_i += 1;
            }
            return false;
        case STT_REFLECTED_GRADIENT:
            if (record->event.pressed) {
                stt_reflected_gradient = !stt_reflected_gradient;
            }
            return false;
        case STT_GRADIENT_FLIP:
            if (record->event.pressed) {
                HSV temp_color = stt_gradient_0;
                stt_gradient_0 = stt_gradient_100;
                stt_gradient_100 = temp_color;
            }
            return false;
        default:
            return true;   // Process all other keycodes normally
    }
}
