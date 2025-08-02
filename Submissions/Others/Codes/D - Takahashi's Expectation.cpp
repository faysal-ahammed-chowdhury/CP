#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 9;
int dp[N][1005], p[N], a[N], b[N];
ll pref[N];
int n;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> a[i] >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + b[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int cur_mood = 0; cur_mood <= 1000; cur_mood++) {
      if (i == n + 1) {
        dp[i][cur_mood] = cur_mood;
      }
      else {
        if (p[i] >= cur_mood) dp[i][cur_mood] = dp[i + 1][cur_mood + a[i]];
        else dp[i][cur_mood] = dp[i + 1][max(0, cur_mood - b[i])];
      }
    }
  }

  int q; cin >> q;
  while (q--) {
    int x; cin >> x;
    if (x <= 500) {
      cout << dp[1][x] << '\n';
    }
    else {
      ll extra = x - 500;
      auto it = lower_bound(pref + 1, pref + n + 1, extra);
      int idx = it - pref;
      if (idx == n + 1) {
        cout << x - pref[n] << '\n';
      }
      else {
        ll y = pref[idx];
        if (idx == n) {
          cout << x - y << '\n';
        }
        else {
          cout << dp[idx + 1][x - y] << '\n';
        }
      }
    }
  }

  return 0;
}