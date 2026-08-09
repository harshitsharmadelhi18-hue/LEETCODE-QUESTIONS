class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        // Push all characters into stack
        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        }

        // Pop characters and put them back into s
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};