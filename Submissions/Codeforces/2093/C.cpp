#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(ll n) {
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  int n, k; cin >> n >> k;

  if (k == 1) {
    if (is_prime(n)) cout << "YES\n";
    else cout << "NO\n";
    return;
  }

  if (n % 2 == 0 or n % 5 == 0) {
    cout << "NO\n";
    return;
  }

  string s = to_string(n);
  int len = s.size() * k;
  if (len > 11) {
    cout << "NO\n";
    return;
  }
 
  string tmp = "";
  for (int i = 1; i <= k; i++) {
    tmp += s;
  }
 
  ll x = atoll(tmp.c_str());
 
  if (is_prime(x)) cout << "YES\n";
  else cout << "NO\n";

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