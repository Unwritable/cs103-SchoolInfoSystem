#include <iostream>
#include <string>
#include <fstream>
<<<<<<< HEAD
#include <sstream>
#include <Windows.h>
#include <vector>
=======
#include <Windows.h>
>>>>>>> origin/indev

using namespace std;

//-----Structs and Function Prototypes-----

// CODE SECTION - Jamie

void Parent_AccessNotices();    // These two functions are just placeholders and could change return types or arguments
void Parent_AccessChildRecords();

typedef struct ParentDetails {  // Any records starting with e are for emergency contact info.
    string username;
    string password;
    string firstName;
    string lastName;
    string dob;
    string email;
    string contactNumber;
    string eFirstName;
    string eLastName;
    string eContactNumber;
    // Find a way to have student data here, may have to just add more strings

    ParentDetails(string un="", string pw="", string fn="", string ln="", string db="", string em="", string cn="", 
                    string efn="", string eln="", string ecn="") {
        username = un;
        password = pw;
        firstName = fn;
        lastName = ln;
        dob = db;
        email = em;
        contactNumber = cn;
        eFirstName = efn;
        eLastName = eln;
        eContactNumber = ecn;
        
    }

} Parent;

typedef struct StudentRecords { // Jamie - Placeholder Student Struct, just for testing. Work out a new one with Freddie.
    string firstName;
    string lastName;
    vector<string> Classes;


} Student;

// CODE SECTION - End

struct Date //Freddie Rive
{
    unsigned int day, month, year;
    string fullDate, dayName;

    Date(int d = 1, int m = 1, int y = 2021) //constructor that takes 3 ints
    {
        year = min(max(y, 1), 2021);  //all inputs are validated to ensure that they fall into acceptable parameters (e.g. months can only be between 1 and 12)
        monthLength[1] = (y % 4 == 0) ? 29 : 28; //account for leap years
        month = min(max(m, 1), 12);
        day = min(max(d, 1), monthLength[m - 1]);

        fullDate = (day > 9) ? day + "/" : (string)("0" + day) + "/"; //date string is constructed out of the validated integers
        fullDate += (month > 9) ? month + "/" : (string)("0" + month) + "/";
        fullDate += year;

        int dayNo = 0; //attempting to accurately calculate the name of the day
        for (int i = 0; i < m - 1; i++)
        {
            dayNo += monthLength[i];
        }
        dayNo += day;

        dayName = days[Loop(dayNo % 7 + 3)]; //this will only be accurate for 2021
    }

    Date(string str) //constructor that takes a string (in dd/mm/yyyy format only)
    {
        if (str.length() == 10) //stops the constructor if the string is obviously incompatible
        {
            int d = ((str[0] - '0') * 10) + (str[1] - '0'); //convert the first 2 chars to an int
            int m = ((str[3] - '0') * 10) + (str[4] - '0');//convert the month chars to an int
            int y = ((str[6] - '0') * 1000) + ((str[7] - '0') * 100) + ((str[8] - '0') * 10) + (str[0] - '0'); //convert the year chars to an int

            year = min(max(y, 1), 2021); //all inputs are validated to ensure that they fall into acceptable parameters (e.g. months can only be between 1 and 12)
            monthLength[1] = (year % 4 == 0) ? 29 : 28; //account for leap years
            month = min(max(m, 1), 12);
            day = min(max(d, 1), monthLength[month - 1]);

            fullDate = str; //the input string can be stored as is

            int dayNo = 0; //attempting to accurately calculate the name of the day
            for (int i = 0; i < m - 1; i++)
            {
                dayNo += monthLength[i];
            }
            dayNo += day;

            dayName = days[Loop(dayNo % 7 + 3)]; //this will only be accurate for 2021
        }
        else //default values given if string entered is incompatible
        {
            day = 1;
            month = 1;
            year = 2021;
            fullDate = "01/01/2021";
            dayName = "Friday";
        }
    }

    int Loop(int input) //for the days
    {
        while (input > 6)
        {
            input -= 7;
        }
        return input;
    }

private:
    int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //lengths of months
    string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" }; //names of days
};

struct Teacher //Freddie Rive
{
    string firstName, middleName, lastName, gender, email, username, password, contactNo;
    int age, yrTaught, classNo;
    Date dob;

