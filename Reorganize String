class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char,int> m;
        priority_queue< pair<int,char> > q;

        for(char i : s){
            m[i]++; 
        }

        for(pair<char,int> i : m){
            q.push(make_pair(i.second,i.first));
        }

        int n = s.size();
        if(n & 1){
            if(q.top().first > (n+1)/2){
                return "";
            }
        }
        else{
            if(q.top().first > n/2){
                return "";
            }
        }

        while(q.size() > 1){
            pair<int,char> a = q.top();
            q.pop();

            pair<int,char> b = q.top();
            q.pop();

            ans = ans + a.second + b.second;

            a.first = a.first - 1;
            b.first = b.first - 1;

            if(a.first > 0)
                q.push(a);
            
            if(b.first > 0)
                q.push(b);
            
        }

        if(!q.empty()){
            if(q.top().first > 1)
                return "";
            else
                ans = ans + q.top().second;
        }
        return ans;
    }
};
