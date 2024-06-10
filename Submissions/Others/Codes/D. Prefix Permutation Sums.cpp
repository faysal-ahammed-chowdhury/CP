#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    long long n; cin >> n;
    long long len = n - 1;
    vector<long long> prefix(len + 1, 0), arr(n + 1, 0);
    for(int i = 1; i <= len; i++) {
      cin >> prefix[i];
    }

    // case (if last element is missing)
    if(prefix[len] < (n * (n + 1) / 2)) {
      prefix.push_back((n * (n + 1) / 2));
      for(int i = 1; i <= n; i++) {
        long long val = prefix[i] - prefix[i  - 1];
        if(val >= 1 && val <= n) {
          arr[val]++;
        }
      }
      bool possible = true;
      for(int i = 1; i <= n; i++) {
        if(arr[i] == 0) {
          possible = false;
        }
      }
      cout << (possible ? "YES\n" : "NO\n");
      continue;
    }

    for(int i = 1; i <= len; i++) {
      long long val = prefix[i] - prefix[i  - 1];
      if(val >= 1 && val <= n) {
        arr[val]++;
      }
    }

    pair<long long, long long> need = {-1, -1};
    long long sum = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
      if(arr[i] == 0) {
        cnt++;
        sum += i;
        if(need.first == -1) {
          need.first = i;
        }
        else {
          need.second = i;
        }
      }
    }

    for(int i = 0; i <= n; i++) {
      arr[i] = 0;
    }

    bool first = true;
    for(int i = 1; i <= len; i++) {
      long long val = prefix[i] - prefix[i  - 1];
      if(sum == val && first) {
        arr[need.first]++;
        arr[need.second]++;
        first = false;
      }
      else if(val >= 1 && val <= n) {
        arr[val]++;
      }
    }

    bool possible = true;
    for(int i = 1; i <= n; i++) {
      if(arr[i] == 0) {
        possible = false;
      }
    }
    cout << (possible ? "YES\n" : "NO\n");
  }

  return 0;
}