#include <bits/stdc++.h>
using namespace std;
class Person{
private:
    string name{};
    int age{};
public:
    Person(string n,int a):name{n},age{a} {}
    const string getname()const{return name;}
    int getage()const{return age;}
};
class employee{
    private:
        string employer{};
        double wage{};
    public:
        employee(string empoyer,double w):employer{empoyer},wage{w} {}
        const string getemployer()const {return employer;}
        double getwage()const {return wage;}
};
class Teacher:public Person,public employee{
    private:
        int grade{};
    public:
        Teacher(string n,int a,string e,double w,int g):Person{n,a},employee{e,w},grade{g}{}
};
int main (){
    Teacher t{"A",45,"B",13.4,2};
return 0;
}
