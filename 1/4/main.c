#include <stdio.h>


void change_even_to_char(char *str, char ch) {
	if (!str) return;
	for (int i = 1; str[i] != '\0'; i += 2) {
		str[i] = ch;
	}
}

int main() {
	char s[100] = "Hello, World!";
	printf("Original: %s\n", s);
	change_even_to_char(s, '*');
	printf("Modified: %s\n", s);
	return 0;
}
