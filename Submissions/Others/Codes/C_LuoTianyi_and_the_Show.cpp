#include <bits/stdc++.h>
using namespace std;

int arr[100005];
void solve() {
    int n, m; cin >> n >> m;
    int left = 0, right= 0, pos = 0;
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        int val; cin >> val;
        if(val == -1) {
            left++;
        }
        else if(val == -2) {
            right++;
        }
        else {
            if(mp.find(val) == mp.end()) {
                arr[++pos] = val;
                mp[val] = 1;
            }
        }
    }

    if(pos == 0) {
        cout << min(m, max(left, right)) << '\n';
        return;
    }
    int ans = 0;
    sort(arr + 1, arr + 1 + pos);
    for(int i = 1; i <= pos; i++) {
        int left_side_has = arr[i] - 1;
        int right_side_has = m - arr[i];
        int left_possible = min(left_side_has, (left + i - 1));
        int right_possible = min(right_side_has, (right + pos - i));
        int possible = min(m, (left_possible + right_possible + 1));
        ans = max(ans, possible);
    }
    int count = arr[pos] == m;
    int possible = min(m, left + (pos - count));
    ans = min(m, max(ans, possible));
    count = arr[1] == 1;
    possible = min(m, right + (pos - count));
    ans = min(m, max(ans, possible));
    cout << min(ans, m) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}