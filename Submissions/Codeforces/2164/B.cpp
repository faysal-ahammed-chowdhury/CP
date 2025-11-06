#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int even = 0, idx1 = -1, idx2 = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      even++;
      if (idx1 == -1) idx1 = i;
      idx2 = i;
    }
  }

  if (even >= 2) {
    int x = a[idx1], y = a[idx2];
    if (x > y) swap(x, y);
    cout << x << ' ' << y << '\n';
    return;
  }

  if (n <= 50) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if ((a[j] % a[i]) % 2 == 0) {
          cout << a[i] << ' ' << a[j] << '\n';
          return;
        }
      }
    }
    cout << -1 << '\n';
    return;
  }

  if (even == 1) {
    for (int i = idx1 + 1; i <= n; i++) {
      if ((a[i] % a[idx1]) % 2 == 0) {
        cout << a[idx1] << ' ' << a[i] << '\n';
        return;
      }
    }

    for (int i = 1; i < idx1; i++) {
      if ((a[idx1] % a[i]) % 2 == 0) {
        cout << a[i] << ' ' << a[idx1] << '\n';
        return;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (i == idx1) continue;
    int j = i + 1;
    if (j == idx1) j++;
    if (j <= n) {
      if (a[j] <= a[i] * 2) {
        cout << a[i] << ' ' << a[j] << '\n';
        return;
      }
    }
  }

  cout << -1 << '\n';
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