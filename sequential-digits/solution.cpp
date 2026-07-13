class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int start = 1; start <= 9; ++start) {
            int num = start;
            for (int next = start + 1; next <= 9; ++next) {
                num = num * 10 + next;   // append next digit
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};