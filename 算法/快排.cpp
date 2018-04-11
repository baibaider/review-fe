// 23//��׼д��
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void print(int a[],int length){
	int i;
	for(i=0;i<length;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void quickSort(int a[],int low,int high){
	int i,j,key;
	if(low+1<high){
		i=low;
		j=high-1;
		key=a[low];
		while(i<j){
			while(i<j&&a[j]>=key) j--;
			a[i]=a[j];
			while(i<j&&a[i]<key) i++;
			a[j]=a[i];
		}
		a[i]=key;
		quickSort(a,low,i);
		quickSort(a,i+1,high);
	}
}

int main(int argc, char *argv[]) {
	int a[]={2,1,4,7,4,8,6,3,4,7};
	print(a,sizeof(a)/sizeof(int));
	quickSort(a,0,sizeof(a)/sizeof(int));
	print(a,sizeof(a)/sizeof(int));
	return 0;
}



/*void sort(int a[],int low,int high){
    if(low < high-1){
        int lt = low,i=low+1,gt = high-1;
        int temp = a[low];
        while(i <= gt){
            if(a[i] < temp){
                sawp(a,lt++,i++);//���н���
            }else if(a[i] > temp){
                sawp(a,i,gt--);
            }else{
                i++;
            }
        }
        sort(a,low,lt);
        sort(a,gt+1,high);
    }
} */

#include<stdio.h>


int left[15]={0};
int right[15]={0};
int cal[8]={0};
int Q[8];
int top=-1;
int sum=0;

void Queen(void)
{
	int i,j;
	for(i=j=0;i<8;)
	{
		if(i==0&&j==8) break;
		for(;j<8;j++)
		{
			if(left[i+j]==0&&right[i+7-j]==0&&cal[j]==0) break;
		}
		if(j<8)
		{
			Q[++top]=j;
			left[i+j]=1;
			right[i+7-j]=1;
			cal[j]=1;
			if(i<7)
			{
				i++;
				j=0;
			}
			else
			{
				sum++;
				PrintQueen();
				printf("%d",sum);
				printf("\n");
				left[i+j]=right[i+7-j]=cal[j]=0;
				top--;
				j++;
			}
		}
		else
		{
			left[Q[top]+top]=0;
			right[top+7-Q[top]]=0;
			cal[Q[top]]=0;
			j=Q[top]+1;
			i=top;
			top--;
		}
	}
}
