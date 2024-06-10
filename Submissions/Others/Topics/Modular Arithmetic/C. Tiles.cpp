#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int power(int a, int power_val) {
  if(power_val == 0) return 1;
  if(power_val & 1) {
    int val = power(a, power_val / 2);
    return ((1LL * val * val) % mod) * a % mod; 
  }
  else {
    int val = power(a, power_val / 2);
    return (1LL * val * val) % mod;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int w, h; cin >> w >> h;
  int x = w + h;
  cout << power(2, x) << '\n';

  return 0;
}