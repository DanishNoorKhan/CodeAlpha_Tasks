#include <iostream>
#include<windows.h>
#include <string>

using namespace std;


class gpa{
public:
	string name = "";
    int course = 0;
    string grade = "A";
    int credit = 0;
    
    gpa(){
		
		name = "";
        course = 0;
        grade = "";//My name is danish noor khaan and i am currently at 
        credit = 0;  
    }
    void Add_details(string name , int course , string grade , int credit){
    	this->name = name;
        this->course = course;
        this->grade = grade;
        this->credit = credit;
    }
    void show_details(){
    	cout<<"Name : "<<name<<endl<<endl;
        cout<<"Course : "<<course<<endl<<endl;
        cout<<"Grade : "<< grade<<endl<<endl;
        cout<<"Credit Hours: "<< credit<<endl<<endl;
    }
	

};

class cgpa{
public:
	
	gpa course_arr[12];
	int sym_counter = 0;
	double sgpa = 0.0;
	int credit = 0;
	double quality_points = 0.0;
	
	cgpa(){
		
		sgpa = 0;
		credit = 0;
		
		
	}
	
	void add_details(int sym_counter ,double sgpa , double quality_points , int credit){
		
		this->sym_counter = sym_counter;
		this->sgpa = sgpa;
		this->credit = credit;
		this->quality_points = quality_points;
	}
	
	void show_details(){
		
	}
};

double show_gpa( double points , int credits){
	
	double SGPA = points / credits;
	return SGPA;
	
	
}

         

double Grade_table(string grade){
				
				double grade_point = 0;
				if(grade == "A") grade_point = 4.0;
				else if(grade == "A-") grade_point = 3.7;
				else if(grade == "B+") grade_point = 3.3;
				else if(grade == "B") grade_point = 3.0;
				else if(grade == "B-") grade_point = 2.7;
				else if(grade == "C+") grade_point = 2.3;
				else if(grade == "C") grade_point = 2.0;
				else if(grade == "C-") grade_point = 1.7;
				else if(grade == "D+") grade_point = 1.3;
				else if(grade == "D") grade_point = 1.0;
				else if(grade == "F") grade_point = 0.0;
				else {
					cout<<"\n\nInvalid Grade !\n\n";
					return 0.01;
				}
				
				return grade_point;
	
} 

void GPA_Calculation(gpa any_sym){
		
	//	any_sym course_obj ;
		
		string name = "";
		string grade = "";
		int credit = 0;
		int total_credit = 0;
		double grade_point = 0.01;
		double quality_points = 0;
		double total_quality_points = 0;
		int total_course = 0;
	
		int course_counter = 0; //reset
		int choise = 0;
		int exit = false;
		
		system("cls");
		cout<<"------------Calculate SGPA "<<"-------------";
		
		cout<<endl<<endl<<"Course Name : "<<name;
		cin>>name;
		
		while(true){
			
				cout<<"Enter total courses : ";
				cin>>total_course;
				
				if(total_course >= 1 && total_course <= 12) break;
				else cout<<"\n\nInvalid Total Course ! \n\n";
			}
		
		while(course_counter < total_course ){
			
			grade_point = 0.01; // declear again as 0.0
			
			while(grade_point == 0.01){
				
				cout<<"\nEnter Grade : ";
				cin>>grade;
				grade_point = Grade_table(grade);
			
			}
			
			while(true){
				
			    cout << "Credit Hours: ";
			    cin >> credit;
			
			    if(credit >= 1 && credit <= 4){
			    	
			    	total_credit += credit;
			        break;
			    }
			    
			    cout << "\nInvalid Credit Hours! Enter 1-4.\n\n";
			}
			
			//Class array addition
			
			//course_obj[0].Add_details(course_counter+1 , grade , credit);
			
			//Total Quality points calculation
			quality_points = grade_point * credit;
			total_quality_points += quality_points;
			
			course_counter++; 
		}
		
		double sgpa;
		
		sgpa = show_gpa(total_quality_points , total_credit);
		cout<<"\nSGPA : "<<sgpa<<endl;
		system("pause");
		
		
}
   
