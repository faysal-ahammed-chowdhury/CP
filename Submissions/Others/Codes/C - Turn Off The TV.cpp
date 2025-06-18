#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  array<int, 3> a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][1] = -a[i][1];
    a[i][2] = i;
  }
  sort(a + 1, a + n + 1);
  
  int mx = -1;
  for (int i = 1; i <= n; i++) {
    int l = a[i][0];
    int r = -a[i][1];

    int idx = a[i][2];
    if (r <= mx) {
      cout << idx << '\n';
      return 0;
    }

    if (i > 2 and l - 1 <= (-a[i - 2][1])) {
      cout << a[i - 1][2] << '\n';
      // cout << a[i - 1][0] << ' ' << a[i - 1][1] << '\n';
      return 0;
    }

    mx = max(mx, r);
  }

  cout << -1 << '\n';

  return 0;
}