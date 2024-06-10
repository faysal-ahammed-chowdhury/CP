#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  int bit1 = __lg(a); bit1++;
  int one1 = __builtin_popcount(a);
  int zero1 = bit1 - one1;

  int bit2 = __lg(b); bit2++;
  int one2 = __builtin_popcount(b);
  int zero2 = bit2 - one2;

  if(one1 == one2 && zero1 == zero2) {
    cout << "good\n";
  }
  else {
    cout << "bad\n";
  }

  return 0;
}