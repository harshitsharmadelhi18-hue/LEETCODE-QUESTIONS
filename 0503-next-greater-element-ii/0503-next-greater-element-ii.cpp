class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        // Traverse the array twice because it is circular
        for (int i = 2 * n - 1; i >= 0; i--) {

            int curr = nums[i % n];

            while (!s.empty() && curr >= s.top()) {
                s.pop();
            }

            // Only store answers during the first traversal
            if (i < n) {
                if (!s.empty()) {
                    ans[i] = s.top();
                }
            }

            s.push(curr);
        }

        return ans;
    }
};