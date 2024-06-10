#include <bits/stdc++.h>
using namespace std;

int a, b, k;

int power(int n, int p) {
  if(p == 1) return n % k;
  if(p & 1) {
    int val = power(n, p / 2);
    return ((1LL * val * val) % k) * n % k;
  }
  else {
    int val = power(n, p / 2);
    return (1LL * val * val) % k;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> k;
  k = pow(10, k);
  cout << power(a, b) << '\n';

  return 0;
}