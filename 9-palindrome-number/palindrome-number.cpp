class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string r_str = to_string(x);
        reverse(r_str.begin(), r_str.end());
        cout << r_str;
        if(str == r_str){
            return true;
        }
        else{
            return false;
        }
    }
};