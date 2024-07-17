#include<iostream>
using std::string;


class Employee{
public:
    string Name;
    string Company;
    int Age;
    
    void hi(){
        std::cout<<"Name:"<<Name<<std::endl;
        std::cout<<"age:"<<Age<<std::endl;
    }
};
//everything in the c++ class is private by default 
//we have three access modifiers private public and protective
//whatever is preivate cant be accessed outside the class 
//public items can be accessed outside the class and can be changes
//protective means is in between pvt and public
int main()
{
    //class is user defined data type 
    int number;
    Employee employee1;
    employee1.Name="sid";
    employee1.Age=24;
    employee1.hi();
    Employee employee2;
    employee2.Name="ASJ";
    employee2.Age=80;
    employee2.hi();
}