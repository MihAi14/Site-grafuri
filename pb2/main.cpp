
#include <fstream>
using namespace std;
ifstream fin1("graf1.in");
ifstream fin2("graf2.in");
ofstream fout("graf.out");

int n,m1,m2,A[101][101],B[101][101],x,y;

int graf_partial(int n, int A[][101], int B[][101])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(B[i][j]==1 && A[i][j]==0) return 0;
    return 1;
}

int main()
{
    fin1>>n>>m1;
    for(int i=1;i<=m1;i++)
    {
        fin1>>x>>y;
        A[x][y]=A[y][x]=1;
    }
    fin2>>n>>m2;
    for(int i=1;i<=m2;i++)
    {
        fin2>>x>>y;
        B[x][y]=B[y][x]=1;
    }
    if(m1>m2)
        if(graf_partial(n,A,B)) fout<<"G2 este graf partial al lui G1";
        else fout<<"NU";
    else
        if(graf_partial(n,B,A)) fout<<"G1 este graf partial al lui G2";
        else fout<<"NU";
    return 0;
}
