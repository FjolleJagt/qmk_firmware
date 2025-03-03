#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
  OS_TOGGLE,
  KC_WLEFT, // One word to the right
  KC_WRIGHT, // One word to the left
  KC_LEND, // End
  KC_LSTART, // Home
  KC_UGRV, // Grave (Linux + MacOS)
  KC_UBS, // Backslack (Linux + MacOS)
  KC_ULGUI, // LGui
  KC_ULCTL, // LCtrl
};

enum os_mode {
   OS_LINUX,
   OS_MAC,
   OS_COUNT, // Used to implement toggling between OSes.
};

static enum os_mode current_os_mode = OS_LINUX;

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define NAV_L   MO(_NAV)
#define ADJ_L   MO(_ADJUST)

#define CT_LEFT LCTL(KC_LEFT)
#define CT_SHFT LCTL(KC_LSFT)
#define CT_RGHT LCTL(KC_RIGHT)
#define KC_NUPI LSFT(KC_NUBS)
#define TAB_LFT LCTL(LSFT(KC_TAB))
#define TAB_RGT LCTL(KC_TAB)
#define ALT_TAB LALT(KC_TAB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ADJ_L   ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_COLON,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_HYPR ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,QK_BOOT ,                          QK_BOOT ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MEH  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_NUPI ,                          KC_HASH ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_RCTL ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,XXXXXXX ,CT_SHFT ,        KC_HOME ,KC_ADEN ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RALT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_ULGUI,XXXXXXX ,KC_TAB  ,     KC_LSFT ,    KC_BSPC ,KC_ULCTL,        NAV_L   ,KC_SPC  ,     SYM_L  ,     KC_MINS ,KC_QUOT ,XXXXXXX ,KC_ENT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_UGRV ,_______ ,                          _______ ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,KC_AMPR ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_ASTR ,KC_PLUS ,KC_LBRC ,KC_RBRC ,KC_NUHS ,_______ ,                          _______ ,KC_CIRC ,KC_4    ,KC_5    ,KC_6    ,KC_EQL  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_MINUS,KC_LPRN ,KC_RPRN ,KC_UBS  ,_______ ,_______ ,        _______ ,_______ ,KC_DLR  ,KC_1    ,KC_2    ,KC_3    ,KC_X    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    KC_DEL  ,_______ ,        _______ ,_______ ,    XXXXXXX ,     KC_DOT  ,KC_0    ,KC_PENT ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,KC_LSTART,KC_LEND,TAB_LFT ,TAB_RGT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN1 ,KC_BTN2 ,        _______ ,ALT_TAB ,XXXXXXX ,KC_WLEFT,KC_PGDN ,KC_PGUP ,KC_WRIGHT,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_BOOT,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,RGB_SAI ,RGB_VAD ,RGB_VAI ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,OS_TOGGLE,XXXXXXX,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RGB_M_X ,RGB_M_T ,RGB_M_SW,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

// Toggles between OS modes
//
// Return value indicates whether to continue normal key processing.
bool toggle_os_mode(void) {
   current_os_mode = (current_os_mode + 1) % OS_COUNT;
   return false; // stop processing this keypress
}

// Process custom keycodes
//
// Return value indicates whether QMK should carry on processing the keypress.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case OS_TOGGLE:
         if (record->event.pressed) {
            return toggle_os_mode();
         }
         return false;
      case KC_WLEFT:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               tap_code16(C(KC_LEFT));  // Ctrl+Left for Linux
            } else if (current_os_mode == OS_MAC) {
               tap_code16(A(KC_LEFT));  // Alt+Left for MacOS
            }
         }
         return false;
      case KC_WRIGHT:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               tap_code16(C(KC_RIGHT));  // Ctrl+Right for Linux
            } else if (current_os_mode == OS_MAC) {
               tap_code16(A(KC_RIGHT));  // Alt+Right for MacOS
            }
         }
         return false;
      case KC_ULCTL:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               register_code(KC_LCTL);
            } else if(current_os_mode == OS_MAC) {
               register_code(KC_LCMD);
            }
         } else {
            if (current_os_mode == OS_LINUX) {
               unregister_code(KC_LCTL);
            } else if(current_os_mode == OS_MAC) {
               unregister_code(KC_LCMD);
            }
         }
         return false;
      case KC_ULGUI:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               register_code(KC_LGUI);
            } else if (current_os_mode == OS_MAC) {
               register_code(KC_LCTL);
            }
         } else {
            if (current_os_mode == OS_LINUX) {
               unregister_code(KC_LGUI);
            } else if (current_os_mode == OS_MAC) {
               unregister_code(KC_LCTL);
            }
         }
         return false;
      case KC_LSTART:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               tap_code16(KC_HOME);
            } else if (current_os_mode == OS_MAC) {
               tap_code16(LCMD(KC_LEFT));
            }
         }
         return false;
      case KC_LEND:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               tap_code16(KC_END);
            } else if (current_os_mode == OS_MAC) {
               tap_code16(LCMD(KC_RIGHT));
            }
         }
         return false;
      case KC_UGRV:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               tap_code16(KC_GRV);
            } else if (current_os_mode == OS_MAC) {
               tap_code16(KC_NUBS);
            }
         }
         return false;
      case KC_UBS:
         if (record->event.pressed) {
            if (current_os_mode == OS_LINUX) {
               tap_code16(KC_NUBS);
            } else if (current_os_mode == OS_MAC) {
               tap_code16(KC_GRV);
            }
         }
         return false;
   }
   return true;
}

/*
// Change LED colors depending on the layer.
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _SYMB:
            rgblight_enable();
            rgblight_setrgb_orange();
            break;
        case _NAV:
            rgblight_enable();
            rgblight_setrgb_springgreen();
            break;
        case _ADJUST:
            rgblight_enable();
            rgblight_setrgb_red();
            break;
        default:  //  for any other layers, or the default layer
            rgblight_disable();
            break;
    }
    return state;
};
*/
