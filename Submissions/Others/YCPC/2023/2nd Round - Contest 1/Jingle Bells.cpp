#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int pos = n / 2 + 1;
  int len = pos + 5;

  int last = 1;
  for(int i = 1, space = len - 1, star = 1; i <= len; i++, space--, star += 2) {
    for(int j = 1; j <= space; j++) {
      cout << ' ';
    }
    for(int j = 1; j <= star; j++) {
      cout << '*';
    }
    cout << '\n';
    last = star;
  }

  for(int k = 1; k <= 5; k++) {
    int space = (last - n) / 2;
    for(int i = 1; i <= space; i++) {
      cout << ' ';
    }
    for(int i = 1; i <= n; i++) {
      cout << '*';
    }
    cout << '\n';
  }

  return 0;
}