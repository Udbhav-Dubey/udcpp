#include <vector>
#include <iostream>
class DSU{
    std::vector<int>parent;
    std::vector<int>size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for (int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if (parent[x]==x){
            return x;
        }
        return parent[x]==find(parent[x]);
    }
    void unite(int x,int y){
        int rx=find(x);
        int ry=find(y);
        if (size[rx]<size[ry]){
            parent[rx]=ry;
            size[ry]+=size[rx];
        }
        else {
            parent[ry]=rx;
            size[rx]+=size[ry];
        }
    }
};
int main (){
    DSU dsu(7);
    dsu.unite(1,2);
    dsu.unite(2,3);
    dsu.unite(4,5);
    dsu.unite(1,4);
    for (int i=0;i<7;i++){
        std::cout << "Element " << i << "has representative : " << dsu.find(i) << std::endl;
    }
    return 0;
}
