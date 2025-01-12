#include <bits/stdc++.h>
using namespace std;

const int N = 1005, inf = 1e9, mod = 1e9 + 7;
string s[N];
int n, m, dp[N][N][3][3], dp2[N][N][3][3];

int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

bool valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

int calc(int i, int j, int last, int sec_last) {
  int ans = 0;
  for (int k = 0; k < 4; k++) {
    int ii = i + dx[k], jj = j + dy[k];
    if (valid(ii, jj)) ans += s[ii][jj] == '#';
  }
  if (last == 0) ans -= s[i - 1][j] == '#';
  else if (last == 1) ans -= s[i][j - 1] == '#';

  if (sec_last == 0 and last == 1) ans -= s[i - 1][j] == '#';
  else if (sec_last == 1 and last == 0) ans -= s[i][j - 1] == '#';

  return ans;
}

int f(int i, int j, int last, int sec_last) { // last = 0 -> up, 1 -> left, 2 -> none
  if (i == n and j == m) return calc(i, j, last, sec_last);
  if (i > n or j > m) return inf;

  int &ans = dp[i][j][last][sec_last];
  if (ans != -1) return ans;

  int ans1 = f(i + 1, j, 0, last);
  int ans2 = f(i, j + 1, 1, last);
  ans = calc(i, j, last, sec_last) + min(ans1, ans2);
  // cout << i << ' ' << j << ' ' << last << ' ' << calc(i, j, last) << ' ' << ans << ' ';
  // cout << ans1 << ' ' << ans2 << '\n';
  return ans;
}

int print(int i, int j, int last, int sec_last) {
  if (i == n and j == m) return 1;
  if (i > n or j > m) return 0;

  int &cnt = dp2[i][j][last][sec_last];
  if (cnt != -1) return cnt;

  int ans = f(i, j, last, sec_last);

  int ans1 = calc(i, j, last, sec_last) + f(i + 1, j, 0, last);
  int ans2 = calc(i, j, last, sec_last) + f(i, j + 1, 1, last);
  
  cnt = 0;
  if (ans == ans1) cnt = (cnt + print(i + 1, j, 0, last)) % mod;
  if (ans == ans2) cnt = (cnt + print(i, j + 1, 1, last)) % mod;
  return cnt;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  cout << f(1, 1, 2, 2) << '\n';
  cout << print(1, 1, 2, 2) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}