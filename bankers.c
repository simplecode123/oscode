#include<stdio.h>
#include<stdlib.h>
main(){
	int i,j,p,r,res[10],avail[10][10],need[10][10],max[10][10],alloc[10][10],sum,finish[10],seq[10],check,no_res,count=0,completed;
	printf("Enter number of processes and resources :  ");
	scanf("%d%d",&p,&r);
	printf("Enter resources values  :   ");
	for(i=0;i<r;i++){
		scanf("%d",&res[i]);
	}
	printf("Enter the allocated values  :   \n");
	for(i=0;i<p;i++){
		printf("For Process : %d\n",i+1);
		for(j=0;j<r;j++){
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter the max values  :   \n");
	for(i=0;i<p;i++){
		printf("For Process : %d\n",i+1);
		for(j=0;j<r;j++){
			scanf("%d",&max[i][j]);
		}
	}
	
	for(i=0;i<p;i++){
		finish[i]=0;
	}
	for(i=0;i<r;i++){
		sum=0;
		for(j=0;j<p;j++){
			sum=sum+alloc[j][i];
		}
		avail[0][i]=res[i] - sum;
	}
	
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	
	while(1){
		no_res=1;
		for(i=0;i<p;i++){
			check=0;
			if(!finish[i]){
				for(j=0;j<r;j++){
					if(need[i][j]<=avail[0][j]){
						check=1;
					}
					else{
						check=0;
						break;
					}
				}
				if(check){
					for(j=0;j<r;j++){
						avail[0][j]=avail[0][j]+alloc[i][j];
	
					}
					seq[count++]=i;
					finish[i]=1;
					no_res=0;
				}
			}
		}
		if(count==p){
			completed=1;
			break;
		}
		if(no_res){
			completed=0;
			break;
		}
	}
	printf("\n\nPno\tAllocated\tMax\tNeeded\tAvailable\n\n");
	for(i=0;i<p;i++){
		printf("P%d\t",i+1);
		for(j=0;j<r;j++){
			printf("%d ",alloc[i][j]);
		}
		printf("\t");
		for(j=0;j<r;j++){
			printf("%d ",max[i][j]);
		}
		printf("\t");
		for(j=0;j<r;j++){
			printf("%d ",need[i][j]);
		}
		printf("\t");
			if(i==0){
			for(j=0;j<r;j++)
			printf("%d ",avail[i][j]);
		}
			printf("\n");
		
	}
	printf("Processes sequence  :   ");
	for(i=0;i<count;i++){ 
		printf("P%d  ",seq[i]+1);
	}
	if(completed){
		printf("\n\nThe above sequence is a safe sequence");
	}
	else{
		printf("\n\nThe above sequence is not a safe sequence");
	}
}
