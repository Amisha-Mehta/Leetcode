class Solution {
public:
    int findGCD(vector<int>& nums) {
        int ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            ans=gcd(nums[0],nums[n-1]);
        }
        return ans;
    }
};