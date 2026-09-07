#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;


class Transaction{
public:

    string transection_id = "";
    string trasfer_account = "";
    string reciver_account = "";
    int amount=0;
    string date = "";
    string transfer_account_type = "";
    string reciver_account_type = "";
    double balance = 0.0;

    Transaction(){
        transection_id = "";
         trasfer_account = "";
         reciver_account = "";
         date = "";
         balance = 0.0;
         transfer_account_type = "";
         reciver_account_type = "";
    }

    void add_info(string transection_id,string trasfer_account,string reciver_account,int amount,string date,string transfer_account_type,string reciver_account_type,double balance){

        this->transection_id = transection_id;
        this->trasfer_account = trasfer_account;
        this->reciver_account = reciver_account;
        this->amount = amount;
        this->date = date;
        this->transfer_account_type = transfer_account_type;
        this->reciver_account_type = reciver_account_type;
        this->balance = balance;

    }

    void get_info(){

        cout<<"Transection ID : "<<transection_id<<endl<<endl;
        cout<<"Trasfer Account : "<<trasfer_account<<endl;
        cout<<"Reciver Account : "<<reciver_account<<endl;
        cout<<"Date : "<<date<<endl;
        cout<<"Tranfer Account Type : "<<transfer_account_type<<endl;
        cout<<"Reciver Account Type : "<<reciver_account_type<<endl<<endl;
        cout<<"Transfer Amount : "<<amount<<endl;
        cout<<"Remaining Balance : "<<balance<<endl<<endl;
    }

};



class Account{
public:
    string account_number = "";
    string account_type = "";
    string mpin = "";
    string phone = "";
    double balance = 0;

    Account(){
         account_number = "";
         account_type = "";
         mpin = "";
         phone = "";
         balance = 0;
    }
    void add_info(string account_number , string account_type , string mpin , string phone , double balance){
        this->account_number = account_number;
        this->account_type = account_type;
        this->mpin = mpin;
        this->phone = phone;
        this->balance = balance;
    }
    void get_info(){
        cout<<"\nAccount Number : "<<account_number<<endl;
        cout<<"Account Type : "<<account_type<<endl;
        cout<<"MPIN : "<<mpin<<endl;
        cout<<"Phone : "<<phone<<endl;
        cout<<"Balance : "<<balance<<endl<<endl;
    }

};



class Customer{
public:
    string name = "";
    string id = "";
    Account accounts[2];
    Transaction transections[10];
    int account_counter = 0;
    int transection_counter = 0;

    Customer(){
        name = "";
        id = "";
        
    }
    void add_info(string name , string id){
        this->name = name;
        this->id = id;
        
    }
    void get_info(){
        cout<<"Customer Name : "<<name<<endl;
        cout<<"Customer ID : "<<id<<endl<<endl;
        
    }


};



class Bank{
public:
    Customer customers[100];
    int customer_counter = 0;
    int current_c_idx = -1;
    int transection_num = 1001;
  

    void registration_portal(){

        if(customer_counter == 100){
            cout<<"\nRegistration limit Exeeded !\n\n";
            return;
        }

        bool valid_name = false;
        string name = "";

        while(true){

            name = "";

            cout << "Enter Your Name : ";
            getline(cin, name);

            int space_counter = 0;
            bool uppercase = false;
            bool valid = true;

            // Size
            if(name.size() < 6 || name.size() > 15){
                cout << "Name must be between 6 and 15 characters.\n\n";
                continue;
            }

            // Characters + uppercase + spaces
            for(int i = 0; i < name.size(); i++){

                if(isalpha(name[i])){
                    if(isupper(name[i]))
                        uppercase = true;
                }
                else if(name[i] == ' '){
                    space_counter++;
                }
                else{
                    valid = false;
                    break;
                }
            }

            if(!valid){
                cout << "Only alphabets and spaces are allowed.\n\n";
                continue;
            }

            // Space
            if(space_counter == 0){
                cout << "Space is required in name.\n\n";
                continue;
            }

            if(space_counter > 2){
                cout << "Maximum 2 spaces are allowed.\n\n";
                continue;
            }

            // Uppercase
            if(!uppercase){
                cout << "At least one uppercase letter is required.\n\n";
                continue;
            }

            valid_name = true;
            break;
        }

        // Customer ID
        string id = "";
        while(true){

            cout << "Enter your Customer ID : ";
            cin >> id;

            // Length must be 7
            if(id.size() != 7){
                cout << "\nCustomer ID must be like CUS1001\n\n";
                continue;
            }

            if(id[0] != 'C' || id[1] != 'U' || id[2] != 'S'){
                cout << "\nInvalid format! Use CUSXXXX\n\n";
                continue;
            }

            bool valid = true;

            for(int i = 3; i < 7; i++){
                if(!isdigit(id[i])){
                    valid = false;
                    break;
                }
            }

            if(!valid){
                cout << "\nLast 4 characters must be digits!\n\n";
                continue;
            }

            // Check duplicate ID
            bool already_exists = false;

            for(int i = 0; i < customer_counter; i++){
                if(customers[i].id == id){
                    already_exists = true;
                    break;
                }
            }

            if(already_exists){
                cout << "\nThis Customer ID is already registered!\n\n";
                continue;
            }

            break;
        }
        customers[customer_counter].add_info(name , id);
        customer_counter++;
        cout<<"\n\n------------------------------------------------------\n\n";
        cout<<"Registration is Successful !\n\n";

    }

