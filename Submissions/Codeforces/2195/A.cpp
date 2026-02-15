#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x == 67) {
      ok = true;
    }
  }

  ok ? cout <<  "YES\n" : cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}