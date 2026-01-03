class Solution{
    public:
        vector<int>parents;
        vector<int>ranks;
        void DSU(int n){
            parents.resize(n);
            ranks.resize(n,0);
            for (int i=0;i<n;i++){
                parents[i]=i;
            }
        }
        int find(int x){
            if (parents[x]==x){return x;}
            return parents[x]=find(parents[x]);
        }
        void unite(int x,int y){
            int rx=find(x);
            int ry=find(y);
            if (rx==ry){return ;}
            if (ranks[rx]>ranks[ry]){
                parents[ry]=rx;
            }
            else if (ranks[ry]>ranks[rx]){
                parents[rx]=ry;
            }
            else {
                parents[ry]=rx;
                ranks[rx]++;
            }
        }
            bool equationsPossible(vector<string>& equations) {
                DSU(26);
                for (auto &eq:equations){
                    if (eq[1]=='='){
                        unite((eq[0]-'a'),(eq[3]-'a'));
                    }
                }
                for (auto &eq:equations){
                    if (eq[1]=='!'){
                        if (find((eq[0]-'a'))==find((eq[3]-'a'))){
                            return false;
                        }
                    }
                }
                return true;
            }
};
