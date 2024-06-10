#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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

  // finding mudulo inverse of a
  int a; cin >> a;
  int power_val = mod - 2;
  cout << power(a, power_val) << '\n'; // calculate (a inverse 1) in mod 1e9 + 7
  // formula: (a inverse 1 in mod 1e9 + 7) = a ^ mod - 2 in mod 1e9 + 7
        
  return 0;
}