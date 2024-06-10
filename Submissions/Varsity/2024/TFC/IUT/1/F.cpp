#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int x = a[1] - b[1];
  if (x >= 0) {
    if (x & 1) x++;
    a[2] += x / 2;
    a[n] += x / 2;
    a[1]  -= x;
  }

  for (int i = 2; i < n; i++) {
    int x = a[i] - b[i];
    if (x >= 0) {
      if (x & 1) x++;
      a[i + 1] += x / 2;
      a[i - 1] += x / 2;
      a[i]  -= x;
    }
  }

  x = a[n] - b[n];
  if (x >= 0) {
    if (x & 1) x++;
    a[n - 1] += x / 2;
    a[1] += x / 2;
    a[n]  -= x;
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    ok &= a[i] == b[i];
  }

  cout << (ok ? "Yes\n" : "No\n");


  return 0;
}