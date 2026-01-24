#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>&nums,vector<int>&temp,int &answer,int left,int mid,int right){
    //    int n1=mid-left+1;
    //    int n2=right-mid;
    //    vector<long long>l1(n1);
    //    vector<long long >l2(n2);
     //   for (int i=0;i<n1;i++){
       //     l1[i]=nums[left+i];
//            cout << l1 [i] << " "; 
        //}
    //    cout << "\n";
        //for (int i=0;i<n2;i++){
          //  l2[i]=nums[mid+i+1];
  //        //  cout << l2[i] << "\n";
        //}
        int j=mid+1;
        for (int i=left;i<=mid;i++){
            while(j<=right&&(long long)nums[i]>2LL*nums[j]){
                j++;
            }
            answer+=(j-(mid+1));
                }
        int i=left,k=left;
        j=mid+1;
        while(i<=mid&&j<=right){
            if (nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else {temp[k++]=nums[j++];}
        }
        while(i<=mid){
            temp[k++]=nums[i++];
        }
        while(j<=right){
            temp[k++]=nums[j++];
        }
        for (int p=left;p<=right;p++){
            nums[p]=temp[p];
        }
    }
    void solver(vector<int>&nums,vector<int>&temp,int &answer,int left,int right){
        if (left>=right){return ;}
        int mid=left+(right-left)/2;
        solver(nums,temp,answer,left,mid);
        solver(nums,temp,answer,mid+1,right);
        merge(nums,temp,answer,left,mid,right);
    }
    int reversePairs(vector<int>& nums) {
        int answer=0;
        int n=nums.size();
        int left=0;
        int right=n-1;
        vector<int>temp(nums.size());
        solver(nums,temp,answer,left,right);
        return answer;
    }
};
int main (){
    Solution sol;
    vector<int>test1={1,3,2,3,1};
    vector<int>test2={2,4,3,5,1};
    cout << "\nl1[i] l2[j]\n";
    cout << "test 1 -> \n" << sol.reversePairs(test1);
    cout << "\nl1[i] l2[j]\n";
    cout << "\ntest 2 -> \n" << sol.reversePairs(test2) << endl;
    vector<long long >test3;
    int x;
    return 0;
}
