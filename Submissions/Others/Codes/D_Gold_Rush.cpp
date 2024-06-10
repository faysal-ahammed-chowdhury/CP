#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const double PI = double(2 * acos(0.0));

bool possible;
void solution(int n, int m) {
    if(n == m) {
        possible = true;
        return;
    }
    if(n % 3 != 0) {
        return;
    }
    int first = (n / 3) * 2;
    int second = n - first;
    if(first == m || second == m) {
        possible = true;
        return;
    }
    solution(first, m);
    solution(second, m);
}

void solve() {
    int n, m; cin >> n >> m;
    possible = false;
    solution(n, m);
    cout << (possible ? "YES\n" : "NO\n");
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