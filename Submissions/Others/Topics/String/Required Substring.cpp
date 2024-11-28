#include <bits/stdc++.h>
using namespace std;

const int N = 1005, M = 105, mod = 1e9 + 7;
int n, m, dp[N][M];
string pat;
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

int f(int i, int j) {
  if (i >= n) return j == m;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = 0;
  if (j == m) {
    for (char c = 'A'; c <= 'Z'; c++) {
      ans += f(i + 1, j);
      ans %= mod;
    }
  }
  else {
    for (char c = 'A'; c <= 'Z'; c++) {
      int tmp = j;
      while (tmp > 0 and c != pat[tmp]) {
        tmp = lps[tmp - 1];
      }
      if (c == pat[tmp]) tmp++;
      ans += f(i + 1, tmp);
      ans %= mod;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> pat;
  m = pat.size();
  lps = build_lps(pat);

  memset(dp, -1, sizeof dp);
  cout << f(0, 0) << '\n';

  return 0;
}
