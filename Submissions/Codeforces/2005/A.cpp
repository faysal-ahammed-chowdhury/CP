#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  if (n == 1) cout << "a\n";
  if (n == 2) cout << "ae\n";
  if (n == 3) cout << "aei\n";
  if (n == 4) cout << "aeio\n";
  if (n == 5) cout << "aeiou\n";
  if (n > 5) {
    int x = n / 5;
    int rem = n % 5;
    string s = "";
    for (int i = 1; i <= x; i++) {
      s += 'a';
    }
    if (rem) {
      s += 'a';
      rem--;
    }
    for (int i = 1; i <= x; i++) {
      s += 'e';
    }
    if (rem) {
      s += 'e';
      rem--;
    }
    for (int i = 1; i <= x; i++) {
      s += 'i';
    }
    if (rem) {
      s += 'i';
      rem--;
    }
    for (int i = 1; i <= x; i++) {
      s += 'o';
    }
    if (rem) {
      s += 'o';
      rem--;
    }
    for (int i = 1; i <= x; i++) {
      s += 'u';
    }
    cout << s << '\n';
  }
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