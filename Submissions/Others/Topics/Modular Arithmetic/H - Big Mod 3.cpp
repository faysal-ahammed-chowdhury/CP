#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define u128 unsigned __int128

ull mulmod(ull a, ull b, u128 mod) {
  ull ans = (u128) a * b % mod;
  return ans;
}

ull power(ull a, ull b, u128 mod) {
  if(b == 1) return a % mod;
  if(b & 1) {
    ull val = power(a, b / 2, mod);
    return mulmod(mulmod(val, val, mod), a, mod);
  }
  else {
    ull val = power(a, b / 2, mod);
    return mulmod(val, val, mod);
  }
}

void solve() {
  ull a, b; string mod_s; cin >> a >> b >> mod_s;
  u128 mod = 0;
  for(auto i: mod_s) {
    int n = i - '0';
    mod = mod * 10 + n;
  }
  cout << power(a, b, mod) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}
