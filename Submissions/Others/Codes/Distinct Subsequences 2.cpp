#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1000000007;
int n;
string s;
int nxt[N][26], dp[N];

int get(char c) {
  return c - 'A';
}

int f(int i) {
  if (i > n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = 1;
  for (int c = 0; c < 26; c++) {
    ans = (ans + f(nxt[i][c])) % mod;
  }
  return ans;
}

void solve() {
  cin >> s;
  n = s.size();
  s = '.' + s;
  for (int i = n; i >= 0; i--) {
    if (i == n) {
      for (int c = 0; c < 26; c++) {
        nxt[i][c] = n + 1;
      }
    }
    else {
      for (int c = 0; c < 26; c++) {
        nxt[i][c] = nxt[i + 1][c];
      }
      nxt[i][get(s[i + 1])] = i + 1;
    }
  }
  memset(dp, -1, sizeof dp);
  cout << f(0) << '\n';
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