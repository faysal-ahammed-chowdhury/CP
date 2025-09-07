#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105, inf = 1e9;
string a, b, c;
int n, m, k, dp[N][N], dp2[N][N], dp3[N][N], dp4[N][N];

int f(int i, int j) {
  if (i > n or j > m) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  if (a[i] == b[j]) ans = 1 + f(i + 1, j + 1);
  else ans = max(f(i + 1, j), f(i, j + 1));
  return ans;
}

int f2(int i, int j) {
  if (i < 1 or j < 1) return 0;
  int &ans = dp2[i][j];
  if (ans != -1) return ans;
  if (a[i] == b[j]) ans = 1 + f2(i - 1, j - 1);
  else ans = max(f2(i - 1, j), f2(i, j - 1));
  return ans;
}

int f3(int i, int match) {
  if (match > k) return i;
  if (i > n) return inf;
  int &ans = dp3[i][match];
  if (ans != -1) return ans;
  if (a[i] == c[match]) ans = f3(i + 1, match + 1);
  else ans = f3(i + 1, match);
  return ans;
}

int f4(int i, int match) {
  if (match > k) return i;
  if (i > m) return inf;
  int &ans = dp4[i][match];
  if (ans != -1) return ans;
  if (b[i] == c[match]) ans = f4(i + 1, match + 1);
  else ans = f4(i + 1, match);
  return ans;
}

int cs;
void solve() {
  cout << "Case " << ++cs << ": ";
  cin >> a >> b >> c;
  n = a.size();
  m = b.size();
  k = c.size();

  a = '.' + a;
  b = '.' + b;
  c = '.' + c;

  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));
  memset(dp3, -1, sizeof(dp3));
  memset(dp4, -1, sizeof(dp4));

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int to1 = f3(i, 1);
      int to2 = f4(j, 1);
      if (max(to1, to2) >= inf) continue;

      int tmp = k + f(to1, to2) + f2(i - 1, j - 1);
      ans = max(ans, tmp);
    }
  }

  cout << ans << '\n';
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