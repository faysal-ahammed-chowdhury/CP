#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 2e5 + 9;

void solve() {
  int n; cin >> n;
  map<int, int> mp1, mp2, mp3;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp1[x]++;
  }
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp2[x]++;
  }
  for(auto i: mp1) {
    int option = n - mp2[i.first];
    mp3[i.first] = option;
  }
  for(auto i: mp1) {
    if(i.second > mp3[i.first]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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