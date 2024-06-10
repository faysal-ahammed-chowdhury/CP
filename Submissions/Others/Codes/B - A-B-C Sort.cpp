#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int start = 0;
    vector<int> ans;
    if(n % 2 == 1) {
      start = 1;
      ans.push_back(a[0]);
    }
    for(int i = start; i < n; i += 2) {
      ans.push_back(min(a[i], a[i + 1]));
      ans.push_back(max(a[i], a[i + 1]));
    }

    if(is_sorted(ans.begin(), ans.end())) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }

  }

  return 0;
}