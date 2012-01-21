#define SIZE 31
#define INF 1e8
double dis[SIZE][SIZE];
void init(int N)
{
	for (k=0;k<N;k++)
		for (i=0;i<N;i++)
			dis[i][j]=INF;
}
void floyd_warshall(int N)
{
        int i,j,k;
        for (k=0;k<N;k++)
                for (i=0;i<N;i++)
                        for (j=0;j<N;j++)
                                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main()
{
	//input size N
	init(N);
	//set values for dis[i][j]
	floyd_warshall(N);
}