void CGPA_Calculation(cgpa sym){
	
		
		int sym_counter = 0;
		int courses = 0;
		double total_quality_points = 0.0;
		int total_credits = 0;
		double CGPA = 0.0;
		
		while(sym_counter < 8){
			
			system("cls");
			cout<<"-------------CGPA Calculator--------------\n\n";
			
			if(sym_counter>0){
				
				int choise = 0;
				cout<<"1). Next Sym cgpa "<<endl;
				cout<<"2). Back"<<endl;
				cout<<"\n choise : ";
				cin>>choise;
				switch(choise){
					case 1:
						break;
					case 2:
						return;
						break;
				}
				
			}
			
			system("cls");
			cout<<"-------------CGPA Calculator--------------\n\n";
			
			double GPA = 0.0;
			int credits = 0;
			int courses=0;
			
			while(true){
			
				cout<<"Enter your GPA : ";
				cin>>GPA;
				
				if(GPA >= 0 && GPA <=4) break;
				else cout<<"\n\nInvalid GPA ! \n\n";
			}
			while(true){
			
				cout<<"Enter total courses : ";
				cin>>courses;
				
				if(courses >= 1 && courses <= 12) break;
				else cout<<"\n\nInvalid Courses ! \n\n";
			}
			while(true){
			
				cout<<"Enter total credit hours : ";
				cin>>credits;
				
				if(credits >= courses * 1 && credits <= courses * 4) break;
				else cout<<"\n\nInvalid Credits ! \n\n";
			}
			
			total_quality_points += GPA * credits;
			total_credits +=credits;
			
			CGPA = total_quality_points / total_credits;
			cout<<"CGPA : "<<CGPA<<endl<<endl;
			system("pause");
			
			
			sym_counter++;
			
		}
}
            
void GPA_and_SGPA_Calculation(cgpa sym[8] , bool all){
	
	int sym_counter = 0;
	
	//For CGPA
	int grand_credit = 0;
	double grand_quality_points = 0;
	double CGPA=0;
	
	while(sym_counter < 8){
		
		string name = "";
		string grade = "";
		int credit = 0;
		int total_credit = 0;
		double grade_point = 0.01;
		double quality_points = 0;
		double total_quality_points = 0;
		int total_course = 0;
	
		int course_counter = 0; //reset
		int choise = 0;
		int exit = false;
		
		if(all){
			if(sym_counter == 0){
				system("cls");
				cout<<"------------"<<" SGPA & CGPA Calculator "<<"-------------";
			}
			if(sym_counter >= 1){
				system("cls");
				cout<<"------------"<<" SGPA & CGPA Calculator "<<"-------------";
				cout<<endl<<endl<<"1). Calculate for sym : "<<sym_counter+1<<endl;
				cout<<"2). Back"<<endl<<endl;
				cout<<"Choise : "<<endl;
				cin>>choise;
				
				switch(choise){
					case 1:
						system("cls");
						cout<<"------------Sym "<< sym_counter+1 <<"-------------";
						break;
					
					case 2:
						exit = true;
						break;
				}
			}
		}
		else{
			cout<<"------------Calculate SGPA "<<"-------------";
		}
		
		if(exit == true) break;
		
		
		while(true){
			
				cout<<endl<<endl<<"Enter total courses : ";
				cin>>total_course;
				
				if(total_course >= 1 && total_course <= 12) break;
				else cout<<"\n\nInvalid Courses ! \n\n";
			}
		
		while(course_counter < total_course ){
			
			cout<<endl<<"Course Name :";
			cin>>name;
			
			grade_point = 0.01; // declear again as 0.0
			while(grade_point == 0.01){
				
				cout<<"Enter Grade : ";
				cin>>grade;
				
				grade_point = Grade_table(grade);
				
				
			}
			
			while(true){
				
			    cout << "Credit Hours: ";
			    cin >> credit;
			
			    if(credit >= 1 && credit <= 4){
			    	
			    	total_credit += credit;
			        break;
			    }
			    
			    cout << "\nInvalid Credit Hours! Enter 1-4.\n\n";
			}
			
			//Class array addition
			
			sym[sym_counter].course_arr[course_counter].Add_details( name , course_counter+1 , grade , credit);
			
			//Total Quality points calculation
			quality_points = grade_point * credit;
			total_quality_points += quality_points;
			
			course_counter++; 
		}
		cout<<endl<<"--------------------------------------"<<endl;
		double sgpa;
		
		sgpa = show_gpa(total_quality_points , total_credit);
		cout<<"GPA : "<<sgpa;
		sym[sym_counter].add_details(sym_counter , sgpa , total_quality_points , total_credit);
		
		//string for cgpa
		grand_credit += total_credit;
		grand_quality_points += total_quality_points;
	    sgpa = show_gpa(grand_quality_points , grand_credit);
	    cout<<endl<<"CGPA : "<<sgpa<<endl;
	    
		system("pause");
		
		sym_counter++;
		
		if(sym_counter == 8) system("pause");
		
	}
}

