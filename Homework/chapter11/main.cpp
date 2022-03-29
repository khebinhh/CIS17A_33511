#include <iostream>
using namespace std;

struct Account{
    string userName, address, city, state, zip, telephoneNum;
    double balance;
    string dateofLastPayment;
};

void showMainMenu(cont unsigned);
void showModifyMenue();
void addAccount(Account[], const unsigned, unsigned&);
void modifyAccount(Account[], const unsigned);
void displayAccounts(Account[], const unsigned);
void setName(Account&);
void setAddress(Account&);
void setCity(Account&);
void setState(Account&);
void setZIP(Account&);
void setTelephone(Account&);
void setBalance(Account&);
void setDateOfLastPayment(Account&);

string getOrdinal(const unsigned);
bool isEmpty(const string);

int main(){
    const unsigned MA = 10;
    Account customers[MAX];
}

void showMainMenu(const unsigned numCustomers){
    
}