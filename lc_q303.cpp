class NumArray {
private : vector <int> psum;
public:
    NumArray(vector<int>& nums) {
        psum.resize(nums.size()+1);
        psum[0]=0;
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            psum[i+1]=sum;
        }
    }
    int sumRange(int left, int right) {
        if (left==0){return psum[right+1];}
        int answer=psum[right+1]-psum[left];
        return answer;
    }
};

