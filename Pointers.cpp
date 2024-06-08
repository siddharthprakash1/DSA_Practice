/*
#include<iostream>
using namespace std;

int main (){
    int* a=new int(11);
    int* b=a;
    cout<<"num1="<<a <<endl;
    cout<<"num=2"<<b;
}
OUTPUT:
num1=0xf31990
num=20xf31990
*/

/*
#include<iostream>
using namespace std;

int main (){
    int* a=new int(11);
    int* b=a;
    cout<<"num1="<<*a <<endl;
    cout<<"num2="<<*b;
}
OUPUT:
num1=11
num2=11
*/


/*
#include<iostream>
using namespace std;
int main(){
    class cookie{
        private:
            string color;
        public:
            cookie(string color){
                this->color=color;
            }
            string getcolor(){
                return color;
            }
            void setcolor(string color){
                this->color=color;
            }
    };
cookie* cookieone= new cookie("Green");
cookie* cookietwo= new cookie("Blue");

cout<<"C1:"<<cookieone->getcolor()<<endl;
cout<<"C2:"<<cookietwo->getcolor()<<endl;
cookieone->setcolor("yellow");
cout<<"C1:"<<cookieone->getcolor()<<endl;
}
OUTPUT:
C1:Green
C2:Blue
C1:yellow
*/