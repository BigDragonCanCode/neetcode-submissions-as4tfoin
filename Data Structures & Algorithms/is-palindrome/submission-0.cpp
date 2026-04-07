using namespace std;

class Solution {
public:
    bool validChar(char c) {
        return (c >= 65 && c <= 122) || (c >= 48 && c<=57);
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;
        while (left<right) {
            char l = s[left];
            char r = s[right];
            if (!validChar(s[left])) {
                left++;
                continue;
            }
            if (!validChar(s[right])) {
                right--;
                continue;
            }
            
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};
