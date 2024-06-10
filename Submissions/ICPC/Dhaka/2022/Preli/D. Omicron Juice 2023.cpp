#include <bits/stdc++.h>
using namespace std;


#define int long long
// @author: faysalahammedchowdhury

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int a, b, c, k; cin >> a >> b >> c >> k;
  int sum = a + b + c;
  if(sum % 3 != 0) {
    cout << "Fight\n";
    return;
  }

  int arr[3] = {a, b, c};
  sort(arr, arr + 3);
  a = arr[0], b = arr[1], c = arr[2];

  if(a == b && b == c) {
    cout << "Peaceful\n";
    return;
  }

  int cnt = 0;
  if(a < k) cnt++;
  if(b < k) cnt++;
  if(c < k) cnt++;
  if(cnt >= 2) {
    cout << "Fight\n";
    return;
  }
  if(k == 0) {
    cout << "Fight\n";
    return;
  }
  
  int avg = sum / 3;
  if(a >= avg) {
    int need = a - avg;
    if(need % k != 0) {
      cout << "Fight\n";
      return;
    }
  }
  else {
    int need = avg - a;
    if(need % k != 0) {
      cout << "Fight\n";
      return;
    }
  }
  if(b >= avg) {
    int need = b - avg;
    if(need % k != 0) {
      cout << "Fight\n";
      return;
    }
  }
  else {
    int need = avg - b;
    if(need % k != 0) {
      cout << "Fight\n";
      return;
    }
  }
  if(c >= avg) {
    int need = c - avg;
    if(need % k != 0) {
      cout << "Fight\n";
      return;
    }
  }
  else {
    int need = avg - c;
    if(need % k != 0) {
      cout << "Fight\n";
      return;
    }
  }
  cout << "Peaceful\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}