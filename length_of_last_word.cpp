class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i, length;
        length = 0;
        i = s.length() - 1;

        while( i >= 0 && s[i] == ' '){
            i--;
        }

        while( i >=0 && s[i] != ' '){
            length++;
            i--;
        }

    return length;
    }
};