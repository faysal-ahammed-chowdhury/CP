#include <bits/stdc++.h>
using namespace std;

int test_case = 0;
void solve() {
    int n, k; cin >> n >> k;
    string s = "";
    for(int i = 'A'; i < 'A' + n; i++) {
        s += i;
    }
    cout << "Case " << ++test_case <<":\n";
    int i = 1;
    do {
        cout << s << '\n';
        i++;
    } while(i <= k && next_permutation(s.begin(), s.end()));
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