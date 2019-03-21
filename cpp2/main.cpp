#include <iostream>
#include<cstdio>

using namespace std;

const int maxn=10000;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        int prime[maxn]={-1};
        int p[maxn]={0};
        int count1=0;
        for(int i=2, j=1;i<n;i++){
            if(p[i]==0){
                prime[j]=i;
                cout<<prime[j]<<endl;
                j++;
                count1++;
                for(int k=2;(k*i)<n;k++){
                    p[k*i]=1;
                }
            }
        }
        cout<<count1<<endl;
    }
    return 0;
}
