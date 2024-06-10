#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;
int n, p, k;
int cs = 0;
bool ok;
int p_bonacci(int n, int p) {
  if (ok) return 0;
  if (n < p) return n;

  int ans = 0;
  for (int i = 1; i <= p; i++) {
    if (ok) return 0;
    if (++cs == k) {
      cout << n << ' ' << n - i << '\n';
      ok = true;
      return 0;
    }
    ans += p_bonacci(n - i, p);
    ans %= mod;
  }
  if (ok) return 0;
  return ans;
}

int tc = 0;
void solve() {
  cin >> n >> p >> k;
  cout << "Case " << ++tc << ": ";
  ok = false;
  p_bonacci(n, p);
  if (!ok) {
    cout << "Invalid\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}