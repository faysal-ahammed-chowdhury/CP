#include <bits/stdc++.h>
using namespace std;

int n, m;
string txt, pat;
vector<int> lps;

vector<int> build_lps(string &pat) {
  int n = pat.size();
  vector<int> lps(n, 0);
  for (int i = 1; i < n; i++) {
    int j = lps[i - 1];
    while (j > 0 and pat[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (pat[i] == pat[j]) j++;
    lps[i] = j;
  }
  return lps;
}

int f(int i, int j, vector<vector<int>> &dp) {
  if (i >= n) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = f(i + 1, 0, dp);
  if (j > 0) ans = max(ans, f(i, lps[j - 1], dp));
  if (txt[i] == '?' or txt[i] == pat[j]) {
    bool ok = j + 1 == m;
    ans = max(ans, ok + f(i + 1, ok ? lps[j] : j + 1, dp));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> txt >> pat;
  n = txt.size();
  m = pat.size();
  lps = build_lps(pat);
  vector<vector<int>> dp(n, vector<int>(m, -1));
  cout << f(0, 0, dp) << '\n';

  return 0;
}
