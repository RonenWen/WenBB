#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
ull f[50][50];
int a[12]={0,-1,-2,-2,-1,1,2,2,1,0};
int b[12]={0,2,1,-1,-2,-2,-1,1,2,0};
int tx,ty;
int hx,hy;
bool d[50][50];
int main()
{
    memset(d,false,sizeof d);
    scanf("%d%d%d%d",&tx,&ty,&hx,&hy);
    tx++,ty++,hx++,hy++;
    for(int i=1;i<=9;i++){
        if(hx+a[i]>=0 && hy+b[i]>=0)
        d[hx+a[i]][hy+b[i]]=true;
    }
    f[1][1]=1;
    for(int i=1;i<=tx;i++)
    {
        for(int j=1;j<=ty;j++)
        {
            if(i==1 && j==1)
                continue;
            if(d[i][j])
                continue;
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    printf("%lld",f[tx][ty]);
    
return 0;
}
