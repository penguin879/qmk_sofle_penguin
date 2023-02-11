#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _NUMBER,
    _GAME,
    _GAME2
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_NUMBER,
    KC_GAME
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, TO(0),           KC_RGUI, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        KC_EQL, KC_LGUI, KC_LCTL, KC_LALT, KC_LBRC, KC_SPC,     KC_ENT, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT
        ),

	[1] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                           KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5,                               KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12,
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_TRNS, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,        KC_TRNS, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, MO(0), KC_TRNS, KC_TRNS, KC_TRNS
        ),
	[2] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_PSLS, KC_PAST, KC_PMNS, KC_F10, KC_F11, KC_F12,
        KC_TAB, KC_NO, KC_Q, KC_W, KC_E, KC_R,                  KC_P7, KC_P8, KC_P9, KC_F7, KC_F8, KC_F9,
        KC_LSFT, KC_NO, KC_A, KC_S, KC_D, KC_F,                 KC_P4, KC_P5, KC_P6, KC_F4, KC_F5, KC_F6,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_G, KC_TRNS,         KC_NO, KC_P1, KC_P2, KC_P3, KC_F1, KC_F2, KC_F3,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS,             KC_TRNS, KC_NUM, KC_PPLS, KC_PMNS, KC_PEQL
        )//,
	// [3] = LAYOUT(
    //     KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_PSLS, KC_PAST, KC_PMNS, KC_F10, KC_F11, KC_F12,
    //     KC_TAB, KC_NO, KC_Q, KC_W, KC_E, KC_R,                  KC_P7, KC_P8, KC_P9, KC_F7, KC_F8, KC_F9,
    //     KC_LSFT, KC_NO, KC_A, KC_S, KC_D, KC_F,                 KC_P4, KC_P5, KC_P6, KC_F4, KC_F5, KC_F6,
    //     KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_G, KC_TRNS,         KC_NO, KC_P1, KC_P2, KC_P3, KC_F1, KC_F2, KC_F3,
    //     KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS,             KC_TRNS, KC_NUM, KC_PPLS, KC_PMNS, KC_PEQL
    //     )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("Pengu"), false);
    oled_write_ln_P(PSTR(""), false);
    // if (keymap_config.swap_lctl_lgui) {
    //     oled_write_ln_P(PSTR("MAC"), false);
    // } else {
    //     oled_write_ln_P(PSTR("WIN"), false);
    // }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrty"), false);
            break;
        case _NUMBER:
            oled_write_ln_P(PSTR("Numb"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwrty\n"), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR("Numb \n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game \n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("NUM"), led_usb_state.num_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif



// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _QWERTY, _NUMBER, _GAME);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                // set_single_persistent_default_layer(_QWERTY);
                // tap_code(TO(_QWERTY));
                layer_on(_QWERTY);
            }
            layer_off(_QWERTY);
            return false;
        case KC_NUMBER:
            if (record->event.pressed) {
                // set_single_persistent_default_layer(_NUMBER);
                // tap_code(TO(_NUMBER));
                layer_on(_NUMBER);
            }
            layer_off(_NUMBER);
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                // set_single_persistent_default_layer(_GAME);
                // tap_code(TO(_GAME));
                layer_on(_GAME);
            }
            layer_off(_GAME);
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE
#define DEBOUNCE_DELAY 5


uint8_t last_state = 0;
uint32_t last_debounce_time = 0;
uint8_t layer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {

    // uint8_t new_state = read_encoder();
    uint32_t current_time = timer_read();
    if (/*new_state != last_state || */(current_time - last_debounce_time) > DEBOUNCE_DELAY) {
        last_debounce_time = current_time;
        // last_state = new_state;
    // left
    if (index == 0) {
        if (clockwise) {
            // tap_code(KC_VOLU);
        // } else {
        //     tap_code(KC_VOLD);
        // }
            if (layer == _GAME * 3) {
                layer = _QWERTY;
                // layer = _GAME;
            } else {
                layer++;
            }
        } else {
            if (layer == _QWERTY){
                // layer = _QWERTY;
                layer = _GAME;
            } else {
                layer--;
            }
        }

        layer = layer % 3;
        layer_clear();
        layer_on(layer);


        // switch (layer) {
        //     case _QWERTY:
        //         tap_code16(KC_QWERTY);
        //     case _NUMBER:
        //         tap_code16(KC_NUMBER);
        //     case _GAME:
        //         tap_code16(KC_GAME);
        // }
        // tap_code(TO(layer));

    // right
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
    }
    return false;
}

#endif
