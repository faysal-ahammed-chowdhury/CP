#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  list<int> li;
  for (int i = 1; i <= n; i++) {
    li.push_back(i);
  }

  auto it = li.begin();
  while (!li.empty()) {
    if (it == li.end()) it = li.begin();
    ++it;
    if (it == li.end()) it = li.begin();
    cout << *it << ' ';
    it = li.erase(it);
    if (it == li.end()) it = li.begin();
  }

  return 0;
}