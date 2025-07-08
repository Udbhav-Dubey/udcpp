class Solution {
public:
    int partition(vector <int> &nums,int low,int high){
        int pivot=nums[high];
        int i=low-1;
        for (int j=low;j<=high;j++){
            if (nums[j]<=pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[j]);
        return i+1;
    }
    void quickSort(vector <int> &nums,int low,int high){
        if (low<=high){
            int pi=partition(nums,low,high);
            quickSort(nums,low,pi+1);
            quickSort(nums,pi-1,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
           quckSort(nums,0,nums.size()-1);
           return nums;
    }
};
