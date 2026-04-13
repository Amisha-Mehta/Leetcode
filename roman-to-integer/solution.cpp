class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        unordered_map<char,int> rom={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        for(int i=0;i<s.size()-1;i++){
            if(rom[s[i]]< rom[s[i+1]]){
                res-=rom[s[i]];
            }else{
                res+=rom[s[i]];
            }
        }
        return res+rom[s[s.size() - 1]];
    }
};