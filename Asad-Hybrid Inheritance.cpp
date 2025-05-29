#include<iostream>
#include<string>
using namespace std;

//base class
class Device{
	protected:
	string brand , model;
	
	public:
		//default constructor
		Device(): brand("No Brand") , model("####"){}
		
		//parameterized constructor
		Device(const string& b , const string& m): brand(b) , model(m){}
		
		//destructor
		virtual~ Device(){
			cout<<"\nDevice destructor called.";
		}
		
		//display function
		void displayDeviceInfo()const{
		cout<<"\nBrand\t\t\t:\t"<<brand;
		cout<<"\nModel\t\t\t:\t"<<model;
		}
};

//derived class 1 from base class
class Sensor: virtual protected Device{
	protected:
		string sensorType;
		
	public:
		//default constructor
		Sensor(): sensorType("Nil"){
		}
		
		//parameterized constructor
		Sensor(const string& b , const string& m , const string& sT): 
		Device(b , m) , sensorType(sT){
		}
		
		//destructor
		~Sensor(){
			cout<<"\nSensor destructor called.";
		}
		
		//display function
		void displaySensorInfo()const{
			cout<<"\nSensor Type\t\t:\t"<<sensorType;
		}
};

//derived class 2 from base class
class Actuator : virtual protected Device{
	protected:
		string actuatorType;
		
	public:
		//default constructor
		Actuator(): actuatorType("Nil"){
		}
		
		//parameterized constructor
		Actuator(const string& b , const string& m , const string& aT)
		: Device(b , m) , actuatorType(aT){
		}
		
		//destructor
		~Actuator(){
			cout<<"\nActuator destructor called.";
		}
		
		//display function
		void displayActuatorInfo()const{
			cout<<"\nActuator Type\t\t:\t"<<actuatorType;
		}
};

//final derived class from Sensor and Actuator
class SmartDevice : protected Sensor , protected Actuator{
	private:
		string connectivityType;
		
	public:
		//default constructor
		SmartDevice(): connectivityType("Nil"){	
		}
		
		//parameterized constructor
		SmartDevice(const string& b , const string& m , const string& sT , const string& aT , const string& cT)
		: Device(b, m), Sensor(b , m ,sT) , Actuator(b , m , aT) , connectivityType(cT){	
		}
		
		//destructor
		~SmartDevice(){
			cout<<"\nSmartDevice destructor called.";
		}
		
		//setter
		void setConnectivityType(const string& cT){
			connectivityType = cT;
		}
		
		//getter
		string getConnectivityType()const{
			return connectivityType;
		}
		
		//display function
		void displaySmartDeviceInfo()const{
			displayDeviceInfo();
			displaySensorInfo();
			displayActuatorInfo();
			cout<<"\nConnectivity Type\t:\t"<<getConnectivityType();
		}
};


int main(){
	SmartDevice s1;
	cout<<"-----Display default values-----\n";
	s1.displaySmartDeviceInfo();
	
	cout<<"\n\n-----Display set values-----\n";
	
//	SmartDevice(brand , model , sensor type , actuator type , connectivity type)
	SmartDevice s2("Siemens" , "2024" , "Motion" , "Light switch" , "Wifi");
	s2.displaySmartDeviceInfo();
	
	cout<<endl;
	
	return 0;
}
