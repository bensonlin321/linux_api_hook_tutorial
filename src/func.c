#include "hook_def.h"
#include <stdio.h>
#include <sys/types.h>

HOOK_FUNC_INIT(getuid);

uid_t getuid(void) {
    HOOK_FUNC(getuid);
    int uid = ORIGINAL_FUNC(getuid)();
    printf("getuid original:%d\n", uid);
    return 800;
}
