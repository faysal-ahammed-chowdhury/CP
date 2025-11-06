#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;
  if (k % 2 == 0) {
    cout << "NO\n";
    return 0;
  }

  if (k == 1) {
    cout << "YES\n";
    cout << 2 << ' ' << 1 << '\n';
    cout << 1 << ' ' << 2 << '\n';
    return 0;
  }

  vector<pair<int, int>> ans;
  ans.push_back({1, 2});

  int it = k / 2;
  int last = 3;
  while (it--) {
    for (int i = last, cnt = 1; cnt <= k + 1; i++, cnt++) {
      for (int j = i + 1, cnt2 = cnt + 1; cnt2 <= k + 1; j++, cnt2++) {
        if (i == last and j == last + 1) {
          ans.push_back({1, i});
          ans.push_back({1, j});
        }
        else {
          ans.push_back({i, j});
        }
      }
    }

    last += k + 1;
  }

  it = k / 2;
  int n = 1;
  while (it--) {
    for (int i = last, cnt = 1; cnt <= k + 1; i++, cnt++) {
      for (int j = i + 1, cnt2 = cnt + 1; cnt2 <= k + 1; j++, cnt2++) {
        n = max(n, j);
        if (i == last and j == last + 1) {
          ans.push_back({2, i});
          ans.push_back({2, j});
        }
        else {
          ans.push_back({i, j});
        }
      }
    }

    last += k + 1;
  }

  cout << "YES\n";
  cout << n << ' ' << ans.size() << '\n';
  for (auto [u, v] : ans) {
    cout << u << ' ' << v << '\n';
  }

  return 0;
}