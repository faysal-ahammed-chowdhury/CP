#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
long long a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, q; cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }
  for (int i = 1; i < N; i++) {
    a[i] += a[i - 1];
  }

  for (int i = 1; i < N; i++) {
    if (a[i] >= k) {
      a[i] = 1;
    }
    else {
      a[i] = 0;
    }
    a[i] += a[i - 1];
  }

  while (q--) {
    int l, r; cin >> l >> r;
    cout << a[r] - a[l - 1] << '\n';
  }

  return 0;
}