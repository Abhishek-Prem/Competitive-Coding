#include <stdio.h>
#include <string.h>

int main()
{
	int t, i, j, k, f, n;
	char st[10][20];
	int s[10], sum;
	scanf("%d", &t);
	while(t--)
	{
		sum=0;
		scanf("%d", &n);
		for(i=0; i<n ; ++i)
		{
			s[i]=0; f=0;
			scanf("%s", st[i]);

			for(k=0; k<i; ++k)
				if( strcmp(st[i], st[k]) == 0)
					{ s[i]=s[k]/2; f=1; }

			if(f!=1)
			{
				for(j=0; st[i][j]!='\0'; ++j)
				{
					if(j==0) s[i]=s[i]+2;
					else
					{
						if( ( (st[i][j]=='d'||st[i][j]=='f') && (st[i][j-1]=='d'||st[i][j-1]=='f') ) ||
						    ( (st[i][j]=='j'||st[i][j]=='k') && (st[i][j-1]=='j'||st[i][j-1]=='k') ) )  s[i]=s[i]+4;
						else s[i]=s[i]+2;
					}
				}
			}
//			printf("%d\n", s[i]);
			sum=sum+s[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
