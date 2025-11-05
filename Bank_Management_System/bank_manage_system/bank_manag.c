#include<stdio.h>
#include<string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

typedef struct{
   char name[30];
   int acc_no;
   float balance;
} Account;


int main(){
    int choice;

    while(1){
        printf("\n\n ------------------------");
        printf("\n[ Bank Management System ]");
        printf("\n ------------------------");
        printf("\n1.Create Account");
        printf("\n2.Diposit Money");
        printf("\n3.Withdraw Money");
        printf("\n4.Check Balance");
        printf("\n5.Exit ");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
        case 1: 
        create_account();
           break;
        case 2: 
        deposit_money();
           break;
        case 3: 
        withdraw_money();
           break;
        case 4: 
        check_balance();
           break;
        case 5: 
        printf("\n ------------------------------------------");
        printf("\n[ Clossing the Bank, Thanks for your visit ]");
        printf("\n[           Developed by: RAHUL            ]");
        printf("\n ------------------------------------------");
           
           return 0;
           break;
        
        default: 
           printf("\nInvalide Option!"); 
            break;
        }
    }


    return 0;
}

void create_account(){
 Account acc;
 FILE *file = fopen("account.dat", "ab+");
 if(file == NULL){
    printf("\nUnable to open file!!");
    return;
 }

 printf("\nEnter your name: ");
 fgets(acc.name, sizeof(acc.name), stdin);
 int ind = strcspn(acc.name, "\n");
 acc.name[ind] = '\0';

 printf("Enter your account number: ");
 scanf("%d", &acc.acc_no);
 acc.balance = 0;

 fwrite(&acc, sizeof(acc), 1, file);
 fclose(file);
 printf("\nAccount Create Successfully!!!\n");

}

void deposit_money(){
FILE *file = fopen("account.dat", "rb+");
if(file == NULL){
    printf("\nUnable to open file\n");
}

int acc_no;
float money;
Account acc_read;
printf("\nEnter your account account number: ");
scanf("%d", &acc_no);
printf("\nEnter amount to deposit: ");
scanf("%f", &money);

while(fread(&acc_read, sizeof(acc_read), 1, file)){
    if(acc_read.acc_no == acc_no){
        acc_read.balance += money;
        fseek(file, -sizeof(acc_read), SEEK_CUR);
        fwrite(&acc_read, sizeof(acc_read), 1, file);
        fclose(file);
        printf("\nSuccessfully deposited Rs.%.2f Now balance is Rs.%.2f", money, acc_read.balance);
        return;
    }
}
fclose(file);
printf("\n Money could not be deposit as the Account no %d was not fount in records", acc_no);

}

void withdraw_money(){
FILE *file = fopen("account.dat", "rb+");
if(file == NULL){
    printf("\nUnable to account open file!");
}

int acc_no;
float money;
Account acc_read;

printf("Enter your account number: ");
scanf("%d", &acc_no);
printf("Enter the amount you wish to withdeaw: ");
scanf("%f", &money );

while(fread(&acc_read, sizeof(acc_read), 1, file)){
    if(acc_read.acc_no == acc_no){
        if(acc_read.balance >= money){
            acc_read.balance -= money;
            fseek(file, -sizeof(acc_read), SEEK_CUR);
            fwrite(&acc_read, sizeof(acc_read), 1, file);
            printf("\nSuccessfully withdraw Rs.%.2f Remaining balance is Rs.%.2f", money, acc_read.balance);
        }else{
            printf("\nInsufficient balance!");
        }
        fclose(file);
        return;
    }
}
fclose(file);
printf("\nMoney could not be withdraw as the Account no %d was not found in recoeds", acc_no);

}


void check_balance(){
FILE *file = fopen("account.dat", "rb");
if(file == NULL){
    printf("\nUnable to open file!!");
}

int acc_no;
Account acc_read;
printf("Enter your account number: ");
scanf("%d", &acc_no);

while(fread(&acc_read, sizeof(acc_read), 1, file)){
    if(acc_read.acc_no == acc_no){
        printf("\nYour Current Balance is R.%.2f\n", acc_read.balance);
        fclose(file);
        return;
    }
}
fclose(file);
printf("\nAccount Number: %d was not fount.\n", acc_no);
}

