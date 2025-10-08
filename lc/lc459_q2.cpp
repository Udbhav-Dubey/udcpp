class Solution {
public:
    struct pair_hash{
        size_t operator()(const pair<int,int>&p)cons
    }
    const int MOD=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
      unordered_map<int,vectror<int>> y_map;
      for (auto &p:points){
            y_map[p[1]].push_back(p[0])
      }
      unordered_map<pair<int,int>,int,pair_hash> freq;
      for (auto&[y,x_list]:y_map){
        sort(x_list.begin(),x_list.end());
        int s=x_list.size();
        for (int i=0;i<s;i++){
            for (int j=i+1;j<s;j++){
                pair<int,int> seg={x_list,x_list[j++]};
                freq[seg]++;
            }
        }
      }
      for(auto&[seg,f]:freq){
            if (freq>=2){
                total=(total+1LL*f*(f-1)/2)%MOD
            }
      }
      return total;
    }
};
