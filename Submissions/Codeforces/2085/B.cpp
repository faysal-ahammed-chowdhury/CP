#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool nozero = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    nozero &= a[i] != 0;
  }

  if (nozero) {
    cout << 1 << '\n';
    cout << 1 << ' '  << n << '\n';
    return;
  }

  if (a[1] > 0) {
    bool zero = false;
    for (int i = 2; i <= n; i++) {
      zero |= a[i] == 0;
    }

    if (zero) {
      cout << 2 << '\n';
      cout << 2 << ' ' << n << '\n';
      cout << 1 << ' ' << 2 << '\n';
    }
    else {
      cout << 1 << '\n';
      cout << 1 << ' ' << n << '\n';
    }
    return;
  }

  if (a[n] > 0) {
    bool zero = false;
    for (int i = 1; i < n; i++) {
      zero |= a[i] == 0;
    }

    if (zero) {
      cout << 2 << '\n';
      cout << 1 << ' ' << n - 1 << '\n';
      cout << 1 << ' ' << 2 << '\n';
    }
    else {
      cout << 1 << '\n';
      cout << 1 << ' ' << n << '\n';
    }
    return;
  }

  bool zero = false;
  for (int i = 3; i <= n; i++) {
    zero |= a[i] == 0;
  }

  if (zero) {
    cout << 3 << '\n';
    cout << 3 << ' ' << n << '\n';
    cout << 1 << ' ' << 2 << '\n';
    cout << 1 << ' ' << 2 << '\n';
  }
  else {
    cout << 2 << '\n';
    cout << 1 << ' ' << 2 << '\n';
    cout << 1 << ' ' << n - 1 << '\n';
  }
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