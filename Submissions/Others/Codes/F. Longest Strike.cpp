#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      mp[x]++;
    }
    bool possible = false;
    int diff = 0, consecutive = 1, l, r, last, mx = -1;
    int cnt = 0, num;
    for(auto i: mp) {
      if(i.second >= k) {
        cnt++;
        num = i.first;
        possible = true;
      }
      if(i.second >= k && i.first - 1 == last && mp[i.first - 1] >= k) {
        consecutive++;
      }
      else {
        if(consecutive != 1 && consecutive > diff) {
          r = last;
          l = r - consecutive + 1;
          diff = (r - l + 1);
        }
        mx = max(mx, consecutive);
        consecutive = 1;
      }
      last = i.first;
    }
    if(consecutive != 1 && consecutive > diff) {
      r = last;
      l = r - consecutive + 1;
      mx = max(mx, consecutive);
    }
    
    if(possible) {
      if(cnt == 1 || mx == 1) {
        cout << num << ' ' << num << '\n';
      }
      else {
        cout << l << ' ' << r << '\n';
      }
    }
    else {
      cout << -1 << '\n';
    }
  }

  return 0;
}