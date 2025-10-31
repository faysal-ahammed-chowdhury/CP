#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  int s = 0, ans = 0, last = 0, en = n;
  vector<int> v;
  for (int i = 1; i <= en; i++) {
    if (((s + a[i]) / x) > last) {
      v.push_back(a[i]);
      s += a[i];
      ans += a[i];
      last = s / x;
    }
    else {
      while (en > i and ((s + a[i]) / x) <= last) {
        s += a[en];
        v.push_back(a[en]);
        last = s / x;
        en--;
      }
      s += a[i];
      v.push_back(a[i]);
      if ((s / x) > last) {
        ans += a[i];
      }
    }
    last = s / x;
  }
  cout << ans << '\n';
  assert(v.size() == n);
  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';
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