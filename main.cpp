#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// This is global variable, do not modify
#define MAX_STUDENTS 5

struct Student {
	int studentId;
	string studentName;
	float studentGrades;
};

/*!
* Function Prototypes
*/
void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
	Student students[MAX_STUDENTS];
	int count = 0;  // this keeps track of the students that are in the class
	int choice;     // user input

	/*!
	* Add the students here!
	*/
	//----------------------------------------------------------------------------------------

	Student student1 = { 12345, "Alice", 85.5 };
	Student student2 = { 10234, "Bobbi", 92.0 };
	Student student3 = { 10023, "Charlie", 78.0 };
	Student student4 = { 10002, "Daniel", 88.5 };
	Student student5 = { 54321, "Eva", 95.0 };

	students[0] = student1;
	students[1] = student2;
	students[2] = student3;
	students[3] = student4;
	students[4] = student5;
	count = 5;

	//----------------------------------------------------------------------------------------

	// Complete the menu with the associated function
	do {
		printMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();  // we add this to consume the leftover newline

		switch (choice) {
		case 1:
			highestGrade(students, count);
			break;
		case 2:
			lowestGrade(students, count);
			break;
		case 3:
			averageGrade(students, count);
			break;
		case 4:
			printStudentId(students, count);
			break;
		case 5:
			printStudentName(students, count);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}

void printMenu() {
	cout << "\n=== Student Record System ===\n";
	cout << "1. Find student with the highest grade\n";
	cout << "2. Find the student with the lowest grade\n";
	cout << "3. Find the average grade in the class\n";
	cout << "4. Print all the student's ID\n";
	cout << "5. Print all the student's names\n";
	cout << "6. Exit\n";
}

/* TODO: Implement these functions */

// Remeber, if you pass an array into a function, it is a pass by reference!
// Because arrays decay to pointers, so you are getting a pointer to the first element
// which allows you to modify the data. 

void highestGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	int maxIndex = 0;
	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades > students[maxIndex].studentGrades) {
			maxIndex = i;
		}
	}

	cout << "Student with the highest grade: " << students[maxIndex].studentName << " (ID: " << students[maxIndex].studentId << ") with grade: "<< students[maxIndex].studentGrades << endl;
}

void lowestGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	int minIndex = 0;
	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades < students[minIndex].studentGrades) {
			minIndex = i;
		}
	}

	cout << "Student with the lowest grade: " << students[minIndex].studentName << " (ID: " << students[minIndex].studentId << ") with grade: "<< students[minIndex].studentGrades << endl;
}

void averageGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float sum = 0.0;
	for (int i = 0; i < count; i++) {
		sum += students[i].studentGrades;
	}

	cout << "Average grade in the class: " << fixed << setprecision(2) << (sum / count) << endl;
}

void printStudentId(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	cout << "Student IDs:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentId << endl;
	}
}

void printStudentName(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	cout << "Student Names:\n";
	for (int i = 0; i < count; i++) {
		cout << students[i].studentName << endl;
	}
}
