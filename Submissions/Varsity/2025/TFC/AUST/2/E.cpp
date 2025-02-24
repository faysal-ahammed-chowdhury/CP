#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 16, M = 4782969 + 100, inf = 1e12;
vector<int> a[N + 3];
int dp[N + 3][M + 100];

int n, sz;

// converting from 1 to 0
int f(int i, int j) {
  if (i == 1) {
    return a[i][j] != 0;
  }

  int &ans = dp[i][j];

  int cnt = 0, x = inf, y = inf, z = inf;
  if (a[i - 1][j * 3] == 1) {
    cnt++;
    x = f(i - 1, j * 3);
  }
  if (a[i - 1][j * 3 - 1] == 1) {
    cnt++;
    y = f(i - 1, j * 3 - 1);
  }
  if (a[i - 1][j * 3 - 2] == 1) {
    cnt++;
    z = f(i - 1, j * 3 - 2);
  }

  // cout << "here: " << i << ' ' << cnt << '\n';
  if (cnt <= 1) {
    ans = 0;
    return ans;
  }

  ans = inf;
  if (cnt == 2) {
    ans = min(ans, min({x, y, z}));
  }
  else if (cnt == 3) {
    ans = min(ans, min({(x + y), (y + z), (z + x)}));
  }

  // cout << ans << '\n';

  return ans;
}

// converting from 0 to 1
int f2(int i, int j) {
  if (i == 1) {
    return a[i][j] != 1;
  }

  int &ans = dp[i][j];

  int cnt = 0, x = inf, y = inf, z = inf;
  if (a[i - 1][j * 3] == 0) {
    cnt++;
    x = f2(i - 1, j * 3);
  }
  if (a[i - 1][j * 3 - 1] == 0) {
    cnt++;
    y = f2(i - 1, j * 3 - 1);
  }
  if (a[i - 1][j * 3 - 2] == 0) {
    cnt++;
    z = f2(i - 1, j * 3 - 2);
  }

  if (cnt <= 1) {
    ans = 0;
    return ans;
  }

  // cout << "here: " << cnt << '\n';

  ans = inf;
  if (cnt == 2) {
    ans = min(ans, min({x, y, z}));
  }
  else if (cnt == 3) {
    ans = min(ans, min({(x + y), (y + z), (z + x)}));
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int cnt = round(powl(3, n));
  a[1].push_back(-1);
  for (int i = 1; i <= cnt; i++) {
    char c; cin >> c;
    a[1].push_back(c - '0');
  }

  sz = 1;
  for (int i = 2; ; i++) {
    cnt /= 3;
    if (cnt == 0) break;
    a[i].push_back(-1);
    for (int j = 1; j <= cnt; j++) {
      int zero = 0, one = 0;
      zero += a[i - 1][j * 3] == 0;
      zero += a[i - 1][j * 3 - 1] == 0;
      zero += a[i - 1][j * 3 - 2] == 0;
      one += a[i - 1][j * 3] == 1;
      one += a[i - 1][j * 3 - 1] == 1;
      one += a[i - 1][j * 3 - 2] == 1;
      if (zero > one) a[i].push_back(0);
      else a[i].push_back(1);
    }
    sz++;
  }

  // cout << sz << '\n';
  cnt = round(powl(3, n));
  assert(a[1].size() == cnt + 1);

  int last = -1;
  for (int i = 1; i <= sz; i++) {
    for (int j = 1; j <= cnt; j++) {
      // cout << a[i][j] << ' ';
      last = a[i][j];
    }
    // cout << '\n';
    cnt /= 3;
  }

  assert(a[sz].size() == 2);

  memset(dp, -1, sizeof dp);
  if (last == 1) cout << f(sz, 1) << '\n';
  else cout << f2(sz, 1) << '\n';

  return 0;
}