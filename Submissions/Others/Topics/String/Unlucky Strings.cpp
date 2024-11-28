#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

// this is a TLE solution. we should optimize the code using matexpo (which i don't know :) )

const int N = 1005, M = 55;
string s, pat;
int n, m;
uint dp[N][M];
vector<int> lps;
bool vis[N][M];

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

uint f(int i, int j) {
  if (j >= m) return 0;
  if (i >= n) return 1;
  if (vis[i][j]) return dp[i][j];
  vis[i][j] = true;
  uint ans = 0;
  for (auto c : s) {
    int tmp = j;
    while (tmp > 0 and c != pat[tmp]) {
      tmp = lps[tmp - 1];
    }
    if (c == pat[tmp]) tmp++;
    ans += f(i + 1, tmp);
  }
  return dp[i][j] = ans;
}

int cs;
void solve() {
  cin >> n >> s >> pat;
  m = pat.size();
  lps = build_lps(pat);

  memset(vis, false, sizeof vis);
  cout << "Case " << ++cs << ": " << f(0, 0) << '\n';
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
