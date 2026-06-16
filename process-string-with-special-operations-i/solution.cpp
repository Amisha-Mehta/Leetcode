class Solution {
public:
    string processStr(string s) {
        int n=s.length();
        string res;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                res+=res;
            }
            else if(s[i]=='%'){
                reverse(res.rbegin(),res.rend());
            }
            else if(s[i]=='*'){
                if(res.size()){
                    res.pop_back();
                }
            }
            else{
                res+=s[i];
            }
        }
        return res;      
    }
};