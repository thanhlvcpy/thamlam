#include <bits/stdc++.h>

using namespace std;
int n,a[100000],t[100000],id[100000];
void quicksort(int l,int r){
    int i=l,j=r;
    int s=id[(l+r)/2];
    while(i<=j){
        while(a[id[i]]<a[s])
            i++;
        while(a[id[j]]>a[s])
            j--;
        if(i<=j){
            swap(id[i],id[j]);
            i++;
            j--;
        }
    }
    if(j>l)
        quicksort(l,j);
    if(i<r)
        quicksort(i,r);
}
int main()
{
    freopen("baihat.inp","r",stdin);
    freopen("baihat.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        id[i]=i;
    quicksort(1,n);
    int t[100000];
    t[1]=a[id[1]];
    for(int i=2;i<=n;i++)
        t[i]=t[i-1]+a[id[i]];
    int T=0;
    for(int i=1;i<=n;i++)
        T=T+t[i];
    cout<<T<<endl;
    for(int i=1;i<=n;i++)
        cout<<id[i]<<" ";
    return 0;
}
