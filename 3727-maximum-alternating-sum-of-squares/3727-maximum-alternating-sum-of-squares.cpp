class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       int i;
       vector <long long> square;
       for(int x:nums){
        square.push_back(x*x);
       }
       sort(square.begin(),square.end());
        int n=nums.size();
        long long ans=0;
        for(i=0;i<n/2;i++){
            ans-=square[i];
        }
        for(i=n/2;i<n;i++){
            ans+=square[i];
        }
        return ans;
    }
};