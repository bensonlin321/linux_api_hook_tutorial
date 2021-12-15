#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "hook_def.h"

int main() {
    printf("get_uid:%d\n", getuid());
    return 0;
}
