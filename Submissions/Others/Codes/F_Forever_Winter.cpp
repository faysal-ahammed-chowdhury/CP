#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

void solve() {
    int n, m; cin >> n >> m;
    vector<int> graph[n + 1];
    while(m--) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for(auto j : graph[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << '\n';
    // }
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        mp[graph[i].size()]++;
    }
    if(mp.size() == 3) {
        for(auto i : mp) {
            if(i.second == 1) {
                cout << i.first << ' ';
                break;
            }
        }
        for(auto i : mp) {
            if(i.second != 1 && i.first != 1) {
                cout << i.first - 1 << '\n';
                break;
            }
        }
    }
    else {
        for(auto i : mp) {
            if(i.first != 1) {
                cout << i.first << ' ' << i.first - 1 << '\n';
                break;
            }
        }
    }
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