#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a, b;
bool vis[105][605];
double dp[105][605];

double f(int i, int sum) {
  if (i > n) return (sum >= a and sum <= b);
  if (vis[i][sum]) return dp[i][sum];
  vis[i][sum] = true;
  double ans = 0;
  for (int j = 1; j <= 6; j++) {
    ans += (1 / 6.0) * f(i + 1, sum + j);
  }
  return dp[i][sum] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> a >> b;
  cout << fixed << setprecision(6);
  cout << f(1, 0) << '\n';

  return 0;
}