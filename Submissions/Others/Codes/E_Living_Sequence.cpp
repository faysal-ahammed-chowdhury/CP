#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

bool notHas4(int n) {
    while(n > 0) {
        if((n % 10) == 4) {
            return false;
        } 
        n /= 10;
    }

    return true;
}

void solve() {
    int n; cin >> n;
    int pos = 1;
    for(int i = 1; pos <= n; i++) {
        if(notHas4(i)) {
            cout << pos << ": " << i << '\n';
            pos++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}