    void login_portal(){

        string name = "";
        string id = "";
        bool c_found = false;
        
        cout<<"Enter your Name : ";
        getline(cin , name);
        cout<<"\nEnter your ID : ";
        getline(cin , id);

        for(int i=0; i<customer_counter; i++){
            if(customers[i].name == name && customers[i].id == id){
                c_found = true;
                current_c_idx = i;
            }
        }

        cout<<"\n\n------------------------------------------------------\n\n";
        if(c_found){

            cout<<"Login is Successful !\n\n";
            //cin.ignore(1000 , '\n');
            system("pause");
            system("cls");
            costumer_manu();
        }
        else{
            cout<<"Name or Id is wrong !\n\n";
        }
    }

    void costumer_manu(){
        while(true){

            int choise = 0;
            cout<<"------------------ Customer Manu ----------------\n\n";
            cout<<"1). Create Account\n";
            cout<<"2). View Account\n";
            cout<<"3). Deposit\n";
            cout<<"4). Withdraw\n";
            cout<<"5). Transfer\n";
            cout<<"6). Transaction History\n";
            cout<<"7). Logout\n";
            cout<<"Choise : ";
            cin>>choise;

            switch(choise){
                case 1:
                    system("cls");
                    cout<<"----------------- Create Account -----------------\n\n";
                    cin.ignore(1000 , '\n');
                    create_account();
                    system("pause");
                    system("cls");
                    break;
                
                case 2:
                    system("cls");
                    cout<<"----------------- View Account -----------------\n\n";
                    cin.ignore(1000 , '\n');
                    view_account();
                    system("pause");
                    system("cls");
                    break;
                
                case 3:
                    system("cls");
                    cout<<"----------------- Deposit Account -----------------\n\n";
                    cin.ignore(1000 , '\n');
                    deposit();
                    system("pause");
                    system("cls");
                    break;

                case 4:
                    system("cls");
                    cout<<"----------------- Withdrow Amount -----------------\n\n";
                    cin.ignore(1000 , '\n');
                    Withdraw();
                    system("pause");
                    system("cls");
                    break;

                case 5:
                    system("cls");
                    cout<<"----------------- Transfer Amount -----------------\n\n";
                    //cin.ignore(1000 , '\n');
                    transfer();
                    system("pause");
                    system("cls");
                    break;

                case 6:
                    system("cls");
                    cout<<"----------------- Transection History -----------------\n\n";
                    cin.ignore(1000 , '\n');
                    transfer_history();
                    system("pause");
                    system("cls");
                    break;

                case 7:
                    cout<<"\n\n------------------------------------------------------\n\n";
                    cout<<"Logout Successful ! \n\n";
                    return ; 
                    
                default:
                    cout<<"\n\nInvalid choise !\n";

            }

        }
    }

