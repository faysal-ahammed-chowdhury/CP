#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

vector<int> f(int len) {
  int z = (len + 1) / 2;
  vector<int> ans;
  for (int st = 1; st + z - 1 <= 9; st++) {
    int n = 0;
    for (int x = st; x <= st + z - 1; x++) {
      n *= 10;
      n += x;
    }
    for (int x = st + z - 2; x >= st; x--) {
      n *= 10;
      n += x;
    }
    ans.push_back(n);
  }
  return ans;
}

int cs;
void solve() {
  int a, b, m; cin >> a >> b >> m;
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    if (i >= a and i <= b and i % m == 0) ans++;
  }
  for (int len = 3; len <= 17; len += 2) {
    vector<int> v = f(len);
    // cout << len << ":\n";
    for (auto x : v) {
      // cout << x << '\n';
      if (x >= a and x <= b and x % m == 0) ans++;
    }
    // cout << '\n';
  }
  cout << "Case #" << ++cs << ": " << ans << '\n';
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