#include<iostream>
using namespace std;
#include<conio.h>
#include<string>

class atm{

    private :
    long int Account_No ;
    string Name;
    int PIN;
    double Balance;
    string Mobile_No;

    public :

    void setData(long int Account_No_a, string Name_a, int PIN_a, double Balance_a, string Mobile_No_a){

        Account_No = Account_No_a;
        Name= Name_a;
        PIN = PIN_a;
        Balance= Balance_a;
        Mobile_No= Mobile_No_a;

    }

    long int getAccount_No(){
        return Account_No;
    }

    string getName(){
        return Name;
    }

    int getPIN(){
        return PIN;
    }

    double getBalance(){
        return Balance;
    }

    string getMobileNo(){
        return Mobile_No;
    }

    void setMobile(string mob_prev, string mob_new){
        if(mob_prev==Mobile_No){
            Mobile_No = mob_new;

            cout<<endl<<"Successfully Update Mobile No.";
            _getch();
        }
        else{
            cout<<"Incorrect Old Mobile No.";
            _getch();
        }
    }

    void cashWithDraw(int amount_a){
        if(amount_a>0 && amount_a<Balance){
            Balance -= amount_a;
            cout<<"Please Collect Your Cash"<<endl;
            cout<<"Available Balance : "<<Balance<<endl;
            _getch();

        }

        else{
                cout<<"Invalid Input or Insufficent Balance"<<endl;
                getch();
        }
    }


}; 

int main(){

    int choice =0, EnterPIN;
    long int EnterAccountNo;

    system("cls");

    atm user1;

    user1.setData(123456789, "AMAN SINGH KANDARI", 1234, 125000.85, "9876543210");

    do
    {
       system("cls");

       cout<<"----> WELCOME TO ATM <----" <<endl;
       cout<<"Enter Your Account No : ";
       cin>>EnterAccountNo;

       cout<<endl;
       cout<<"Enter PIN : ";
       cin>> EnterPIN;

       if( (EnterAccountNo == user1.getAccount_No()) && EnterPIN == user1.getPIN()){

        do
        {
            int amount=0;
            string oldMobileNo, newMobileNo;

            system("cls");

            cout<<endl;
            cout<<"------> WELCOME TO ATM <-------"<<endl;
            cout<<endl;
            cout<<"Select Options "<<endl;
            cout<<"1. Check Balance"<<endl;
            cout<<"2. Cash Withdraw"<<endl;
            cout<<"3. Show User Details"<<endl;
            cout<<"4. Update Mobile No."<<endl;
            cout<<"5. Exit"<<endl;
            cin>>choice;

            switch (choice)
            {
            case 1:
                cout<<"Your Bank balance is : "<<user1.getBalance()<<endl;

                _getch();
                break;
            
            case 2:
                cout<<"Enter the amount : "<<endl;
                cin>>amount;
                user1.cashWithDraw(amount);

                break;

            case 3:
                cout<<"----> User Details are :- "<<endl;
                cout<<"--> Account No : "<<user1.getAccount_No()<<endl;
                cout<<"--> Name : "<<user1.getName()<<endl;
                cout<<"--> Balance : "<<user1.getBalance()<<endl;
                cout<<"--> Mobile No. :"<<user1.getMobileNo()<<endl;

                _getch();
                break;

            case 4:
                cout<<"Enter Old Mobile No. : ";
                cin>> oldMobileNo;
                cout<<endl;

                cout<<"Enter New Mobile No. : ";
                cin>> newMobileNo;
                cout<<endl;

                user1.setMobile(oldMobileNo, newMobileNo);
                break;

            case 5:
            exit(0);


            default:
                cout<<"Enter Valid Data !!!";


            }
        } while (1);
        
       }

       else{
        cout<<"User Details are Invalid !!!";
        getch(); 
       }


    } while (1);

    return 0;  
}