#include <cstdio>

int gcd(int a, int b) {
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main() {
    int test, point, num, deno, i;
    char str[16];
    scanf("%d", &test);
    while(test--) {
        scanf("%s", str);
        point = 0, num = 0, deno = 1;
        for(i = 0; str[i]; i++) {
            if(str[i] == '.') {
                point = 1;
                continue;
            }
            num = num * 10 + str[i] - '0';
            if(point) deno *= 10;
        }
        printf("%d\n", deno / gcd(num, deno));
    }
    return 0;
}