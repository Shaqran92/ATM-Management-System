#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

void Menu();
void checkBalance(double balance);
double deposit(double balance);
double withdraw(double balance);
double transfer(double balance);

int main(){
	string name , CNIC;
do{	
    double accountBalance = 10000;   
    cout << "*************  Welcome to SoftI Bank  *************" << endl;
    cout << "\n\n         Create an Account to use SoftI Bank" << endl;
    cout<<"\nEnter Your Name : ";
    getline(cin , name);
    cout<<"\nEnter your 13 digit CNIC Number : ";
    cin>>CNIC;
    if(CNIC.size()==13){
        int day , month , year , card , trans , option;
        string pin_1 , pin_2;
        cout<<"\nEnter your date of birth (DD/MM/YYYY)"<<endl;
        cout<<"Enter Day : ";
        cin>>day;
        cout<<"Enter Month : ";
        cin>>month;
        cout<<"Enter Years : ";
        cin>>year;
        if(day<0 || day>31){
            cout<<"Invalid Days"<<endl;
        }
        else if(month<0 || month>12){
            cout<<"Invalid Month"<<endl;
        }
        else{
            cout<<"\nCreate your 5 digit PIN : ";
            cin>>pin_1;
            if(pin_1.size()<5 || pin_1.size()>5){
                cout<<"Invalid size of PIN"<<endl;
            }
            else if(pin_1.size()==5){
                cout<<"\nRe-Enter your 5 digit PIN : ";
                cin>>pin_2;
            }
            cout<<"\nCongratulations Your Bank Account is been created"<<endl;
            cout<<"\nDo you want to Activate your ATM card"<<endl<<"1. Yes"<<endl<<"2. NO"<<endl;
            cin>>card;
            if(card != 1){
                exit(0);
            }
            else if(card == 1){
                cout<<"|| Congratulation Your card is been Activated ||"<<endl;
                cout<<"\n          Your Account Information Is"<<endl;
                cout<<"\n*************Welcome to SoftI Bank*************"<<endl;
                cout<<"\n           Name : "<<name<<endl;
                cout<<"           CNIC : "<<CNIC<<endl;
                cout<<"           Date of Birth : "<<day<<"/"<<month<<"/"<<year<<endl;
                cout<<"\n***********************************************"<<endl;
            }
            cout<<"\nYou have Rs : 10000 of Initial Balance"<<endl;
            cout<<"\nDo you want to perform Transaction"<<endl<<"1. Yes"<<endl<<"2. No"<<endl;
            cin>>trans;
            if(trans == 1){
            	char option_1;
                do {
                    Menu();
                    cout << "\nEnter your Choice: ";
                    cin >> option_1;
                    switch (option_1) {
                        case '1':
                            checkBalance(accountBalance);
                            break;
                        case '2':
                            accountBalance = deposit(accountBalance);
                            break;
                        case '3':
                            accountBalance = withdraw(accountBalance);
                            break;
                        case '4':
                            accountBalance = transfer(accountBalance);
                            break;
                        case '5':
                            cout << "Thank you for using the ATM. Goodbye!\n";
                            break;
                        default :
                            cout << "Invalid choice. Please try again.\n";
                    }
                } while (option_1 != '5');
                if(option_1 == '5'){
                	exit(0);
				}
            }
            else if(trans == 2){
                exit(0);
            }
        }    
    }
    else if(CNIC.size()<13 || CNIC.size()>13){
        cout<<"Invalid CNIC Number"<<endl;
    }
} while (CNIC != "0");
return 0;
}
void Menu() {
	cout << "\n***      Welcome to SoftI ATM      ***\n"<<endl;
    cout << "\n      ***        Menu        ***\n"<<endl;
    cout << "      *    1. Check Balance    *\n";
    cout << "      *    2. Deposit          *\n";
    cout << "      *    3. Withdraw         *\n";
    cout << "      *    4. Transfer         *\n";
    cout << "      *    5. Exit             *\n";
}
void checkBalance(double balance) {
    cout << fixed << setprecision(2);
    cout << "\nYour account balance is: Rs. " << balance << endl;
}
double deposit(double balance) {
    double amount;
    cout << "\nEnter amount to Deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "\nDeposit successful. Your new balance is: Rs. " << balance << endl;
    } else {
        cout << "\nInvalid Deposit amount. Please enter a positive value.\n";
    }
    return balance;
}
double withdraw(double balance) {
    double amount;
    cout << "\nEnter amount to Withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "\nWithdrawal successful. Your new balance is: Rs. " << balance << endl;
    } else if (amount <= 0) {
        cout << "\nInvalid withdrawal amount. Please enter a positive value.\n";
    } else {
        cout << "\nInsufficient Funds. Withdrawal not allowed.\n";
    }
    return balance;
}
double transfer(double balance) {
    double amount;
    string name_1;
    cout << "\nWhere you want to Transfer Money";
    cout << "\nEnter Name : ";
    cin >> name_1;
    cout << "\nEnter amount to transfer : ";
    cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "\nMoney Transfered to : " << name_1 << endl;
        cout << "Rs. " << amount << " Has been Transfered to : " << name_1 <<" Succesfully" << endl;
        cout << "\nYour new balance is : Rs. " << balance << endl;
    }
    else if (amount <= 0) {
        cout << "\nInvalid transfer amount. Please enter a positive value.\n";
    }
    else {
        cout << "\nInsufficient funds. tranfer not allowed.\n";
    }
    return balance; 
}