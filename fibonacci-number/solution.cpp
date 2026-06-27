class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        // return fib(n-1)+fib(n-2);
        int prev=0;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev1;
            prev=prev1;
            prev1=curr;
        }
        return prev1;
    }
};