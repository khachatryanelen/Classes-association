#include <iostream>
#include <string>

class CarEngine;


class Driver{
    private:
        std::string m_name;
        std::string m_gender;
    public:
    Driver(const std::string& name,const std::string& gender){
        m_name=name;
        m_gender=gender;
    }
    ~Driver(){}
    
    std::string getName(){
        return m_name;
    }
    std::string getGender(){
        return m_gender;
    }
};

class CarEngine{
    private:
        bool running;

    public:
        CarEngine(){
            running=false;
        }
        CarEngine(bool run){
            running=run;
        }
        ~CarEngine(){}
    bool getTheState(){
        return running;
    }
    void setRunning(bool run){
        running=run;
    }

    void startRunning(){
        std::cout<<"Engine is running. "<<std::endl;
        running=true;
    }
    void stopRunning(){
        std::cout<<"Engine is stopped. "<<std::endl;
        running=false;
    }
};
class Car{
    private:
        CarEngine m_engine;
        std::string m_model;
        Driver* m_driver;
    public:
    Car(const std::string& model,bool running,Driver* driver){
        m_model=model;
        m_engine.setRunning(running);
        m_driver=driver;
    }
    ~Car(){}
    std::string getModel(){
        return m_model;
    }
    Driver* getDriver(){
        return m_driver;
    }
    void startCar() {
        std::cout << "Car " << m_model << " is starting..." << std::endl;
        m_engine.startRunning();
    }

    void stopCar() {
        std::cout << "Car " << m_model << " is stopping..." << std::endl;
        m_engine.stopRunning();
    }
    void changeDriver(Driver* newDriver){
        m_driver=newDriver;
        std::cout<<"The driver now is: "<<m_driver->getName()<<std::endl;
    }
};

int main(int argc,const char* argv[]){
    Driver driver1("Mesrop", "male");
    Car myCar("Toyota ", false, &driver1);

    myCar.startCar();

    Driver driver2("Elena", "female");
    myCar.changeDriver(&driver2);

    myCar.stopCar();
    
    return 0;
}
