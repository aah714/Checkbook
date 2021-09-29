#include <iostream>
#include<string>
using namespace std;

//struct Check                  <-----from Q1 but commented out
//{
//    int CheckNum;
//    float CheckAmount;
//    string CheckMemo;
//};

class Check   //defining Check class
{   public:
        Check();            //default
        int getCheckNum();
        float getCheckAmount();
        string getCheckMemo();
        void setCheckNum(int number);       //updates checkNum with number entered
        void setCheckAmount(float amount);  //updates checkAmount with the amount entered
        void setCheckMemo(string memo);     //updates checkMemo with memo entered
    private:
        int CheckNum;
        float CheckAmount;
        string CheckMemo;

};

class Checkbook
{
public:
    Checkbook();
    Checkbook(float bal);
    void deposit(float amount);   //passing by reference--giving address of variable
    void displayChecks();           //passing by reference
    bool writeCheck(float amount);
    static int getallChecks();
private:
    int balance;
    static const int n= 5;
    Check CheckArray[n];
    int numOfChecks;
    float lastDeposit;
    int checkLimit=n;
    static int allChecks;




};

int Checkbook::allChecks=0;


int main() {  //this is function because of the ()
    Checkbook cb1(1000), cb2(500);
    for(int i=0; i<10; i++){
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout<<"cb1 check details"<<endl;
    cb1.displayChecks();
    cout<<"cb2 check details"<<endl;
    cb2.displayChecks();

    cout<<cb1.getallChecks()<<endl;
    cout<<cb2.getallChecks()<<endl;


    return 0;
}



Check::Check(){
    CheckNum=0;
    CheckMemo="";
    CheckAmount=0;
}

int Check::getCheckNum() {
    return CheckNum;
}

float Check::getCheckAmount() {
    return CheckAmount;
}

string Check::getCheckMemo() {
    return CheckMemo;
}

void Check::setCheckAmount(float amount) {
    CheckAmount=amount;
}

void Check::setCheckNum(int number) {
    CheckNum=number;
}

void Check::setCheckMemo(string memo) {
    CheckMemo=memo;
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

    if (amount <= balance&& numOfChecks < n && allChecks < 10){
        Check check1;
        string userinput;
        cout<<"memo? "<<endl;
        cin>>userinput;
        check1.setCheckMemo(userinput);
        check1.setCheckNum(numOfChecks);
        check1.setCheckAmount(amount);
        CheckArray[numOfChecks]=check1;
        numOfChecks++;
        balance-=amount;
        allChecks++;
        return true;
    }

    else{
        return false;
    }
}

void Checkbook::displayChecks() {
    for(int i=numOfChecks-1; i>=0; i--){
        cout<<CheckArray[i].getCheckAmount()<< " "<< CheckArray[i].getCheckNum()<< " "<< CheckArray[i].getCheckMemo()<<endl;
    }
}

int Checkbook::getallChecks() {
    return allChecks;
}
