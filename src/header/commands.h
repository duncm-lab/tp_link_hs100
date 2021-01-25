#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdbool.h>
#include <stdint.h>

#define INFO       "{\"system\":{\"get_sysinfo\":{}}}"
#define ON         "{\"system\":{\"set_relay_state\":{\"state\":1}}}"
#define OFF        "{\"system\":{\"set_relay_state\":{\"state\":0}}}"
#define LEDOFF     "{\"system\":{\"set_led_off\":{\"off\":1}}}"
#define LEDON      "{\"system\":{\"set_led_off\":{\"off\":0}}}"
#define CLOUDINFO  "{\"cnCloud\":{\"get_info\":{}}}"
#define WLANSCAN   "{\"netif\":{\"get_scaninfo\":{\"refresh\":0}}}"
#define TIME       "{\"time\":{\"get_time\":{}}}"
#define SCHEDULE   "{\"schedule\":{\"get_rules\":{}}}"
#define COUNTDOWN  "{\"count_down\":{\"get_rules\":{}}}"
#define ANTITHEFT  "{\"anti_theft\":{\"get_rules\":{}}}"
#define REBOOT     "{\"system\":{\"reboot\":{\"delay\":1}}}"
#define RESET      "{\"system\":{\"reset\":{\"delay\":1}}}"
#define ENERGY     "{\"emeter\":{\"get_realtime\":{}}}"



char * select_command(char *comm);
#endif /* ifndef COMMANDS_H */
