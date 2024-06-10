#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  map<int, vector<int>> mp;
  mp[0] = {0};
  mp[1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  mp[2] = {0, 2, 3, 5, 6, 8, 9};
  mp[3] = {3, 6, 9};
  mp[4] = {0, 4, 5, 6, 7, 8, 9};
  mp[5] = {0, 5, 6, 8, 9};
  mp[6] = {6, 9};
  mp[7] = {0, 7, 8, 9};
  mp[8] = {0, 8, 9};
  mp[9] = {9};

  int t, n; cin >> t;
  while(t--) {
    string s; cin >> s;
    if(s.size() ==  1) {
      cout << s << '\n';
    }
    else if(s.size() == 2) {
      int a = s[0] - '0';
      int b = s[1] - '0';
      n = a * 10 + b;
      int ans = 10000;
      for(auto i: mp) {
        for(auto j: i.second) {
          int x = i.first;
          x = (x * 10) + j;
          if(abs(x - n) <= abs(ans - n)) {
            ans = x;
          }
        }
      }
      cout << ans << '\n';
    }
    else {
      int a = s[0] - '0';
      int b = s[1] - '0';
      int c = s[2] - '0';
      n = a * 100 + b * 10 + c;
      int ans = 10000;
      for(auto i: mp) {
        for(auto j: i.second) {
          for(auto k: mp[j]) {
            int x = i.first;
            x = (x * 100) + (j * 10) + k;
            if(abs(x - n) <= abs(ans - n)) {
              ans = x;
            }
          }
        }
      }
      cout << ans << '\n';
    }
  }

  return 0;
}