    Teacher(string* str, int a, int tght, int clss, Date d)
    {
        this->username = *(str);
        this->password = *(str + 1);
        this->firstName = *(str + 2);
        this->middleName = *(str + 3);
        this->lastName = *(str + 4);
        this->gender = *(str + 5);
        this->email = *(str + 6);
        this->age = a;
        this->contactNo = *(str + 7);
        this->yrTaught = tght;
        this->classNo = clss;
        this->dob = d;
    }

    Teacher() //default constructor; make sure you check firstname when making a new teacher struct
    {
        this->username = "NULL";
    }

    void DisplayInfo(int index = 0)
    {
        if (index > 0)
        {
            cout << "Information for teacher " << index << " (" << firstName << " " << middleName << " " << lastName << ")\n";
        }
        else
        {
            cout << "Information for teacher " << firstName << " " << middleName << " " << lastName << endl;
        }
        cout << "Age: " << age << "\nDate of birth: " << dob.fullDate << "\nGender: " << gender << "\nContact Phone: " << contactNo << "\nEmail Address: " << email << "\nYear Taught: "
            << yrTaught << "\nClassroom number: " << classNo << endl << endl;
    }
};

int GetIntInput(int min = -2147483647, int max = 2147483647); //Freddie Rive
string GetNewPassword(); //Freddie Rive
Teacher LogInAsTeacher(); //Freddie Rive
void TeacherAccountManagement(); //Freddie Rive


//-----------------------------------------

int main()
{
<<<<<<< HEAD

	// Jesse Simpson - Start
	int option; // Stores the user's option.
	ifstream inputDetails; // File identifier for reading purposes
	string str; // For storing getline data from the inputDetails file

	// Operates while the User has not exited. Not final, and is subject to change based on other functions/screens.
	do {
		// Output menu
		cout << "-------------------------------------------------------" << endl;
		cout << "|     Emerald Hill High School Information System     |" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "\n1. Contact Details";
		cout << "\n2. Events";
		cout << "\n3. Term Dates";
		cout << "\n4. Account Settings" << endl;
		cout << "\n5. Exit" << endl;
		cout << "\n[Enter your option:] ";

		cin >> option; // User Input for Menu Selection

		cout << "\n"; // New line so it doesn't look too close together, helping with readability

		// Menu options switch case. Account Settings does not work at this time, as I am waiting on the Login screen stuff to get underway.
		// Options 1-3 all do the same basic operation of reading from an existing txt file. Said txt file plans to be modifiable by an Admin.
		// Sleep only works on windows at this time.
		switch (option) {
		case 1:
			inputDetails.open("contactDetails.txt", ios::in);
			while (getline(inputDetails, str)) {
				cout << str << endl;
			}
			cout << "\n";
			inputDetails.close();
			Sleep(1500);
			break;
		case 2:
			inputDetails.open("eventDetails.txt", ios::in);
			while (getline(inputDetails, str)) {
				cout << str << endl;
			}
			cout << "\n";
			inputDetails.close();
			Sleep(1500);
			break;
		case 3:
			inputDetails.open("termDetails.txt", ios::in);
			while (getline(inputDetails, str)) {
				cout << str << endl;
			}
			cout << "\n";
			inputDetails.close();
			Sleep(1500);
			break;
		default: // Explaining that the user has inputted the incorrect number, clears screen before showing menu again. Only works on Windows.
			cout << "What you entered does not match the menu options listed, please try again." << endl;
			Sleep(1500);
			system("CLS");
		}
	} while (option != 5);

	// Jesse Simpson - End

	return 0;
 }


// CODE SECTION - Jamie

#pragma region ParentScreen

void Parent_AccessNotices() {
    string line;

    fstream fs;

    fs.open("data/notices.txt", ios::in);
    
    while (getline(fs, line)) {
        cout << line << endl;
    }

    fs.close();
}

void Parent_AccessChildRecords() {

}

#pragma endregion

// CODE SECTION - End

//----------------------------------Generic-Functions-------------------------------------//

int GetIntInput(int min, int max) //default variables are declared with the function at the top of the program
{
	int rtrn;
	while (true)
	{
		try
		{
			cin >> rtrn;
			if (cin.fail())
			{
				throw string("Error: Please only enter digits.");
			}
			else if (rtrn < min || rtrn > max)
			{
				throw string("Error: Input outside of acceptable range.");
			}
			break;
		}
		catch (string error)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << error << " Try again: ";
		}
	}
	cin.ignore();
	return rtrn;
}

