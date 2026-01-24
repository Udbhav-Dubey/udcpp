class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        if (n==1){return 0;}
        int sum=nums[0];
        int maxy=0;
        int ce=0;
        for (int i=0;i<n-1;i++){
                maxy=max(maxy,i+nums[i]);
            if (i==ce){
                count++;
                ce=maxy;
            if (i>=n-1){break;}
            }
            }
        return count;
    }
};
