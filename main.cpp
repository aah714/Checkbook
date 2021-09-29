#include <iostream>
#include<string>
using namespace std;

struct Check     //defining Check struct
{
    int CheckNum;
    float CheckAmount;
    string CheckMemo;
};

class Checkbook      //defining Checkbook class
{
public:
    Checkbook();
    Checkbook(float bal);
    void deposit(float amount);
    void displayChecks();
    bool writeCheck(float amount);
private:
    int balance;
    static const int n= 5;
    Check CheckArray[n];
    int numOfChecks;
    float lastDeposit;
    int checkLimit=n; // sets checkLimit to variable n


};

int main() {
    Checkbook cb1(1000); //initializing cb1 with $1000 for the balance
    for(int i=0; i<5; i++){
        cb1.writeCheck(120);
    }
    cout<<"cb1 details"<<endl;
    cb1.displayChecks();


    return 0;
}


Checkbook::Checkbook()
{
    balance=0;
    numOfChecks=0;
}

Checkbook::Checkbook(float bal)
{
    balance=bal;
    numOfChecks=0;
}

void Checkbook::deposit(float amount)
{
    balance+=amount;
    lastDeposit=amount;
}

bool Checkbook::writeCheck(float amount)
{

    if (amount <= balance){
        Check check1;
        string userinput;
        cout<<"memo? "<<endl;
        cin>>userinput;
        check1.CheckMemo=userinput;
        check1.CheckNum=numOfChecks;
        check1.CheckAmount=amount;
        CheckArray[numOfChecks]=check1;
        numOfChecks++;
        balance-=amount;
        return true;
    }

    else{
        return false;
    }
}

void Checkbook::displayChecks() {
    for(int i=numOfChecks-1; i>=0; i--){
        cout<<CheckArray[i].CheckAmount<< " "<< CheckArray[i].CheckNum<< " "<< CheckArray[i].CheckMemo<<endl;
    }
}

