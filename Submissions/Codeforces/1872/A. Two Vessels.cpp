#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int a, b, c; cin >> a >> b >> c;
    double need = (a + b) / 2.0;
    double diff = abs(need - a);
    int ans = diff / c;
    if(abs(diff - (long long) diff) <= 1e-6) {
      if((long long) diff % c == 0) {
        cout << diff / c << "\n";
        continue;
      }
    }
    cout << ++ans << '\n';
  }

  return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// // @author: faysalahammedchowdhury

// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   int t; cin >> t;
//   while(t--) {
//     int a, b, c; cin >> a >> b >> c;
//     double need = (a + b) / 2.0;
//     double diff = abs(need - a);
//     int ans = diff / c;
//     cout << ceil(diff / c) << '\n';
//   }

//   return 0;
// }