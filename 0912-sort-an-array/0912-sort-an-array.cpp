class Solution {
public:
        void countingsort(vector<int>& nums,int exp) {
        int n=nums.size();
        vector <int>output(n);
        int count[10]={0};
        //countdigits
        for(int i=0;i<n;i++){
            int digit=(nums[i]/exp)%10;
            count[digit]++;
        }
        //count into positions
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        //build output
        for(int i=n-1;i>=0;i--){
            int digit=(nums[i]/exp)%10;
            output[count[digit]-1]=nums[i];
            count[digit]--;
        }
        for(int i=0;i<n;i++){
            nums[i]=output[i];
        }
    }
    void radixsort(vector<int>&nums){
        if(nums.empty()){
            return;
        }
        int maxelem=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxelem){
                maxelem=nums[i];
            }
        }
        for(int exp=1;maxelem/exp>0;exp*=10){
            countingsort(nums,exp);
        }
    }
    vector <int> sortArray(vector <int>&nums){
        vector <int>positive;
        vector <int>negative;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                positive.push_back(nums[i]);
            }else{
                negative.push_back(-nums[i]);
            }
        }
        radixsort(positive);
        radixsort(negative);
        vector <int> result;
        for(int i=negative.size()-1;i>=0;i--){
            result.push_back(-negative[i]);
        }
        for(int i=0;i<positive.size();i++){
            result.push_back(positive[i]);
        }
        return result;
    }
};