class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        int missing=-1;
        vector<int> ans;
        for(int num:nums){
            freq[num]++;
        }
        for(int i=1;i<n+1;i++){
            if(freq[i]==0){
                missing=i;
                ans.push_back(missing);
            }
        }
        return ans;
    }
};