#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  pair<int, int> a[n + 1];
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    cout << a[i].first << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n; i++) {
    cout << b[a[i].second] << ' ';
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