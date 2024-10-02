#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(long n) {
    for(long d=2; d*d <= n; d++) {
        if (n%d == 0)
            return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    long m = atoi(argv[1]);
    bool count = argc > 2;
    if ( count ) {
        long acc = 0;
        for(long i = 2; i <= m; i++) {
            if (is_prime(i)) {
                acc++;
            }
        }
        printf("%ld\n", acc);
    }
    else {
        for(long i = 2; i <= m; i++) {
            if (is_prime(i)) {
                printf("%ld\n", i);
            }
        }
    }
}
