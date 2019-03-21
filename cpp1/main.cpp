#include <iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int maxn=1000;

int main()
{
    int n;
    while ((scanf("%d",&n)!=EOF)&&n!=0){
        int M,N;
        cin>>M>>N;
        int match[maxn][maxn]={0};
        int a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            match[a][b]=1;
        }
    }
    return 0;
}
