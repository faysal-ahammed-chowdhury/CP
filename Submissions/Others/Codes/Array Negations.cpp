#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n and k > 0; i++, k--) {
    if (a[i] > 0) break;
    a[i] = -a[i];
  }
  
  if (k & 1) {
    sort(a + 1, a + n + 1);
    a[1] = -a[1];
  }

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
  }
  cout << sum << '\n';
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