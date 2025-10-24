#include <iostream>
#include <string>

class CarEngine;

class Driver{
    private:
        std::string m_name;
        std::string m_gender;
        CarEngine* m_carEngine;
    public:
    Driver(const std::string& name,const std::string& gender,CarEngine* carEngine){
        m_name=name;
        m_gender=gender;
        m_carEngine=carEngine;
    }
    ~Driver(){}
    
    std::string getName(){
        return m_name;
    }
    std::string getGender(){
        return m_gender;
    }
    CarEngine* getCarEngine(){
        return m_carEngine;
    }
};

class CarEngine{
    private:
        bool running;
        Driver* driver;
        
    public:
        CarEngine(bool run,Driver* dr){
            running=run;
            driver=dr;
        }
        ~CarEngine(){}
    bool getTheState(){
        return running;
    }
    Driver* getDriver(){
        return driver;
    }
    void startRunning(){
        std::cout<<"Engine is running. "<<std::endl;
        running=true;
    }
    void stopRunning(){
        std::cout<<"Engine is stopped. "<<std::endl;
        running=false;
    }
    void changeDriver(Driver* newDriver){
        driver=newDriver;
        std::cout<<"The driver now is: "<<driver->getName()<<std::endl;

    }
};

int main(int argc,const char* argv[]){
    CarEngine engine(false,nullptr);
    Driver driver("Mesrop","female",&engine);
    engine.changeDriver(&driver);
    
    engine.startRunning();
    
    return 0;
}
