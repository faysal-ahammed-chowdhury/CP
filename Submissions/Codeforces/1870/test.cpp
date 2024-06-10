#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 2e5 + 9;
int a[N], pos[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    pos[x] = i;
  }
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      int l = min(pos[i], pos[j]);
      int r = max(pos[i], pos[j]);
      v.push_back({l, r});
    }
  }

  // for(int i = 1; i <= q; i++) {
  //   int l, r; cin >> l >> r;
  //   int ans = upper_bound(v.begin(), v.end(), {r, r}) - lower_bound(v.begin(), v.end(), {l, l});
  //   cout << ans  + (r - l + 1) << '\n';
  // }

  return 0;
}