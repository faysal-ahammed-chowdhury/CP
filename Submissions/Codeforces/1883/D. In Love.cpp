#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;
  multiset<int> ends, starts;
  while (q--) {
    char c; int l, r; cin >> c >> l >> r;
    if (c == '+') {
      starts.insert(-l);
      ends.insert(r);

      int x = -*starts.begin();
      int y = *ends.begin();
      if (x > y) {
        cout << "Yes\n";
      }
      else {
        cout << "No\n";
      }
    }
    else {
      if (starts.empty()) {
        cout << "No\n";
      }
      else {
        starts.erase(starts.find(-l));
        ends.erase(ends.find(r));
        int x = -*starts.begin();
        int y = *ends.begin();
        if (x > y) {
          cout << "Yes\n";
        }
        else {
          cout << "No\n";
        }
      }
    }
  }

  return 0;
}