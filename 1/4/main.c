#include <stdio.h>
void change_even_to_char(char *str, char ch) {
	if (!str || str[0] == '\0' || str[1] == '\0') return;
	str[1] = ch;
	change_even_to_char(str + 2, ch);
}

int main() {
	char s[100] = "Hello, World!";
	printf("Original: %s\n", s);
	change_even_to_char(s, '*');
	printf("Modified: %s\n", s);
	return 0;
}
