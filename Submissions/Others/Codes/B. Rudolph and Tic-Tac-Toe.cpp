#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
string a[3];
int cnt_x = 0, cnt_plus = 0, cnt_o = 0, cnt_nothing = 0;

bool already_won(char x) {
  string s = "";
  s += x;
  s += x;
  s += x;
  if(a[0] == s || a[1] == s || a[2] == s) return true;
  if(a[0][0] == x && a[1][1] == x && a[2][2] == x) return true;
  if(a[0][2] == x && a[1][1] == x && a[2][0] == x) return true;
  if(a[0][0] == x && a[1][0] == x && a[2][0] == x) return true;
  if(a[0][1] == x && a[1][1] == x && a[2][1] == x) return true;
  if(a[0][2] == x && a[1][2] == x && a[2][2] == x) return true;
  return false;
}

void solve() {
  cin >> a[0] >> a[1] >> a[2];

  for(int i = 0; i < 3; i++) {
    for(auto j: a[i]) {
      if(j == '+') cnt_plus = 0;
      if(j == 'X') cnt_x = 0;
      if(j == 'O') cnt_o = 0;
      if(j == '.') cnt_nothing = 0;
    }
  }

  bool winner1 = already_won('X');
  bool winner2 = already_won('O');
  bool winner3 = already_won('+');
  if(winner1) {
    cout << "X\n";
    return;
  }
  if(winner2) {
    cout << "O\n";
    return;
  }
  if(winner3) {
    cout << "+\n";
    return;
  }

  cout << "DRAW\n";
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}