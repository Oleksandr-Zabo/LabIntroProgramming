#include <stdio.h>
#include <assert.h>

typedef struct FRACTION {
    int numerator;
    int denominator;
} FRACTION;

int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 0 ? 1 : a;
}

void simplify(FRACTION* frac) {
    int sign = 1;
    if (frac->denominator < 0) {
        sign = -1;
        frac->denominator = -frac->denominator;
        frac->numerator = -frac->numerator;
    }
    int d = gcd(frac->numerator, frac->denominator);
    frac->numerator /= d;
    frac->denominator /= d;
}

FRACTION add(FRACTION a, FRACTION b) {
    FRACTION result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    simplify(&result);
    return result;
}
FRACTION sub(FRACTION a, FRACTION b) {
    FRACTION result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    simplify(&result);
    return result;
}

FRACTION mul(FRACTION a, FRACTION b) {
    FRACTION result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    simplify(&result);
    return result;
}

FRACTION div(FRACTION a, FRACTION b) {
    FRACTION result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    simplify(&result);
    return result;
}

FRACTION frac_pow(FRACTION base, int exp) {// pow- standard function in math.h
    FRACTION result = {1, 1};
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mul(result, base);
        }
        base = mul(base, base);
        exp /= 2;
    }
    return result;
}

void test_fractions() {
    FRACTION a = {1, 2};
    FRACTION b = {3, 4};

    assert(add(a, b).numerator == 5 && add(a, b).denominator == 4);
    assert(sub(a, b).numerator == -1 && sub(a, b).denominator == 4);
    assert(mul(a, b).numerator == 3 && mul(a, b).denominator == 8);
    assert(div(a, b).numerator == 2 && div(a, b).denominator == 3);
    assert(frac_pow(a, 2).numerator == 1 && frac_pow(a, 2).denominator == 4);
    assert(frac_pow(b, 3).numerator == 27 && frac_pow(b, 3).denominator == 64);
    printf("All fraction tests passed\n");
}

void demo() {
    FRACTION a = {1, 2};
    FRACTION b = {3, 4};

    FRACTION res_add = add(a, b);
    printf("Addition: %d/%d + %d/%d = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, res_add.numerator, res_add.denominator);

    FRACTION res_sub = sub(a, b);
    printf("Subtraction: %d/%d - %d/%d = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, res_sub.numerator, res_sub.denominator);

    FRACTION res_mul = mul(a, b);
    printf("Multiplication: %d/%d * %d/%d = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, res_mul.numerator, res_mul.denominator);

    FRACTION res_div = div(a, b);
    printf("Division: %d/%d / %d/%d = %d/%d\n", a.numerator, a.denominator, b.numerator, b.denominator, res_div.numerator, res_div.denominator);

    int exp = 3;
    FRACTION res_pow = frac_pow(a, exp);
    printf("Exponentiation: (%d/%d)^%d = %d/%d\n", a.numerator, a.denominator, exp, res_pow.numerator, res_pow.denominator);
}

int main() {
    test_fractions();
    printf("All tests completed successfully.\n");
    demo();
    return 0;
}