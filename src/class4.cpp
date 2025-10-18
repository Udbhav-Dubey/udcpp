#include <iostream>
using namespace std;
class parent {
    protected :
        int pro_id;
};
class child : public parent {
    public : 
        void SetId (int id){
        pro_id = id;
        }
        int getId(){
            return pro_id;
        }
};
int main (){
    child obj;
    obj.SetId(10);
    cout << "ID : " << obj.getId();
return 0;
}
