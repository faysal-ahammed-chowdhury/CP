#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n; cin >> n;
  int nn = n + n;
  bool en = false, st = false;
  string s = "";
  int len = 0;
  while (true) {
    if (len == n) {
      cout << "! " << s << endl;
      return;
    }
    if (!en) {
      cout << "? " << s + '0' << endl;
      int query; cin >> query;
      if (query) {
        s += '0';
        len++;
      }
      else if (len < n) {
        cout << "? " << s + '1' << endl;
        int query; cin >> query;
        if (query) {
          s += '1';
          len++;
        }
        else en = true;
      }
    }
    else if (len < n and !st) {
      cout << "? " << '0' + s << endl;
      int query; cin >> query;
      if (query) {
        s = '0' + s;
        len++;
      }
      else if (len < n) {
        if (len == n - 1) {
          s = '1' + s;
          cout << "! " << s << endl;
          return;
        }
        cout << "? " << '1' + s << endl;
        int query; cin >> query;
        if (query) {
          s = '1' + s;
          len++;
        }
        else st = true;
      }
    }
  }
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}