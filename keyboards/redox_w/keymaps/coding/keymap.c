#include QMK_KEYBOARD_H
//
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
// _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
// _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
// _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
// _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
// _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ ,)
//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */
#define _QWERTY 0
#define _SYMB 1
#define _I3WM 2
#define _ADJUST 3

# define KC_WMTAB LT(2,KC_TAB)
# define KC_WMEQL LT(2,KC_EQL)
# define KC_AQUOT RALT_T(KC_QUOT)
# define KC_CTDWM LCA_T(KC_PGDN)
# define KC_L3UP LT(3,KC_PGDN)
# define KC_L3END LT(3,KC_END)
# define KC_CTHOM LCA_T(KC_HOME)
# define KC_CTLZ RCTL(KC_Z)
# define KC_CTLX RCTL(KC_X)
# define KC_CTLC RCTL(KC_C)
# define KC_CTLV RCTL(KC_V)
# define GUIESC RGUI(KC_ESC)
# define SGUI1 SGUI(KC_1)
# define SGUI2 SGUI(KC_2)
# define SGUI3 SGUI(KC_3)
# define SGUI4 SGUI(KC_4)
# define SGUI5 SGUI(KC_5)
# define SGUI6 SGUI(KC_6)
# define SGUI7 SGUI(KC_7)
# define SGUI8 SGUI(KC_8)
# define SGUI9 SGUI(KC_9)
# define SGUI0 SGUI(KC_0)
# define SGUIS SGUI(KC_S)
# define SGUIQ SGUI(KC_Q)
# define SGUIC SGUI(KC_C)
# define SGUIN SGUI(KC_N)
# define SGUIZ SGUI(KC_Z)
# define SGUIENT SGUI(KC_ENT)
# define SGUISPC SGUI(KC_SPC)
# define SGUISLSH SGUI(KC_SLSH)
# define RGUI1 RGUI(KC_1)
# define RGUI2 RGUI(KC_2)
# define RGUI3 RGUI(KC_3)
# define RGUI4 RGUI(KC_4)
# define RGUI5 RGUI(KC_5)
# define RGUI6 RGUI(KC_6)
# define RGUI7 RGUI(KC_7)
# define RGUI8 RGUI(KC_8)
# define RGUI9 RGUI(KC_9)
# define RGUI0 RGUI(KC_0)
# define RGUIC RGUI(KC_C)
# define RGUID RGUI(KC_D)
# define RGUIW RGUI(KC_W)
# define RGUIB RGUI(KC_B)
# define RGUII RGUI(KC_I)
# define RGUILEFT RGUI(KC_LEFT)
# define RGUIRIGHT RGUI(KC_RIGHT)
# define RGUIUP RGUI(KC_UP)
# define RGUIDOWN RGUI(KC_DOWN)
# define RGUIN RGUI(KC_N)
# define RGUIR RGUI(KC_R)
# define RGUIT RGUI(KC_T)
# define RGUISPC RGUI(KC_SPC)
# define RGUIENT RGUI(KC_ENT)
# define RGUIBSPC RGUI(KC_BSPC)
# define PREVWKS HYPR(KC_LEFT)
# define NEXTWKS HYPR(KC_RIGHT)

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    ESC_L, // Our custom tap dance key; add any other tap dance keys to this enum
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_LPRN ,                          KC_RPRN ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_AQUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_RALT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,        ,        ,                ,        ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RALT ,
//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
           ,        ,        ,        ,    MO(_SYMB),    KC_SFT  ,        ,                ,KC_SFT  ,   MO(_SYMB),     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT),
//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	[_SYMB] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_LPRN ,                          KC_RPRN ,KC_PMNS ,KC_UNDS ,KC_LT   ,KC_GT   ,KC_QUES ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_LCBR ,                          KC_RCBR ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_PIPE  ,KC_COMM ,KC_DQUO,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,KC_PSLS ,KC_BSLS ,_______ ,_______ ,KC_DOT  ,_______ ,
//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,     _______ ,    KC_BSPC ,KC_DEL  ,        KC_ENT , KC_SPC  ,    _______ ,     _______ ,_______ ,_______ ,_______),
//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
	[_I3WM] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
   GUIESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,RGUI(KC_S),
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,SGUI1   ,SGUI2,   SGUI3   ,SGUI4   ,SGUI5   ,KC_LPRN ,                          KC_RPRN ,SGUI6   ,SGUI7   ,SGUI8   ,SGUI9   ,SGUI0   , _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   TD(ESC_L),RGUI1 ,RGUI2   ,RGUI3   ,RGUI4   ,RGUI5   ,PREVWKS ,                          NEXTWKS ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSFT, RGUIC   ,RGUID   ,RGUIW   ,RGUIB   ,RGUII   ,SGUIZ   ,SGUIN   ,        RGUIN   ,RGUIR   ,RGUILEFT,RGUIDOWN,RGUIUP  ,RGUIRIGHT,SGUISLSH,KC_RSFT ,
//├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
   XXXXXXX ,XXXXXXX ,SGUIC   ,SGUIQ   ,     RGUIT   ,    SGUISPC ,RGUISPC ,        RGUIENT ,SGUIENT ,    RGUIBSPC,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX )
//└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
};


// Fix receivers led colors
#undef red_led_off
#undef red_led_on
#undef blu_led_off
#undef blu_led_on
#undef grn_led_off
#undef grn_led_on

#define yel_led_off   PORTF |= (1<<5)
#define yel_led_on    PORTF &= ~(1<<5)
#define red_led_off   PORTF |= (1<<4)
#define red_led_on    PORTF &= ~(1<<4)
#define blu_led_off   PORTD |= (1<<1)
#define blu_led_on    PORTD &= ~(1<<1)

#undef set_led_off
#undef set_led_red
#undef set_led_blue
#undef set_led_green
#undef set_led_yellow
#undef set_led_magenta
#undef set_led_cyan
#undef set_led_white

#define set_led_off     red_led_off; yel_led_off; blu_led_off
#define set_led_yellow  red_led_off; yel_led_on;  blu_led_off
#define set_led_red     red_led_on;  yel_led_off; blu_led_off
#define set_led_blue    red_led_off; yel_led_off; blu_led_on

//to be fixed yet
#define set_led_green   red_led_off; yel_led_on;  blu_led_off
#define set_led_magenta red_led_on;  yel_led_off; blu_led_on
#define set_led_cyan    red_led_off; yel_led_on;  blu_led_on
#define set_led_white   red_led_on;  yel_led_on;  blu_led_on

// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_I3WM);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_I3WM)) {
                // If already set, then switch it off
                layer_off(_I3WM);
            } else {
                // If not already set, then switch the layer on
                layer_on(_I3WM);
            }
            break;
	case TD_UNKNOWN:
	    tap_code(KC_NO);
	    break;
	case TD_NONE:
	    tap_code(KC_NO);
	    break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_I3WM);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_L] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
	    set_led_off;
            break;
        case _SYMB:
	    set_led_yellow;
            break;
        case _I3WM:
	    set_led_red;
            break;
        case 3:
	    set_led_blue;
            break;
        default:
            break;
    }
  return state;
};
