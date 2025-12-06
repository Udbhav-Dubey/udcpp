#include <vector>
#include <iostream>
class DSU{
    std::vector<int>parent;
    std::vector<int>rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (rx==ry)return ;
        if (rank[rx]<rank[ry]){
            parent[rx]=ry;
        }
        else if (rank[ry]<rank[rx]){
            parent[ry]=rx;
        }
        else {
            parent[ry]=rx;
            rank[rx]++;
        }
    }
};
int main (){
    DSU dsu(7);
    dsu.unite(1,2);
    dsu.unite(2,3);
    dsu.unite(4,5);
    std::cout << "Find(3)= " << dsu.find(3) << std::endl;
    std::cout << "Find(5)= " << dsu.find(5) << std::endl;
    if (dsu.find(2)==dsu.find(3)){
        std::cout << "2 and 3 are in same set\n";
    }
    else std::cout << "2 and 3 are in diff set\n";
    if (dsu.find(1)==dsu.find(5)){
        std::cout << "1 and 5 are in same set \n";
    }
    else std::cout << "1 and 5 are in diff set\n";
    return 0;
}
