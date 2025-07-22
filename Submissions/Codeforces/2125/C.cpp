#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

int lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}

int f(int n) {
  int ans = 0;
  vector<int> v = {2, 3, 5, 7};
  for (int mask = 0; mask < 16; mask++) {
    vector<int> tmp;
    for (int i = 0; i < 4; i++) {
      if (CHECK(mask, i)) tmp.push_back(v[i]);
    }
    if (tmp.size() > 0) {
      int lc = tmp[0];
      for (auto x : tmp) {
        lc = lcm(lc, x);
      }
      if (tmp.size() % 2 == 1) ans += (n / lc);
      else ans -= (n / lc);
    }
  }

  return n - ans;
}

void solve() {
  int l, r; cin >> l >> r;
  cout << f(r) - f(l - 1) << '\n';
  // cout << f(100) << '\n';
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