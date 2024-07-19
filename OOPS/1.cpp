#include<iostream>
using std::string;

class Employee {
private:
    string Name;
    string Company;
    int Age;

public:
    // Setter for Name
    void setName(string name) {
        Name = name;
    }

    // Getter for Name
    string getName() {
        return Name;
    }

    // Setter for Age
    void setAge(int age) {
        if (age >= 18)
            Age = age;
    }

    // Getter for Age
    int getAge() {
        return Age;
    }

    // Method to display employee details
    void hi() {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Age: " << Age << std::endl;
    }

    // Constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
};

// everything in the C++ class is private by default 
// we have three access modifiers private public and protected
// whatever is private can't be accessed outside the class 
// public items can be accessed outside the class and can be changed
// protected means is in between private and public

int main() {
    // class is user defined data type 
    int number;
    Employee employee1 = Employee("Sid", "yt", 24); // originally we just had Employee employee1; that was because by default there is a constructor
    // here we made our own constructor

    // employee1.Name = "sid";
    // employee1.Age = 24;
    employee1.hi();
    Employee employee2 = Employee("AJS", "yt", 30);
    // employee2.Name = "ASJ";
    // employee2.Age = 80;
    employee2.hi();

    employee1.setName("Ohio");
    std::cout << employee1.getName() << " is ";

    employee1.setAge(20);
    std::cout << employee1.getAge() << std::endl;

    return 0;
}

// constructor is a special type of method that is invoked each time an object of the class is created in this case employee
// constructor does not have a return type
// constructor has the same name as the class that it belongs to
// constructor in general has to be public

/*
Encapsulation is the idea of bundling data and methods that operate on that data so that they are grouped together
within a class. We do this with the purpose of preventing anyone or anything outside of our class from being able to directly 
access our data and to interact with it and to modify it.
 */

/*
Abstraction hiding  complex thing behind a procedure that make things looks simple
*/