#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], b[N];
long long pref_a[N], pref_b[N];

int get(int i, int n) {
  return n - i + 1;
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  reverse(b + 1, b + n + 1);

  pref_a[1] = 1;
  for (int i = 2; i < n; i++) {
    if (abs(a[i] - a[i + 1]) <= abs(a[i] - a[i - 1])) {
      pref_a[i] = 1;
    }
    else {
      pref_a[i] = a[i + 1] - a[i];
    }
  }

  pref_b[1] = 1;
  for (int i = 2; i < n; i++) {
    if (abs(b[i] - b[i + 1]) <= abs(b[i] - b[i - 1])) {
      pref_b[i] = 1;
    }
    else {
      pref_b[i] = abs(b[i + 1] - b[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    pref_a[i] += pref_a[i - 1];
    pref_b[i] += pref_b[i - 1];
  }

  int m; cin >> m;
  while (m--) {
    int l, r; cin >> l >> r;
    if (l == r) {
      cout << 0 << '\n';
    }
    else if (l < r) {
      cout << pref_a[r - 1] - pref_a[l - 1] << '\n';
    }
    else {
      l = get(l, n);
      r = get(r, n);
      cout << pref_b[r - 1] - pref_b[l - 1] << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}