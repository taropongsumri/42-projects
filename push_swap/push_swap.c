#include "push_swap.h"
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc <= 1) {
        write(2,"Error Missing Arguments\n",24);
        return 0;
    }

    int i = 1;
    int j = 0;
    while (i < argc) {
        j = 0;
        while (argv[i][j] != '\0') {
            j++;
        }
        i++;
    }
    return 0;
}