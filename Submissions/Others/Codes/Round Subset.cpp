#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 202, inf = 5000;
int n, k, dp[2][N][N * 20];
pair<int, int> a[N];

bool ok(int cnt2) {
  int cnt5 = dp[0][k][cnt2];
  return cnt5 >= cnt2;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    ll x; cin >> x;
    int cnt2 = 0, cnt5 = 0;
    while (x % 2 == 0) {
      cnt2++;
      x /= 2;
    }
    while (x % 5 == 0) {
      cnt5++;
      x /= 5;
    }
    a[i] = make_pair(cnt2, cnt5);
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int rem = 0; rem <= k; rem++) {
      for (int cnt2 = 0; cnt2 <= (n * 20); cnt2++) {
        if (i == n + 1) {
          if (cnt2 == 0) dp[0][rem][cnt2] = 0;
          else dp[0][rem][cnt2] = -inf;
        }
        else {
          int &ans = dp[0][rem][cnt2];
          ans = dp[1][rem][cnt2];
          if (rem > 0) ans = max(1ll * ans, 1ll * a[i].second + dp[1][rem - 1][max(0, cnt2 - a[i].first)]);
        }
      }
    }
    for (int rem = 0; rem <= k; rem++) {
      for (int cnt2 = 0; cnt2 <= (n * 20); cnt2++) {
        dp[1][rem][cnt2] = dp[0][rem][cnt2];
      }
    }
  }

  int l = 0, r = n * 20, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';

  return 0;
}