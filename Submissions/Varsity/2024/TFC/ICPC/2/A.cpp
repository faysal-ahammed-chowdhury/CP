#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<array<int, 3>> star;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    int sum = 0;
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] >= 0) sum += a[i][j];
    }
    star.push_back({x, sum, i});
  }
  sort(star.rbegin(), star.rend());

  array<int, 2> score[n + 1];
  memset(score, 0, sizeof score);
  for (int i = 1; i <= n; i++) {
    int sum = 0, cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] <= -1) cnt++;
      else sum += a[i][j];
    }
    int l = sum, r = sum + (k * cnt);
    score[i] = {l, r};
  }

  int last = score[star[0][2]][1], prev = star[0][0];
  int increase[n + 1];
  increase[star[0][2]] = last - score[star[0][2]][0];
  for (int i = 1; i < star.size(); i++) {
    int idx = star[i][2];
    if (prev == star[i][0]) {
      int mn = score[idx][0];
      if (mn > last) {
        cout << "No\n";
        return;
      }
      int mx = score[idx][1];
      last = min(last, mx);
      increase[idx] = last - mn;
      assert(increase[idx] >= 0);
    }
    else {
      int mn = score[idx][0];
      if (mn >= last) {
        cout << "No\n";
        return;
      }
      int mx = score[idx][1];
      last = min(last - 1, mx);
      increase[idx] = last - mn;
    }
    prev = star[i][0];
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    int x = increase[i];
    for (int j = 1; j <= m; j++) {
      if (a[i][j] <= -1) {
        int here = min(k, x);
        a[i][j] = here;
        cout << here << ' ';
        x -= here;
      }
      else cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}