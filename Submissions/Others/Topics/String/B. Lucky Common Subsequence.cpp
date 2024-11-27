#include <bits/stdc++.h>
using namespace std;

const int N = 105, inf = 1e9;
string s1, s2, virus;
int n, m, o;
vector<int> lps;
int dp[N][N][N];

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

int kmp(string &txt, string &pat) {
  vector<int> lps = build_lps(pat);
  int n = txt.size(), m = pat.size();
  int ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j > 0 and txt[i] != pat[j]) {
      j = lps[j - 1];
    }
    if (txt[i] == pat[j]) j++;
    if (j == m) {
      ans++;
      j = lps[j - 1];
    }
  }
  return ans;
}

int f(int i, int j, int k) {
  if (k >= o) return -inf;
  if (i >= n or j >= m) return 0;
  int &ans = dp[i][j][k];
  if (ans != -1) return ans;
  ans = f(i + 1, j, k);
  ans = max(ans, f(i, j + 1, k));
  if (s1[i] == s2[j]) {
    if (s1[i] == virus[k]) {
      ans = max(ans, 1 + f(i + 1, j + 1, k + 1));
    }
    else {
      int tmp = k;
      while (tmp > 0 and s1[i] != virus[tmp]) {
        tmp = lps[tmp - 1];
      }
      if (s1[i] == virus[tmp]) tmp++;
      ans = max(ans, 1 + f(i + 1, j + 1, tmp));
    }
  }
  // cout << i << ' ' << j << ' ' << k << ' ' << ans << '\n';
  return ans;
}

void print(int i, int j, int k) {
  if (k >= o) return;
  if (i >= n or j >= m) return;
  int ans = f(i, j, k);

  if (s1[i] == s2[j]) {
    if (s1[i] == virus[k]) {
      if (ans == 1 + f(i + 1, j + 1, k + 1)) {
        cout << s1[i];
        return print(i + 1, j + 1, k + 1);
      }
    }
    else {
      int tmp = k;
      while (tmp > 0 and s1[i] != virus[tmp]) {
        tmp = lps[tmp - 1];
      }
      if (s1[i] == virus[tmp]) tmp++;
      if (ans == 1 + f(i + 1, j + 1, tmp)) {
        cout << s1[i];
        return print(i + 1, j + 1, tmp);
      }
    }
  }

  if (ans == f(i + 1, j, k)) return print(i + 1, j, k);
  if (ans == f(i, j + 1, k)) return print(i, j + 1, k);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s1 >> s2 >> virus;
  n = s1.size();
  m = s2.size();
  o = virus.size();
  lps = build_lps(virus);

  memset(dp, -1, sizeof dp);
  int len = f(0, 0, 0);
  if (len == 0) cout << len << '\n';
  else print(0, 0, 0);

  return 0;
}
