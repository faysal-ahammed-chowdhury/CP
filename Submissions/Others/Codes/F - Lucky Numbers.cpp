#include <bits/stdc++.h>
using namespace std;

int calculate_luck(int n) {
    stringstream ss;
    ss << n;
    string s; ss >> s;
    sort(s.begin(), s.end());
    int largest = s.back() - '0';
    int smallest = s.front() - '0';
    return largest - smallest;
}

void solve() {
    int smallest, largest; cin >> smallest >> largest;
    int range = min(largest, smallest + 100);
    int ans = -1, max_luck = 0;
    for(int i = smallest; i <= range; i++) {
        int luck = calculate_luck(i);
        if(luck >= max_luck) {
            ans = i;
            max_luck = luck;
        }
    }
    cout << ans << '\n';
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