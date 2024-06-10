#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.length();
  map<char, int> mp;
  for(auto i: s) {
    mp[i]++;
  }
  
  int cnt = 0;
  char mid;
  for(auto i: mp) {
    if(i.second & 1) {
      mid = i.first;
      cnt++;
    }
    // cout << i.first << ' ' << i.second << '\n';
  }

  if(cnt > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }

  string ans = "";
  for(auto i: mp) {
    char ch = i.first;
    int len = i.second;
    len /= 2;
    for(int j = 1; j <= len; j++) {
      ans += ch;
    }   
  }

  string tmp = ans;
  reverse(tmp.begin(), tmp.end());
  if(cnt == 1) {
    ans += mid;
  }
  ans += tmp;

  cout << ans << '\n';



  return 0;
}