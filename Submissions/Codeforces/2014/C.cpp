#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1], sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (n == 1 or n == 2) {
    cout << -1 << '\n';
    return;
  }
  sort(a + 1, a + n + 1);
  int half = (n / 2) + 1;
  int avg = a[half] * 2;
  int tot = (avg * n) + 1;
  cout << max(0ll, tot - sum) << '\n';
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