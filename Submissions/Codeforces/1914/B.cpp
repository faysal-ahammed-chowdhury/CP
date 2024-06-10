#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int first = n - k;
  for (int i = first; i <= n; i++) {
    cout << i << ' ';
  }
  for (int i = first - 1; i >= 1; i--) {
    cout << i << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}