#include "serial.h"
#include "menu.h"
#include "lang.h"
#include "plugin.h"
#include "splash.h"

static int menu_pair(void) {
    const char* msg = "btc_pair";
    #ifndef SIMULATOR
    serial_tx(msg);
    #endif
    splash(HZ, "Pairing!");
    return PLUGIN_OK;
}

static int menu_power_on(void) {
    const char* msg = "btc_poweron";
    #ifndef SIMULATOR
    serial_tx(msg);
    #endif
    splash(HZ, "Bluetooth powering on!");
    return PLUGIN_OK;
}

static int menu_power_off(void) {
    const char* msg = "btc_poweroff";
    #ifndef SIMULATOR
    serial_tx(msg);
    #endif
    splash(HZ, "Bluetooth powering off!");
    return PLUGIN_OK;
}

MENUITEM_FUNCTION(menu_pair_item,      0, "Pair",      menu_pair,      NULL, Icon_NOICON);
MENUITEM_FUNCTION(menu_power_on_item,  0, "Power on",  menu_power_on,  NULL, Icon_NOICON);
MENUITEM_FUNCTION(menu_power_off_item, 0, "Power off", menu_power_off, NULL, Icon_NOICON);

MAKE_MENU(bluetooth_submenu, "Bluetooth", NULL, Icon_Submenu,
    &menu_pair_item,
    &menu_power_on_item,
    &menu_power_off_item
);