    void create_account(){

        string account_number = "";
        string account_type = "";
        string mpin = "";
        string phone = "";
        double balance = 0;
        int choise = 0;
        bool valid = true;

        while(true){

            if(customers[current_c_idx].account_counter == 2){
                cout<<"Customer can't create more then 2 accounts.\n\n";
                break;
            }
            //account number
            while(true){
                cout<<"Create Account Number : ";
                cin>>account_number;

                if(account_number.size() != 6){
                    cout<<"\n\n Account must be like AC1001";
                    continue;
                }
                if(account_number[0] != 'A' || account_number[1] != 'C'){
                    cout<<"\n\n Invalid Formate : \n";
                    cout<<"Use ACXXXX";
                    continue;
                }

                valid = true;

                for(int i = 2; i < 6; i++){
                    if(!isdigit(account_number[i])){
                        valid = false;
                        break;
                    }
                }

                if(!valid){
                    cout << "\nLast 4 characters must be digits!\n\n";
                    continue;
                }

                
                for(int i = 0; i < customer_counter; i++){

                    for(int j = 0; j < customers[i].account_counter; j++){

                        if(account_number == customers[i].accounts[j].account_number){
                            cout<<"\n\nThis Account is already created ! \n\n";
                            return;
                        }

                    }
                }

                break;
            }

            //account type
            while(true){
                cout<<"Account type : ";
                cout<<"\n\n1). Business";
                cout<<"\n2). Saving\n";
                cout<<"Choise : ";
                cin>>choise;

                if(choise == 1) account_type = "Business";
                else if(choise == 2) account_type = "Saving";
                else cout<<"\n\nInvalid choise !\n\n";

                if(choise == 1 || choise == 2){
                    break;
                }
            }

            //MPIN
            
            while(true){

                valid = true;
                cout<<"Create MPIN : ";
                cin>>mpin;

                if(mpin.size() != 4){
                    cout<<"\n\nExactly 4 Digits are allowed\n\n";
                    continue;
                }
                if(mpin == "0000"){
                    cout<<"\n\nInvalied MPIN ! \n\n";
                    continue;
                }
                for(int i=0; i<mpin.size(); i++){
                    if(!isdigit(mpin[i])){
                        valid = false;
                    }
                }
                if(!valid){
                    cout << "\n\nOnly Digits are allowed!\n\n";
                    continue;
                }

                break;
            }

            //phone
            valid = true;

            while(true){
                cout<<"Enter Phone number : ";
                cin>>phone;

                if(phone.size() != 11){
                    cout<<"\n\n Use exactly 11 Digits ! \n\n";
                    continue;
                }
                
                // if(phone == "0300000000000"){
                //     cout<<"\n\nInvalied MPIN ! \n\n";
                //     continue;
                // }
                // it can be posible 

                if(phone[0] != '0' || phone[1] != '3'){
                    cout<<"\n\nUse valid format : ";
                    cout<<"03XXXXXXXXX\n\n";
                    continue;
                }
                for(int i=0; i<phone.size(); i++){
                    if(!isdigit(phone[i])){
                        valid = false;
                    }
                }
                if(!valid){
                    cout << "\n\nOnly Digits are allowed!\n\n";
                    continue;
                }

                break;

            }

            while(true){

                cout << "Balance : ";
                cin >> balance;

                if(balance < 0){
                    cout << "\n\nBalance cannot be negative!\n\n";
                    continue;
                }

                if(account_type == "Saving" && balance < 1000){
                    cout << "\n\nSaving Account requires minimum Rs. 1000!\n\n";
                    continue;
                }

                if(account_type == "Business" && balance < 10000){
                    cout << "\n\nBusiness Account requires minimum Rs. 10000!\n\n";
                    continue;
                }

                break;
            }

            
            customers[current_c_idx].accounts[customers[current_c_idx].account_counter].add_info(account_number, account_type, mpin, phone, balance);
            //it means customer class->account->counter->add_info.
            customers[current_c_idx].account_counter++;
            
            cout<<"\n\n------------------------------------------------------\n\n";
            cout<<"Account Created Successfully !\n\n";
            //system("pause");
            //system("cls");
            break;
           
        }
    }

    void view_account(){

        //if no account is created yet
        if(customers[current_c_idx].account_counter == 0){
            cout << "\nNo account found.\n\n";
            return;
        }

        int choise = 0;

        if(customers[current_c_idx].account_counter == 1){
            customers[current_c_idx].accounts[0].get_info();
            return;
        }
        cout<<"Account 1 : ";
        cout<<"\nAccount 2 : \n\n";
        cout<<"Choise : ";
        cin>>choise;

        switch(choise){
            case 1:
                system("cls");
                cout<<"----------------- Account-1 -----------------\n\n";
                customers[current_c_idx].accounts[0].get_info();
                break;
            case 2:
                system("cls");
                cout<<"----------------- Account-2 -----------------\n\n";
                customers[current_c_idx].accounts[1].get_info();
                break;
            default:
                cout<<"\n\nInvalid choise !\n";
        }
    } 

