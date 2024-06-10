#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  string s; cin >> s;
  int n = s.size();
  map<int, char> mp;
  char mx = s[n - 1];
  mp[n - 1] = mx;
  for(int i = n - 2; i >= 0; i--) {
    mx = max(mx, s[i]);
    mp[i] = mx;
  }

  string ans = "";

  for(auto i: mp) {
    if(i.second == s[i.first]) {
      ans += i.second;
    }
  }

  cout << ans << '\n';

  return 0;
}