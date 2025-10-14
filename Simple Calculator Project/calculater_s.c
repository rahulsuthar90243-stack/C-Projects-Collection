// Simple Calculater
#include<stdio.h>
#include<math.h>
double division(double a, double b);
void print_menu();
int modulus(int, int);

int main(){
int choice;
double first, second, result;
while(1){
    print_menu();
    scanf("%d", &choice);
    if(choice == 7){
       printf(" Developed by:Rahul");
        break;
    }
    if(choice < 1 || choice > 7){
        printf("Invalid Menu choide ");
        continue;
    }
    printf("\nPlease Enter the first number: ");
    scanf("%lf", &first);
    printf("Please Enter the second number: ");
    scanf("%lf", &second);

    switch (choice)
    {
        case 1: // Add
             result = first + second;
             break;
        case 2: // Subtrect
             result = first - second;
             break;
        case 3: // Multiply
             result = first * second;    
             break;
        case 4: // Devide
             result = division(first, second);
             break;
        case 5: // Modulus
             result = modulus(first, second);
             break;
        case 6: // Power
             result = pow(first, second);
             break;
    }
    if(result != 0){
     printf("\n Result of Operations is : %.2f", result);
    }
    };

    return 0;
}
int modulus(int a, int b){
 if(b == 0){
 printf("Invalid Argument of Modulus\n");
 return 0;
 }else{
    return a % b;
 }
}

double division(double a, double b){
if(b == 0){
 printf("Invalid Argument of Division\n");
 return 0;
}else{
    return a / b;
}
}

void print_menu(){
printf("\n-----------------------------");
printf("\n Welcome to Simple Calculator\n");
printf("\n choose on of the follwing option: \n");
printf(" 1. Add\n");
printf(" 2. Subtract\n");
printf(" 3. Multiply\n");
printf(" 4. Divide\n");
printf(" 5. Modulus\n");
printf(" 6. power\n");
printf(" 7. Exit\n");
printf(" Now, enter your choice: ");
}










































































// // Simple Calculater
// #include<stdio.h>
// #include<math.h>
// void print_menu();

// int main(){
// int choice;
// double first, second, result;
// while(1){
//     print_menu();
//     scanf("%d", &choice);
//     if(choice == 7){
//         break;
//     }
//     printf("\nPlease Enter the first number: ");
//     scanf("%lf", &first);
//     printf("Please Enter the second number: ");
//     scanf("%lf", &second);

//     switch (choice)
//     {
//     case 1: 
//         result = first + second;
//         printf("\nresult: %.2lf", result);
//         break;
//     case 2: 
//         result = first - second;
//         printf("\nresult: %.2lf", result);
//         break; 
//     case 3: 
//         result = first * second;
//         printf("\nresult: %.2lf", result);
//         break;
//     case 4: 
//         result = first / second;
//         printf("\nresult: %.2lf", result);
//         break;
//     case 5: 
//         // result = first % second;
//         break;
//     case 6: 
//         result = pow(first, second);
//         printf("\nresult: %.2lf", result);
//         break;
    
//     default:
//         break;
//     }

// }

//     return 0;
// }


// void print_menu(){
//     printf("\n Welcome to Simple Calculator\n");
//     printf("\n choose on of the follwing option: \n");
//     printf(" 1. Add\n");
//     printf(" 2. Subtract\n");
//     printf(" 3. Multiply\n");
//     printf(" 4. Divide\n");
//     printf(" 5. Modulus\n");
//     printf(" 6. power\n");
//     printf(" 7. Exit\n");
//     printf("Now, enter your choice: ");
// }