#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define i128 __int128

// ull mulmod(ull a, ull b, ull mod) {
//   if(b == 1) return a % mod;
//   if(b & 1) {
//     ull val = mulmod(a, b / 2, mod);
//     return (((val + val) % mod) + a) % mod;
//   }
//   else {
//     ull val = mulmod(a, b / 2, mod);
//     return (val + val) % mod;
//   }
// }

ull mulmod(ull a, ull b, ull mod) {
  ull ans = ((i128)a * b) % mod;
  return ans;
}

ull power(ull a, ull b, ull mod) {
  if(b == 0) return 1 % mod;
  if(b & 1) {
    ull val = power(a, b / 2, mod);
    return mulmod(mulmod(val, val, mod), a, mod);
  }
  else {
    ull val = power(a, b / 2, mod);
    return mulmod(val, val, mod);
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ull a, b, mod;
  while(cin >> a >> b >> mod) {
    cout << power(a, b, mod) << '\n';
  }
        
  return 0;
}