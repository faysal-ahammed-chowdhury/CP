#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int a, b; cin >> a >> b;
  if (a >= b) {
    cout << a << '\n';
    return;
  }
  int d = b - a;
  a -= d;
  cout << max(0ll, a) << '\n';
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