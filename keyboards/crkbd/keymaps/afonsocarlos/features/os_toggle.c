#include QMK_KEYBOARD_H

#include "os_toggle.h"
#include "os_detection.h"

static os_t    os               = {.type = OS_UNSURE};
static uint8_t detect_try_count = 0;

bool is_macos(void) {
    return os.type == OS_MACOS;
}

bool is_linux(void) {
    return os.type == OS_LINUX;
}

void try_detect_os(void) {
    if (os.type != OS_UNSURE) {
        return;
    }
    if (os.type == OS_UNSURE && detect_try_count > 10) {
        os.type = OS_WINDOWS;
        return;
    }
    os.type = detected_host_os();
    detect_try_count++;
}

bool process_os_toggle(uint16_t keycode, keyrecord_t *record) {
    try_detect_os();
    switch (keycode) {
        // Change OS
        case TG_LINUX:
            if (record->event.pressed) {
                os.type = OS_LINUX;
            }
            return false;

        case TG_MAC:
            if (record->event.pressed) {
                os.type = OS_MACOS;
            }
            return false;

        case TG_WIN:
            if (record->event.pressed) {
                os.type = OS_WINDOWS;
            }
            return false;
    }

    return true;
}
