#include "planck.h"
#include "action_layer.h"

// make planck/rev4:cflee:dfu

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _GAME1,
  _GAME1_LOWER,
  _ADJUST
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,   // start assigning numbers to custom keycodes safely
  RAISE,
  T_GAME1,
  GAME1_L
};

// 1Password shortcuts
#define CMD_1P LGUI(KC_BSLASH)
#define CMD_1PO LGUI(LALT(KC_BSLASH))
// macOS screenshot shortcuts
#define C_SS LGUI(LSFT(KC_3))
#define C_SSA LGUI(LSFT(KC_4))
#define C_SSC LGUI(LCTL(LSFT(KC_3)))
#define C_SSAC LGUI(LCTL(LSFT(KC_4)))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
 * Modifiers, without OS swaps and with AG_NORM (MAGIC_UNSWAP_ALT_GUI)
 *   Cmd = GUI (Winkey)
 *   Opt = Alt
 *
 * Esc is GRAVE_ESC
 *   GUI-Esc is Cmd-`
 *   Shift-Esc is Shift-`, aka ~
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {_______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},



/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,    _______,    KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |Pg Dn |Pg Up |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Game 1 (Stardew Valley)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   W  |   E  |      |   1  |   2  |   3  |   4  |      |  F4  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   5  |   6  |   7  |   8  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |   X  |   C  |   M  |   9  |   0  |   -  |   =  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |_LOWER|      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME1] = {
  {_______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3,    KC_4, _______,   KC_F4, _______},
  {_______, _______, _______, _______, _______,    KC_5,    KC_6,    KC_7,    KC_8, _______, _______, _______},
  {_______, _______, _______, _______,    KC_M,    KC_9,    KC_0, KC_MINS,  KC_EQL, _______, _______, _______},
  {_______, _______, _______, _______, _______, GAME1_L, _______, _______, _______, _______, _______, _______}
},

/* Game 1 (Stardew Valley) Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |      |      |      |      |      |      |      |
 * |------+-------------+------+------+------+------+------+------+------+------+------|
 * |      |   5  |   6  |   7  |   8  |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------|
 * |      |   9  |   0  |   -  |   =  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME1_LOWER] = {
  {_______,    KC_1,    KC_2,    KC_3,    KC_4, _______, _______, _______, _______, _______, _______, _______},
  {_______,    KC_5,    KC_6,    KC_7,    KC_8, _______, _______, _______, _______, _______, _______, _______},
  {_______,    KC_9,    KC_0, KC_MINS,  KC_EQL, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset| Debug|Aud on|Audoff|AGnorm|AGswap|GAME1 |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |    SS|   SSA| SS Cp|SSA Cp|      |      |Cmd-BS|CmdSBS|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, T_GAME1, _______, _______, _______, KC_DEL },
  {_______, C_SS,    C_SSA,   C_SSC,   C_SSAC,  _______, _______,  CMD_1P, CMD_1PO, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

#ifdef AUDIO_ENABLE
  float game1_song_on[][2] = SONG(Q__NOTE(_B5), Q__NOTE(_D6), Q__NOTE(_G6), Q__NOTE(_B6));
  float game1_song_off[][2] = SONG(Q__NOTE(_B6), Q__NOTE(_G6), Q__NOTE(_D6), Q__NOTE(_B5));
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case T_GAME1:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_GAME1)) {
          #ifdef AUDIO_ENABLE
            PLAY_SONG(game1_song_off);
          #endif
          layer_off(_GAME1);
        } else {
          #ifdef AUDIO_ENABLE
            PLAY_SONG(game1_song_on);
          #endif
          layer_on(_GAME1);
        }
      }
      return false;
      break;
    case GAME1_L:
      if (record->event.pressed) {
        layer_on(_GAME1_LOWER);
        update_tri_layer(_GAME1_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_GAME1_LOWER);
        update_tri_layer(_GAME1_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}