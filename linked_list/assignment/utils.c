#include <stdio.h>
#include "utils.h"

void info(char* message) {
    printf(CYAN "%s\n" RESET, message);
}
void success(char* message) {
    printf(GREEN "%s\n" RESET, message);
}
void warn(char* message) {
    printf(YELLOW "%s\n" RESET, message);
}
void output(char* message) {
    printf(MAGENTA "%s\n" RESET, message);
}
void error(char* message) {
    printf(RED "%s\n" RESET, message);
}