#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        write(2, "Error: Missing arguments\n", 6);
    }
    else if (argc > 2)
    {
        write(2, "Error: Too many arguments\n", 6);
    }
    else
    {
        rush();
    }
    return (0);
}