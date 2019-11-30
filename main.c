#include "myBank.h"
#include <stdio.h>
void menu()
{
    printf("\nMENU:\n");
    printf("O - to open acount \n");
    printf("B - to check your balance acount \n");
    printf("D - to deposit \n");
    printf("W - to withdraw amount \n");
    printf("C - to close acount \n");
    printf("I - to add interest \n");
    printf("P - to print open acounts balance \n");
    printf("E - to close all acounts and exit \n");
    printf("\n Please enter your choice: ");
}
int checkAccount(int account_number)//check if account exist (0=not exist, 1=exist, )
{
     if(account_number>900&&account_number<951)return 1;
     else{return 0;}
}
int checkAmount(double amount)//check if amount legal (0=illegal, 1=legal, )
{
    if(amount>=0)return 1;
    else{return 0;}
}
int main()
{
    char c;
    int account_number;
    double amount;
    double percent;
    do
    {
    menu(); //print menu
    scanf("%c", &c);
     switch(c)
    {
        case 'O': //openaccount
            printf("Please enter your first amount: ");
            scanf("%lf" , &amount);
            openAccount(amount);
            break;
        case 'B': //checkBalance
            printf("Please enter your account number: ");
            scanf("%d", &account_number);
            checkBalance(account_number);
            break;
        case 'D': //deposit
            printf("Please enter your account number: ");
            scanf("%d", &account_number);
            printf("Please enter amount: ");
            scanf("%lf", &amount);
            deposit(account_number,amount);
            break;
        case 'W': //withdrawal
            printf("Please enter your account number: ");
            scanf("%d", &account_number);
            printf("Please enter amount: ");
            scanf("%lf", &amount);
            withdrawal(account_number,amount);
            break;
        case 'C': //closeAccount
            printf("Please enter the account number you want to close: ");
            scanf("%d", &account_number);
            closeAccount(account_number);
            break;
        case 'I': //interest
            printf("Please enter a percentage interest rate: ");
            scanf("%lf", &percent);
            interest(percent);
            break;
        case 'P': //print
            print();
            break;
        case 'E':
            closeAll();
            break;
        default:
            printf("\n Error! your choise is not possible, please try again \n");
    }
        while((getchar()!='\n'));
    }
    while(c!='E');
    return 0;
}



     // int account; // enter a number of open account
    // int close_account;// enter a number of close account
    // double amount; 
    // amount=42.44222;
    // openAccount(amount);
    // account=901;
    // checkBalance(account); 
    // close_account =902;
    // checkBalance(close_account); //should be a close account
    // amount=40;
    // deposit(account,amount);
    // amount=20;
    // withdrawal(account,amount);
    // withdrawal(close_account,amount); //should be a close account
    // amount=1000;
    // withdrawal(account, amount); //not enough money 
    // closeAccount(account);
    // closeAccount(account);//should be closed already
    // openAccount(amount); //1000
    // openAccount(10000); //
    // interest(40);// should be 1400 and 14000
    // print();
    // closeAll();
    // print();