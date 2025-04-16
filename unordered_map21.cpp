#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<int,int>freak;
    freak={{1,44},{2,22},{3,11}};
    for (auto i : freak){
        cout << "(" << i.first << ", " << i.second << ")";
        cout << "is in bucket= " << freak.bucket(i.first) << endl;
    }
    cout << endl;
    int n=freak.bucket_count();
    cout << "map has " << n << "buckets.\n\n";
    for (int i=0;i<n;i++){
        cout << "bucket " << i << "has" << freak.bucket_size(i) << " elements.\n";
    }
return 0;
}
