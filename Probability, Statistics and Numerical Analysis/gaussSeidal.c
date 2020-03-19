float m[100][100];
float ans[3]={0,0,0};
int main()
{
	int n,i,j,k,temp;
	int large=0;
	printf("enter no of variables: \n");
	scanf("%d",&i);
	for(k=0;k<i;k++)
	for(j=0;j<=i;j++)
	scanf("%f",&m[k][j]);

for(n=0;n<5;n++)
{
    for(j=0;j<i;j++)
    {
        ans[j]=m[j][i];
        for(k=0;k<i;k++)
        {
            if(j==k)
                continue;
            else
            {
                ans[j]-=(ans[k]*m[j][k]);

            }
        }
        ans[j]/=m[j][j];
        printf(" %d --> %f \n",j,ans[j]);
    }
}
	for(k=0;k<i;k++)
    printf(" %.4f ",ans[k]);

}
