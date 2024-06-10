#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n], b[n];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  long long prefix[n + 1];
  prefix[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + b[i];
  }

  for (int i = 1; i <= n; i++) {
    int idx = upper_bound(b + 1, b + 1 + n, a[i]) - b;
    if (idx == n + 1) {
      cout << 0 << ' ';
    }
    else {
      cout << prefix[n] - prefix[idx - 1] << ' ';
    }
  }
  cout << '\n';

  return 0;
}