string GetNewPassword()
{
	string rtrn, check;
	cout << "\nPlease enter your new password: ";
	getline(cin, rtrn);
	while (true)
	{
		cout << "\nPlease re-enter your password to confirm: ";
		getline(cin, check);
		if (check != rtrn)
		{
			cout << "\nYour entries do not match up. Do you want to:\n 1. Attempt again\n 2. Enter a new password\n ?: ";
			int i;
			i = GetIntInput(1, 2);
			if (i == 1)
			{
				continue;
			}
			else
			{
				rtrn = GetNewPassword();
				break;
			}
		}
		break;
	}
	return rtrn;
}

//-------------------------------Teacher-Functions------------------------------//
Teacher RegisterNewTeacher()
{
	string str[8], dateStr;
	int age, contactNo, yrTaught, classNo;
	Date dob;

	cout << "\nPlease enter your new username: ";
	getline(cin, str[0]);
	str[1] = GetNewPassword();
	cout << "\nPlease enter your first name: ";
	getline(cin, str[2]);
	cout << "\nPlease enter your middle name: ";
	getline(cin, str[3]);
	cout << "\nPlease enter your last name: ";
	getline(cin, str[4]);
	cout << "\nPlease enter your age: ";
	age = GetIntInput(0, 127);
	cout << "\nPlease enter your Date of birth (in dd/mm/yyyy format): ";
	getline(cin, dateStr);
	Date date = Date(dateStr);
	dob = date;
	cout << "\nPlease enter your gender: ";
	getline(cin, str[5]);
	cout << "\nPlease enter your email address: ";
	getline(cin, str[6]);
	cout << "\nPlease enter your contact phone number: ";
	getline(cin, str[7]);
	cout << "\nPlease enter the year you teach at our school: ";
	yrTaught = GetIntInput(0, 13);
	cout << "\nPlease enter your classroom number: ";
	classNo = GetIntInput(0);

	ofstream teacherFile("teachers.csv", ios::app);

	teacherFile << str[0] << ',' << str[1] << ',' << str[2] << ',' << str[3] << ',' << str[4] << ',' << str[5] << ',' << str[6] << ',' << str[7] << ',' << age << ','
		<< dob.fullDate << ',' << yrTaught << ',' << classNo << '\n';

	teacherFile.close();

	Teacher rtrn = Teacher(str, age, yrTaught, classNo, dob);

	return rtrn;
}

void FetchTeachers()
{
	ifstream teacherFile("teachers.csv", ios::in);
	int index = 1;
	while (teacherFile.peek() != -1)
	{
		string str[8], temp;
		int age, contactNo, yrTaught, classNo;
		Date dob;

		getline(teacherFile, str[0], ',');
		getline(teacherFile, str[1], ',');
		getline(teacherFile, str[2], ',');
		getline(teacherFile, str[3], ',');
		getline(teacherFile, str[4], ',');
		getline(teacherFile, str[5], ',');
		getline(teacherFile, str[6], ',');
		getline(teacherFile, str[7], ',');
		getline(teacherFile, temp, ',');
		age = stoi(temp);
		getline(teacherFile, temp, ',');
		dob = Date(temp);
		getline(teacherFile, temp, ',');
		yrTaught = stoi(temp);
		getline(teacherFile, temp, '\n');
		classNo = stoi(temp);

		Teacher teach = Teacher(str, age, yrTaught, classNo, dob);
		teach.DisplayInfo(index);
		index++;
	}
	teacherFile.close();
}

Teacher FetchTeacher(int index)
{
	ifstream teacherFile("teachers.csv", ios::in);

	string str[8], temp;
	int age, contactNo, yrTaught, classNo;
	Date dob;

	for (int i = 0; i < index; i++)
	{
		getline(teacherFile, temp, '\n');
	}

	getline(teacherFile, str[0], ',');
	getline(teacherFile, str[1], ',');
	getline(teacherFile, str[2], ',');
	getline(teacherFile, str[3], ',');
	getline(teacherFile, str[4], ',');
	getline(teacherFile, str[5], ',');
	getline(teacherFile, str[6], ',');
	getline(teacherFile, str[7], ',');
	getline(teacherFile, temp, ',');
	age = stoi(temp);
	getline(teacherFile, temp, ',');
	dob = Date(temp);
	getline(teacherFile, temp, ',');
	yrTaught = stoi(temp);
	getline(teacherFile, temp, '\n');
	classNo = stoi(temp);

	teacherFile.close();
	return Teacher(str, age, yrTaught, classNo, dob);
}

