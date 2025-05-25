#include <iostream>
#include <string>
using namespace std;

//base class 1
class User{
	private:
		string name , joiningDate;
		
	public:
		//default constructor
		User(){
			setName("No Name");
			setJoiningDate("##-##-####");
		}
		
		//destructor
		virtual ~User(){
			cout<<"\nUser destructor called.";
		}
		
		//setters
		void setName(const string& n){
			name = n;
		}
		void setJoiningDate(const string& jD){
			joiningDate = jD;
		}
		
		//getters
		string getName()const{
			return name;
		}
		string getJoiningDate()const{
			return joiningDate;
		}
};

//base class 2
class Payment{
	private:
		string currency , doneOn;
		int paymentID;
		float amount;
		
	public:
		//default constructor
		Payment(){
			setPaymentID(0);
			setCurrency("Pkr");
			setAmount(0.0f);
			setDoneOn("##-##-####");
		}
		
		//destructor
		virtual ~Payment(){
			cout<<"\nPayment destructor called.";
		}
		
		//setters
		void setPaymentID(int pID){
			paymentID = pID;
		}
		void setCurrency(const string& cur){
			currency = cur;
		}
		void setAmount(float am){
			amount = am;
		}
		void setDoneOn(const string& dOn){
			doneOn = dOn;
		}
		
		//getters
		int getPaymentID()const{
			return paymentID;
		}
		string getCurrency()const{
			return currency;
		}
		float getAmount()const{
			return amount;
		}
		string getDoneOn()const{
			return doneOn;
		}
};

//derived class inherit both base classes
class Gym : public User , public Payment{
	public:
		//deafulat constructor
		Gym(){
		}
		
		//parameterized constructor
		Gym(const string& n , const string& jD , int pID , const string& cur , float am , const string& dOn){
			setName(n);
			setJoiningDate(jD);
			setPaymentID(pID);
			setCurrency(cur);
			setAmount(am);
			setDoneOn(dOn);
		}
		
		//destructor
		~Gym(){
			cout<<"\nGym destructor called.";
		}
		
		//member functions
		void addUser(const string& n , const string& jD){
			setName(n);
			setJoiningDate(jD);
		}
		void addPayment(int pID , const string& cur , float am , const string& dOn){
			setPaymentID(pID);
			setCurrency(cur);
			setAmount(am);
			setDoneOn(dOn);
		}
		
		//display function
		void displayGym(){
			cout<<"\nName\t\t:\t"<<getName();
			cout<<"\nJoining Date\t:\t"<<getJoiningDate();
			cout<<"\nPayment ID\t:\t"<<getPaymentID();
			cout<<"\nAmount\t\t:\t"<<getAmount()<<" "<<getCurrency();
			cout<<"\nPayment date\t:\t"<<getDoneOn();
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
		
		cout<<"Currency: ";
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
