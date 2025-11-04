// [ User Management System ]
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>

#define MAX_USERS 10
#define CREDNETIAL_LENGTH 30
typedef struct {
    char username[CREDNETIAL_LENGTH];
    char password[CREDNETIAL_LENGTH];
}user;

 user users[MAX_USERS];
 int user_count = 0;
 
void register_user();
int login_user();
void fix_fget_input(char*);
void input_credentials(char* username, char* password);

int main(){
    int option;
    int user_index; 

    while(1){
    printf("\n\n ---------------------------");  
    printf("\n[ Welcome to User Managment ]");
    printf("\n ---------------------------");   

    printf("\n1.Register");
    printf("\n2.Login");
    printf("\n3.Exit");
    printf("\nSelect an Option: ");
    scanf("%d", &option);
    getchar();

    switch (option){
    case 1:
    register_user();
    break;
    case 2:
    user_index = login_user();
    if(user_index >= 0){
        printf("Login Successful! Welcome, %s", users[user_index].username);
    }else{
        printf("\nLogin Failed! Incorrect User or Password.\n");
    }
    break;
    case 3: printf("\n **-- Exiting Program! --**");
            printf("\n**-- Developed by: RAHUL --**\n");
    return 0;
    break;
    default: printf("Invalide Option Please try again.\n");
    break;
    }
  }

    return 0;
}

void register_user(){
    if (user_count == MAX_USERS){
        printf("\nThe Maxximum %d Users are Supported! No More registrastion Allowed!!!!\n", MAX_USERS);
        return;
    }
    int new_index = user_count;
    printf("\nRegistration a new user");
    input_credentials(users[new_index].username, users[new_index].password);

    user_count++;
    printf("\nResgitration Successful!");
}

int login_user(){
    char username[CREDNETIAL_LENGTH];
    char password[CREDNETIAL_LENGTH];

    input_credentials(username, password);

    for(int i=0; i < user_count; i++){
        if(strcmp(username, users[i].username) == 0 &&
           strcmp(password, users[i].password) == 0){
            return i;
           }
    }
    return -1;
}

void input_credentials(char* username, char* password){
    printf("\nEnter username: ");
    fgets(username, CREDNETIAL_LENGTH, stdin);
    fix_fget_input(username);
    printf("Enter password (masking enabled): ");


// change terminal properties
       int i = 0;
    char ch;

    // password masking using _getch()
    while ((ch = _getch()) != '\r' && i < CREDNETIAL_LENGTH - 1) { // '\r' = Enter key
        if (ch == '\b' && i > 0) { // handle backspace
            printf("\b \b");
            i--;
        } else if (ch != '\b') {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
    printf("\n");
}

void fix_fget_input(char* string){
int index =  strcspn(string, "\n");
string[index] = '\0';
}
