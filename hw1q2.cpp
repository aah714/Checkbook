#include <iostream>
#include<string>
using namespace std;

//struct Check                  <-----from Q1 but commented out
//{
//    int CheckNum;
//    float CheckAmount;
//    string CheckMemo;
//};

class Check   //declaring Check class
{   public:
        Check();            //default
        int getCheckNum();
        float getCheckAmount();
        string getCheckMemo();
        void setCheckNum(int number);       //updates checkNum with number entered
        void setCheckAmount(float amount);  //updates checkAmount with the amount entered
        void setCheckMemo(string memo);     //updates checkMemo with memo entered
    private:
        int CheckNum;    //declaring CheckNum
        float CheckAmount;  //declaring CheckAmount
        string CheckMemo;   //declaring CheckMemo

};

class Checkbook     //declaring class called Checkbook
{
public:
    Checkbook();
    Checkbook(float bal);
    void deposit(float amount);     //passing by reference--giving address of variable
    void displayChecks();           //passing by reference
    bool writeCheck(float amount);
    static int getallChecks();   //returns variable for allchecks
private:
    int balance;
    static const int n= 5;
    Check CheckArray[n];
    int numOfChecks;
    float lastDeposit;
    int checkLimit=n;
    static int allChecks;  //static means variable pertaining to the class
                           //keeps track of how many checks are creating in the entire program



};

int Checkbook::allChecks=0;  //initializing static variable to 0


int main() {  //this is function because of the ()
    Checkbook cb1(1000), cb2(500);  //creating object of Checkbook called cb1 and cb2 with balances of 100 and 500
    for(int i=0; i<10; i++){   //loop from 0 up to 10
        cb1.writeCheck(150);  //calling writeChecks on cb1
        cb2.writeCheck(130);  //calling writechecks on cb2
    }
    cout<<"cb1 check details"<<endl;   //displaying string
    cb1.displayChecks();               //calling displayChecks for cb1
    cout<<"cb2 check details"<<endl;   //displaying string detrails
    cb2.displayChecks();                //calling displayChecks for cb2

    cout<<cb1.getallChecks()<<endl;  //calling getallchecks method and displaying the result
    cout<<cb2.getallChecks()<<endl;


    return 0;
}


                   //defining constructor
Check::Check(){            //initializing CheckNum to 0
    CheckNum=0;            //initializing checkMemo to an empty string
    CheckMemo="";         //initializing checkAmount to 0
    CheckAmount=0;
}

int Check::getCheckNum() {  //defining checknum
    return CheckNum;       //returning checknum
}

float Check::getCheckAmount() {
    return CheckAmount;
}

string Check::getCheckMemo() {
    return CheckMemo;
}

void Check::setCheckAmount(float amount) {  //setting checkamount to amount passed
    CheckAmount=amount;
}

void Check::setCheckNum(int number) {
    CheckNum=number;
}

void Check::setCheckMemo(string memo) {
    CheckMemo=memo;
}

Checkbook::Checkbook() //defining default constructor
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

bool Checkbook::writeCheck(float amount)  //
{

    if (amount <= balance&& numOfChecks < n && allChecks < 10){
        Check check1;                 //declaring object of Check - check1
        string userinput;             //declaring a userinput variable
        cout<<"memo? "<<endl;         //getting user input for memo and storing in
        cin>>userinput;                // -userinput variable
        check1.setCheckMemo(userinput);   //calling setcheckMemo for check1 and passing in userinput
        check1.setCheckNum(numOfChecks);          //calling setchecknum and passing in numofchecks
        check1.setCheckAmount(amount);           //calling setcheckamount and passing in amount
        CheckArray[numOfChecks]=check1;          //setting checkArray at index numofchecks=check1 object
        numOfChecks++;                         //incrementing num of checks
        balance-=amount;                      //subracting amount from balance
        allChecks++;                           //incrememnting all checks
        return true;
    }

    else{
        return false;
    }
}

void Checkbook::displayChecks() { //defining displayChecks
    for(int i=numOfChecks-1; i>=0; i--){   //loop through checkARray
        cout<<CheckArray[i].getCheckAmount()<< " "<< CheckArray[i].getCheckNum()<< " "<< CheckArray[i].getCheckMemo()<<endl;
    }  //displays check array details in output
}

int Checkbook::getallChecks() {
    return allChecks;   //returns allChecks
}
