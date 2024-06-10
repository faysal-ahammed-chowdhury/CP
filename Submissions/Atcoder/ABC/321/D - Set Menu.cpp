#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, p; cin >> n >> m >> p;
  vector<int> a(n), b(m);
  for(auto &i: a) {
    cin >> i;
    i = min(i, p);
  }
  for(auto &i: b) {
    cin >> i;
    i = min(i, p);
  }

  sort(b.begin(), b.end());

  vector<long long> prefix(m);
  prefix[0] = b[0];
  for(int i = 1; i < m; i++) {
    prefix[i] = prefix[i - 1] + b[i];
  }

  long long ans = 0;
  for(auto i: a) {
    int possible = p - i;
    int pos = upper_bound(b.begin(), b.end(), possible) - b.begin();
    ans += (1ll * i * pos) + (pos > 0 ? prefix[pos - 1] : 0);
    pos = b.end() - upper_bound(b.begin(), b.end(), possible);
    ans += (1ll * pos * p);
  }
  cout << ans << '\n';

  return 0;
}