#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 50;
int n, k, m, a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> m;
  int tot = 0;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    tot += a[i];
  }
  sort(a + 1, a + k + 1);


  if (m == 0) {
    cout << 0 << '\n';
    return 0;
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int point = (k * i) + i;
    int rem_task = n - i;
    ll rem_time = m - (1ll * tot * i);
    if (rem_time < 0) break;
    for (int j = 1; j <= k; j++) {
      int x = rem_time / a[j];
      x = min(x, rem_task);
      point += x;
      rem_time -= x * a[j];
    }
    // cout << i << ' ' << point << '\n';
    ans = max(ans, point);
  }
  cout << ans << '\n';

  return 0;
}