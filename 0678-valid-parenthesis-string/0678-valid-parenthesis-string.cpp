class Solution {
public:
    bool checkValidString(string s) {
        stack <int> brackstack;
        stack <int> starstack;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                brackstack.push(i);
            }else if(s[i]=='*'){
                starstack.push(i);
            }else{
                if(!brackstack.empty()){
                    brackstack.pop();
                }else if(!starstack.empty()){
                    starstack.pop();
                }else{
                    return false;
                }
            }
        }
        while(!brackstack.empty() && !starstack.empty()){
            if(brackstack.top()>starstack.top()){ //* must come after (
                return false;
            }
            brackstack.pop();
            starstack.pop();
        }
        return brackstack.empty();
    }
};