#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= 60; i++) {
    set<int> se;
    for (int j = 1; j <= n; j++) {
      se.insert(a[j] % (1ll << i));
    }
    if (se.size() == 2) {
      cout << (1ll << i) << '\n';
      return;
    } 
  }

  for (int i = 1; i <= n; i++) {
    set<int> se;
    for (int j = 1; j <= n; j++) {
      se.insert(a[j] % a[i]);
    }
    if (se.size() == 2) {
      cout << a[i] << '\n';
      return;
    } 
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}