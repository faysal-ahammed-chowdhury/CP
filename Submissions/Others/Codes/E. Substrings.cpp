#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int sum = 0;
  int a[n];
  map<char, int> mp;
  for (int i = n - 1; i >= 0; i--) {
    a[i] = (((((sum + 1) % mod) - mp[s[i]]) % mod) + mod) % mod;
    sum = (sum + a[i]) % mod;
    mp[s[i]] += a[i];
    mp[s[i]] %= mod;
  }

  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = (ans + a[i]) % mod;
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