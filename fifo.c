#include<stdio.h>
void main()
{
int nof,nop,i,page[20],frm[10],j,flag=0,pf=0,victim=-1;
printf("enter no of frames");
scanf("%d",&nof);
printf("Enter no of pages");
scanf("%d",&nop);
printf("Enter page nos.");
for(i=0;i<nop;i++)
scanf("%d",&page[i]);
printf("the given p[ages are\n");
for(i=0;i<nop;i++)
printf("%d ",page[i]);
for(i=1;i<=nof;i++)
frm[i]=-1;
printf("\n");
for(i=0;i<nop;i++)
{
flag=0;
printf("\npage no %d->",page[i]);
for(j=0;j<nof;j++)
{
if(frm[j]==page[i])
{
flag=1;
break;
}
}
if(flag==0)
{
pf++;
victim++;
victim=victim%nof;
frm[victim]=page[i];
for(j=0;j<nof;j++)
printf("%d",frm[j]);
}
}
printf("No of page faults are %d",pf);
}
