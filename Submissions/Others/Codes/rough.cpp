#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1005, inf = 1e9;
const double eps = 1e-6;
int n, m, service_day[N][N], price[N][N], mn[N][N];
int dp[N][N];

int f(int i, int day) {
  if (i > n) return 0;
  int &ans = dp[i][day];
  if (ans != -1) return ans;
  ans = mn[i][day] + f(i + 1, day);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> service_day[i][j] >> price[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < N; j++) {
      mn[i][j] = inf;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      mn[i][service_day[i][j]] = min(mn[i][service_day[i][j]], price[i][j]);
    }
    for (int j = 1000; j >= 1; j--) {
      mn[i][j] = min(mn[i][j], mn[i][j + 1]);
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j < 8; j++) {
  //     cout << mn[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  memset(dp, -1, sizeof dp);

  double unit = inf;
  int ans = inf;
  for (int day = 1; day <= 1000; day++) {
    int tot = f(1, day);
    double here = (double)(tot) / day;
    if (abs(unit - here) <= eps) {
      ans = min(ans, tot);
    }
    else if (unit >= (here - eps)) {
      ans = tot;
      unit = here;
    }
  }
  cout << ans << '\n';

  return 0;
}