#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, w; cin >> n >> w;
  int weight[n + 1], value[n + 1];
  map<int, vector<ll>> mp;
  for (int i = 1; i <= 4; i++) {
    mp[i].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
    mp[weight[i] - weight[1] + 1].push_back(value[i]);
  }

  for (auto &[_, v] : mp) {
    sort(v.rbegin(), v.rend());
    for (int i = 1; i + 1 < v.size(); i++) {
      v[i] += v[i - 1];
    }
  }

  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        for (int l = 0; l <= n; l++) {
          if (i + j + k + l > n) continue;
          if (i > 0 and mp[1].size() < i) continue;
          if (j > 0 and mp[2].size() < j) continue;
          if (k > 0 and mp[3].size() < k) continue;
          if (l > 0 and mp[4].size() < l) continue;

          ll cur = 0;
          if (i > 0) cur += mp[1][i - 1];
          if (j > 0) cur += mp[2][j - 1];
          if (k > 0) cur += mp[3][k - 1];
          if (l > 0) cur += mp[4][l - 1];
          ll cost = 1ll * weight[1] * i;
          cost += 1ll * (weight[1] + 1) * j;
          cost += 1ll * (weight[1] + 2) * k;
          cost += 1ll * (weight[1] + 3) * l;
          if (cost <= w) {
            ans = max(ans, cur);
          }
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}