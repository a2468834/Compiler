/*
input file name at parameters
add "-sort" after file name to enable sorting before computing
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//#define TEST

typedef struct{
	int left,right;
}Line;



int line_comp(Line former,Line later)
{
	int comp;
	if(former.left>=later.right || later.left>=former.right)		//if 2 data are not overlapping
		comp=0;
	else if(former.left<=later.left && former.right>later.left)	//if the later's left is in the former's range
	{
		if(former.right>=later.right)		//if the later is all in the former's range
			comp=later.right-later.left;
		else if(former.right<later.right)	//if the 2 data are not all included in each
			comp=former.right-later.left;
	}
	else if(later.left<=former.left && later.right>former.left)	//if the former's left is in the later's range
	{
		if(later.right>=former.right)		//if the former is all in the later's range
			comp=former.right-former.left;
		else if(later.right<former.right)	//if the 2 data are not all included in each
			comp=later.right-former.left;
	}
//printf("%d\n",comp);
	
	return comp;
}	//end of line_comp()



int main(int argc,char *argv[])
{
	unsigned long long length=0;
	
	if(argc>3)
	{
		printf("Invalid parameter input!\n");
		return 2;
	}
	
	int SORT=0;
	if(argc==3 && strcmp(argv[2],"-sort")==0)
		SORT=1;
	
	FILE *input=fopen(argv[1],"r");
	
	if(!input)
	{
		printf("Can't find the file!\n");
		return 1;
	}
	
	
	int i=0;
	char c;
	while((c=fgetc(input))!=EOF)	//count the number of the data
	{
		if(c=='\n')
			i++;
	}
	
	rewind(input);
	
	
	int max=i;
	
	Line *data=(Line *)malloc(sizeof(Line)*max);
	
	
	double sort_time_use;
	if(SORT==1)
	{
		printf("Start sorting...\n");
		clock_t sort_start=clock();
		
		for(i=0;i<max;i++)
		{
			if(i==0)
				fscanf(input,"%d %d",&data[i].left,&data[i].right);
			else
			{
				int left_temp;
				fscanf(input,"%d",&left_temp);
				int j,temp_p;
				for(j=0;j<i;j++)
				{
					if(data[j].left>left_temp)
					{
						temp_p=j;
						break;
					}
				}
				for(j=i;j>temp_p;j--)
					data[j]=data[j-1];
				
				data[temp_p].left=left_temp;
				fscanf(input,"%d",&data[temp_p].right);
			}
		}
		
		clock_t sort_end=clock();
		sort_time_use=(double)(sort_end-sort_start)/CLOCKS_PER_SEC;
		printf("sorting time use: %.3f sec\n",sort_time_use);
	}
	else
		for(i=0;i<max;i++)
			fscanf(input,"%d %d",&data[i].left,&data[i].right);
	
	fclose(input);
	
	
	clock_t com_start=clock();
	
//printf("%d\n",max);
	
	printf("Start computing...\n");
	
	for(i=0;i<max;i++)
	{
		int j;
		for(j=i+1;j<max;j++)
		{
			length+=line_comp(data[i],data[j]);
#ifdef TEST
printf("%d %d\n",i,j);
#endif
		}	
	}
	
	clock_t com_end=clock();
	
	double com_time_use=(double)(com_end-com_start)/CLOCKS_PER_SEC;
	
	printf("total overlapping length: %llu\n",length);
	printf("computing time use: %.3f sec\n",com_time_use);
	if(SORT==1)
		printf("total time use: %.3f sec\n",com_time_use+sort_time_use);
	
	
	
	
	
	return 0;
}
