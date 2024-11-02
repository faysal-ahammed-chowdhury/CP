#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 16, inf = 1e9;
int h[N], n, dp[(1 << N) + 5];
string s[N];

int f(int mask) {
  if (__builtin_popcount(mask) == n) return 0;
  int &ans = dp[mask];
  if (ans != -1) return ans;
  ans = inf;
  for (int i = 1; i <= n; i++) {
    if (CHECK(mask, i) == false) {
      int mx = 1;
      for (int j = 1; j <= n; j++) {
        if (CHECK(mask, j)) {
          mx = max(mx, s[j][i] - '0');
        }
      }
      ans = min(ans, ((h[i] + mx - 1) / mx) + f(mask | (1 << i)));
    }
  }
  return ans;
}

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }
  memset(dp, -1, sizeof dp);
  cout << "Case " << ++cs << ": " << f(0) << '\n';
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