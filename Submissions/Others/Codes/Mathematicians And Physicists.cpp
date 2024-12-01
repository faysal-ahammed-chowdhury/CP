#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
const int N = 105, M = 1e5 + 9, inf = 1e18;
int n, m;
pair<int, int> a[N], b[M];
int dp1[M][N], dp2[N][M];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b[i].second;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].first;
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  o_set<pair<int, int>> se;
  memset(dp1, -1, sizeof dp1);
  for (int i = n; i >= 1; i--) {
    se.insert({a[i].second, i});
    if ((i > 1 and a[i].first == a[i - 1].first)) continue;
    dp1[a[i].first][0] = 0;
    for (int j = 1; j <= se.size(); j++) {
      dp1[a[i].first][j] = max(0ll, dp1[a[i].first][j - 1]);
      dp1[a[i].first][j] += (*se.find_by_order(j - 1)).first;
    }
  }

  for (int i = 100000; i >= 0; i--) {
    if (dp1[i][0] == -1) {
      for (int j = 0; j <= n; j++) {
        dp1[i][j] = dp1[i + 1][j];
      }
    }
  }

  o_set<pair<int, int>> se2;
  se.clear();
  memset(dp2, -1, sizeof dp2);
  for (int i = m; i >= 1; i--) {
    se.insert({b[i].second, i});
    if (b[i].first > 100 or (i > 1 and b[i].first == b[i - 1].first)) continue;
    if (se2.size() == 0) {
      se2 = se;
      se2.erase({b[i].second, i});
    }
    dp2[b[i].first][0] = 0;
    for (int j = 1; j <= se.size(); j++) {
      dp2[b[i].first][j] = max(0ll, dp2[b[i].first][j - 1]);
      dp2[b[i].first][j] += (*se.find_by_order(j - 1)).first;
    }
  }

  if (se2.size() == 0) se2 = se;

  if (dp2[100][0] == -1) {
    dp2[100][0] = 0;
    for (int j = 1; j <= se2.size(); j++) {
      dp2[100][j] = max(0ll, dp2[100][j - 1]);
      dp2[100][j] += (*se2.find_by_order(j - 1)).first;
    }
  }

  for (int i = 100; i >= 0; i--) {
    if (dp2[i][0] == -1) {
      for (int j = 0; j <= m; j++) {
        dp2[i][j] = dp2[i + 1][j];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int cur = max(0ll, dp1[j][i]) + max(0ll, dp2[i][j]);
      // cout << i << ' ' << j << ' ' << max(0ll, dp1[j][i]) << ' ' << max(0ll, dp2[i][j]) << ' ' << cur << '\n';
      ans = max(ans, cur);
    }
  }

  cout << ans << '\n';

  return 0;
}
