
// **USER MANAGEMENT SYSTEM** \\.
#include<stdio.h>
#include<string.h>

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
    case 3: printf("Exiting Program!");
            printf("\nDeveloped by: TECH BY RAHUL\n");
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
    
    printf("\nRegistar a new user: ");
    printf("\nEnter username: ");
    scanf("%[^\n]s", users[new_index].username);
    getchar();

    printf("Enter password: ");
    scanf("%[^\n]a", users[new_index].password);
    getchar();

    printf("\nRegistration Successful! ");

    user_count++;
}

int login_user(){
    char username[CREDNETIAL_LENGTH];
    char password[CREDNETIAL_LENGTH];

    printf("Enter username: ");
    scanf("%[^\n]s", username);
    getchar();

    printf("Enter password: ");
    scanf("%[^\n]", password);
    getchar();

    for(int i = 0; i < user_count; i++){
        if(strcmp(users[i].username, username) == 0 &&
           strcmp(users[i].password, password) == 0){
           
            return i;
           }
    }

    return -1;
}
