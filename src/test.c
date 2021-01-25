#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


typedef struct _test {
    char *x;
} test;


void update(test *t){
    t->x = "hello";
}

int main(int argc, char *argv[])
{
    int x[1];
    x[0] = 1;
    int y[1];
    y[0] = 2;
    int z[2] = {*x , *y};
}
