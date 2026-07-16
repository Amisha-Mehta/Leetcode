class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> res;
        int mx=INT_MIN;
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mx=max(nums[i],mx);
            res.push_back(gcd(nums[i],mx));
        }
        sort(res.begin(),res.end());
        int left=0, right=n-1;
        while(left<right){
            sum+=gcd(res[left],res[right]);
            left++;
            right--;
        }
        return sum;
    }
};