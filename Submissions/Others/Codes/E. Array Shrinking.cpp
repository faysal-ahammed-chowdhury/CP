#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
int dp1[N][N], dp2[N];
int n, a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n; i >= 1; i--) {
    for (int j = i; j <= n; j++) {
      if (i == j) dp1[i][j] = a[i];
      else if (i < j) {
        for (int k = i; k < j; k++) {
          if (dp1[i][k] != 0 and dp1[i][k] == dp1[k + 1][j]) {
            dp1[i][j] = dp1[i][k] + 1;
          }
        }
      }
    }
  }

  dp2[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp2[i] = 1e9;
    for (int j = 0; j < i; j++) {
      if (dp1[j + 1][i]) dp2[i] = min(dp2[i], dp2[j] + 1);
    }
  }

  cout << dp2[n] << '\n';

  return 0;
}