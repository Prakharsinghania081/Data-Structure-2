
#include <stdio.h>
#include <stdlib.h>

// I want you to change the increment and n and see at what point you end up with an extra loop




int main(){

    float i;
    float increment = 0.1; //Change around this
    float n = 1; //And this (this is 10 times increment)
    int count = 1;

    for (i=0.0; i<n; i+=increment) {
        printf("Loop Number: %d\n", count);
        count=count+1;
    }

    return 0;
}
