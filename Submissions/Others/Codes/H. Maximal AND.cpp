#include <bits/stdc++.h>
using namespace std;

int get_bit(int n, int k) {
  return (n & (1 << k)) == 0 ? 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, max_op; cin >> n >> max_op;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    map<int, int> mp;
    for(int i = 0; i < n; i++) {
      for(int k = 0; k <= 30; k++) {
        mp[k] += get_bit(a[i], k);
      }
    }

    vector<int> v;
    for(int k = 30; k >= 0; k--) {
      int need = n - mp[k];
      if(max_op >= need) {
        v.push_back(k);
        max_op -= need;
      }
    }

    int ans = a[0];
    for(int i = 1; i < n; i++) {
      ans &= a[i];
    }
    for(auto i: v) {
      ans = ans | (1 << i);
    }
    cout << ans << '\n';
  }

  return 0;
}