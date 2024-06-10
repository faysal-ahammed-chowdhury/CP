#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int x = (int) s.size();
  map<char, int> mp;
  for(auto c: s) {
    mp[c]++;
  }

  int n = (int) mp.size();
  if(n <= 2) {
    cout << 0 << '\n';
    return 0;
  }

  vector<int> v;
  for(auto i: mp) {
    v.push_back(i.second);
  }
  sort(v.rbegin(), v.rend());
  int sum = v[0] + v[1];
  cout << x - sum << '\n';

  return 0;
}