#include <bits/stdc++.h>
using namespace std;

string say(int k) {
  cout << "guess " << k << endl;
  string s; cin >> s;
  return s;
}

int32_t main() {
  int n; cin >> n;

  int l = 0, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    string s = say(mid);
    if (s == "correct") break;
    if (s == "low") {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  return 0;
}