#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 2e9, mod = 998244353;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll mn = 0, min_idx = 1;
  ll pref[n + 1]; 
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
    if (pref[i] < mn) {
      mn = pref[i];
      min_idx = i;
    }
  }
  
  ll k = 0;
  for (int i = 1; i <= n; i++) {
    k += a[i];
    if (i == min_idx) k = abs(k);
  }

  if (mn >= 0) {
    cout << power(2, n, mod) << '\n';
    return;
  }

  int cnt = 0;
  ll ans = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    ll r_sum = pref[n] - pref[i];
    sum += a[i];
    cnt += sum >= 0;
    if (sum < 0 and abs(sum) + r_sum == k) {
      int tot = cnt + n - i;
      ans = (ans + power(2, tot, mod)) % mod;
    }
  }

  if (ans == 0) ans = power(2, n, mod);
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