class Solution {

public:

    bool isPossibleToSplit(vector<int>& nums) {

        if (nums.size()==2){

            return true;

        }

        unordered_map<int,int>freq;

        for (auto i:nums){

            freq[i]++;

        }

        for (auto it : freq) {

     if (it.second > nums.size() / 2 || ( it.second>2 ) )return false;

    }

        return true;

    }

};
