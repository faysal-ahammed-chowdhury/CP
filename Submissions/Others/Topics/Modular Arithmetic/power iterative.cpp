#include<bits/stdc++.h>
using namespace std;

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x = 1e8 + 9; long long n = 1e18; int m = 1e9 + 7;
  cout << power(x, n, m) << '\n';
  return 0;
}