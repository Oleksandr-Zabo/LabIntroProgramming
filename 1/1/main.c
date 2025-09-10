
#include <stdio.h>

int main() {
    float a, b, c, x;
    printf("Enter brick sides a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Enter square hole side x: ");
    scanf("%f", &x);

    if ((a <= x && b <= x) || (a <= x && c <= x) || (b <= x && c <= x)) {
        printf("can\n");
    } else {
        printf("cannot\n");
    }
    return 0;
}