#include<stdio.h>


const char* COLOR_END = "\033[0m";
const char* RED ="\033[1;31m";
const char* GREEN ="\033[1;32m";
const char* YELLOW ="\033[1;33m";
const char* BLUE ="\033[1;34m";
const char* PINK ="\033[1;35m";
const char* AQUA ="\033[1;36m";
void print_menu();
void create_file();
void delete_file();
void rename_file();

int main(){

    while (1){
        int choice;
        print_menu();
        printf("%s\nPlease,Enter Your Choice: %s", BLUE, COLOR_END);
        scanf("%d", &choice);
        switch (choice){
        case 1:
            create_file();
            break;
        case 2:
            delete_file();
            break;
        case 3:
            rename_file();
            break;
        case 4:
            printf("%s\nThank you for using File Manager.%s", PINK, COLOR_END);
            printf("\n%s  ----------------------------%s", PINK, COLOR_END);
            printf("\n%s  |    Developed by Rahul     | %s", PINK, COLOR_END);
            printf("\n%s  ----------------------------%s", PINK, COLOR_END);
            return 0;   

        default:
            printf("%sInvalid choice%s", RED, COLOR_END);
            break;
        }
    }

    return 0;
}

void rename_file(){
    char oldName[50];
    char newName[50];
    int press;

    while (1) {
        printf("%s\nEnter old file name: %s", PINK, COLOR_END);
        scanf("%s", oldName);

        printf("%sEnter new file name: %s",  PINK, COLOR_END);
        scanf("%s", newName);

        if (rename(oldName, newName) == 0) {
            printf("%s\nFile renamed successfully.%s", GREEN, COLOR_END);
            return;
        } else {
            printf("%s\nRename failed!%s", RED, COLOR_END);
            printf("%s\nTry again (1) or Exit (2): %s", BLUE, COLOR_END);
            scanf("%d", &press);

            if (press == 2)
                return;
            else if (press != 1)
                printf("%s\nInvalid choice!%s", RED, COLOR_END);
        }
    }
}
 


void delete_file(){
    char filename[50];
    int press;

    while (1) {
        printf("%s\nPlease, Enter File Name: %s", PINK, COLOR_END);
        scanf("%49s", filename);

        if (remove(filename) == 0) {
            printf("%s\nFile deleted successfully!%s", GREEN, COLOR_END);
            return;  
        } 
        else {
            printf("%s\nFile not found!%s", RED, COLOR_END);
            printf("%s\nTry one more time (1) or Exit (2): %s", BLUE, COLOR_END);
            scanf("%d", &press);

            if (press == 2)
                return;
            else if (press != 1)
                printf("%s\nInvalid choice!%s", RED, COLOR_END);
        }
    }
}


void create_file(){
    char filename[50];
    printf("%s\nPlease, Enter File Name: %s", PINK, COLOR_END);
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("%s\nFile creation failed!!!", RED, COLOR_END);
        return;
    }

    printf("%sFile created successfully%s", GREEN, COLOR_END);
    fclose(file);
}

void print_menu(){
    printf("\n%s            ----------------------------%s", BLUE, COLOR_END);
    printf("\n%s            |  Personal File Manager   | %s", BLUE, COLOR_END);
    printf("\n%s            ----------------------------%s", BLUE, COLOR_END);
    printf("\n%s1.Create File%s", YELLOW, COLOR_END);
    printf("\n%s2.Delete File%s", YELLOW, COLOR_END);
    printf("\n%s3.Rename File%s", YELLOW, COLOR_END);
    printf("\n%s4.Exit %s", RED, COLOR_END);
}