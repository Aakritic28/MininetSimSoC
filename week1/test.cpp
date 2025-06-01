#include<iostream>
#include<utility>
#include <string>

using namespace std;
struct Employee{
    int id {};
    int age {};
    float salary {};
};
template<typename T, typename U>
void print(pair<T,U> p){
    cout << p.first << " " <<p.second<<endl;
}

class A
{
public:
    virtual std::string getName() const { return "A"; }
};

class B: public A
{
public:
    virtual std::string getName() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string getName() const { return "C"; }
};
class D: public C
{
public:
    virtual std::string getName() const { return "D"; }
};

template<typename T>
struct triad{
 T one;
 T two;
 T three;
};

void printemp(Employee& e){
    cout<< e.id << " " << e.age << " " << e.salary <<endl;
}
int main(){
    Employee jay{1, 23, 34000};
    ++jay.age;
    Employee maya{2, 22, 45000};
    Employee *ptr =&maya;
    ptr->age = 45;
    printemp(jay);
    pair<int, float> p{2.3444, 78990.90};
    print(p);
    triad<int> t{1,2,89};
    cout << t.three << endl;
    D d{};
    C& c{d};
    A a{c};
    cout << "rbase is a "<<a.getName()<<endl;
}

// ptr -> c is equivalent (*ptr).c