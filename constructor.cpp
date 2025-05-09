#include <iostream>
#include <string>

using namespace std;

class Students {
    int age;
    string firstName , lastName , email , cnic;

    
    public:
    // my constructor
    Students() {
        setFirstName("No");
        setLastName("Name");
        setAge(00);
        setEmail("abcd@xyz.com");
        setCnic("00000-0000000-0");
    }

    Students(string fN , string lN , int a, string eM , string c) {
        setFirstName(fN);
        setLastName(lN);
        setAge(a);
        setEmail(eM);
        setCnic(c);
	}
    
    // my setters
    void setFirstName(string fN) {
        firstName = fN;
    }
    void setLastName(string lN) {
        lastName = lN;
    }
    void setAge(int a) {
        age = a;
    }
    void setEmail(string eM) {
        email = eM;
    }
    void setCnic(string c) {
        cnic = c;
    }
    // my getters
    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    int getAge() {
        return age;
    }
    string getEmail() {
        return email;
    }
    string getCnic() {
        return cnic;
    }
    void getAllDetails() {
        cout<<"Name:\t"<<getFirstName()<<" "<<getLastName()<<endl<<"Age:\t"<<getAge()<<endl<<"email:\t"<<getEmail()<<endl<<"CNIC:\t"<<getCnic()<<endl<<endl;
    }
};

void inputStudentsData(Students* , int);
void displayStudentsData(Students* , int);
int validateAge();
int validateSize();

int main() {
	int size=0;
	cout<<"Hello Admin!\nEnter total students: ";
	size = validateSize();
	Students* s = new Students[size];
	
	inputStudentsData(s , size);
	displayStudentsData(s , size);
    
    return 0;
}

void inputStudentsData(Students* s , int size){
	for(int i=0 ; i<size ; i++){
        string fN, lN, eM, c;
        int a;
        
        cout << "\nEnter details for student " << i+1 << ":\n";
        cout << "First Name: ";
        cin.get();
        getline(cin , fN);
        cout << "Last Name: ";
        cin.get();
        getline(cin , lN);
        cout << "Age: ";
        a = validateAge();
        cout << "Email: ";
        cin >> eM;
        cout << "CNIC: ";
        cin >> c;
        
        s[i] = Students(fN, lN, a, eM, c);
    }
}

void displayStudentsData(Students* s , int size){
	cout<<"\n\nStudents details.\n\n";
	
	for(int i=0 ; i<size ; i++){
		cout<<"Students # "<<i+1<<endl;
		s[i].getAllDetails();
	}
}

int validateAge(){
	int a=0;
	while(true){
		cin>>a;
		if(a<1){
			cout<<"Invalid input. Note: age must be greater than 0.\n";
		} else{
			return a;
		}
	}
}

int validateSize(){
	int a=0;
	while(true){
		cin>>a;
		if(a<1){
			cout<<"Invalid input. Note: Students must be greater than 0.\n";
		} else{
			return a;
		}
	}
}
