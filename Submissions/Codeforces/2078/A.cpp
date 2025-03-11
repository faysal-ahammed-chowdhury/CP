#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int c; cin >> c;
    sum += c;
  }

  int avg = sum / n;
  if (avg * n == sum and avg == x) {
    cout << "YES\n";
  }
  else cout << "NO\n";
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