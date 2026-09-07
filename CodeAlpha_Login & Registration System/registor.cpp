#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

class userdata{
public:
    string name = "";
    string pass = "";

    userdata(){
        name = "";
        pass = "";
    }
	
	void registration(){
	//NAME Validations
	
	while(true){
		
		bool uppercase = false;
		bool no_digits = true;
		bool space = false;
		int space_counter = 0;
		bool all_alpha = true;
		int error_counter = 0;
		
		//Validation variables
		bool valid_name = false;
		bool valid_pass = false;
		
		string name;
		string pass;
		cout<<"Enter Name your: ";
		getline(cin , name);
		cout<<endl;
		
		//Size
			if(name.size() > 15){
			cout<<"Name is too long !\n\n";
			continue;}
			
			if(name.size() < 6){
			cout<<"Name is too Short !\n\n";
			continue;}
			
			error_counter = 0;
			
		for(int i=0; i<name.size(); i++){
			
			
			//Avoid Spacial charactor
			
			if(isalpha(name[i]) || name[i] == ' ' || isdigit(name[i])){
				//Valid condition so no changes
			}
			else{
				error_counter++;
				cout<<error_counter<<")."<<"Don't use any spacial charactor. \n\n";
				all_alpha = false;
				break;
			}
		}
		
		//if(!all_alpha) cout<<"At least one Uppercase letter is requaired. \n\n";
		
	
		//Digits
		for(int i=0; i<name.size(); i++){
			if(isdigit(name[i])){
				
				error_counter++;
				cout<<error_counter<<")."<<"Digits are not allowed.\n\n";
				no_digits = false;
				break;
			}
		}
		
		//Uppercase
		for(int i=0; i<name.size(); i++){
			if(name[i]>='A' && name[i]<='Z'){
				uppercase = true;
				break;
			}
		}
		if(!uppercase){
			error_counter++;
			cout<<error_counter<<")."<<"At least one Uppercase letter is requaired\n\n";
		}
			
		
		//space 
			for(int i=0; i<name.size(); i++){
			if(name[i] == ' '){
				space = true;
				space_counter++;
			}
			if(space_counter==3){
		
				error_counter++;
				cout<<error_counter<<")."<<"Too much spaces are not Allowd\n\n";
				break;
			}
		}
		if(!space){
			error_counter++;
		    cout<<error_counter<<")."<<"Space required in name\n\n";
		}
		
		//Rigistraion
		if(uppercase && all_alpha && space && no_digits && space_counter <=2 && (name.size() <=15 && name.size() >= 6)){
			
//			cout<<endl<<"-------------------------------------------------------\n\n";
//			cout<<"Registraion successfull !\n\n";
			valid_name = true;
			
		  }
		else{
			cout<<endl<<"-------------------------------------------------------\n\n";
			cout<<"Registraion failed !\n\n";
			system("pause");
			system("cls");
			cout<<"-------Login and Registration System--------\n\n";
			
		}
		
		if(valid_name){
			
			
			
			while(true){
			
				int error_counter = 0;
				bool speacial_c = false;
				no_digits = true;
				uppercase = false;
				space = false;
				
				
				cout<<"Password : ";
				cin>>pass;
				cout<<endl;
				 
				for(int i=0; i<pass.size(); i++){
					
					
				//USE Spacial charactor
				
					if(!isalpha(pass[i]) && pass[i] != ' ' && !isdigit(pass[i])){
						
						speacial_c = true;
					//	break;
					}
					
				//USe digits
				
					if(isdigit(pass[i])){
						no_digits = false;
					}
				
				//No spaces
				
					if(pass[i] >= 'A' && pass[i] <= 'Z'){
						uppercase = true;
					}
					
					if(pass[i] == ' '){
						space = true;
					}
				
					
				}
				
				if(!speacial_c){
					error_counter++;
					cout<<error_counter<<")."<<"Use at-least one spacial charactor. \n\n";
				}
				if(no_digits){
					error_counter++;
					cout<<error_counter<<")."<<"Use at-least one digit. \n\n";
				}
				if(!uppercase){
					error_counter++;
					cout<<error_counter<<")."<<"Use at-least one Uppercase lettor. \n\n";
				}
				if(space){
					error_counter++;
					cout<<error_counter<<")."<<"Don't use space \n\n";
				}
				
				//Last validation
				if(speacial_c && !no_digits && uppercase && !space){
					
					
					valid_pass = true;
					break;
					
				}
				else{
				cout<<endl<<"Wrong password";
				cout<<endl<<"-------------------------------------------------------\n\n";
				cout<<"Registraion failed !\n\n";
				system("pause");
				system("cls");
				cout<<"-------Login and Registration System--------\n\n";
				
				
				}
				
			}
	}
	
	if(valid_pass && valid_name){
	
	    cout << "\n-------------------------------------------------------\n\n";
	    cout << "Registration successfull !\n\n";
	
	    ofstream file("users.txt", ios::app);

		file << name << "|" << pass << endl;

		file.close();
	
	    system("pause");
	    return;
	}
}
	//of name validation
	//full name(space requared)
	//1 upper letter
	//No other special charactors
	
	//for password validation
	//requaried atleast 1 special char.
	//one upper case lettor.
	//digits compalsory
	}

void login(){

    string login_name;
    string login_pass;

    cout << "Enter Name: ";

    getline(cin, login_name);

    cout << "Enter Password: ";
    cin >> login_pass;

    ifstream file("users.txt");

    if(!file){
        cout << "File could not be opened!\n";
        return;
    }

    string name;
    string pass;


    bool found = false;

    while(getline(file, name, '|') && getline(file, pass)){

        if(name == login_name && pass == login_pass){
            found = true;
            break;
        }
    }

    file.close();

    if(found){
        cout << "\nLogin Successful!\n";
    }
    else{
        cout << "\nInvalid Name or Password!\n";
    }

    system("pause");
}

void reset(){
	
	ofstream file("users.txt" , ios::trunc);

	file.close();
	
	cout << "\nAll user data has been reset!\n";
    system("pause");
}

};
int main(){
	userdata d1;

	while(true){
		system("cls");
	int choise = 0;
	cout<<"-------Login and Registration System--------\n\n";
	cout<<"1) Rigistration \n";
	cout<<"2) Login\n";
	cout<<"3) Reset file\n";
	cout<<"4) Exit\n\n";
	cout<<"Choise : ";
	cin>>choise;
	
	switch(choise){
		case 1:
			cin.ignore(1000, '\n');
			d1.registration();
			break;
		case 2:
			cin.ignore(1000, '\n');
			d1.login();
			break;
		case 3:
			d1.reset();
			break;
		case 4:
			cout<<" Thanks for Watching !";
			return 0;
			break;
		default:
			cout<<"\nInvalid Input !\n\n";
			break;
			
	}
}
}


