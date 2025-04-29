#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9, K = 28, inf = 1e9;
string s;
int n, k;
int dp[N], nxt[N][K];

int f(int i) {
  if (i > n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = inf;
  for (char c = 'a', cnt = 1; cnt <= k; c++, cnt++) {
    int j = nxt[i][c - 'a'];
    if (j <= n) ans = min(ans, 1 + f(j + 1));
    else {
      ans = 0;
      break;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  cin >> s;
  s = '.' + s;

  for (char c = 'a', cnt = 1; cnt <= k; c++, cnt++) {
    int last = n + 1;
    for (int i = n; i >= 1; i--) {
      if (s[i] == c) last = i;
      nxt[i][c - 'a'] = last;
    }
  }

  // for (char c = 'a', cnt = 1; cnt <= k; c++, cnt++) {
  //   cout << c << ":\n";
  //   for (int i = 1; i <= n; i++) {
  //     cout << i << ' ' << nxt[i][c - 'a'] << '\n'; 
  //   }
  // }

  memset(dp, -1, sizeof dp);
  // cout << f(3) << '\n';
  // return 0;

  int q; cin >> q;
  while (q--) {
    string t; cin >> t;
    int m = t.size();
    t = '.' + t;
    int last = 1;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
      // cout << "here: ";
      // cout << last << ' ' << nxt[last][t[i] - 'a'] << '\n';
      last = nxt[last][t[i] - 'a'] + 1;
      if (i < m and last > n) {
        flag = true;
        break;
      }
      if (last - 1 > n) flag = true;
      if (last > n) break;
    }
    // cout << last << '\n';
    if (flag or m > n) cout << 0 << '\n';
    else cout << f(last) + 1 << '\n';
  }

  return 0;
} 