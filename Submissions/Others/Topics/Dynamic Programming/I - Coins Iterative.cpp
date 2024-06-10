#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int n;
double a[N], dp[N][N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int head = 0; head <= n; head++) {
      if (i == n + 1) {
        int tail = n - head;
        if (head > tail) dp[i][head] = 1;
        else dp[i][head] = 0;
      }
      else {
        double &ans = dp[i][head];
        ans = a[i] * dp[i + 1][head + 1];
        ans += (1 - a[i]) * dp[i + 1][head];
      }
    }
  }

  cout << fixed << setprecision(10) << dp[1][0] << '\n';

  return 0;
}