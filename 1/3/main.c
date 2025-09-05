#include <stdio.h>

int main() {
	int IM[100];
    for (int i = 0; i < 100; i++) {
        if(i%2==0){
            IM[i]=i+2;
        } else {
            IM[i]=i;
        }
    }

    for (int i = 0; i < 100; i++) {
        printf("%d ", IM[i]);
    }
	return 0;
}