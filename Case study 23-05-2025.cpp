#include <iostream>
#include <string>

using namespace std;

//Base class
class Payment{
	private:
		float amount;
	
	public:
		//default constructor
		Payment(){
			setAmount(0);
			cout<<"Payment constructor called.\n";
		}
			
		//setters
		void setAmount(const float a){
			amount = a;
		}
		
		//getters
		float getAmount(){
			return amount;
		}
};

//Derived class for cash
class Cash : public Payment{
	private:
		float cashTendered;
	
	public:
		//default constructor
		Cash(){
			setCashTendered(0);
			cout<<"Cash constructor called.\n\n";
		}
		
		//setters
		void setCashTendered(const float cT){
			cashTendered = cT;
		}
		
		//getters
		float getCashTendered(){
			return cashTendered;
		}
};

//Derived class for cheque
class Cheque : public Payment{
	private:
		string name , bankID;
	
	public:
		//default constructor
		Cheque(){
			setName("No Name");
			setBankID("0000");
			cout<<"Cheque constructor called.\n\n";
		}
		
		//setters
		void setName(const string n){
			name = n;
		}
		
		void setBankID(const string bID){
			bankID = bID;
		}
		
		//getters
		string getName(){
			return name;
		}
		
		string getBankID(){
			return bankID;
		}
		
		//member function
		void authorized(){
			cout<<"Cheque authorized function called.";
		}
};

//Derived class for credit card
class CreditCard : public Payment{
	private:
		string name , type;
	
	public:
		//default constructor
		CreditCard(){
			setName("No Name");
			setType("Default Type");
			cout<<"Credit card constructor called.\n\n";
		}
		
		//setters
		void setName(const string n){
			name = n;
		}
		
		void setType(const string t){
			type = t;
		}
		
		//getters
		string getName(){
			return name;
		}
		
		string getType(){
			return type;
		}
		
		//member function
		void authorized(){
			cout<<"Credit card authorized function called.";
		}
};

int main(){
	
	cout<<"-----Cash object called-----\n\n";
	Cash cash1;
	cout<<"Cash Amount: "<<cash1.getAmount()<<endl;
	cout<<"Cash tendered: "<<cash1.getCashTendered()<<endl;
	
	cout<<"\n-----Cheque object called-----\n\n";
	Cheque cheque1;
	cout<<"Cheque Amount: "<<cheque1.getAmount()<<endl;
	cout<<"Cheque Name: "<<cheque1.getName()<<endl;
	cout<<"Cheque Bank ID: "<<cheque1.getBankID()<<endl;
	cheque1.authorized();
	
	cout<<"\n\n------Credit Card object called-------\n\n";
	CreditCard CC1;
	cout<<"Credit Card Amount: "<<CC1.getAmount()<<endl;
	cout<<"Credit Card Name: "<<CC1.getName()<<endl;
	cout<<"Credit Card Type: "<<CC1.getType()<<endl;
	CC1.authorized();
	
	return 0;
}
