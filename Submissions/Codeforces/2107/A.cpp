#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int mx = 0, idx = -1, mn = 1e5;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x > mx) {
      mx = x;
      idx = i;
    }
    if (x < mn) mn = x;
  }

  if (mx == mn) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    if (i == idx) cout << 2 << ' ';
    else cout << 1 << ' ';
  }
  cout << '\n';
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