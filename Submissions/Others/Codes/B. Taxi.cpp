#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int sum= mp[4];
    int min13 = min(mp[1], mp[3]);
    sum += min13;
    mp[1] -= min13;
    mp[3] -= min13;
    sum += mp[2] / 2;
    mp[2] = mp[2] % 2;
    if(mp[2] > 0) {
        int one = min(2, mp[1]);
        sum++;
        mp[1] -= one;
    }
    if(mp[3] != 0) {
        sum += mp[3];
    }
    else {
        sum += ceil(mp[1] / 4.0);
    }
    cout << sum << '\n';
}