#include <bits/stdc++.h>
using namespace std;

const int mod = 10000007;

int power(int n, int k) {
  if(k == 0) return 1;
  int val = power(n, k / 2);
  if(k & 1) {
    return ((1LL * val * val) % mod) * n % mod;
  }
  else {
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
  int n, k; cin >> n >> k;
  while(n && k) {
    int ans1 = (power(n, n) % mod + power(n - 1, n - 1) % mod + power(n - 1, n - 1) % mod) % mod;
    int ans2 = (power(n, k) % mod + power(n - 1, k) % mod + power(n - 1, k) % mod) % mod;
    int ans = (ans1 % mod + ans2 % mod) % mod;
    cout << ans << '\n';
    cin >> n >> k;
  }        
  return 0;
}