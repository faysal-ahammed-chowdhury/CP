#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(int i = 1; i < n; i++) {
      a[i] += a[i - 1];
    }
    while(q--) {
      int k; cin >> k;
      if(k > a[n - 1]) {
        cout << -1 << '\n';
        continue;
      }
      int diff = lower_bound(a.begin(), a.end(), k) - a.begin();
      cout << diff + 1 << '\n';
    }
  }

  return 0;
}