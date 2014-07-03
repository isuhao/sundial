
#include "sundial/crc64.h"
#include <stdio.h>


int 
main(int argc, char *argv[])
{
    printf("e9c6d914c4b8d9ca == %016llx\n",
        (unsigned long long) crc64(0, (unsigned char*)"123456789", 9));

    return 0;
}

