#include <bits/stdc++.h>
using namespace std;

const int N = 105, MAX_VAL = 1e5 + 9, inf = 1e9;
int n, tot, a[N];
bool dp[2][N / 2][MAX_VAL / 2];

// int fun(int i, int nisi, int sum) {
//   if (i == n + 1) {
//     if (nisi == 0) {
//       return abs((tot - sum) - sum);
//     }
//     return inf;
//   }

//   int &ans = dp[i][nisi][sum];
//   if (ans != -1) return ans;

//   ans = fun(i + 1, nisi, sum);
//   if (nisi > 0) {
//     ans = min(ans, fun(i + 1, nisi - 1, sum + a[i]));
//   }
//   return ans;
// }


int cs = 0;
void solve() {
  cin >> n;
  tot = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tot += a[i];
  }

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  int pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  int half = (tot / 2) + (tot % 2);
  memset(dp, 0, sizeof(dp));

  for (int i = n + 1; i >= 1; i--) {
    int x = min((n + 1) - i + 1, (n + 1) / 2);
    for (int nisi = 0; nisi <= x; nisi++) {
      int y = min(half, pref[i + nisi - 1] - pref[i - 1]);
      for (int sum = 0; sum <= y; sum++) {
        if (i == n + 1) {
          dp[0][nisi][sum] = (nisi == 0 and sum == 0);
        }
        else {
          bool &ans = dp[0][nisi][sum];
          ans = dp[1][nisi][sum];
          if (nisi > 0 and sum >= a[i]) {
            ans |= dp[1][nisi - 1][sum - a[i]];
          }
        }
      }
    }

    for (int nisi = 0; nisi <= x; nisi++) {
      int y = min(half, pref[i + nisi - 1] - pref[i - 1]);
      for (int sum = 0; sum <= y; sum++) {
        dp[1][nisi][sum] = dp[0][nisi][sum];
      }
    }
  }

  int x, y, diff = inf;
  for (int sum = 0; sum <= half; sum++) {
    if (dp[0][(n + 1) / 2][sum]) {
      int d =  abs((tot - sum) - sum);
      if (d < diff) {
        diff = d;
        x = sum;
        y = (tot - sum);
      }
    }
  }

  if (x > y) {
    swap(x, y);
  }

  cout << "Case " << ++cs << ": ";
  cout << x << ' ' << y << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}