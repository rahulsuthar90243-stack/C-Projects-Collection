#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

const char* COLOR_END = "\033[0m";
const char* RED ="\033[1;31m";
const char* GREEN ="\033[1;32m";
const char* YELLOW ="\033[1;33m";
const char* BLUE ="\033[1;34m";
const char* PINK ="\033[1;35m";
const char* AQUA ="\033[1;36m";


#define MAX_QUES_LEN 400
#define MAX_OPTION_LEN 100

typedef struct {
    char Text[MAX_QUES_LEN];
    char option[4][MAX_OPTION_LEN];
    char correct_option;
    // int timeout;
    int prize_mony;
}Questions;


int read_questions(char* file_name, Questions** questions);
void print_formatted_questions(Questions question, int que);
void play_game(Questions* questions, int no_of_questions);
int use_lifeline(Questions* Question, int*lifeline);


int main(){
    srand(time(NULL));
    printf("\n\t\t%s------------------------------------------%s", PINK, COLOR_END);
    printf("\n\t\t%s[ Chalo kalte hai KON BANEGA CRORPATI!!! ]%s", PINK, COLOR_END);
    printf("\n\t\t%s------------------------------------------%s", PINK, COLOR_END);

    Questions* questions;
    int no_of_questions = read_questions("Questions.txt", &questions);
    play_game(questions, no_of_questions);
    
    return 0;
}

void play_game(Questions* questions, int no_of_questions){
    int money_won = 0;
    int lifeline[] = {1,1};


    for(int i=0; i < no_of_questions; i++){
    print_formatted_questions(questions[i], i + 1);
    char ch = getchar();
    ch = toupper(ch);
    while(getchar()!='\n');

    if(ch == 'L'){
       int value = use_lifeline(&questions[i], lifeline);
       if(value != 2){
        i--;
       }
        continue;
    }

    if(ch == questions[i].correct_option){
        printf("\n%sCorrect!%s", GREEN, COLOR_END);
        money_won = questions[i].prize_mony;
        printf("\n%sCongratulation! you won Rs %d%s", BLUE, money_won, COLOR_END);
    }else{
        printf("\n%sWrong! Correct answer is %c%s", RED, questions[i].correct_option, COLOR_END);
        break;
    }
    }
    printf("\n\n%sGame Over! Your total winnings: Rs %d%s", BLUE, money_won, COLOR_END);
    printf("\n\t\t%s-----------------------%s\n", PINK, COLOR_END);
    printf("\t\t%s[ Developed by: RAHUL ]%s", PINK, COLOR_END);
    printf("\n\t\t%s-----------------------%s\n", PINK, COLOR_END);

}

int use_lifeline(Questions* question, int* lifeline){

    printf("\n%sAvailable Lifeline: %s", PINK, COLOR_END);

    if(lifeline[0]) printf("\n%s1. Fifty Fifty (50/50)%s", PINK, COLOR_END);
    if(lifeline[1]) printf("\n%s2. Skip the Questions%s\n", PINK, COLOR_END);
    printf("%s\nChoose a lifeline or 0 to return: %s", PINK, COLOR_END);

    char ch = getchar();
     while(getchar() != '\n');   // <-- THIS FIXES EVERYTHING

    switch (ch){
    case '1':
        if(lifeline[0]){
           lifeline[0] = 0;
           int remove = 0;
           while(remove < 2){
            int num = rand() % 4;
            if((num + 'A') != question->correct_option && 
               question->option[num][0] != '\0'){
                question->option[num][0] = '\0';
                remove++;
            }
           }
           return 1;
        }
        break;
    case '2':
        if(lifeline[1]){
           lifeline[1] = 0;
           return 2;
        }
        break;
    default:
    printf("\n%sReturning to the Questions%s", PINK, COLOR_END);
        break;
    }
    return 0;
}


void print_formatted_questions(Questions question, int que){
printf("\n\n%sQ%d.%s%s",YELLOW, que, question.Text, COLOR_END );
for(int i=0; i < 4; i++){
    if(question.option[i][0] != '\0'){
    printf("%s%c. %s%s",AQUA, ('A' + i), question.option[i], COLOR_END);
    }
}
printf("\n%sPlease answer quickly..%s",YELLOW, COLOR_END);
printf("\n%sEnter your answer (A, B, C, or  D) for L for lifeline -> %s", GREEN, COLOR_END);
 
}


int read_questions(char* file_name, Questions** questions){
    FILE *file = fopen(file_name, "r");
    if(file == NULL){
        printf("\nUnable to open the questions bank.");
        exit(0);
    }

    char str[MAX_QUES_LEN];
    int no_of_lines = 0;
    while(fgets(str, MAX_QUES_LEN, file)){
        no_of_lines++;
    }
    int no_of_questions = no_of_lines / 7;
    *questions = (Questions *) malloc(no_of_questions * sizeof(Questions));

    rewind(file);
    for(int i=0; i < no_of_questions; i++){
        fgets((*questions)[i].Text, MAX_QUES_LEN, file);
        for(int j=0; j < 4; j++){
            fgets((*questions)[i].option[j], MAX_OPTION_LEN, file);
        }
        
        char option[10];
        fgets(option, 10, file);
        (*questions)[i].correct_option = option[0];

        char prize_money[10];
        fgets(prize_money, 10, file);
        (*questions)[i].prize_mony = atoi(prize_money);
        
    }
    fclose(file);
    return no_of_questions;
}