#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n; cin >> n;
  set<int> se;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    se.insert(x);
  }
  int mex = 0;
  while(se.find(mex) != se.end()) {
    mex++;
  }
  while(true) {
    cout << mex << endl;
    cin >> mex;
    if(mex < 0) return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}