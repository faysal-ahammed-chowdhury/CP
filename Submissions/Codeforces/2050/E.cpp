#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1010, inf = 1e9;
string s1, s2, s3;
int n, m, p, dp[N][N];

int f(int i, int j, int k) {
  if (k > p) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = inf;
  if (i <= n and s1[i] == s3[k]) ans = min(ans, f(i + 1, j, k + 1));
  if (j <= m and s2[j] == s3[k]) ans = min(ans, f(i, j + 1, k + 1));
  if (i <= n) ans = min(ans, 1 + f(i + 1, j, k + 1));
  if (j <= m) ans = min(ans, 1 + f(i, j + 1, k + 1));

  return ans;
}

void solve() {
  cin >> s1 >> s2 >> s3;
  n = s1.size();
  m = s2.size();
  p = s3.size();

  s1 = '.' + s1;
  s2 = '.' + s2;
  s3 = '.' + s3;

  for (int i = 0; i <= n + 5; i++) {
    for (int j = 0; j <= m + 5; j++) {
      dp[i][j] = -1;
    }
  }
  cout << f(1, 1, 1) << '\n';
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