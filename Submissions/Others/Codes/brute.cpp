#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 10, MAX = 1e9;
int n, d, ans;
int H[N], E[N];

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void f(int mask, vector<int> &v, int tot, vector<int> &vec) {
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (CHECK(mask, i) == false) ok &= v[i] <= 0;
  }
  if (ok) {
    ans = min(ans, tot);
    // cout << tot << '\n';
    // if (tot == MAX) {
    //   for (auto x : vec) {
    //     cout << x << ' ';
    //   }
    //   cout << '\n';
    // }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (CHECK(mask, i) == false) {
      int cost = (max(0ll, v[i]) + d - 1) / d;
      v[i - 1] -= E[i];
      v[i + 1] -= E[i];
      vec.push_back(i);
      f(mask | (1 << i), v, tot + cost, vec);
      vec.pop_back();
      v[i - 1] += E[i];
      v[i + 1] += E[i];
    }
  }
}

void solve() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> H[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> E[i];
  }
  vector<int> v(n + 5, 0);
  for (int i = 1; i <= n; i++) {
    v[i] = H[i];
  }

  ans = 1e18;

  vector<int> vec;
  f(0, v, 0, vec);
  cout << ans << '\n';
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