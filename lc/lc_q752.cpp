class Solution {
public:
    int openLock(vector<string>& deadends, string target) { 
        unordered_set<string> dead;
        unordered_set<string>visited;
        for (auto &s : deadends){
            if (s=="0000"){return -1;}
            dead.insert(s);
        }
        int count=0;
        string intial="0000";
        queue<string>q;
        q.push(intial);
        while(!q.empty()){
            int len=q.size();
            while(len--){
                string s=q.front();
                q.pop;
                if (s==target){return count;}
            for (int i=0;i<4;i++){
                string up=s;
                up[i]=(cur[i]=='9')?'0':cur[i]+1;
                if (!dead.count(up)&&!visited.count(up)){
                    visited.insert(up);
                    q.push(up);
                }
                string down=s;
                down[i]=(cur[i]=='0')?'9':cur[i]-1;
                if (!dead.count(down)&&!visited.count(down)){
                    visited.insert(down);
                    q.push(down);
                }
                }
            }
            count++;
        }
        return -1;
    }
};
