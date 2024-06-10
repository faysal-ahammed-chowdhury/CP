#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  string s = to_string(n);
  int len = (int)s.size();
  int mul = pow(10, len);
  int tmp = n;
  for(int i = 0; i < 10000009; i++) {
    if(n % k == 0) {
      cout << i << '\n';
      return 0;
    }
    n = (1LL * n * mul) % k + tmp;
    n = n % k;
  }
  cout << -1 << '\n';
        
  return 0;
}