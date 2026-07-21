class Solution {
public:
    int maxSubArray(vector<int>&arr) {
     int sum=arr[0],msum=arr[0];
    for(int i=1;i<arr.size();i++){
        sum=max(arr[i],sum+arr[i]);
        msum=max(sum,msum);
    }
        return msum;
    }
};