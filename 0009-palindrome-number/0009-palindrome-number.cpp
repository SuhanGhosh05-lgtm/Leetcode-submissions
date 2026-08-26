class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int digit,ori=x;
        long long rem=0;
        while(x>0){
            digit=x%10;
            rem=rem*10+digit;
            x=x/10;
        }
    return ori==rem;
    }
};