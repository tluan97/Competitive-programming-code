/*
	KNAPSACK
	Cho n vat co khoi luong a[i]
	va gia tri c[i]
	tim cach lay cac mon sao cho
	co tong gia tri la lon nhat
	va tong khoi luong khong vuot qua w
*/
#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 101;
const int maxw = 10001;

int n,w,a[maxn],c[maxn];
int f[maxn][maxw];

int knapsack()
{
	for (int i=0;i<maxn;i++)
	for (int j=0;j<maxw;j++)
		f[i][j]=0;	
	for (int i=1;i<=n;i++)
	for (int j=1;j<=w;j++)
		if (a[i]>j) f[i][j]=f[i-1][j];
		else f[i][j]= (f[i-1][j] > c[i]+f[i-1][j-a[i]]) ? 
                       f[i-1][j] : c[i]+f[i-1][j-a[i]];
    return f[n][w];
}
int main()
{
	FILE *fi,*fo;
    char sti[12],sto[12];
    for (int i=1;i<=10;i++)
    {
        strcpy(sti,"Bai1_xx.inp");
        sti[strlen(sti)-6]=i/10+'0';
        sti[strlen(sti)-5]=i%10+'0';
        strcpy(sto,"Bai1_xx.out");
        sto[strlen(sto)-6]=i/10+'0';
        sto[strlen(sto)-5]=i%10+'0';
        fi=fopen(sti,"r");
        fo=fopen(sto,"w");
        fscanf(fi,"%d %d",&n,&w);
        for (int i=1;i<=n;i++)
            fscanf(fi,"%d %d",&a[i],&c[i]);
        int re=knapsack();
        cout<<re<<endl;
        fprintf(fo,"%d\n",re);
        fclose(fi);fclose(fo);
    }
}
