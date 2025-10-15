#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<tuple<int, int, int>> v;
 
void build(int b, int e, int lvl) {
  if (b == e) {
    return;
  }
  int mid = (b + e) >> 1;
  build(b, mid, lvl + 1);
  build(mid + 1, e, lvl + 1);

  for (int i = b; i <= mid; i++) {
    for (int j = mid + 1; j <= e; j++) {
      v.push_back({lvl, i, j});
    }
  }
}

void solve() {
  v.clear();
  int n; cin >> n;
  build(1, n, 1);
  sort(v.rbegin(), v.rend());
  for (auto [_, x, y] : v) {
    cout << x << ' ' << y << endl;
    int verdict; cin >> verdict;
    if (verdict == 1) {
      return;
    }
  }
}

int32_t main() {
  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}