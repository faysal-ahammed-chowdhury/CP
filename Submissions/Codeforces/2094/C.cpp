#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + n + 1];
  set<int> se;
  for (int i = 1; i <= n + n; i++) {
    se.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int x; cin >> x;
      se.erase(x);
      a[i + j] = x;
    }
  }
  a[1] = *se.begin();
  for (int i = 1; i <= n + n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}