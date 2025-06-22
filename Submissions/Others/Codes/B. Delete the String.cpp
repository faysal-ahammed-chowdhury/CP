#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9, inf = 1e9;
int n;
string s;
int dp[N][2], nxt[N][26];

int get(char c) {
  return c - 'a';
}

int f(int i, bool running) {
  if (i > n) return 0;

  int &ans = dp[i][running];
  if (ans != -1) return ans;
  ans = inf;

  int idx = nxt[i][get(s[i])];
  if (idx == -1) {
    if (!running) {
      ans = min(ans, 1 + f(i + 1, false));
    }
    else {
      ans = min(ans, f(i + 1, false));
    }
  }
  else {
    if (!running) {
      ans = min(ans, 1 + f(i + 1, false));
      ans = min(ans, 1 + f(idx, true));
    }
    else {
      ans = min(ans, f(i + 1, false));
      ans = min(ans, f(idx, true));
    }
  }

  // cout << i << ' ' << *it <<' ' << running << ' ' << ans << '\n';

  return ans;
}

void solve() {
  cin >> n >> s;
  s = '.' + s;

  for (char c = 'a'; c <= 'z'; c++) {
    int last = -1;
    for (int i = n; i >= 1; i--) {
      nxt[i][get(c)] = last;
      if (s[i] == c) last = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i][1] = -1;
  }

  cout << f(1, false) << '\n';
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