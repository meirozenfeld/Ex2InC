#ifndef _myBank_h_
#define _myBank_h_
void openAccount (double firstAmount);
void checkBalance (int account_number);
void deposit (int account_number, double amount);
void withdrawal (int account_number, double amount);
void closeAccount (int account_number);
void interest(double percent);
void print();
void closeAll();
int checkAccount(int account_number);
int checkAmount(double amount);
#endif
