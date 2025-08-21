#include <iostream>
#include <string>
using namespace std;
class Student {
public :
    string name;
    int roll_number;
  void displayInfo(){
        cout << "the name is " << name << "\nthe id is " << roll_number << endl;
    }
};
int main (){
    Student student1;
    student1.name="kakarot";
    student1.roll_number=44;
    Student student2;
    student2.name="kushi";
    student2.roll_number=37;
    student1.displayInfo();
    student2.displayInfo();
    return 0;
}
