

#include "sundial/endianconv.h"
#include <stdio.h>


int 
main(int argc, char *argv[])
{
    char buf[32];

    sprintf(buf, "ciaoroma");
    memrev16(buf);
    printf("%s\n", buf);

    sprintf(buf, "ciaoroma");
    memrev32(buf);
    printf("%s\n", buf);

    sprintf(buf, "ciaoroma");
    memrev64(buf);
    printf("%s\n", buf);

    return 0;
}

