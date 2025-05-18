#include <iostream>
#include <cstring>
using namespace std;

class Student {

    char* name;
    int rollNumber;
    int mathMarks;
    int englishMarks;
    int scienceMarks;
    int totalMarks;

    void calculateTotal() {
        totalMarks = mathMarks + englishMarks + scienceMarks;
    }

public:
    // default constructor
    Student() {
        name = new char[1];
        name[0] = '\0';
        rollNumber = mathMarks = englishMarks = scienceMarks = totalMarks = 0;
    }

    // parameterized constructor - name, roll, marks
    Student(const char* n, int roll, int math, int eng, int sci) {
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
        this->rollNumber = roll;
        this->mathMarks = math;
        this->englishMarks = eng;
        this->scienceMarks = sci;
        this->calculateTotal();
    }

    // parameterized constructor - name only
    Student(const char* n) {
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
        this->rollNumber = mathMarks = englishMarks = scienceMarks = totalMarks = 0;
    }

    // parameterized constructor - roll and marks
    Student(int roll, int math, int eng, int sci) {
        this->name = new char[1];
        name[0] = '\0';
        this->rollNumber = roll;
        this->mathMarks = math;
        this->englishMarks = eng;
        this->scienceMarks = sci;
        this->calculateTotal();
    }

    // copy constructor
    Student(const Student& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->rollNumber = other.rollNumber;
        this->mathMarks = other.mathMarks;
        this->englishMarks = other.englishMarks;
        this->scienceMarks = other.scienceMarks;
        this->totalMarks = other.totalMarks;
    }

    // setters
    void setName(const char* n) {
        delete[] this->name;
        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
    }

    void setRollNumber(int roll) {
        this->rollNumber = roll;
    }

    void setMarks(int math, int eng, int sci) {
        this->mathMarks = math;
        this->englishMarks = eng;
        this->scienceMarks = sci;
        this->calculateTotal();
    }

    // getters
    const char* getName() const {
        return name;
    }

    int getRollNumber() const {
        return rollNumber;
    }

    int getTotalMarks() const {
        return totalMarks;
    }

    // display function
    void displayStudent() const {
        cout << "Name: " << name << "\t|  Roll No: " << rollNumber
             << "  |\t Math: " << mathMarks << ",\t English: " << englishMarks
             << ",\t Science: " << scienceMarks << "\t|\t Total: " << totalMarks << endl;
    }

    // destructor
    ~Student() {
        cout << "Deleting student: " << name << endl;
        delete[] name;
    }
};

// selection sort based on totalMarks in descending order
void sortStudents(Student* students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (students[j]->getTotalMarks() > students[maxIdx]->getTotalMarks()) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            Student* temp = students[i];
            students[i] = students[maxIdx];
            students[maxIdx] = temp;
        }
    }
}

int main() {
    const int numStudents = 5;
    Student* students[numStudents];

    // using various constructors and setters
    students[0] = new Student("Ali", 101, 85, 90, 78);
    students[1] = new Student("Asad");
    students[1]->setRollNumber(102);
    students[1]->setMarks(70, 75, 80);

    students[2] = new Student(103, 65, 60, 70);
    students[2]->setName("Usama");

    students[3] = new Student("Farhan", 104, 95, 88, 92);

    students[4] = new Student(*students[3]);  // copy constructor
    students[4]->setName("Waqas");

    cout << "Before Sorting:\n";
    for (int i = 0; i < numStudents; i++) {
        students[i]->displayStudent();
    }

    sortStudents(students, numStudents);

    cout << "\nAfter Sorting by Total Marks (Descending):\n";
    for (int i = 0; i < numStudents; i++) {
        students[i]->displayStudent();
    }
	
	cout<<endl<<endl;
	
    // free memory
    for (int i = 0; i < numStudents; i++) {
        delete students[i];
    }

    return 0;
}

