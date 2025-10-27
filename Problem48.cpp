#include <iostream>
#include <string>

class CarEngine;
class Car;

class Parking{
  private:
    std::string m_parkingName;
    int m_capacity;
    int count;
    Car** cars;
public:
    Parking(const std::string& park,int capacity){
        m_capacity=capacity;
        m_parkingName=park;
        count=0;
        cars=new Car*[capacity];
    }
    ~Parking(){
        delete[] cars;
    }
    int getCapacity(){
        return m_capacity;
    }
    int getCount(){
        return count;
    }
    void parkCar(Car* newCar){
        if(count>=m_capacity){
            std::cout<<"There is no free place! "<<std::endl;
        }
        else{
            cars[count++]=newCar;
        }
    }
};
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
        CarEngine& operator =(const CarEngine& other){
            if(this!=&other){
                this->running=other.running;
            }
            return *this;
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
    Car(const Car& other){
        this->m_model=other.m_model;
        this->m_engine=other.m_engine;
        this->m_driver=other.m_driver;
    }
    Car& operator =(const Car& other){
        if(this!=&other){
            this->m_model=other.m_model;
            this->m_engine=other.m_engine;
            this->m_driver=other.m_driver;
        }
        return *this;
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
