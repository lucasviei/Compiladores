#include <stdlib.h>
#include "global.h"

void erro(m)char *m;{
    fprintf(stderr,"linha %d: %s\n", clinha,m);
    exit(1);
}