#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j <= 8; j++) {
      int x; cin >> x;
      sum += x;
    }
    cout << sum << '\n';
  }
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