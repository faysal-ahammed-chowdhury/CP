#include <bits/stdc++.h>
using namespace std;

int s;

void solve() {
  int n; cin >> n;
  long long a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  if (s == 0) {
    int x = (n + 1) / 2;
    if (n & 1) {
      cout << a[x] << '\n';
    }
    else {
      cout << a[x + 1] - a[1] << '\n';
    }
  }
  else {
    int x = (n + 1) / 2;
    long long ans = 0;
    for (int i = 1; i <= x; i++) {
      int y = i - 1;
      int end = n - y, start = end - i;
      ans = max(ans, a[end] - a[start]);
    }
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t >> s;
  while (t--) {
    solve();
  }

  return 0;
}