#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() { 
    float a, b, c, D, x1, x2; 
     
    printf("Enter the a: "); 
    scanf("%f", &a); 
    printf("Enter b: "); 
    scanf("%f", &b); 
    printf("Enter c: "); 
    scanf("%f", &c); 
    D = b*b - 4*a*c;
    if(D < 0){
        printf("No solution");
    }
    else if(D == 0){
        x1 = (-b + sqrt(D)) / (2*a);
        printf("One solution: "); 
        printf("%f", x1);
    }
    else{
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
        printf("Two solution: "); 
        printf("%f", x1);
        printf(" and "); 
        printf("%f", x2);
    }
     
    return 0; 
} 

//gcc main.c -o main.exe; ./main.exe