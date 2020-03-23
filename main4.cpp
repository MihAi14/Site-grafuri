#include <fstream>
using namespace std;
ifstream fin("graf.in");
ofstream fout("graf.out");

int n,X[21],P[21],l;

void afisare()
{
    for(int i=1;i<=l;i++)
        fout<<X[i]<<" ";
    fout<<X[1]<<endl;
}

void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(k==l) afisare();
            else back(k+1);
            P[i]=0;
        }
}

int main()
{
    fin>>n>>l;
    back(1);
    return 0;
}
