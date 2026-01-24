class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ce=0;
        int n=nums.size();
        if (n==1){return 1;}
        int i=0;
        int maxy=0;

        while(i<nums.size()-1){
            maxy=max(maxy,i+nums[i]);
            if (i==ce){
                ce=maxy;
           
            if (i>=n-1){return 1;}
            }
        }
        return 0;       
    }
};
