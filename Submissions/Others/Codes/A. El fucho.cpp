#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a = n, b = 0;
  int ans = 0;
  while (a >= 2 or b >= 2) {
    int half = a / 2;
    ans += half;
    a -= half;
    ans += b / 2;
    b -= b / 2;
    b += half;
  }

  cout << ++ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}