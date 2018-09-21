#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int check(int n)
{
    int i, s2;
    float s;
    for(i=1; i<=n; ++i)
        s=s+(i*i);
    s2=sqrt(s);
    if(s2==s)
        return 1;
    else
        return 0;
}

int main() 
{
    int n, k[100], i, j, q, m;
    long int a[100], s[100];
    cin>>q;
    for(i=1; i<=q; ++i) 
    {
        cin>>a[i]; cin>>k[i];
    }
    for(i=1; i<=q; ++i) 
    {
        s[i]=0;
        for(j=1; j<=a[i]; ++j)
        {
            for(m=0; m<=k[i]; ++m)
            {
                if(check(j+m))
                    s[i]=s[i]+(j+m);
                if(check(j-m))
                    s[i]=s[i]+(j-m);
            }
        }
        cout<<s[i]<<endl;
    }
    return 0;
}
