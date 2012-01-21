#include<iostream>
using namespace std;
#include<vector>

int TFLAG=0,FLAG;
vector< vector<bool> > Available(81,vector<bool>(9,1));
vector< vector<int> > Mat(9,vector<int>(9,0));
vector<int> Counter(81,9);
vector<int> Dummy(81,0);
vector<int> Account(81,0);
int ctr=0,d;

//Remove the value from options of other elemnts in Row
void removerow(int i,int val)
{
	int k;
	for (k=0;k<9;k++)
		if (Mat[i][k]==0)
			if (Available[i*9+k][val-1]!=0)
			{
				Available[i*9+k][val-1]=0;
				Counter[i*9+k]-=1;
			}
}

//Remove the value from options of other elemnts in Column
void removecol(int j,int val)
{
	int k;
	for (k=0;k<9;k++)
		if (Mat[k][j]==0)
			if (Available[k*9+j][val-1]!=0)
			{
				Available[k*9+j][val-1]=0;
				Counter[k*9+j]-=1;
			}
}

//Remove the value from options of other elemnts in box
void removebox(int i,int j,int val)
{
	int k,l;
	for (k=0;k<3;k++)
		for (l=0;l<3;l++)
		{
			if (Mat[(i-i%3)+((i+k)%3)][(j-j%3)+((j+l)%3)]==0)
				if (Available[(((i-i%3)+((i+k)%3))*9)+((j-j%3)+((j+l)%3))][val-1]!=0)
				{
					Available[(((i-i%3)+((i+k)%3))*9)+((j-j%3)+((j+l)%3))][val-1]=0;
					Counter[(((i-i%3)+((i+k)%3))*9)+((j-j%3)+((j+l)%3))]-=1;
				}
		}
}

//Preprocessing of given Sudoku
void preprocessing()
{
	int i,j,val;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
		{
			if (Mat[i][j]!=0)
			{
				TFLAG++;
				val=Mat[i][j];
				Counter[i*9+j]=0;
				removerow(i,val);
				removecol(j,val);
				removebox(i,j,val);
			}
		}
}

//Fill places where only one option is left
void fill_one()
{
	int i,j,k;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
		{
			if (Counter[i*9+j]==1)
			{
				TFLAG++;
				Counter[i*9+j]=0;
				k=0;
				while (Available[i*9+j][k]==0)
					k++;
				k++;
				Mat[i][j]=k;
				removerow(i,k);
				removecol(j,k);
				removebox(i,j,k);
			}
		}
}

//Fill places where the given option is the only option to be filled in te box
void fill_box()
{
	int i,j,k,l,m;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Mat[i][j]==0)
			{
				for (m=0;m<9;m++)
					if (Available[i*9+j][m]==1)
					{
						FLAG=1;
						for (k=0;k<3 && FLAG==1;k++)
							for (l=0;l<3 && FLAG==1;l++)
								if (Available[((i-i%3)+((i+k)%3))*9+((j-j%3)+((j+l)%3))][m]==1 \
										&& Mat[((i-i%3)+((i+k)%3))][((j-j%3)+((j+l)%3))]==0 \
										&& (((i-i%3)+((i+k)%3))!=i || ((j-j%3)+((j+l)%3))!=j))
									FLAG=0;
						if (FLAG==1)
						{
							TFLAG++;
							Counter[i*9+j]=0;
							m++;
							Mat[i][j]=m;
							removerow(i,m);
							removecol(j,m);
							m=9;
						}
					}
			}
}

//Fill places where the given option is the only option to be filled in te row
void fill_row()
{
	int i,j,k,l,m;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Mat[i][j]==0)
			{
				for (m=0;m<9;m++)
					if (Available[i*9+j][m]==1)
					{
						FLAG=1;
						for (k=0;k<9 && FLAG==1;k++)
							if (Available[i*9+k][m]==1 && Counter[i*9+k]!=0 && k!=j)
								FLAG=0;
						if (FLAG==1)
						{
							TFLAG++;
							Counter[i*9+j]=0;
							m++;
							Mat[i][j]=m;
							removecol(j,m);
							removebox(i,j,m);
							m=9;
						}
					}
			}
}

//Fill places where the given option is the only option to be filled in te Col
void fill_col()
{
	int i,j,k,l,m;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Mat[i][j]==0)
			{
				for (m=0;m<9;m++)
					if (Available[i*9+j][m]==1)
					{
						FLAG=1;
						for (k=0;k<9 && FLAG==1;k++)
							if (Available[k*9+j][m]==1 && Counter[k*9+j]!=0 && k!=i)
								FLAG=0;
						if (FLAG==1)
						{
							TFLAG++;
							Counter[i*9+j]=0;
							m++;
							Mat[i][j]=m;
							removerow(i,m);
							removebox(i,j,m);
							m=9;
						}
					}
			}
}

//Resetting all variables
void reset()
{
	int i,j;
	//Reseting Available Matrix
	for (i=0;i<81;i++)
		for (j=0;j<9;j++)
			Available[i][j]=1;
	//Reseting Counter Matrix
	for (i=0;i<81;i++)
		Counter[i]=9;
	//Reseting Total Flag Counter
	TFLAG=0;
}

