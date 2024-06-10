#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int b[n];
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> a;
    a.push_back(b[0]);
    for(int i = 1; i < n; i++) {
      if(b[i - 1] <= b[i]) {
        a.push_back(b[i]);
      }
      else {
        a.push_back(b[i]);
        a.push_back(b[i]);
      }
    }
    cout << a.size() << '\n';
    for(auto i: a) {
      cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}