void help(){

    system("cls");

    cout << "==================== HELP & INSTRUCTIONS ====================\n\n";

    cout << "1. SGPA & CGPA Calculator\n";
    cout << "--------------------------------------------------------------\n";
    cout << "This option calculates both SGPA and CGPA semester by semester.\n";
    cout << "You can enter up to 8 semesters.\n\n";

    cout << "Steps:\n";
    cout << "  - Enter total number of courses (1-12).\n";
    cout << "  - Enter course name.\n";
    cout << "  - Enter grade.\n";
    cout << "  - Enter credit hours (1-4).\n";
    cout << "  - SGPA will be calculated automatically.\n";
    cout << "  - CGPA will also be updated after each semester.\n\n";


    cout << "2. Calculate SGPA\n";
    cout << "--------------------------------------------------------------\n";
    cout << "This option calculates SGPA for one semester only.\n\n";

    cout << "Steps:\n";
    cout << "  - Enter total courses (1-12).\n";
    cout << "  - Enter grade for each course.\n";
    cout << "  - Enter credit hours for each course (1-4).\n";
    cout << "  - Your SGPA will be displayed.\n\n";


    cout << "3. Calculate CGPA\n";
    cout << "--------------------------------------------------------------\n";
    cout << "This option calculates CGPA using semester GPAs.\n\n";

    cout << "Steps:\n";
    cout << "  - Enter your semester GPA (0-4).\n";
    cout << "  - Enter total courses (1-12).\n";
    cout << "  - Enter total credit hours.\n";
    cout << "  - You can enter up to 8 semesters.\n";
    cout << "  - CGPA will be calculated automatically.\n\n";


    cout << "4. Grade System\n";
    cout << "--------------------------------------------------------------\n";
    cout << "  A   = 4.0\n";
    cout << "  A-  = 3.7\n";
    cout << "  B+  = 3.3\n";
    cout << "  B   = 3.0\n";
    cout << "  B-  = 2.7\n";
    cout << "  C+  = 2.3\n";
    cout << "  C   = 2.0\n";
    cout << "  C-  = 1.7\n";
    cout << "  D+  = 1.3\n";
    cout << "  D   = 1.0\n";
    cout << "  F   = 0.0\n\n";


    cout << "5. Important Instructions\n";
    cout << "--------------------------------------------------------------\n";
    cout << "  * Maximum courses per semester: 12\n";
    cout << "  * Credit hours per course: 1-4\n";
    cout << "  * Maximum semesters: 8\n";
    cout << "  * GPA/SGPA range: 0.0 - 4.0\n";
    cout << "  * Enter grades exactly as shown above.\n";
    cout << "  * Invalid values will ask you to enter them again.\n\n";


    cout << "6. Calculation Formula\n";
    cout << "--------------------------------------------------------------\n";
    cout << "Quality Points = Grade Point x Credit Hours\n\n";
    cout << "SGPA = Total Quality Points / Total Credit Hours\n\n";
    cout << "CGPA = Total Quality Points of all semesters\n";
    cout << "       ------------------------------------\n";
    cout << "       Total Credit Hours of all semesters\n\n";


    cout << "==============================================================\n";
    cout << "Press Enter to return to Main Menu...";

    cin.ignore();
    cin.get();
}



int main(){
	
	cgpa sym[8];
	gpa any_sym;
	cgpa all_sym;
	
	while(true){
	
	system("cls");
    cout<<"---------------CGPA Calculator-----------------\n\n";
    cout<<"1)- Calculate SGPA and CGPA"<<endl;
    cout<<"2)- Calculate SGPA"<<endl;
    cout<<"3)- Calculate CGPA"<<endl;
    cout<<"4)- Help"<<endl;
	cout<<"5)- Exit"<<endl;
    int choise=0;
    int exit = false;
    cout<<"Enter your choise : ";
    cin>>choise;
    
    switch(choise){
    	
        case 1:
            GPA_and_SGPA_Calculation(sym,true);
            break;
        case 2:
            GPA_Calculation(any_sym);
            break;
        case 3:
        	CGPA_Calculation(all_sym);
        	break;
        case 4:
        	help();
        	break;
        case 5:
            cout << endl << "Thank you for using my software!"<< "\nSpecial thanks to Code Alpha for the opportunity."<< endl;
            cout<<endl;
            exit = true;
            break;
    }
    
    if(exit) break;
	}
}

