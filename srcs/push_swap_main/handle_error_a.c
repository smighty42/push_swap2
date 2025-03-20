#include <unistd.h>
#include <stdlib.h>
void write_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

