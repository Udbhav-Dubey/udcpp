#include <iostream>
#include <vector>
using namespace std;
int maxSubArray (int* nums,int numsSize){
    int max_t=0;
    int max=0;
    for (int i=0;i<numsSize;i++){
        if (max_t<i){
            continue;
        }
        max_t+= nums[i];
        
    }
    return max_t;
}
int main (){
        cout << "please enter the size of array : ";
        int numsSize;
        cout << "please enter the array\n";
        vector <int >nums(numsSize);
        for (int i=0;i<numsSize;i++){
            cin >> nums[i];
        }
        cout << "the output is " << maxSubArray(& nums,numsSize) << endl;
return 0;
}