    void Withdraw(){

        //if no account is created yet
        if(customers[current_c_idx].account_counter == 0){
            cout << "\nNo account found.\n\n";
            return;
        }

        string account_number ="";
        string mpin ="";
        int account_idx =0;
        bool account_found = false;
        int amount = 0;

        cout<<"Enter Account number : ";
        cin>>account_number;
        cout<<"Enter MPIN : ";
        cin>>mpin;

        for(int i = 0; i<2; i++){
            if(account_number == customers[current_c_idx].accounts[i].account_number && mpin == customers[current_c_idx].accounts[i].mpin){
                account_found = true;
                account_idx =i;
                break;
            }
        }
        
        if(account_found){

            cout << "\nEnter amount : ";
            cin >> amount;

            if(amount <= 0){
                cout << "Amount must be greater than 0!\n";
                return;
            }

            if(customers[current_c_idx].accounts[account_idx].balance < amount){
                cout << "\nInsufficient balance ! \n\n";
                return;
            }

            customers[current_c_idx].accounts[account_idx].balance -= amount;

            cout << "\n\n------------------------------------------------------\n\n";
            cout << "Money Withdraw Successfully !\n\n";

            return;
        }
        else{
            cout<<"Invalid Account or Mpin !\n\n";
            return;
        }
    }

    void deposit(){

        //if no account is created yet
        if(customers[current_c_idx].account_counter == 0){
            cout << "\nNo account found.\n\n";
            return;
        }

        string account_number ="";
        string mpin ="";
        int account_idx =0;
        bool account_found = false;
        int amount = 0;

        cout<<"Enter Account number : ";
        cin>>account_number;
        cout<<"Enter MPIN : ";
        cin>>mpin;

        for(int i = 0; i<2; i++){
            if(account_number == customers[current_c_idx].accounts[i].account_number && mpin == customers[current_c_idx].accounts[i].mpin){
                account_found = true;
                account_idx =i;
                break;
            }
        }
        
        if(account_found){

            cout<<endl<<"Enter amount : ";
            cin>>amount;

            if(amount <= 0){
                cout << "Amount must be greater than 0!\n";
                return;
            }
            customers[current_c_idx].accounts[account_idx].balance +=amount;

            cout<<"\n\n------------------------------------------------------\n\n";
            cout<<"Money Deposit Successfully !\n\n";
            //system("pause");
            //system("cls");1
            return;
        }
        else{
            cout<<"Invalid Account or Mpin !\n\n";
            return;
        }
    }

