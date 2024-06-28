#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006 
using namespace std;

ll n;
ll ans(1e9);

bool dk(ll a, ll b){
    if(abs(a) < abs(b)) return true;
    else if(abs(a) == abs(b)){
         if(a < b) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(auto & x : a) cin >> x;
    for(auto & x : b) cin >> x;

    sort(a.begin(), a.end(), dk);
    sort(b.begin(), b.end(), dk);
   
    ll i(0), j(0);
    while(i < n && j < n){
        ans = min (ans, abs(a[i] + b[j]));
        if(ans == 0) break;
        if(abs(a[i]) < abs(b[j])) i++;
        else if(abs(a[i]) > abs(b[j])) j++;
        else{
            if(abs(a[i + 1]) == abs(a[i])) i++;
            else if(abs(b[j + 1]) == abs(b[j])) j++;
            else{
                i++;
                j++;
            }
        }
    }
    cout << ans;
    return 0;
}
