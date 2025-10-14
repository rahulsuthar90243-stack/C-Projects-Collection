// Guessing Game 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int rendom, guess;
    int no_of_guess = 0;
    srand(time(NULL));   // Random seed set using current time

    printf("Wellcome to the world Guessing Number \n");
    rendom = rand() % 100 +1;  // Generate number between 1–100)

    do{
         printf("\n please Enter your guess between (1 to 100): ");
        scanf("%d", &guess);
        no_of_guess++;

        if(guess < rendom){
        printf("Guess a larger number.\n");
        }else if(guess > rendom){
            printf("Guess a smaller number.\n");
        }else{
            printf("\n");
            printf("Congratulation !!!You have Successfully guessed the Number in %d attempt", no_of_guess);
        }

    }while(guess != rendom);

    printf("\nBye Bye. Thanks for playling.\n");
    printf("Developed by: Rahul\n");

    return 0;
}



// // rendom number generate
// #include<stdio.h>
// #include<time.h>
// #include<stdlib.h>
// int main(){

//     srand(time(NULL));

//    printf("%d\n", rand());
//    printf("%d\n", rand());
//    printf("%d\n", rand());
//    printf("%d\n", rand());
//    printf("%d\n", rand());

// }

// // generate rendom number between renge of value
// #include<stdio.h>
// #include<stdlib.h>
// #include<time.h>
// int main(){

//     srand(time(NULL));

//     int rendom = rand() % 50;
//     printf("%d", rendom);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main() {
//     int random;

//     srand(time(NULL));  // Random seed set using current time

//     random = rand() % 100 + 1;  // Generate number between 1–100

//     printf("Random number: %d\n", random);

//     return 0;
// }

