#include <bits/stdc++.h>
using namespace std;
#define int __int128
#define ll unsigned long long

const int N = 105;
ll a[N][N], n, m, k, x, y;

int need(int cnt) {
  int up = (cnt + 1) / 2;
  int down = cnt / 2;
  int middle = cnt;
  int tot = (up + down + (middle * (n - 2))) * m;
  return tot;
}

bool ok(int cnt) {
  return need(cnt) <= k;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k >> x >> y;

  if (n == 1) {
    int cnt = k / m;
    k %= m;
    for (int j = 1; j <= m; j++) {
      a[1][j] += cnt;
      if (k > 0) {
        a[1][j]++;
        k--;
      }
    }

    ll mx = 0, mn = 1e19;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        mn = min(mn, a[i][j]);
        mx = max(mx, a[i][j]);
      }
    }
    cout << mx << ' ' << mn << ' ' << a[x][y] << '\n';
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (k > 0) {
        a[i][j]++;
        k--;
      }
    }
  }
  
  int l = 0, r = 1e20, rep = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      rep = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  k -= need(rep);

  // cout << rep << '\n';
  // return 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1) {
        int up = (rep + 1) / 2;
        a[i][j] += up;
      }
      else if (i == n) {
        int down = (rep) / 2;
        a[i][j] += down;
      }
      else {
        a[i][j] += rep;
      }
    }
  }

  if (rep & 1) {
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (k > 0) {
          a[i][j]++;
          k--;
        }
      }
    }
  }
  else {
    for (int i = n - 1; i >= 1; i--) {
      for (int j = 1; j <= m; j++) {
        if (k > 0) {
          a[i][j]++;
          k--;
        }
      }
    }
  }

  ll mx = 0, mn = 1e18;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      mn = min(mn, a[i][j]);
      mx = max(mx, a[i][j]);
    }
  }

  cout << mx << ' ' << mn << ' ' << a[x][y] << '\n';

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= m; j++) {
  //     cout << a[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  assert(k == 0);

  return 0;
}