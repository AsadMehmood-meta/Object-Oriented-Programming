#include <iostream>
#include <string>
using namespace std;

//base class 1
class User{
	protected:
		string name , joiningDate;
		
	public:
		//default constructor
		User(){
			name = "No Name";
			joiningDate = "##-##-####";
		}
		
		//destructor
		virtual ~User(){
			cout<<"\nUser destructor called.";
		}

};

//base class 2
class Payment{
	protected:
		string currency , doneOn;
		int paymentID;
		float amount;
		
	public:
		//default constructor
		Payment(){
			paymentID = 0;
			currency = "Pkr";
			amount = 0.0f;
			doneOn = "##-##-####";
		}
		
		//destructor
		virtual ~Payment(){
			cout<<"\nPayment destructor called.";
		}
		
};

//derived class inherit both base classes
class Gym : protected User , protected Payment{
	public:
		//deafulat constructor
		Gym(){
		}
		
		//parameterized constructor
		Gym(const string& n , const string& jD , int pID , const string& cur , float am , const string& dOn){
			name = "No Name";
			joiningDate = "##-##-####";
			paymentID = 0;
			currency = "Pkr";
			amount = 0.0f;
			doneOn = "##-##-####";
		}
		
		//destructor
		~Gym(){
			cout<<"\nGym destructor called.";
		}
		
		//member functions
		void addUser(const string& n , const string& jD){
			name = n;
			joiningDate = jD;
		}
		void addPayment(int pID , const string& cur , float am , const string& dOn){
			paymentID = pID;
			currency = cur;
			amount = am;
			doneOn = dOn;
		}
		
		//display function
		void displayGym(){
			cout<<"\nName\t\t:\t"<<name;
			cout<<"\nJoining Date\t:\t"<<joiningDate;
			cout<<"\nPayment ID\t:\t"<<paymentID;
			cout<<"\nAmount\t\t:\t"<<amount<<" "<<currency;
			cout<<"\nPayment date\t:\t"<<doneOn;
		}
};

void assignValues(Gym*  , int size); //function to assign values in every object by user input
void displayGymArray(Gym*  , int size); //function to display every object

int main(){
	int size = 0;		//how many objects created
	
	cout<<"-----GYM Management System-----\n\n";
	cout<<"How many members in your gym: ";
	cin>>size;
	cin.ignore();
	cout<<endl;
	
	Gym* gym = new Gym[size];
	
	assignValues(gym , size);
	displayGymArray(gym , size);	
	delete[] gym;
	
	return 0;
}

//function to display every object
void displayGymArray(Gym* gym , int size){
	for(int i=0 ; i<size ; i++){
		cout<<"Gym object "<<i+1<<" info:";
		gym[i].displayGym();
		cout<<endl<<endl;
	}
}

//function to assign values in every object by user input
void assignValues(Gym* gym , int size){
	int pID;
	string n , jD , cur , pD;
	float am;
	
	for(int i=0 ; i<size ; i++){
		cout<<"Assign details of member "<<i+1<<":\n";
		
		cout<<"Name: ";
		getline(cin , n);
		
		cout<<"Joining Date (DD-MM-YYYY): ";
		getline(cin , jD);
		
		gym[i].addUser(n , jD);
		
		pID = i+1001;
		
		cout<<"Currency (Pkr, Usd, etc): ";
		getline(cin , cur); 
		
		cout<<"Amount: ";
		cin>>am;
		
		cout<<"Payment date: ";
		cin.ignore();
		getline(cin , pD);
		
		gym[i].addPayment(pID , cur , am , pD);
		cout<<endl<<endl;
	}
}
