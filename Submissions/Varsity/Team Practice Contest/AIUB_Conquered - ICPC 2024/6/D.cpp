#include <bits/stdc++.h>
using namespace std;

const int N = 10005, K = 505;
int n, s, k;
double dp[N][K];
bool vis[N][K];

double f(int i, int unique) {
  if (i > n) return unique >= k;
  if (vis[i][unique]) return dp[i][unique];
  vis[i][unique] = true;
  double ans = f(i + 1, unique) * ((1.0 * unique) / s); 
  if (unique < s) ans += f(i + 1, unique + 1) * ((1.0 * (s - unique)) / s);
  return dp[i][unique] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s >> k;
  cout << fixed << setprecision(10);
  cout << f(1, 0) << '\n';

  return 0;
}