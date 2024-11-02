#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 1e12;
int n, m, k, dp[N]; 
string s;

int f(int i) {
  if (i >= n + 1) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = inf;
  if (s[i] == 'C') return inf;
  if (s[i] == 'L') {
    for (int j = 1; j <= m; j++) {
      ans = min(ans, f(i + j));
    }
  }
  ans = min(ans, 1 + f(i + 1));
  return ans;
}

void solve() {
  cin >> n >> m >> k >> s;
  s = 'L' + s;
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  int need = f(0);
  cout << (need <= k ? "YES" : "NO") << '\n';
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