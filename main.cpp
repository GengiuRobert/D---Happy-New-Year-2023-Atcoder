#include <bits/stdc++.h>
using namespace std;

//int n = 1e8;
int main()
{
    unsigned long long n=1e7;
    double rootn = sqrt(n);
    vector<bool> sieve(n+1, 1);
    vector<unsigned long long> pp;
    for(unsigned long long i=2; i<=n; i++)
    {
        if (sieve[i])
        {
            pp.push_back(i);
            if (i<=rootn)
                for(unsigned long long j=i*i; j<=n; j+=i)//i*i eficient
                    sieve[j] = 0;
        }
    }

    int i=0,t;
    long long x;
    cin>>t;
    for(i=0; i<t; ++i)
    {
        cin>>x;
        int j=0;
        unsigned long long p,q;

        while(x%pp[j]!=0)
            ++j;
        x=x/pp[j];
        if(x%pp[j]==0)
        {
            p=pp[j];
            x=x/pp[j];
            q=x;
        }
        else
        {
            q=pp[j];
            p=sqrt((long double)x);
        }
        cout<<p<<" "<<q<<'\n';
    }


    return 0;
}
