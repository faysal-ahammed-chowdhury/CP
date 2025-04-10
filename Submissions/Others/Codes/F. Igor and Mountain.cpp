#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005, mod = 998244353;
int n, m, d;
string s[N];
int dp[N][N];
int cur[N], pref[N];

void solve() {
  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = 0;
      cur[j] = 0;
      pref[j] = 0;
    }
  }

  for (int j = 1; j <= m; j++) {
    dp[1][j] = s[1][j] == 'X';
  }

  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j] == 'X') {
          int l = max(1, j - (d - 1)), r = min(m, j + (d - 1));
          dp[i][j] = pref[r] - pref[l - 1];
          if (dp[i][j] < 0) dp[i][j] += mod;
        }
      }
    }
    for (int j = 1; j <= m; j++) {
      pref[j] = (pref[j - 1] + dp[i][j]) % mod;
    }
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        int l = max(1, j - d), r = min(m, j + d);
        int x = pref[r] - pref[l - 1];
        if (x < 0) x += mod;
        dp[i][j] = x;
      }
    }
    for (int j = 1; j <= m; j++) {
      pref[j] = (pref[j - 1] + dp[i][j]) % mod;
    }
  }

  cout << pref[m] << '\n';
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