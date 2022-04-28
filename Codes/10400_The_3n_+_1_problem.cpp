#include<iostream>
using namespace std;
int i;
int f(int j)
{
    i=0;
    while(j!=1)
    {
        if(j%2==1)
        {
            j=3*j+1;
            i++;
        }
        else if(j%2==0)
        {
            j=j/2;
            i++;
        }
    }
    i++;
    return i;
}
int main()
{
    int a,b,k,l;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        cout<<a<<" "<<b<<" ";
        if(a>b)swap(a,b);
        k=f(a);
        for(l=a+1;l<=b;l++)
        {
            if(f(l)>k)k=f(l);
        }
        cout<<k<<"\n";
    }
}