Teacher GetTeacherByUsername(string username)
{
	ifstream teacherFile("teachers.csv", ios::in);
	string fileName;
	int index = 0;
	while (teacherFile.peek() != -1)
	{
		getline(teacherFile, fileName, ',');
		if (fileName == username)
		{
			teacherFile.close();
			return FetchTeacher(index);
		}
		getline(teacherFile, fileName, '\n');
		index++;
	}
	teacherFile.close();
	return Teacher();
}

Teacher LogInAsTeacher()
{
	string input;
	Teacher teacher;
	try
	{
		cout << "\nPlease enter your username: ";
		getline(cin, input);

		teacher = GetTeacherByUsername(input);
		if (teacher.username == "NULL")
		{
			throw (string)"\nUsername not found.";
		}

		for (int attempts = 3; attempts > 0; attempts--)
		{
			cout << "\n(Attempts remaining: " << attempts << ") Please enter your password: ";
			getline(cin, input);
			if (input == teacher.password)
			{
				cout << "\nYou have now logged in as " << teacher.username << endl;
				break;
			}
			else
			{
				cout << "\nYour password was incorrect." << endl;
			}
		}
	}
	catch (string error)
	{
		cout << endl << error << endl;
	}

	teacher.DisplayInfo();
	Sleep(15000);
	return teacher;
}

void TeacherAccountManagement()
{
	while (true)
	{
		int option = 0;
		system("CLS");
		cout << "-------------------------------------------------------" << endl;
		cout << "|     Emerald Hill High School Information System     |" << endl;
		cout << "|              Teacher Log In / Register              |" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "\n1. Log into an existing account\n2. Register a new account\n3. Return to Main Menu\n[Enter your option] ";
		option = GetIntInput(1, 4);
		switch (option)
		{
		case 1:
			LogInAsTeacher();
			break;
		case 2:
			RegisterNewTeacher();
			break;
		case 3:
			return;
		case 4:
			FetchTeachers();
			Sleep(15000);
			break;
		}
	}
}
=======
    // Jesse Simpson - Start
    int option; // Stores the user's option.
    ifstream inputDetails; // File identifier for reading purposes
    string str; // For storing getline data from the inputDetails file
    
    // Operates while the User has not exited. Not final, and is subject to change based on other functions/screens.
    do {
        // Output menu
        cout << "-------------------------------------------------------" << endl;
        cout << "|     Emerald Hill High School Information System     |" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "\n1. Contact Details";
        cout << "\n2. Events";
        cout << "\n3. Term Dates";
        cout << "\n4. Account Settings" << endl;
        cout << "\n5. Exit" << endl;
        cout << "\n[Enter your option:] ";
        
        cin >> option; // User Input for Menu Selection
        
        cout << "\n"; // New line so it doesn't look too close together, helping with readability

        // Menu options switch case. Account Settings does not work at this time, as I am waiting on the Login screen stuff to get underway.
        // Options 1-3 all do the same basic operation of reading from an existing txt file. Said txt file plans to be modifiable by an Admin.
        // Sleep only works on windows at this time.
        switch (option) {
        case 1:
            inputDetails.open("contactDetails.txt", ios::in);
            while (getline(inputDetails, str)) {
                cout << str << endl;
            }
            cout << "\n";
            inputDetails.close();
            Sleep(1500);
            break;
        case 2:
            inputDetails.open("eventDetails.txt", ios::in);
            while (getline(inputDetails, str)) {
                cout << str << endl;
            }
            cout << "\n";
            inputDetails.close();
            Sleep(1500);
            break;
        case 3:
            inputDetails.open("termDetails.txt", ios::in);
            while (getline(inputDetails, str)) {
                cout << str << endl;
            }
            cout << "\n";
            inputDetails.close();
            Sleep(1500);
            break;
        default: // Explaining that the user has inputted the incorrect number, clears screen before showing menu again. Only works on Windows.
            cout << "What you entered does not match the menu options listed, please try again." << endl;
            Sleep(1500);
            system("CLS");
        }
        } while (option != 5);

        // Jesse Simpson - End

        return 0;
 }
>>>>>>> origin/indev
