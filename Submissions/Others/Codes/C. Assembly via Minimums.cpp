#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  multiset<int> ms;
  for(int i = 0; i < n * (n - 1) / 2; i++) {
    int x; cin >> x;
    ms.insert(x);
  }
  int curr = 1, last;
  while(!ms.empty()) {
    int tmp = *ms.begin();
    for(int i = 1; i <= n - curr; i++) {
      ms.erase(ms.find(tmp));
    }
    curr++;
    cout << tmp << ' ';
    last = tmp;
  }
  cout << last << '\n';
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