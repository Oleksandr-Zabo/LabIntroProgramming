#include <stdio.h>
#include <assert.h>

// Main function for substring search
int isSubStr(const char *str, const char *sub) {
    if (!str || !sub) return -1;
    if (sub[0] == '\0') return 0; // empty substring - 0
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; sub[j] != '\0'; j++) {
            if (str[i + j] != sub[j]) break;
        }
        if (sub[j] == '\0') return i;
    }
    return -1;
}

// Tests for isSubStr function
void test_isSubStr() {
    assert(isSubStr("hello world", "world") == 6);
    assert(isSubStr("abcdef", "def") == 3);
    assert(isSubStr("abcdef", "xyz") == -1);
    assert(isSubStr("abcabc", "abc") == 0); // first occurrence
    assert(isSubStr("abcabc", "cab") == 2);
    assert(isSubStr("abc", "") == 0); // empty substring - 0
    assert(isSubStr("", "a") == -1); // substring not found in empty string
    assert(isSubStr("", "") == 0);   // both empty: position 0
    printf("All tests passed\n");
}

void demo() {
    char str[] = "programming";
    char sub[] = "gram";
    int pos = isSubStr(str, sub);
    if (pos != -1)
        printf("Substring \"%s\" found in \"%s\" at position %d\n", sub, str, pos);
    else
        printf("Substring \"%s\" not found in \"%s\"\n", sub, str);
}

int main() {
    test_isSubStr();
    printf("All tests completed successfully.\n");
    demo();
    return 0;
}