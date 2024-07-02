#include "host.h"
#include "quantum.h"
#include "layers.h"

#include "features/os_toggle.h"

#ifdef OLED_ENABLE

static void render_logo(void)
{
    static const char PROGMEM font_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    oled_write_P(font_logo, false);
}

static void render_icon(void)
{
#ifdef OLED_90ROTATION
    static const char PROGMEM font_icon[] = {
        0x9b,0x9c,0x9d,0x9e,0x9f,
        0xbb,0xbc,0xbd,0xbe,0xbf,
        0xdb,0xdc,0xdd,0xde,0xdf,0
    };
#else
    static const char PROGMEM font_icon[] = {
        // Use \r (0x0d) to jump to the next line without clearing the rest of the current line
        0x9b,0x9c,0x9d,0x9e,0x9f,0x0d,
        0xbb,0xbc,0xbd,0xbe,0xbf,0x0d,
        0xdb,0xdc,0xdd,0xde,0xdf,0
    };
#endif
    oled_write_P(font_icon, false);
}

static void render_layer(void)
{
    uint8_t layer = layer_state ? get_highest_layer(layer_state) : get_highest_layer(default_layer_state);
#ifdef OLED_90ROTATION
    oled_write_P(PSTR("Layer"), false);
#else
    oled_write_P(PSTR("Layer: "), false);
#endif

    switch (layer)
    {
        case _BASE:
            oled_write_P(PSTR("BASE "), false);
            break;
        case _GAME_NUMPAD:
            oled_write_P(PSTR("GAME "), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV "), false);
            break;
        case _NUMS:
            oled_write_P(PSTR("NUMS"), false);
            break;
        case _SYS:
            oled_write_P(PSTR("SYS "), false);
            break;
    }
}

static void render_keyboard_leds(void)
{
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
#ifdef OLED_90ROTATION
    oled_write_P(led_state.num_lock ? PSTR("NUMLK") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLK") : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLK") : PSTR("     "), false);
#else
    oled_write_P(led_state.num_lock ? PSTR("NUM  ") : PSTR("     "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("     "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRL") : PSTR("    "), false);
#endif
}

static void render_os(void)
{
#ifdef OLED_90ROTATION
    oled_write_P(PSTR("OS"), false);
#else
    oled_write_P(PSTR("OS: "), false);
#endif

    if (is_linux()) {
        oled_write_P(PSTR("LINUX  "), false);
    } else if (is_macos()) {
        oled_write_P(PSTR("MAC OS "), false);
    } else {
        oled_write_P(PSTR("WINDOWS"), false);
    }
}

#if defined(OLED_90ROTATION)

static void render_status(void)
{
    render_icon();
    render_layer();

    // Host Keyboard LED Status
    oled_write_P(PSTR("-----"), false);
    render_keyboard_leds();

    oled_write_P(PSTR("-----"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return rotation;
}

#else  // OLED_90ROTATION

static void render_status(void)
{
    render_icon();

    // Host Layer Status
    oled_set_cursor(6, 0);
    render_layer();

    // Host Keyboard LED Status
    oled_set_cursor(6, 1);
    render_keyboard_leds();

    // Host OS
    oled_set_cursor(6, 2);
    render_os();
}

#endif // OLED_90ROTATION

bool oled_task_user(void)
{
    if (is_keyboard_master())
        render_status();
    else
    {
        render_logo();
        // oled_scroll_left();
    }
    return false;
}

#endif
