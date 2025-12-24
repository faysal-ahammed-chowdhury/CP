#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

void solve() {
  int n, m; cin >> n >> m;
  if (n == 1) {
    cout << m + 1 << '\n';
    return;
  } 

  int msb = __lg(m);
  int x = 0;
  for (int k = msb; k >= 0; k--) {
    if (!CHECK(m, k)) SET(x, k);
  }

  cout << m - x + 1 << '\n';
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