#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();

  int i = 0, j = n - 1, cnt = 0;
  map<int, int> mp1, mp2;
  while(i < j) {
    bool done = false;
    mp1[s[i] - '0']++;
    mp2[s[j] - '0']++;
    bool possible = true;
    for(auto i: mp1) {
      if(!(mp2.find(i.first) != mp2.end() && i.second == mp2[i.first])) {
        possible = false;
      }
    }
    for(auto i: mp2) {
      if(!(mp1.find(i.first) != mp1.end() && i.second == mp1[i.first])) {
        possible = false;
      }
    }
    if(possible) {
      done = true;
      cnt += 2;
    }
    if(done == false && (j - i) == 1) {
      cnt++;
    }
    i++, j--;
  }

  if(n % 2 == 1) cnt++;

  cout << cnt << '\n';

  return 0;
}