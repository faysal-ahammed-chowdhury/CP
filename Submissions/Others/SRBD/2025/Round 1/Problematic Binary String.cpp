#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
const int N = 1e5 + 9, inf = 1e9;
int n;
string s;
int dp[N][2][2][2];

int f(int i, int me, int next, int nextnext) {
  if (i > n) return 0;

  int &ans = dp[i][me][next][nextnext];
  if (ans != -1) return ans;
  ans = inf;

  if (i == 1) {
    if (me == !(i & 1)) {
      int x = 1;
      if (i + 3 <= n) x = s[i + 3] - '0';
      ans = min(ans, f(i + 1, next, nextnext, x));
      ans = min(ans, 2 + f(i + 1, next, !nextnext, x));
    }
    else if (i + 1 <= n) {
      int x = 1;
      if (i + 3 <= n) x = s[i + 3] - '0';
      ans = min(ans, 1 + f(i + 1, !next, nextnext, x));
      ans = min(ans, 1 + f(i + 1, !next, !nextnext, x));
    }
  }
  else {
    if (me == !(i & 1)) {
      int x = 1;
      if (i + 3 <= n) x = s[i + 3] - '0';
      ans = min(ans, f(i + 1, next, nextnext, x));
    }
    else if (i + 1 <= n) {
      int x = 1;
      if (i + 3 <= n) x = s[i + 3] - '0';
      ans = min(ans, 1 + f(i + 1, !next, !nextnext, x));
    }
  }

  return ans;
}

void solve() {
  cin >> n >> s;

  if (n == 1) {
    cout << (s != "0") << '\n';
    return;
  }

  if (n == 2) {
    if (s == "00") cout << -1 << '\n';
    else if (s == "11") cout << -1 << '\n';
    else if (s == "10") cout << 1 << '\n';
    else if (s == "01") cout << 0 << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        for (int l = 0; l <= 1; l++) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }

  s = '.' + s;
  int ans = f(1, s[1] - '0', s[2] - '0', s[3] - '0');
  if (ans >= inf) ans = -1;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}