#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int arr[n];
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '<') {
            arr[i] = 0;
        }
        else {
            arr[i] = 1;
        }
    }
    vector<int> v;
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i - 1]) count++;
        else {
            v.push_back(count);
            count = 1;
        }
    }
    v.push_back(count);
    sort(v.rbegin(), v.rend());
    for(auto i: v) {
        cout << i + 1 << '\n';
        break;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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