#include <stdio.h>
#include <math.h>

#define _SIZE_ 168

int primes[_SIZE_] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,
    89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
    197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
    317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
    449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587,
    593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719,
    727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859,
    863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
    
int check(int n){
    int right=0, left=_SIZE_-1, middle;
    do {
        middle = (left + right) / 2;
        if (primes[middle] == n)
            return 1;
        if (primes[middle] > n)
            left = middle-1;
        if (primes[middle] < n)
            right = middle+1;
    } while (left >= right);
    return 0;
}

int main(){
    int n, sqrt_number, i;
    while (scanf("%d", &n) != EOF) {
        if (n==0) break;
        
        if (n == 1) {
            printf("%d\n", 1);
            continue;
        }
        
        if (n<=1000) {
            printf("%d\n", check(n) ? 0 : 1);
            continue;
        }
        
        sqrt_number = (int)sqrt(n);
        for (i=0; i<_SIZE_; i++) {
            if (sqrt_number < primes[i]) break;
            if (n%primes[i] == 0){
                printf("1\n");
                n = -1;
                break;
            }
        }
        
        if(n != -1) printf("0\n");
    }
    
    return 0;
}
