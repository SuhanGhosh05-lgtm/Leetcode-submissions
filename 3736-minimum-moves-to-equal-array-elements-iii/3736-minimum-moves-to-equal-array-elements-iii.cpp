class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxelem=*max_element(nums.begin(),nums.end());
        int moves=0;
        for(int i=0;i<nums.size();i++){
            moves+=maxelem-nums[i];
        }
        return moves;
    }
};