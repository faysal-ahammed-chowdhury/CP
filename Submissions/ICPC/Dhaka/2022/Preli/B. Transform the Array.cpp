#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 5e5 + 9, MAX_VAL = 1e7 + 9;
int spf[MAX_VAL];

void spf_sieve() {
  for(int i = 2; i < MAX_VAL; i++) {
    spf[i] = i;
  }
  for(int i = 2; i < MAX_VAL; i++) {
    if(spf[i] == i) {
      for(int j = i; j < MAX_VAL; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

int cs = 0;
void solve() {
  cout << "Case " << ++cs << ": ";
  int n; cin >> n;
  int a[n], b[n];
  set<int> se;
  int g = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    g = __gcd(g, a[i]);
    int x = a[i];
    while(x > 1) {
      int p = spf[x];
      se.insert(p);
      while(x % p == 0) {
        x /= p;
      }
    }
  }
  bool ok1 = true, all_same = true;
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    if(b[i] != a[i]) all_same = false;
    int x = b[i];
    while(x > 1) {
      int p = spf[x];
      if(se.find(p) == se.end()) {
        ok1 = false;
      }
      while(x % p == 0) {
        x /= p;
      }
    }
  }

  if(ok1) cout << "Yes ";
  else cout << "No ";

  if(all_same) {
    cout << "Yes\n";
    return;
  }

  set<int> gcd_pf;
  int x = g;
  while(x > 1) {
    int p = spf[x];
    gcd_pf.insert(p);
    while(x % p == 0) {
      x /= p;
    }
  }

  set<pair<int, int>> se1, se2;

  x = a[0];
  while(x > 1) {
    int p = spf[x], pw = 0;
    while(x % p == 0) {
      pw++;
      x /= p;
    }
    se1.insert({p, pw});
  }

  x = b[0];
  while(x > 1) {
    int p = spf[x], pw = 0;
    while(x % p == 0) {
      pw++;
      x /= p;
    }
    se2.insert({p, pw});
  }

  set<int> common;

  for(auto i: se1) {
    if(se2.find(i) == se2.end()) {
      if(gcd_pf.find(i.first) == gcd_pf.end()) {
        cout << "No\n";
        return;
      }
      else {
        common.insert(i.first);
      }
    }
  }
  for(auto i: se2) {
    if(se1.find(i) == se1.end()) {
      if(gcd_pf.find(i.first) == gcd_pf.end()) {
        cout << "No\n";
        return;
      }
      else {
        common.insert(i.first);
      }
    }
  }

  for(int i = 1; i < n; i++) {
    set<pair<int, int>> se1, se2;

    x = a[i];
    while(x > 1) {
      int p = spf[x], pw = 0;
      while(x % p == 0) {
        pw++;
        x /= p;
      }
      se1.insert({p, pw});
    }

    x = b[i];
    while(x > 1) {
      int p = spf[x], pw = 0;
      while(x % p == 0) {
        pw++;
        x /= p;
      }
      se2.insert({p, pw});
    }

    set<int> my_set;

    for(auto i: se1) {
      if(se2.find(i) == se2.end()) {
        if(gcd_pf.find(i.first) == gcd_pf.end()) {
          cout << "No\n";
          return;
        }
        else {
          my_set.insert(i.first);
        }
      }
    }
    for(auto i: se2) {
      if(se1.find(i) == se1.end()) {
        if(gcd_pf.find(i.first) == gcd_pf.end()) {
          cout << "No\n";
          return;
        }
        else {
          my_set.insert(i.first);
        }
      }
    }

    if(common != my_set) {
      cout << "No\n";
      return;
    }

  }

  cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  spf_sieve();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}