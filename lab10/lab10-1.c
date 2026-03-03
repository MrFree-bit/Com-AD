#include <stdio.h>

long SumLoop( int n ){
    long sum = 0;
    int i;
    for(i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

long SumRecur( int n ){
    if(n == 1)
        return 1;
    else
        return n + SumRecur(n - 1);
}

int main() {
    printf( "SumLoop(n) = %d", SumLoop( 10 ) );
    printf( "SumRecur(n) = %d", SumRecur( 10 ) );
    return 0;
}