#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int mn = INT_MAX, first, second;
    for(int i = 1; i < n; i++) {
      if(abs(a[i] - a[i - 1]) <= mn) {
        mn = abs(a[i] - a[i - 1]);
        first = max(a[i - 1], a[i]);
        second = min(a[i - 1], a[i]);
      }
    }

    bool take_first = false, take_second = false;
    vector<int> v, ans;
    for(int i = 0; i < n; i++) {
      if(a[i] == first && take_first == false) {
        take_first = true;
        continue;
      }
      if(a[i] == second && take_second == false) {
        take_second = true;
        continue;
      }
      v.push_back(a[i]);
    }
    
    if(upper_bound(v.begin(), v.end(), first) == v.end()) {
      swap(first, second);
    }
    ans.push_back(first);
    auto it1 = lower_bound(v.begin(), v.end(), first);
    for(auto it = it1; it != v.end(); it++) {
      ans.push_back(*it);
    }
    for(auto it = v.begin(); it != it1; it++) {
      ans.push_back(*it);
    }
    ans.push_back(second);
    for(auto i: ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}