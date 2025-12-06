#include <iostream>
#include <vector>
class DSU{
    private:
        std::vector<int>parent;
public:
    DSU(int n){
        parent.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x]==x){
            return x;
        }
        return find(parent[x]);
    }
    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (rx==ry)return ;
        parent[rx]=ry;
    }
};
int main (){
    int size=5;
    DSU dsu(size);
    dsu.unite(1,2);
    dsu.unite(3,4);
    bool inSameSet=(dsu.find(1)==dsu.find(2));
    std::cout << "Are 1 and 2 in same set ? " << (inSameSet?"Yes":"No") << std::endl;
    return 0;
}
