#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n;
double dp[N];
bool vis[N];

double f(int x) {
  if (x > n) return 0;
  if (x == n) return 0;
  if (vis[x]) return dp[x];
  vis[x] = true;
  double ans = (double)x / n;
  ans += ((double)(n - x) / n) * (1 + f(x + 1));
  ans /= (double)(n - x) / n;
  dp[x] = ans;
  return ans;
}

int cs;
void solve() {
  cin >> n;
  memset(vis, 0, sizeof vis);
  cout << fixed << setprecision(10);
  cout << "Case " << ++cs << ": " << f(0) << '\n';
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