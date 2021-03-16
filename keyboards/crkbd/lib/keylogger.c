#include <stdio.h>
#include "crkbd.h"

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

//char debugLog_buf[63] = {};
//char debugLog_str1[20] = {};
//char debugLog_str2[20] = {};
//char debugLog_str3[20] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}

void setdebugLog_str1(const char *data){
  //snprintf(debugLog_str1, sizeof(debugLog_str1), "%s",data);
}
void setdebugLog_str2(const char *data){
  //snprintf(debugLog_str2, sizeof(debugLog_str2), "%s",data);
}
void setdebugLog_str3(const char *data){
  //snprintf(debugLog_str3, sizeof(debugLog_str3), "%s",data);
}

//const char *read_debugLog(void) {

  //snprintf(debugLog_buf, sizeof(debugLog_buf), "%s\n%s\n%s",debugLog_str1,debugLog_str2,debugLog_str3);
  //return debugLog_buf;
//}