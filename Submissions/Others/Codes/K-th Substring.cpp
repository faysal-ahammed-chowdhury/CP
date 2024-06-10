#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int k; cin >> k;
  int n = s.size();

  vector<string> v;
  for (int i = 0; i < n; i++) {
    v.push_back(s.substr(i, 1));
    if (i + 1 < n) v.push_back(s.substr(i, 2));
    if (i + 2 < n) v.push_back(s.substr(i, 3));
    if (i + 3 < n) v.push_back(s.substr(i, 4));
    if (i + 4 < n) v.push_back(s.substr(i, 5));
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  cout << v[k - 1] << '\n';

  return 0;
}