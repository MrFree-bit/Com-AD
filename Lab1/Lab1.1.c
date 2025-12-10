#include <stdio.h>

int main() {
    printf("Enter number of times to print 'Hello, World!': ");
    int in_loop;
    scanf("%d", &in_loop);
        for(int i = 0; i < in_loop ; i++){
            printf("Hello World\n");
        } 
    return 0;
}