class Solution {
public:
    int hii(int n) {
       int rev=0;
       while(n!=0){
        rev=rev*10 + n%10;
        n /=10;
       }
       return rev;
    }
    int mirrorDistance(int n){
        int res=hii(n);
        return abs(res-n);
    }
};