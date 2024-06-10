#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int len = r - l;
            int min_height = min(height[l], height[r]);
            int area = len * min_height;
            ans = max(ans, area);
            if (height[l] == min_height) l++;
            else r--;
        }
        return ans;
    }
};

int32_t main() {

    return 0;
}