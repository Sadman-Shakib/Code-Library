#include <bits/stdc++.h>
using namespace std;

#define ff               first
#define sc               scanf
#define endl             '\n'
#define pf               printf
#define ss               second
#define in               insert
#define clr(arr, x)      memset(arr, x, sizeof arr);
#define not_psble        {cout <<   -1  << endl; return; }
#define YES              {cout << "YES" << endl; return; }
#define NOO              {cout << "NO"  << endl; return; }
#define pp               pop_back
#define pb               push_back
#define mp               make_pair
#define rep(i, l, r)     for(int i = l; i < r; ++i)
#define printarr(arr)    for(int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
#define all(x)           x.begin(), x.end()
#define rall(x)          x.rbegin(), x.rend()
#define printans         cout << ans << endl;
#define int              long long
#define arrin(v, n)      {for(int i = 0; i < n; ++i) cin >> v[i];}


vector <int> build_lps(string s) {
        vector <int> lps(s.size());
        int i = 1, j = 0;
        while(i < s.size()) {
                while(j > 0 and s[j] != s[i]) j = lps[j-1];
                if(s[i] == s[j]) {
                        j++;
                }
                lps[i] = j;
                i++;
        }
        return lps;
}
 
int res = 0;
 
void kmp(string s, string t) {
        vector <int> lps = build_lps(t);
        for(int i = 0, j = 0; i < s.size(); ) {
                if(s[i] == t[j]) {
                        j++; i++;
                } else {
                        if(j != 0) {
                                j = lps[j-1];
                        } else i++;
                }
 
                if(j == t.size()) ++res, j = lps[j-1];
        }
}
 
void solve() {
  
        string s, t; cin >> s >> t;
        kmp(s, t);
        cout << res << endl;
}
 
int32_t main() {
 
        // S4DM4N S4K1B 
        ios_base::sync_with_stdio(false); 
        cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif 
        int clock_start = clock(); // clock start
 
        //cin >> t; 
    
        for(int i = 1; i <= t; ++i){
                //cout << "Case " << i << ": ";
                solve();
        }
 
#ifndef ONLINE_JUDGE
        cerr << (double) (clock() - clock_start) / CLOCKS_PER_SEC << endl; // CLOCKS_PER_SEC = 1000
#endif
        return 0;
}

// Problem : https://cses.fi/problemset/task/1753
// Title   : String matching 
// OJ      : CSES
