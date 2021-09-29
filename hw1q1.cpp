#include <iostream>
#include<string>
using namespace std;

struct Check     //defining struct called Check
{
    int CheckNum;      //declaring Checknum
    float CheckAmount;
    string CheckMemo;
};

class Checkbook      //defining Checkbook class
{
public:
    Checkbook();                       //class declaration
    Checkbook(float bal);              //defining class
    void deposit(float amount);         //saying that this class will have method to display
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
    for(int i=0; i<5; i++){   //loop from i=0 to i=4
        cb1.writeCheck(120);  //calling writeCheck method for cb1
    }
    cout<<"cb1 details"<<endl;  //outputting details of cb1
    cb1.displayChecks();       //calling displayChecks


    return 0;
}


Checkbook::Checkbook()
{
    balance=0;           //initializing both to 0
    numOfChecks=0;
}

Checkbook::Checkbook(float bal)
{
    balance=bal;      //defining overloaded constructor
    numOfChecks=0;
}

void Checkbook::deposit(float amount) //defining deposit
{
    balance+=amount;      //adding amount(parameter) to balance
    lastDeposit=amount;   //setting lastDeposit to the amount(parameter)
}

bool Checkbook::writeCheck(float amount)  //defining writeChecks methods
{

    if (amount <= balance){    // if the amount is <=balance
        Check check1;          //declaring check1
        string userinput;       //declaring user input variable
        cout<<"memo? "<<endl;   //displaying "memo?"
        cin>>userinput;         //getting user input and storing in userinput variable
        check1.CheckMemo=userinput;  //setting checkMemo attribute to userinput
        check1.CheckNum=numOfChecks; //setting Checknum attribute to numofchecks
        check1.CheckAmount=amount;  //sets checkamount attribute to amount
        CheckArray[numOfChecks]=check1; //setting CheckArray at index of numofChecks to check1
        numOfChecks++;  //incrementing num of checks by 1
        balance-=amount;   //subtracting amount from the balance
        return true;
    }

    else{
        return false;  //else return false
    }
}

void Checkbook::displayChecks() {  //defining displayChecks method
    for(int i=numOfChecks-1; i>=0; i--){    //loop through checkarray
        cout<<CheckArray[i].CheckAmount<< " "<< CheckArray[i].CheckNum<< " "<< CheckArray[i].CheckMemo<<endl;
    }  //outputting/displaying details
}

