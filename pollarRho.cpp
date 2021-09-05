#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
int main(){
    // ios_base::sync_with_stdio(false),cin.tie(0);
    auto pow = [&](ll a,ll b,ll p)-> ll{
        ll res = 1;
        a %= p;
        while(b){
            if(b & 1)
                res = ((__uint128_t)res * a) % p;
            b >>= 1;
            a = (__uint128_t)a * a % p;
        }
        return res;
    };
    auto solve = [&](ll b,ll n)-> bool{
        ll a = 2 + rand() % (n - 4), r = pow(a,b,n);
        if(r == 1 || r == n - 1)
            return true;
        while(b != n - 1){
            r = (__uint128_t)r * r % n;
            b <<= 1;
            if(r == 1) return false;
            if(r == n - 1) return true;
        }
        return false;
    };
    auto miller = [&](ll n)-> bool{
        if(n <= 4){
            if(n == 1 || n == 4) return false;
            return true;
        }
        ll p = n - 1;
        while(!(p % 2)) p /= 2;
        int times= 10;
        bool isprime = true;
        while(times--){
            if(!solve(p, n))
                isprime= false;
        }
        return isprime ? true : false;
    };
    srand(time(NULL));
    auto pollar = [&](ll n)-> ll{
        if(n == 1) return n;
        if(!(n & 1)) return 2;
        ll x = (rand()% (n - 2)) + 2,y = x,c = (rand() % (n - 1))+ 2,d = 1;
        while(d == 1){
            x = (pow(x,2,n) + c + n) % n;
            y = (pow(y,2,n) + c + n) % n;
            y = (pow(y,2,n) + c + n) % n;
            d = __gcd(abs(x - y), n);
        }
        return d;
    };
    map<ll,int> mp;
    auto fct = [&](auto &&f,ll n)-> void{
        if(n == 1) return;
        if(miller(n)){
            mp[n]++;
            return;
        }
        ll d = pollar(n);
        f(f,d);
        f(f,n / d);
    };
    ll n;
    while(cin>> n){
        mp.clear();
        fct(fct,n);
        for(auto [a,b]: mp)
            cout<< a<<" "<< b<<" ";
    }


    return 0;
}