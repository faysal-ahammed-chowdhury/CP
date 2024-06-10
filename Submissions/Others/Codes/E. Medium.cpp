#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;
  string s; cin >> s;
  map<char, int> mp;
  for(auto i: s) {
    mp[i]++;
  }
  for(auto i: mp) {
    if(i.second % k != 0) {
      cout << -1 << '\n';
      return 0;
    }
  }

  string ans = "";
  for(auto i: mp) {
    for(int j = 0; j < i.second / k; j++) {
      ans += i.first;
    }
  }
  string tmp = ans;
  for(int i = 1; i < k; i++) {
    ans += tmp;
  }
  cout << ans << '\n';

  return 0;
}