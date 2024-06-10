#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int n;
double a[N], dp[N][N];
bool vis[N][N];

double fun(int i, int head) {
  if (i == n + 1) {
    if (head > (n - head)) return 1;
    return 0;
  }
  double &ans = dp[i][head];
  if (vis[i][head]) return ans;
  vis[i][head] = true;
  ans = a[i] * fun(i + 1, head + 1);
  ans += (1 - a[i]) * fun(i + 1, head);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << fixed << setprecision(10) << fun(1, 0) << '\n';

  return 0;
}