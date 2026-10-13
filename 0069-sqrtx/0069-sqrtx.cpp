class Solution {
public:
    long long mySqrt(long long x) {
        long long low = 0;
        long long high = x;
        long long mn = INT_MAX;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(mid*mid<=x){
                mn = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return mn;
    }
};