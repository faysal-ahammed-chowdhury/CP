#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }
void CLR(int &N, int pos) { (N &= ~(1 << pos)); }

void solve() {
  int n; cin >> n;
  set<int> se;
  vector<int> ans;
  ans.push_back((1 << n) - 1);
  se.insert((1 << n) - 1);
  for (int i = n - 1; i >= 0; i--) {
    int rem = n - i;
    int x = (1 << i) - 1;
    for (int j = 0; j < (1 << rem); j++) {
      int y = j;
      y = y << i;
      int z = x + y;
      if (se.find(z) == se.end()) {
        ans.push_back(z);
        se.insert(z);
      }
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    if (se.find(i) == se.end()) {
      ans.push_back(i);
    }
  } 

  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}