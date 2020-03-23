
#include <fstream>
using namespace std;
ifstream fin("graf.in");
ofstream fout("graf.out");

struct muchie { int i,j; };
int n,m,X[5001],nrsol;
muchie M[5001];

void afisare(int k)
{
    nrsol++;
    fout<<"Graful partial numarul "<<nrsol<<":\n";
    for(int i=1;i<=k;i++)
        fout<<M[X[i]].i<<" "<<M[X[i]].j<<"\n";
    int A[101][101]={0};
    for(int i=1;i<=k;i++)
        A[M[X[i]].i][M[X[i]].j]=A[M[X[i]].j][M[X[i]].i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            fout<<A[i][j]<<" ";
        fout<<"\n";
    }
}

void back(int k)
{
    for(int i=X[k-1]+1;i<=m;i++)
    {
        X[k]=i;
        afisare(k);
        back(k+1);
    }
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
        fin>>M[i].i>>M[i].j;
    afisare(0);
    back(1);
    return 0;
}
