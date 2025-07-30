#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2005, mod = 1e9 + 7;
string s, t;
int n, m;
pair<int, int> dp[N][N];
pair<int, int> f(int i, int j) {
  if (j > m) return {n - i + 1, 1};
  if (i > n) return {m - j + 1, 1};
  pair<int, int> &ans = dp[i][j];
  if (~ans.first) return ans;
  ans = {N + N, 0};
  if (s[i] == t[j]) {
    ans.first = min(ans.first, 1 + f(i + 1, j + 1).first);
    ans.second += f(i + 1, j + 1).second;
    ans.second %= mod;
  }
  else {
    ans.first = min(ans.first, 1 + f(i + 1, j).first);
    ans.first = min(ans.first, 1 + f(i, j + 1).first);
    if (ans.first == 1 + f(i + 1, j).first) {
      ans.second += f(i + 1, j).second;
      ans.second %= mod;
    }
    if (ans.first == 1 + f(i, j + 1).first) {
      ans.second += f(i, j + 1).second;
      ans.second %= mod;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;
  n = s.size(), m = t.size();
  s = '.' + s;
  t = '.' + t;

  memset(dp, -1, sizeof dp);
  cout << f(1, 1).second << '\n';

  return 0;
}