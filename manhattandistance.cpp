#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
#define sz(x) ((int)x.size())
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    
    auto Dsum = [&](vector <ll> arr) -> ll{
        sort(all(arr));
        ll res = 0, sum = 0;
        for(int i = 0;i < sz(arr);i++){
            res += (arr[i] * i - sum);
            sum += arr[i];
        }
        return res;
    };

    return 0;
}