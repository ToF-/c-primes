#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

long small_primes[] = {
   2 ,   3 ,   5 ,   7 ,  11 ,  13 ,  17 ,  19 ,  23 ,  29 ,  31 ,  37 ,  41 ,  43 ,
  47 ,  53 ,  59 ,  61 ,  67 ,  71 ,  73 ,  79 ,  83 ,  89 ,  97 , 101 , 103 , 107 ,
 109 , 113 , 127 , 131 , 137 , 139 , 149 , 151 , 157 , 163 , 167 , 173 , 179 , 181 ,
 191 , 193 , 197 , 199 , 211 , 223 , 227 , 229 , 233 , 239 , 241 , 251 , 257 , 263 ,
 269 , 271 , 277 , 281 , 283 , 293 , 307 , 311 , 313 , 317 , 331 , 337 , 347 , 349 ,
 353 , 359 , 367 , 373 , 379 , 383 , 389 , 397 , 401 , 409 , 419 , 421 , 431 , 433 ,
 439 , 443 , 449 , 457 , 461 , 463 , 467 , 479 , 487 , 491 , 499 , 503 , 509 , 521 ,
 523 , 541 , 547 , 557 , 563 , 569 , 571 , 577 , 587 , 593 , 599 , 601 , 607 , 613 ,
 617 , 619 , 631 , 641 , 643 , 647 , 653 , 659 , 661 , 673 , 677 , 683 , 691 , 701 ,
 709 , 719 , 727 , 733 , 739 , 743 , 751 , 757 , 761 , 769 , 773 , 787 , 797 , 809 ,
 811 , 821 , 823 , 827 , 829 , 839 , 853 , 857 , 859 , 863 , 877 , 881 , 883 , 887 ,
 907 , 911 , 919 , 929 , 937 , 941 , 947 , 953 , 967 , 971 , 977 , 983 , 991 , 997 };

const int max_small_primes = 168;

long square(long n) {
    return n * n;
}

const long max_prime = 1000 * 1000;
const int sieve_max = (1000 * 1000) / 64;

unsigned long sieve[sieve_max];

void sieve_it(unsigned long n) {
    int sieve_pos = n/64;
    unsigned long bitmask = ((unsigned long) 1 << (n%64) ) ^ ULONG_MAX;
    sieve[sieve_pos] &= bitmask;
}

void init_sieve() {
    for(int i=0; i<sieve_max; i++)
        sieve[i] = ULONG_MAX;
    sieve_it(1);
    for(int i=0; i<max_small_primes; i++) {
        unsigned long p = small_primes[i];
        unsigned long f = square(p);
        while (f <= max_prime) {
            sieve_it(f);
            f+= p;
        }
    }
}

bool is_prime(unsigned long n) {
    int sieve_pos = n/64;
    unsigned long bitmask = (unsigned long)1 << (n%64);
    unsigned long result =  (sieve[sieve_pos] & bitmask);
    return result != 0;
}

int main(int argc, char *argv[]) {

    init_sieve();
    long m = atol(argv[1]);
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
