class Solution {
public:
    bool isValid(string s) {

       vector<char> stack;
       
       for (char c : s){
        if (c == '(' || c == '[' || c == '{'){
            stack.push_back(c);
        }
        else{
            if(stack.empty()){ 
                return false;
                }
            char top = stack.back();
            stack.pop_back();
            if (c == ')' && top != '(' ||
                c == ']' && top != '[' ||
                c == '}' && top != '{'){
                    return false;
                }
        }
       }
    return stack.empty();
    }
};
