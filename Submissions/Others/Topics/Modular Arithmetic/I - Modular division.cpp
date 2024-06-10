#include <bits/stdc++.h>
using namespace std;

int power(int n, int p, int mod) {
  if(p == 0) return 1;
  if(p & 1) {
    int val = power(n, p / 2, mod);
    return (1LL * val * val) % mod * n % mod;
  }
  else {
    int val = power(n, p / 2, mod);
    return 1LL * val * val % mod;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, mod; cin >> a >> b >> mod;
  int x = power(b, mod - 2, mod);
  cout << 1LL * a * x % mod << '\n';
  return 0;
}