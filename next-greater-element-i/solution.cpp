class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;--i){
            int curr=nums2[i];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            mp[curr]=st.empty()?-1:st.top();
            st.push(curr);
        }
        vector<int> res;
        // res.reserve(nums1.size());
        for(int num:nums1){
            res.push_back(mp[num]);
        }
        return res;
    }
};