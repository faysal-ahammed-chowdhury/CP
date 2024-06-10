#include <bits/stdc++.h>
using namespace std;

map<char, char> mp;
bool is_palindrome(string s) {
    string ans = s;
    reverse(ans.begin(), ans.end());
    return ans == s;
}

bool is_mirror_string(string s) {
    int n = (int)s.size();
    for(int i = 0, j = n - 1; i <= j; i++, j--) {
        if(s[i] == mp[s[j]]) continue;
        if(s[j] == mp[s[i]]) continue;
        return false;
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mp['A'] = 'A';
    mp['E'] = '3';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['J'] = 'L';
    mp['L'] = 'J';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['0'] = 'O';
    mp['S'] = '2';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['W'] = 'W';
    mp['X'] = 'X';
    mp['Y'] = 'Y';
    mp['Z'] = '5';
    mp['1'] = '1';
    mp['2'] = 'S';
    mp['3'] = 'E';
    mp['5'] = 'Z';
    mp['8'] = '8';

    string s;
    while(cin >> s) {
        bool mirror = is_mirror_string(s); 
        bool ans = is_palindrome(s);
        if(ans == false && mirror == false) {
            cout << s << " -- is not a palindrome.\n";
        }
        else if(ans == true && mirror == false) {
            cout << s << " -- is a regular palindrome.\n";
        }
        else if(ans == false && mirror == true) {
            cout << s << " -- is a mirrored string.\n";
        }
        else if(ans == true && mirror == true) {
            cout << s << " -- is a mirrored palindrome.\n";
        }
        cout << '\n';
    } 
        
    return 0;
}