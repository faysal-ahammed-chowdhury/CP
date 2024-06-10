#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        deque<int> dq;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                int sum = nums[i] + nums[j];
                ans += lower_bound(dq.begin(), dq.end(), sum) - dq.begin();
            }
            dq.push_front(nums[i]);
        }
        return ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> nums(n);
    for (auto& x : nums) {
        cin >> x;
    }
    Solution c;
    cout << c.triangleNumber(nums);

    return 0;
}