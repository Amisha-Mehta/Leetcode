class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        string str="";
        for(int i=n-1;i>=0;i--){
            if(str.empty() && s[i]==' '){
                continue;
            }
            if(s[i]==' ')
                break;
            str+=s[i];
        }
        return str.length();

    // string str="";
    // vector<string> ans;
    // for(int i=0;i<n;i++){
    //     if(s[i]!=' '){
    //         str+=s[i];
    //     }
    //     else if(!str.empty()){
    //         ans.push_back(str);
    //         str="";
    //     }
    // }
    // if(!str.empty()){
    //     ans.push_back(str);
    // }
    // return ans[ans.size()-1].size();
    }
};