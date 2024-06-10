#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

long long min(long long a, long long b) {
    return a < b ? a : b;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, string>> v;
    for(int i = 0; i < n; i++) {
        int m; cin >> m;
        string s; cin >> s;
        v.push_back({m, s});
    }
    long long min_first = INT_MAX;
    long long min_second = INT_MAX;
    long long min_both = INT_MAX;
    for(auto i : v) {
        if(i.second[0] == '1' && i.second[1] == '0') {
            min_first = min(min_first, i.first);
        }
        if(i.second[0] == '0' && i.second[1] == '1') {
            min_second = min(min_second, i.first);
        }
        if(i.second[0] == '1' && i.second[1] == '1') {
            min_both = min(min_both, i.first);
        }
    }

    if(min_both == INT_MAX && (min_first == INT_MAX || min_second == INT_MAX)) {
        cout << -1 << '\n';
        return;
    }
    cout << min(min_both, min_first + min_second) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}