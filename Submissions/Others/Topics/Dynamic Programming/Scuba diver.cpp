#include <bits/stdc++.h>
using namespace std;

const int N = 1005, inf = 1e9;
int n, oxygen_weight, nitrogen_weight;
int oxygen[N], nitrogen[N], weight[N];
int dp[2][25][85];

void solve() {
  cin >> oxygen_weight >> nitrogen_weight >> n;
  for (int i = 1; i <= n; i++) {
    cin >> oxygen[i] >> nitrogen[i] >> weight[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int oxygen_need = 0; oxygen_need <= oxygen_weight; oxygen_need++) {
      for (int nitrogen_need = 0; nitrogen_need <= nitrogen_weight; nitrogen_need++) {
        if (i == 0) {
          if (oxygen_need == 0 and nitrogen_need == 0) {
            dp[1][oxygen_need][nitrogen_need] = 0;
          }
          else {
            dp[1][oxygen_need][nitrogen_need] = inf;
          }
        }
        else {
          int &ans = dp[1][oxygen_need][nitrogen_need];
          ans = inf;
          ans = min(ans, weight[i] + dp[0][max(0, oxygen_need - oxygen[i])][max(0, nitrogen_need - nitrogen[i])]);
          ans = min(ans, dp[0][oxygen_need][nitrogen_need]);
        }
      }
    }
    for (int oxygen_need = 0; oxygen_need <= oxygen_weight; oxygen_need++) {
      for (int nitrogen_need = 0; nitrogen_need <= nitrogen_weight; nitrogen_need++) {
        dp[0][oxygen_need][nitrogen_need] = dp[1][oxygen_need][nitrogen_need];
      }
    }
  }
  cout << dp[1][oxygen_weight][nitrogen_weight] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}