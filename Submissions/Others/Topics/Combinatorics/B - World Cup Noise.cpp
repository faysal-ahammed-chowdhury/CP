#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 55;
ll f[N];

int cs = 0;
void solve() {
  int n; cin >> n;
  cout << "Scenario #" << ++cs << ":\n";
  cout << f[n] << '\n';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  f[1] = 2, f[2] = 3;
  for (int i = 3; i < N; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}