//Printing the solution
void print()
{
	if (TFLAG==81)
		printf("SOLVED\n");
	else
		printf("UNSOLVED\n");
	int i,j;
	for (i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
			printf("%d ",Mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

//Checking if the Guess is Correct
int check()
{
	int i,j,k,l,m;
	vector<bool> C(9,0);
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Counter[i*9+j]==0 && Mat[i][j]==0)
				return 1;
	//Checking boxes
	for (i=0;i<9;i+=3)
		for (j=0;j<9;j+=3)
			for (k=0;k<3;k++)
				for (l=0;l<3;l++)
				{
					if (Mat[((i-i%3)+((i+k)%3))][((j-i%3)+((j+l)%3))]!=0)
						C[Mat[((i-i%3)+((i+k)%3))][((j-i%3)+((j+l)%3))]-1]=1;
					else
					{
						for (m=0;m<9;m++)
							if (Available[((i-i%3)+((i+k)%3))*9+((j-i%3)+((j+l)%3))][m]==1)
								C[m]=1;
					}
				}
	for (m=0;m<9;m++)
		if (C[m]==0)
			return 1;
	//Checking Rows
	for (i=0;i<9;i++)
	{
		for (m=0;m<9;m++)
			C[m]=0;
		for (j=0;j<9;j++)
		{
			if (Mat[i][j]!=0)
				C[Mat[i][j]-1]=1;
			else
			{
				for (m=0;m<9;m++)
					if (Available[i*9+j][m]==1)
						C[m]=1;
			}
		}
		for (m=0;m<9;m++)
			if (C[m]==0)
				return 1;
	}
	//Checking Cols
	for (i=0;i<9;i++)
	{
		for (m=0;m<9;m++)
			C[m]=0;
		for (j=0;j<9;j++)
		{
			if (Mat[j][j]!=0)
				C[Mat[j][i]-1]=1;
			else
			{
				for (m=0;m<9;m++)
					if (Available[j*9+i][m]==1)
						C[m]=1;
			}
		}
		for (m=0;m<9;m++)
			if (C[m]==0)
				return 1;
	}
	return 0;
}

//Keep Account of Guessing
void fillaccount()
{
	int i,j;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Mat[i][j]!=0 && Account[i*9+j]==0)
				Account[i*9+j]=ctr;
}
//Clear wrong data filled in case of Guess
void clearoldsolution()
{
	int i,j;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
		{
			if (Account[i*9+j]>=ctr || Account[i*9+j]==0)
				Mat[i][j]=0;
		}
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Account[i*9+j]>=ctr)
				Account[i*9+j]=0;
	reset();
	preprocessing();
}

//Fill Logically
void fill()
{
	while (!equal(Counter.begin(),Counter.end(),Dummy.begin()))
	{
		copy(Counter.begin(),Counter.end(),Dummy.begin());
		fill_one();
		fill_box();
		fill_row();
		fill_col();
	}
}

//Fill in case Guess work is needed
void recursivefill()
{
	int CTFLAG,UFLAG=0,i,j,k;
	ctr++;
	d++;
	//If there are no more options return
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Counter[i*9+j]==2)
				UFLAG=1;
	if (UFLAG==0)
	{
		return;
	}
	//Checking for first option
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			if (Counter[i*9+j]==2)
			{
				k=0;
				while (Available[i*9+j][k]==0)
					k++;
				k++;
				Mat[i][j]=k;
				Counter[i*9+j]=0;
				TFLAG++;
				removerow(i,k);
				removecol(j,k);
				removebox(i,j,k);
				j=10;i=10;
			}
	fill();
	fillaccount();
	//Checking if putting the first option was the right choice
	UFLAG=check();
	if (UFLAG==0)
	{
		recursivefill();
	}
	//Checking the second option
	if (TFLAG!=81)
	{
		clearoldsolution();
		for (i=0;i<9;i++)
			for (j=0;j<9;j++)
				if (Counter[i*9+j]==2)
				{
					k=0;
					while (Available[i*9+j][k]==0)
						k++;
					k++;
					while (Available[i*9+j][k]==0)
						k++;
					k++;
					Mat[i][j]=k;
					Counter[i*9+j]=0;
					TFLAG++;
					removerow(i,k);
					removecol(j,k);
					removebox(i,j,k);
					j=10;i=10;
				}
		fill();
		fillaccount();
		UFLAG=check();
		//Checking if second option gave the right answer
		if (UFLAG==1)
		{
			ctr--;
			clearoldsolution();
			return;
		}
		else if (TFLAG!=81)
		{
			recursivefill();
file:///C|/Users/gaurav/Desktop/Sudoku.txt (10 of 12) [2/9/2009 10:31:11 PM]
file:///C|/Users/gaurav/Desktop/Sudoku.txt
			return;
		}
	}
}

int main()
{
	freopen("inputsudoku.txt","r",stdin);
	freopen("outputsudoku.txt","w",stdout);
	int i,j,k,CSOLVED=0,CUNSOLVED=0,UFLAG,NTFLAG;
	//Input (Put 0 for empty spaces)
	while (scanf("%d",&Mat[0][0])!=EOF)
	{
		reset();
		ctr=1;
		for (i=0;i<9;i++)
			for (j=0;j<9;j++)
				Account[i*9+j]=0;
		for (j=1;j<9;j++)
			scanf ("%d",&Mat[0][j]);
		for (i=1;i<9;i++)
			for (j=0;j<9;j++)
				scanf ("%d",&Mat[i][j]);
		//Preprocessing of Given Sudoku
		preprocessing();
		//Solving of Sudoku logicallly
		fill();
		//If still not Solved Guess Work On
		if (TFLAG!=81)
		{
			fillaccount();
			recursivefill();
		}
		if (TFLAG==81)
			CSOLVED++;
		else
			CUNSOLVED++;
		print();
	}
	printf ("Total Su Doku : %d\n",CSOLVED+CUNSOLVED);
	printf ("Total Solved : %d\n",CSOLVED);
	printf ("Total Unsolved : %d\n",CUNSOLVED);
}
