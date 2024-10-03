#include <stdio.h>
#include<stdlib.h>
#include<math.h>

float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);

int main() {
    char operator;
    float num1, num2, result;
    
    
    FILE *fp = fopen("calculator.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter operator (+, -, *, /): "); 
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%f", &num2);
    
    
    switch(operator) {
        case '+':
            result = add(num1, num2);
            printf(" %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = subtract(num1, num2);
            if (num1>=num2){
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            }
            else{
                printf("%.2f - %.2f = -%.2f\n", num1, num2, result);
            }
            break;
        case '*':
            result = multiply(num1, num2);
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = divide(num1, num2);
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("Error: Division by zero\n");
                
                return 1;
            }
            break;
        
        default:
            printf("Error: Invalid operator\n");
            
            return 1;
    }
    
    fprintf(fp, "%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    
    fclose(fp);

    return 0;
}


float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    return num1 / num2;
}

