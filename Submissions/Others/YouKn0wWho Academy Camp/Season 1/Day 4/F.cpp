#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n, m, k; cin >> n >> m >> k;
  string a, b; cin >> a >> b;
  map<char, set<char>> mp;
  for(int i = 0; i < n; i++) {
    if(i - k + 1 >= 0) {
      mp[a[i]].insert(a[i - k + 1]);
    }
  }
  map<char, int> mp2;
  long long ans = 0;
  for(int i = 0; i < m; i++) {
    for(auto j: mp[b[i]]) {
      if(j == b[i]) ans++;
      ans += mp2[j];
    }
    mp2[b[i]]++;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}