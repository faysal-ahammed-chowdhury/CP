#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;
ll n, k; 

bool possible(ll g) {
  i128 S = ((g + g) + (i128(k - 1) * g));
  if (S > n) return false;
  S = i128(k) * S;
  if (S & 1) return false;
  S /= 2;
  return S <= n;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  if ((i128(k) * (k + 1)) / 2 > n) {
    cout << -1 << '\n';
    return 0;
  }
  ll ans = 0;
  for (ll g = 1; g * g <= n; g++) {
    if (n % g == 0) {
      if (possible(g)) ans = max(ans, g);
      if (possible(n / g)) ans = max(ans, n / g);
    }
  }
  ll sum = 0;
  for (int i = 1, val = ans; i < k; i++, val += ans) {
    cout << val << ' ';
    sum += val;
  }
  cout << n - sum << '\n';

  return 0;
}