#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Student{
	private:
		char stuID[10]; // student ID number
		char stuName[30]; // student name
		char dob[15]; // date of birth
		char gender[5]; // gender
		char classID[10]; // class ID number
		char major[30]; // major
		int course; // course
		char college[50]; // college
	public:
		/* Function allow user enter informations of student then save all these informations in student.txt
		*/
		void enterInfo(){
			system("cls");
			ofstream fileOut;
			// open file with append mode
			fileOut.open("student.txt", ios::app);
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\tStudent ID number:       "; 
			gets(stuID);
			cout << endl;
			// write to file
			fileOut << stuID;
			fileOut << '\t';
			cout << "\t\t\t\t\t\tFull name:     "; 
			gets(stuName);
			cout << endl;
			fileOut << stuName; 
			fileOut << '\t';
			cout << "\t\t\t\t\t\tDate of birth:  "; 
			gets(dob);
			cout << endl;
			fileOut << dob; 
			fileOut << '\t';
			cout << "\t\t\t\t\t\tGender:  "; 
			gets(gender);
			cout << endl;
			fileOut << gender; 
			fileOut << '\t';
			cout << "\t\t\t\t\t\tClass ID number:     "; 
			gets(classID);
			cout << endl;
			fileOut << classID; 
			fileOut << '\t';
			cout << "\t\t\t\t\t\tMajor:  "; 
			gets(major);
			cout << endl;
			fileOut << major; 
			fileOut << '\t';
			cout << "\t\t\t\t\t\tCourse:   "; 
			cin >> course;
			cout << endl;
			fileOut << course; 
			fileOut << '\t';
			cin.ignore(); // ignore enter key
			cout << "\t\t\t\t\t\tCollege:       "; 
			gets(college);
			cout << endl;
			fileOut << college; 
			fileOut << '\n';
			
			// close file
			fileOut.close();
			
			char choose;
			cout << "\t\t\t\t\t\tDo you want to continue? (Y/N): ";
			cin >> choose; 
			cin.ignore();
			if(choose == 'Y' || choose == 'y')
				enterInfo();
			else
				showMenu();
			getchar(); // enter any key from keyboard
		}
		
		/* Function to split a string using a char as delimiter.
		Parameters:
			- stringToBeSplitted
			- delimeter:
		Return an array store substrings which splitted from stringToBeSplitted
		Reference from https://thispointer.com/how-to-split-a-string-in-c/ */
		vector<string> split(string stringToBeSplitted, char delimiter){
			vector<string> splittedString;
			stringstream ss(stringToBeSplitted); // convert stringToBeSplitted into stringstream
			string item;
			// using getline() method to split string then save substrings in item base on delimeter
			while(getline(ss, item, delimiter)){ 
				splittedString.push_back(item); // push these items into splittedString
			}
			return splittedString;
		}
		
		/* Function to display informations of all student */
		void displayInfo(){
			system("cls");
			ifstream fileIn;
			fileIn.open("student.txt", ios::in); // open file
			string line;
			bool displayed = false; // flat variable is check whether information of student are displayed or not
			// read from file line by line
			while(getline(fileIn, line)){
				vector<string> result = split(line,'\t'); // slipt a line from file base on tab character
				// display informations of student
				cout << endl << endl << endl;
				cout << "\t\t\t\t\t\tStudent ID number:      " << result[0] << endl;
				cout << "\t\t\t\t\t\tFull name:    " << result[1] << endl;
				cout << "\t\t\t\t\t\tDate of birth: " << result[2] << endl;
				cout << "\t\t\t\t\t\tGender: " << result[3] << endl;
				cout << "\t\t\t\t\t\tClass ID number:    " << result[4] << endl;
				cout << "\t\t\t\t\t\tMajor: " << result[5] << endl;
				cout << "\t\t\t\t\t\tCourse:  " << result[6] << endl;
				cout << "\t\t\t\t\t\tCollege:      " << result[7] << endl << endl;
				cout << "\t\t\t\t\t\t**********************************************";
				displayed = true; // set displayed is true
			}
			fileIn.close(); // close file
			if(displayed){ // if these informations is displayed
				cout << endl << endl << endl; 
				// print notification
				cout << "\t\t\t\t\t\tDisplayed all informations of student!" << endl;
				cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
				getchar();
				showMenu(); // go back menu screen
			}
			else{
				cout << endl << endl << endl;
				cout << "\t\t\t\t\t\tNo information to display!" << endl;
				cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
				getchar();
				showMenu();	
			}
		}
		
		/* Function to search informations of a student */
		void searchInfo(){
			system("cls");
			ifstream fileIn;
			fileIn.open("student.txt", ios::in);
			string id;
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\tEnter student ID number: "; 
			cin >> id;
			cin.ignore();
			string line;
			bool found = false;
			while(getline(fileIn, line)){
				vector<string> result = split(line,'\t');
				if(id.compare(result[0]) == 0){ // check sutdent ID number
					cout << endl << endl << endl << endl;
					cout << "\t\t\t\t\t\tStudent informations" << endl;
					cout << "\t\t\t\t\t\tStudent ID number:      " << result[0] << endl;
					cout << "\t\t\t\t\t\tFull name:    " << result[1] << endl;
					cout << "\t\t\t\t\t\tDate of birth: " << result[2] << endl;
					cout << "\t\t\t\t\t\tGender: " << result[3] << endl;
					cout << "\t\t\t\t\t\tClass ID number:    " << result[4] << endl;
					cout << "\t\t\t\t\t\tMajor: " << result[5] << endl;
					cout << "\t\t\t\t\t\tCourse:  " << result[6] << endl;
					cout << "\t\t\t\t\t\tCollege:      " << result[7] << endl << endl;
					cout << "\t\t\t\t\t\t**********************************************" << endl << endl;
					found = true;
					cout << "\t\t\t\t\t\tSearched successfully!" << endl;
					cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
					fileIn.close();
					getchar();
					showMenu();
				}
			}
			fileIn.close();
			cout << endl << endl << endl;
			if(!found){
				cout << "\t\t\t\t\t\tNo information to display!" << endl;
				cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
				getchar();
				showMenu();
			}
		}
		
		/* Function to delete information of a student */
		void deleteInfo(){
			ifstream fileIn;
			fileIn.open("student.txt", ios::in);
			ofstream fileOut;
			fileOut.open("temp.txt", ios::out);
			string id;
			bool deleted = false;
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\tEnter student ID number: "; 
			cin >> id;
			cin.ignore();
			string line;
			while(getline(fileIn, line)){
				vector<string> result = split(line,'\t');
				if(id.compare(result[0]) != 0){
					fileOut << line;
					fileOut << '\n';
				}
				else
					deleted = true;
			}
			if(deleted){
				fileIn.close();
				fileOut.close();
				remove("student.txt");
				rename("temp.txt", "student.txt");
				cout << "\t\t\t\t\t\tStudent " << id << " number is deleted!" << endl;
				cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
				getchar();
				showMenu();
			}
			else{
				fileIn.close();
				fileOut.close();
				cout << "\t\t\t\t\t\tDo not have this student!" << endl;
				cout << "\t\t\t\t\t\tPress any key to continue!" << endl;\
				getchar();
				showMenu();
			}
		}
		
		/* Function to modify informations of a student */	
		void modifyInfo(){
			ifstream fileIn;
			fileIn.open("student.txt");
			ofstream fileOut;
			fileOut.open("temp.txt");
			string line, id;
			bool modified = false;
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\tStudent ID number: "; 
			cin >> id; 
			cin.ignore();
			system("cls");
			while(getline(fileIn, line)){
				vector<string> result = split(line, '\t');
				if(id.compare(result[0]) == 0){
					while(true){
						int option;
						cout << endl << endl << endl << endl << endl << endl;
						cout << "\t\t\t\t\t\tChoose item that you want to modify?" << endl << endl;
						cout << "\t\t\t\t\t\t**************************************" << endl;
						cout << "\t\t\t\t\t\t*                                    *" << endl;
						cout << "\t\t\t\t\t\t*        1. Student ID number        *" << endl;
						cout << "\t\t\t\t\t\t*        2. Full name                *" << endl;
						cout << "\t\t\t\t\t\t*        3. Date of birth            *" << endl;
						cout << "\t\t\t\t\t\t*        4. Gender                   *" << endl;
						cout << "\t\t\t\t\t\t*        5. Class ID number          *" << endl;
						cout << "\t\t\t\t\t\t*        6. Major                    *" << endl;
						cout << "\t\t\t\t\t\t*        7. Course                   *" << endl;
						cout << "\t\t\t\t\t\t*        8. College                  *" << endl;
						cout << "\t\t\t\t\t\t*                                    *" << endl;
						cout << "\t\t\t\t\t\t**************************************" << endl;
						cout << "\t\t\t\t\t\tPlease enter your choose: "; 
						cin >> option;
						cin.ignore();
						
						switch(option){
						
							case 1:{
								cout << "\t\t\t\t\t\tEnter student ID number: "; gets(stuID);
								result[0] = stuID;
							}
								break;
							case 2:{
								cout << "\t\t\t\t\t\tEnter full name: "; gets(stuName);
								result[1] = stuName;
							}
								break;
							case 3:{
								cout << "\t\t\t\t\t\tEnter date of birth: "; gets(dob);
								result[2] = dob;
							}
								break;
							case 4:{
								cout << "\t\t\t\t\t\tEnter gender: "; gets(gender);
								result[3] = gender;
							}
								break;
							case 5:{
								cout << "\t\t\t\t\t\tEnter class ID number: "; gets(classID);
								result[4] = classID;
							}
								break;
							case 6:{
								cout << "\t\t\t\t\t\tEnter major: "; gets(major);
								result[5] = major;
							}
								break;
							case 7:{
								cout << "\t\t\t\t\t\tEnter course: "; cin >> course;
								result[6] = course;	
							}	
								break;
							case 8:{
								cout << "\t\t\t\t\t\tEnter college: "; gets(college);
								result[7] = college;
							}
								break;	
							default:
								cout << "\t\t\t\t\t\tSu lua chon khong hop le!";
						}
						
						char choose;
						cout << "\t\t\t\t\t\tDo you want to continue? (Y/N): "; cin >> choose;
						cin.ignore();
						if(choose == 'N' || choose == 'n')
							break;
					}
					
					for(int i = 0; i < 8; i++){
						fileOut << result[i];
						fileOut << '\t';
					}
					fileOut << '\n';
					modified = true;
				}
				else{
					fileOut << line;
					fileOut << '\n';
				}
			}
			if(modified){
				fileIn.close();
				fileOut.close();
				remove("student.txt");
				rename("temp.txt", "student.txt");
				cout << endl << endl << endl << endl << endl << endl;
				cout << "\t\t\t\t\t\t Modified successfully!" << endl;
				cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
				getchar();
				showMenu(); 
			}
			else{
				fileIn.close();
				fileOut.close();
				cout << endl << endl << endl << endl << endl << endl;
				cout << "\t\t\t\t\t\tDo not found this student" << endl;
				cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
				getchar();
				showMenu(); 
			}
		}
		
		/* Function to exit the system */
		void exitSys(){
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t*********************************************" << endl;
			cout << "\t\t\t\t\t\t*                                           *" << endl;
			cout << "\t\t\t\t\t\t*        You have exited the system!        *" << endl;
			cout << "\t\t\t\t\t\t*                                           *" << endl;
			cout << "\t\t\t\t\t\t*********************************************" << endl;
			cout << "\t\t\t\t\t\t   Press enter to exit the program!" << endl;
			getchar();
			exit(0);
		}
		
		/* Function to show menu */
		void showMenu(){
			system("cls");
			int option;
			cout << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t***************************************************" << endl;
			cout << "\t\t\t\t\t\t*                                                 *" << endl;
			cout << "\t\t\t\t\t\t*         1. Add student informations             *" << endl;
			cout << "\t\t\t\t\t\t*         2. Modify student informations          *" << endl;
			cout << "\t\t\t\t\t\t*         3. Delete student informations          *" << endl;
			cout << "\t\t\t\t\t\t*         4. Search student informations          *" << endl;
			cout << "\t\t\t\t\t\t*         5. Display student informations         *" << endl;
			cout << "\t\t\t\t\t\t*         6. Exit                                 *" << endl;
			cout << "\t\t\t\t\t\t*                                                 *" << endl;
			cout << "\t\t\t\t\t\t***************************************************" << endl;
			cout << "\t\t\t\t\t\tPlease enter your choose: "; cin >> option;
			cin.ignore();
			switch(option){
				case 1:{
					system("cls");
					enterInfo();
				}
					break;
					
				case 2:{
					system("cls");
					modifyInfo();
				}
					break;
						
				case 3:{
					system("cls");
					deleteInfo();
				}
					break;
						
				case 4:{
					system("cls");
					searchInfo();
				}
					break;
						
				case 5:{
					system("cls");
					displayInfo();	
				}
					break;
						
				case 6:{
					system("cls");
					cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "\t\t\t\t\t\t***********************************************" << endl;
					cout << "\t\t\t\t\t\t*                                             *" << endl;
					cout << "\t\t\t\t\t\t*        You have exited the system!          *" << endl;
					cout << "\t\t\t\t\t\t*                Thank you!!                  *" << endl;
					cout << "\t\t\t\t\t\t*                                             *" << endl;
					cout << "\t\t\t\t\t\t***********************************************" << endl;
					exit(0);
				}
					break;
						
				default:{
					system("cls");
					cout << endl << endl << endl << endl << endl << endl << endl << endl;
					cout << "\t\t\t\t\t\t   Sorry! The system do not have this function!" << endl;
					cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
					getchar();
					showMenu();
				}
			}
		}
		
		/* Function to show login screen */	
		void loginScreen(){
			system("cls");
			string userName;
			string password;
			bool check = false;
			int test = 0;
			do{
				system("cls");
				cout << endl << endl << endl << endl << endl << endl;
				cout << "\t\t\t\t\t\tUsername: "; 
				cin >> userName;
				cout << "\t\t\t\t\t\tPassword: "; 
				cin >> password;
				cin.ignore();
				if(userName.compare("admin") == 0 && password.compare("admin") == 0){
					cout << endl << endl << endl << endl << endl << endl;
					cout << "\t\t\t\t\t\tLogin successfully!" << endl;
					cout << "\t\t\t\t\t\tPress any key to continue!";
					getchar();
					showMenu();
					check = true;
				}
				else{
					system("cls");
					test++;
					cout << endl << endl << endl << endl << endl << endl;
					cout << "\t\t\t\t\t\tYou are only allowed to try 3 times. You just have " << (3-test) << " times left!" << endl;
					cout << "\t\t\t\t\t\tPress any key to continue!" << endl;
					getchar();
					if(test == 3){
						cout << "\t\t\t\t\t\tYou have entered the wrong username or password 3 times and you are not allowed to login to the system!" << endl;
						getchar();
						exitSys();
					}
				}
			} while(!check);
		}
		
		/* Time delay
		Basic idea is to get current clock and add the required delay to that clock, till 
		current clock is less then required clock run an empty loop. 
		*/
		void delay(unsigned int mseconds){ 
		    // Storing start time 
		    clock_t startTime = clock(); 
		    // looping till required time is not acheived 
		    while (clock() < startTime + mseconds); 
		} 
			
		/* Function to display title of system. This function will call in mainPage() function */	
		void title(){
			cout << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t********************************************" << endl;
			cout << "\t\t\t\t\t\t*                                          *" << endl;
			cout << "\t\t\t\t\t\t*        STUDENTS MANAGEMENT SYSTEM        *" << endl;
			cout << "\t\t\t\t\t\t*                                          *" << endl;
			cout << "\t\t\t\t\t\t********************************************" << endl;
		}
		
		/* Function to display main screen of system */	
		void mainScreen(){
			system("cls");
			title();
			cout << endl << "\t\t\t\t\t\t\tPress any key to continue!" << endl << endl;
			getchar();
			cout << "\t\t\t\t\t\tLoading";
			for(int process = 0; process < 36; process++){
				delay(50); // delay 50 milisecond
				cout << ".";
			}
		}
};

// Function to deploy Student class
void deploy(){
	Student student; 
	student.mainScreen();
	student.loginScreen();
}

int main(){
	deploy();
	return 0;
}
