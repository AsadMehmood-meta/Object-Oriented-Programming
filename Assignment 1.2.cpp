#include <iostream>
using namespace std;

double inputAmount();

class accounts {
	double* balance;
	
	public:
	
	//counsructor
	accounts (){
		setBalance(0);
	}
	
	void setBalance(double b) { balance = new double(b);}
	
	double getBalance() { return *balance;}
	
	void display(){
		cout<<"\nYour account balance : "<<getBalance()<<endl<<endl;
	}
	
	
	// Function to deposit money into the account
	void deposit(double amount) {	
   		 *balance += amount;
	}

	// Function to withdraw money from the account
	double withdraw(double amount) {
		
  	  if (*balance >= amount) {
  	      return *balance -= amount;
  	  } else {
  	      cout << "Insufficient funds!" << endl;
 	       return *balance;
 	   }
	}

};

int main() {
    accounts account1;
    
    //set balance 
    double balance =0;
    cout<<"Set account balance: ";
    cin>>balance;
    account1.setBalance(balance);
    
    account1.display();
    
    // Perform a deposit
    cout<<"How much amount you want to deposit: ";
	double amountDeposit = inputAmount();
	account1.deposit(amountDeposit);
	
	account1.display();

    // Perform a withdrawal
    cout<<"How much amount you want to withdraw: ";
	double amountWithdraw = inputAmount();
	account1.withdraw(amountWithdraw);
	
	account1.display();

    // Try to withdraw an amount greater than the balance
    cout<<"How much amount you want to withdraw: ";
	amountWithdraw = inputAmount();
	account1.withdraw(amountWithdraw);
	
	account1.display();

    return 0;
}

double inputAmount(){
	while(1){
	double amount =0;
	cin>>amount;
	if (amount<0){
		cout<<"Invalid amount. Plz input valid amount.\n";
	}	else{
		return amount;
	}
	}
}
