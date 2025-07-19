#include <stdio.h>

int main() {
    double g = 0.0;
    long n = 0, m = 0, i = 0, j = 0;
    long a = 0, b = 0, c = 0, d = 1, sum = 0;
    long arr[1000], raa[1000];
    scanf("%ld", &n);
    scanf("%ld", &m);
    for (i = 1; i <= n; i++) {
        scanf("%ld", &arr[i]);
        a = n - i;
        b = arr[i];
        for (j = 0; j < a; j++) {
            b = b * 10;
        }
        sum = sum + b;
    }
    sum = sum + m;
    for (i = 1; i <= n; i++) {
        c = n - i;
        d = 1;
        for (j = 0; j < c; j++) {
            d = d * 10;
        }
        g = sum / d;
        raa[i] = g;
        sum = sum % d;
    }
    for (i = 1; i <= n; i++) {
        printf("%ld", raa[i]);
    }
    return 0;
}