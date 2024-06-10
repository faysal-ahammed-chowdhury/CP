#include <bits/stdc++.h>
using namespace std;

const int mod = 10;

unsigned int power(unsigned int a, unsigned int b) {
  if(b == 0) return 1;
  unsigned int val = power(a, b / 2);
  if(b & 1) {
    return (val * val % mod) * a % mod;
  }
  else {
    return val * val % mod;
  }
}

void solve() {
  unsigned int a, b; cin >> a >> b;
  cout << power(a, b) << '\n';
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