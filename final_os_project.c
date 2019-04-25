#include<stdio.h>
#include<stdlib.h>
int main()
{
int count,n,a,time,remain,fvalue=0,t_q;
int wait_timing=0,turnaround_timing=0,array1[10],array2[10],array3[10];
printf("\nEnter number of total Process:\t ");
scanf("%d",&a);
if(a==0){                             
printf("\nwrong input");
   exit(1);
}
remain=a;
for(count=0;count<a;count++)   
{
printf("\nEnter arrival time for process , Process Number %d :",count+1);
scanf("%d",&array1[count]);                             
if(array1[count]<0){
printf("\nwrong input");
   exit(1);
}
printf("\nEnter  Burst Time for Process , Process Number %d :",count+1);
scanf("%d",&array2[count]);                           
if(array2[count]==0){
printf("\nwrong input");
   exit(1);
}
array3[count]=array2[count];
}
printf("\nenter time quantum:\t");
scanf("%d",&t_q);        
printf("\nprocess\t|turnaround time|waiting time\n\n");
for(time=0,count=0;remain!=0;)
{
if(array3[count]<=t_q&& array3[count]>0)
{
time+=array3[count];
array3[count]=0;
fvalue=1;
}
else if(array3[count]>0)
{
array3[count]-=t_q;
time+=t_q;
}
if(array3[count]==0 && fvalue==1)
{
remain--;
printf("%d\t\t%d\t\t%d\n",count+1,time-array1[count],time-array1[count]-array2[count]);
wait_timing+=time-array1[count]-array2[count];
turnaround_timing+=time-array1[count];
fvalue=0;
}
if(count==a-1)
count=0;
else if(array1[count+1]<=time)
count++;
else
count=0;
}
printf("\naverage waiting time= %f\n",wait_timing*1.0/a);
printf("\navarage turnaround time = %f",turnaround_timing*1.0/a);
return 0;
}
