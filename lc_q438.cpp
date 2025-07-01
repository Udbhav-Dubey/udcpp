#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sfreq[26]={0};
        int pfreq[26]={0};
        for (int i=0;i<p.size();i++){
            sfreq[s[i]-'a']++;
        }
        for (int i=0;i<p.size();i++){
            pfreq[p[i]-'a']++;
        }
        int left=0;
        int ctr=0;
        vector <int> answer(s.size());
        if (memcmp(pfreq,sfreq, sizeof pfreq) == 0) {
            answer.push_back(left);
            ctr++;
        } 
        for (int right=p.size();right<s.size();right++){
            sfreq[s[left]-'a']--;
            sfreq[s[right]-'a']++;
            left++;
            if (memcmp(pfreq,sfreq, sizeof pfreq) == 0) {
                answer.push_back(left);
                ctr++;
            }
        }
        answer.resize(ctr);
        return answer;
    }
};
int main (){
    string s;
    string p;
    cout << "please enter the string s : "; 
    cin >> s;
    cout << "please enter the string p : ";
    cin >> p;
    Solution sol;
    cout << "solution is \n";
    vector <int> vec=sol.findAnagrams(s,p);
    for (auto it : vec ){
        cout << it << " "; 
    }
return 0;
}
