#include "myBank.h"
#include <stdio.h>
#define accountRange 901
/* set array of double values.
first demantion for money account=[0] and account mode=[1] (0=close, 1=open).
second demantion for number of accounts */
double accountArr [][50] ={{0,0},{0}};
void openAccount (double firstAmount)
{
    if (checkAmount(firstAmount))
    {  
    firstAmount*=100;
    firstAmount=(int)firstAmount;
    firstAmount/=100;
    for (int i = 0; i < 50; i++)
    {
        if(accountArr[1][i]==0)
        {
            accountArr[1][i]=1;
            accountArr[0][i]=firstAmount;
            int account_number=i+accountRange;
            printf("The account number %d is opened \n", account_number);
            break;
        }
        if(i==49) printf("No accounts available \n");
    }
    }
    else{printf("The amount must be positive \n");}
}
void checkBalance (int account_number)
{
    if(checkAccount(account_number))
    {
    int n=account_number-accountRange;
    if(accountArr[1][n]==0)printf("Account number %d is closed \n", account_number);
    else
    {
        double amount=accountArr[0][n];
        printf("The balance in account number %d is %0.2f \n", account_number, amount);
    }
    }
    else{printf("The acount does not exist \n");}
}
void deposit(int account_number, double amount)
{
    if(checkAccount(account_number)&&checkAmount(amount))
    {
    int n=account_number-accountRange;
    if(accountArr[1][n]==0)printf("Account number %d is closed \n", account_number);
    else
    {
        accountArr[0][n]+=amount;
        checkBalance(account_number);
    }
    }
    else{printf("The amount must be positive, or acount does not exist \n");}

}
void withdrawal(int account_number, double amount)
{
    if(checkAccount(account_number)&&checkAmount(amount))
    {
    amount*=100;
    amount=(int)amount;
    amount/=100;
    int n=account_number-accountRange;
    if(accountArr[1][n]==0)printf("Account number %d is closed \n", account_number);
    else
    {
        if(accountArr[0][n]<amount)printf("Not enough money in account number %d \n", account_number);
        else
        {
        accountArr[0][n]-=amount;
        checkBalance(account_number);
        }
    }
    }
    else{printf("The amount must be positive, or acount does not exist \n");}
}
void closeAccount(int account_number)
{
    if(checkAccount(account_number))
    {
    int n=account_number-accountRange;
    if(accountArr[1][n]==0)printf("Account number %d is already closed \n", account_number);
    else
    {
       accountArr[1][n]=0; // close the account
       accountArr[0][n]=0; // reset money;
       printf("Closing account number %d succeeded \n", account_number);
    }
    }
    else{printf("The acount does not exist \n");}
}
void interest(double percent)
{
    if (percent>=0)
    {
    for (int i=0;i<50;i++)
    {
        if(accountArr[1][i]==1)
        {
            double amount=accountArr[0][i]; 
            double interest_rate=amount*(percent/100); 
            deposit(i+accountRange,interest_rate);
        }
    }
    }
    else{printf("The percent must be positive \n");}
}
void print()
{
    for (int i = 0; i < 50; i++)
    {
        if(accountArr[1][i]==1)//if account is open
        {
            int n=accountRange+i;
            checkBalance(n);
        }
    }
}
void closeAll()
{
    for(int i=0;i<50;i++)
    {
        if(accountArr[1][i]==1)//if account is open
        {
            int n=accountRange+i;
            closeAccount(n);
        }
    }
    printf("\n Bye bye! \n");
}
