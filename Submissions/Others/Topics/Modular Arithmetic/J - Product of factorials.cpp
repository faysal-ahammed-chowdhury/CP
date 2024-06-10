#include <bits/stdc++.h>
using namespace std;

#define u128 unsigned __int128
const long long mod = 109546051211;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  long long a[n + 1];
  a[0] = 1, a[1] = 1;
  for(int i = 2; i <= n; i++) {
    a[i] = 1LL * a[i - 1] * i % mod;
  }
  for(int i = 2; i <= n; i++) {
    a[i] = (u128)a[i - 1] * a[i] % mod;
  }
  cout << a[n] << '\n';    
  return 0;
}