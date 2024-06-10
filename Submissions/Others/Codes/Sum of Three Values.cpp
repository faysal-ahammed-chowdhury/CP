#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;
int a[N];

void solve() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int need = k - (a[i] + a[j]);
      ans += mp[need];
    }
    mp[a[i]]++;
  }

  cout << ans << '\n';
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