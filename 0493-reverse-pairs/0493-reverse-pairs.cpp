class Solution {
public:
int mergesort(vector <int>&nums,int low, int high){
    if(low>=high){
        return 0;
    }
    int count=0;
    int mid=low+(high-low)/2;
    count+=mergesort(nums,low,mid);//checking reverse pair for left side
    count+=mergesort(nums,mid+1,high);//chhecking reverse pair for right side
    //now counting the reverse pair
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && (long long)nums[i]>2LL*nums[j]){
            j++;
        }
    count+=j-(mid+1);
    }
    //merging two sorted halves
    int left=low,right=mid+1;
    vector <int> temp;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    //merging the remaining elements
    while(left<=mid){
            temp.push_back(nums[left]);
            left++;
}
while(right<=high){
            temp.push_back(nums[right]);
            right++;
}
for(int i=0;i<temp.size();i++){
    nums[low+i]=temp[i];
}
return count;
}
    int reversePairs(vector<int>& nums) {
       return mergesort(nums,0,nums.size()-1);
       
    }
};