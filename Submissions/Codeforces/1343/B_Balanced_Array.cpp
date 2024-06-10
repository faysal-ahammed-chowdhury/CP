#include <bits/stdc++.h>
using namespace std;

// @author: Faaysal

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int half = n / 2;
    if (half % 2 == 0) {
      cout << "YES\n";
      int curr = 3;
      vector<int> even, odd;
      for (int i = 1; i <= half; i++) {
        if (i % 2 == 0) {
          odd.push_back(curr);
          even.push_back(curr + 1);
        }
        else {
          odd.push_back(curr);
          even.push_back(curr - 1);
        }
        curr += 4;
      }

      for (auto i : even) {
        cout << i << ' ';
      }
      for (auto i : odd) {
        cout << i << ' ';
      }
      cout << '\n';
    }
    else {
      cout << "NO\n";
    }
  }

  return 0;
}