
#include <fstream>
using namespace std;
ifstream fin("graf.in");
ofstream fout("graf.out");

int n,m,A[101][101],X[101];

void afisare(int k)
{
    fout<<"Varfurile subgrafului: ";
    for(int i=1;i<=k;i++)
        fout<<X[i]<<" ";
    fout<<endl;
    fout<<"Matricea de adiacenta:\n";
    int P[101]={0};
    for(int i=1;i<=k;i++)
        P[X[i]]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(P[i] && P[j]) fout<<A[i][j]<<" ";
            else fout<<"0 ";
        fout<<endl;
    }
}

void back(int k)
{
    for(int i=X[k-1]+1;i<=n;i++)
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
    {
        int x,y;
        fin>>x>>y;
        A[x][y]=A[y][x]=1;
    }
    back(1);
    return 0;
}
