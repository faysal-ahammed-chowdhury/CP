#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (k >= n) {
    for (int i = 1; i <= n; i++) {
      cout << 0 << ' ';
    }
    return 0;
  }

  for (int i = k + 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  for (int i = 1; i <= k; i++) {
    cout << 0 << ' ';
  }
  cout << '\n';

  return 0;
}