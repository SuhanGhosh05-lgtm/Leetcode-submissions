class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector <int> count(100001,0);
        for(int cost:costs){
            count[cost]++;
        }
        int bars=0;
        for(int i=1;i<=100000;i++){
            while(count[i]>0 && coins>=i){
                coins-=i;
                bars++;
                count[i]--;
            }
            if(coins<i){
                break;
            }
        }
        return bars;
    }
};