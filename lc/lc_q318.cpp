#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector <int> mask(word.size());
        for (int i=0;i<words.size();i++){
            for (int j=0;j<words[i].size();j++){
                 mask[i]|=(1<<(words[i][j]-'a'))
            }
        }
        int maxi=0;
        for (int i=0;i<words.size();i++){
            for (int j=i+1;j<words.size();j++){
                    if ((mask[i]&mask[j])==0){
                        int current=(words[i].size()+1)*(words[j].size()+1);
                        if (current>maxi){maxi=current;}
                    }
            }
        }
        return maxi;
    }
};
int main(){
    vector <string> words;
    string x;
    while(cin>>x){
        words.push_back(x);
        if (cin.peek()=='\n') break;
    }
Solution sol;
    cout << "the answer is " << sol.maxProduct(words);
    return 0;
}
