#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;

  if (n == 1) {
    cout << 0 << '\n';
    return;
  }

  n -= k;
  n = max(0, n);

  int cnt = ((n + (k - 1) - 1) / (k - 1));
  cnt++;
  cout << cnt << '\n';
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