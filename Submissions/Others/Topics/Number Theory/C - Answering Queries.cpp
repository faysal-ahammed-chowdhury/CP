#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long sum = 0;
    for(int i = 0; i < n; i++) {
      sum += 1LL * a[i] * (n - 1 - i);
      sum -= 1LL * a[i] * i;
    }
    cout << "Case " << ++cs << ":\n";
    while(q--) {
      int type; cin >> type;
      if(type == 1) {
        cout << sum << '\n';
      }
      else {
        int i, x; cin >> i >> x;
        sum -= 1LL * a[i] * (n - 1 - i);
        sum += 1LL * a[i] * i;
        a[i] = x;
        sum += 1LL * a[i] * (n - 1 - i);
        sum -= 1LL * a[i] * i;
      }
    }
  }

  return 0;
}