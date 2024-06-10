#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], b[n + 1], c[n + 1];
  a[0] = 0, b[0] = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
    c[i] = a[i];
    mx = max(mx, a[i]);
  }

  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1);
  for (int i = 1; i <= n; i++) {
    c[i] += c[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == mx) {
      cout << 0 << ' ';
      continue;
    }
    auto idx = upper_bound(b + 1, b + n + 1, a[i]) - b;
    cout << c[n] - c[idx - 1] << ' ';
  }
  cout << '\n';

  return 0;
}