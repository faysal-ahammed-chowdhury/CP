#include <bits/stdc++.h>
using namespace std;

// @author: Faaysal

#define ll long long

void solve() {
  int n, m, d; cin >> n >> m >> d;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = max(a[i], 0);
  }
  multiset<int> ms;
  ll sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, sum + a[i] - 1ll * d * i);
    ms.insert(a[i]);
    sum += a[i];
    if (ms.size() == m) {
      sum -= *ms.begin();
      ms.erase(ms.begin());
    }
  }

  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}