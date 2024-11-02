#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, x;
string s, t;
vector<int> lps;

vector<int> prefix_function(const string &s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}

int f(int i, int j, vector<vector<int>> &dp) {
  if (i >= n) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  int one = (j == m - 1) and (s[i] == t[j] or s[i] == '?');
  ans = f(i + 1, 0, dp);
  if (s[i] == '?' or s[i] == t[j]) {
    ans = max(ans, one + f(i + 1, (one ? x : j + 1), dp));
  }
  if (j > 0) {
    ans = max(ans, f(i, lps[j - 1], dp));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;
  n = s.size();
  m = t.size();
  lps = prefix_function(t);
  x = lps.back();

  vector<vector<int>> dp(n + 5, vector<int>(m + 5, -1));
  cout << f(0, 0, dp) << '\n';

  return 0;
}