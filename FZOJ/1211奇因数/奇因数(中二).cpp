#include <cstdio>
using namespace std;
long long n,ans(0);
int main()
{
    scanf("%lld",&n);
    while(n)
    {
        if(n&1) ans+=n,n--;
        else
        {
            ans+=((n)*(n/2))/2;
            n>>=1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
