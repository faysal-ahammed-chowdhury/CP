#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;
  string s = "9876543210";
  vector<long long> v;
  for(int mask = 1; mask < (1 << 10); mask++) {
    string ans = "";
    for(int k = 0; k < 10; k++) {
      if(mask & (1 << k)) {
        ans += s[k];
      }
    }
    long long num = atol(ans.c_str());
    if(num != 0) v.push_back(num);
  }
  sort(v.begin(), v.end());


  cout << v[k - 1] << '\n';

  return 0;
}