    void transfer(){

        //if no account is created yet
        if(customers[current_c_idx].account_counter == 0){
            cout << "\nNo account found.\n\n";
            return;
        }

        string account_number = "";
        string mpin = "";
        string other_a_number ="";
        int amount = 0;
        bool account_found = false;
        //t_account_found =0;
        int account_idx = 0;
        int customer_idx = 0;
        int current_account = 0;

        cin.ignore(1000, '\n');

        cout<<"Enter Your Account Number : ";
        getline(cin,account_number);
        cout<<"Enter MPIN : ";
        getline(cin,mpin);
        cout<<"Enter Trasfer Accunt Number : ";
        getline(cin,other_a_number);

        for(int i=0; i<2; i++){
            if(account_number == customers[current_c_idx].accounts[i].account_number && mpin == customers[current_c_idx].accounts[i].mpin){
                current_account = i;
                account_found = true;
                break;
            }
        }

        if(!account_found){

            cout<<"\n\n------------------------------------------------------\n\n";
            cout<<" Account number or MPIN is incorrect ! \n\n";
            return;
        }

        account_found = false;
        
        for(int i=0; i<customer_counter; i++){
            for(int j=0; j<customers[i].account_counter; j++){
                if(other_a_number == customers[i].accounts[j].account_number){
                    customer_idx = i;
                    account_idx = j;
                    account_found = true;
                    break;
                }
            }
        }

        if(!account_found){

            cout<<"\n\n------------------------------------------------------\n\n";
            cout<<" Transfer Account Not found ! \n\n";
            return;
        }

        if(account_number == other_a_number){

            cout << "You cannot transfer money to the same account!\n\n";
            return;
        }

        while(true){

            cout<<"\nEnter Amount : ";
            cin>>amount;
            
            if(amount <= 0){
                cout << "Amount must be greater than 0!\n";
                continue;
            }
            else if(amount < 500 ){
                cout<<"\n\nAccount is too low\n\n";
                continue;
            }
            else if(amount > 50000){
                cout<<"\n\nAmount is too high\n\n";
                continue;
            }
            else if(amount % 500 != 0){
                cout<<"Amount should be multiple of 500";
                continue;
            }

            if(customers[current_c_idx].accounts[current_account].account_type == "Saving" && customers[current_c_idx].accounts[current_account].balance - amount < 1000){
                cout << "Minimum balance of Rs. 1000 must be maintained!\n\n";
                return;
            }
            else if(customers[current_c_idx].accounts[current_account].account_type == "Business" && customers[current_c_idx].accounts[current_account].balance - amount < 10000){
                cout << "Minimum balance of Rs. 10,000 must be maintained!\n\n";
                return;
            }
            
            break;
        }

        if(customers[current_c_idx].accounts[current_account].balance >= amount){

            customers[customer_idx].accounts[account_idx].balance += amount;
            customers[current_c_idx].accounts[current_account].balance -= amount;

            //Transection ID creation

            //int transection_id = transection_id + to_string(customers[current_c_idx].transection_counter+1);
            string transection_id = "TXN-" + to_string(transection_num );
            transection_num ++;

             
            time_t now = time(0);
            string date = ctime(&now);

            //sender history
            customers[current_c_idx].transections[customers[current_c_idx].transection_counter].add_info(transection_id, customers[current_c_idx].accounts[current_account].account_number, customers[customer_idx].accounts[account_idx].account_number, amount,date, customers[current_c_idx].accounts[current_account].account_type, customers[customer_idx].accounts[account_idx].account_type, customers[current_c_idx].accounts[current_account].balance);
            customers[current_c_idx].transection_counter++;

            //reciver History
            if(current_c_idx != customer_idx){

                customers[customer_idx].transections[customers[customer_idx].transection_counter].add_info(transection_id, customers[current_c_idx].accounts[current_account].account_number, customers[customer_idx].accounts[account_idx].account_number, amount,date, customers[current_c_idx].accounts[current_account].account_type, customers[customer_idx].accounts[account_idx].account_type, customers[customer_idx].accounts[account_idx].balance);
                customers[customer_idx].transection_counter++;
            }

            cout<<"\n\n------------------------------------------------------\n\n";
            cout<<" Money Tranfered Successfully ! \n\n";
            cin.ignore(1000, '\n');
        }
        else{

            cout<<"\n\n------------------------------------------------------\n\n";
            cout<<" Your Balance is inshafisent ! \n\n";
            cin.ignore(1000, '\n');
        }

    }

    void transfer_history(){

        //if you made no transection in this account of this customer
        if(customers[current_c_idx].transection_counter==0){
            cout << "\n\nNo transaction history found.\n";
            cout << "You haven't made any transactions yet.\n\n";
            return;
        }

        int choise = 0;
        //cout<<"----------------- Transection History ---------------\n\n";
        cout<<"1). View All Transections\n";
        cout<<"2). Search by Transection ID\n";
        cout<<"Choise : ";
        cin>>choise;

        cin.ignore(1000, '\n');

        switch(choise){
            case 1:
                system("cls");
                cout<<"----------------- Transection History ---------------\n\n";
                view_transections();
                break;
            case 2:
                system("cls");
                cout<<"----------------- Transection History ---------------\n\n";
                search_transaction();
                break;

            default:
                cout<<"Invalid Chosie !";
                break;
        }

    }

    void view_transections(){

        for(int i=0; i<customers[current_c_idx].transection_counter; i++){

            customers[current_c_idx].transections[i].get_info();
            cout<<"\n\n---------------------------------------------\n\n";
        }
    }

    void search_transaction() {

        string id = "";

        cout << "Enter Transaction ID : ";
        cin >> id;

        bool found = false;

        for (int i = 0; i < customers[current_c_idx].transection_counter; i++) {

            if (customers[current_c_idx].transections[i].transection_id == id) {

                customers[current_c_idx].transections[i].get_info();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nTransaction ID not found!\n\n";
        }
    }

};


// MAIN

int main(){

    Bank bank;

    int choice;

    do
    {
        system("cls");
        cout<<"------------------ BANKING SYSTEM ----------------\n\n";
        cout << "1. Register Customer\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                system("cls");
                cout<<"-----------------Registration Portal-----------------\n\n";
                cin.ignore(1000 , '\n');
                bank.registration_portal();
                system("pause");
                break;

            case 2:
                system("cls");
                cout<<"----------------- Login Portal -----------------\n\n";
                cin.ignore(1000 , '\n');
                bank.login_portal();
                system("pause");
                break;

            case 3:
                cout << "Thanks for Coming to our Bank! \n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}

