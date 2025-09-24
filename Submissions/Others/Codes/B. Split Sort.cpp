#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  set<int> se;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (se.find(a[i] - 1) == se.end()) cnt++;
    se.insert(a[i]);
  }

  cout << --cnt << '\n';
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