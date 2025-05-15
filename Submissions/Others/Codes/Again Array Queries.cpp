#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, M = 1005;
int n, q, a[N];

int cs;
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int l, r; cin >> l >> r;
    l++, r++;

    if (r - l + 1 > 1000) {
      cout << 0 << '\n';
      continue;
    }

    vector<int> v;
    for (int i = l; i <= r; i++) {
      v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int ans = 1e9;
    for (int i = 0; i + 1 < v.size(); i++) {
      ans = min(ans, abs(v[i] - v[i + 1]));
    }
    cout << ans << '\n';
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