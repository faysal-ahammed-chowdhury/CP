#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n + 1], b[n + 1], diff[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
      diff[i] = a[i] - b[i];
    }
    sort(diff + 1, diff + n + 1);
    // for(int i = 1; i <= n; i++) {
    //   cout << diff[i] << ' ';
    // }
    // cout << '\n';
    int ans[n + 1];
    for(int i = 1; i <= n; i++) {
      int d = a[i] - b[i];
      int idx = upper_bound(diff + 1, diff + n + 1, d) - diff - 1;
      // cout << i << " " << d << " " << idx << '\n';
      ans[i] = idx - 1;
    }

    vector<int> res;
    for(int i = 1; i <= n; i++) {
      if(ans[i] == n - 1) {
        res.push_back(i);
      }
    }

    cout << res.size() << '\n';
    for(auto i: res) {
      cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}