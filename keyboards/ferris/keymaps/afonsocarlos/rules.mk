BOOTLOADER = rp2040
CONVERT_TO = promicro_rp2040

SRC += features/accents.c
SRC += features/caps_line.c
SRC += features/num_word.c
SRC += features/os_toggle.c
SRC += features/rgb_config.c
SRC += features/shortcuts.c

AUTO_SHIFT_ENABLE    = yes
BOOTMAGIC_ENABLE     = yes
CAPS_WORD_ENABLE     = yes
COMBO_ENABLE         = yes
DEFERRED_EXEC_ENABLE = yes
KEY_OVERRIDE_ENABLE  = yes
LAYER_LOCK_ENABLE    = yes
LTO_ENABLE           = yes
MAGIC_ENABLE         = yes
MOUSEKEY_ENABLE      = yes
NO_USB_STARTUP_CHECK = yes
OS_DETECTION_ENABLE  = yes
EXTRAKEY_ENABLE = yes
SPLIT_KEYBOARD = yes
UNICODE_ENABLE = yes

#Dont use
AUDIO_ENABLE       = no
BLUETOOTH_ENABLE   = no
COMMAND_ENABLE     = no
CONSOLE_ENABLE     = no
GRAVE_ESC_ENABLE   = no
KEY_LOCK_ENABLE    = no
MIDI_ENABLE        = no
NKRO_ENABLE        = no
OLED_ENABLE        = no
RGB_MATRIX_ENABLE  = no
RGBLIGHT_ENABLE    = no
SLEEP_LED_ENABLE   = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE  = no
TAP_DANCE_ENABLE   = no
VIA_ENABLE         = no
WPM_ENABLE         = no

EXTRAFLAGS += -flto

INTROSPECTION_KEYMAP_C = features/combos.c

LAYOUTS = split_3x5_2xza
