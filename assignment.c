#include<stdio.h>
int g;   //Global Variable g
void main()
{     
     printf("_-_-_-_-_-_-_-_-_-_-_-_-___PRIORITY BASED SCHEDULING ALGORITHM___-_-_-_-_-_-_-_-_-_-_-_-_\n\n");
 	int n;
	char c;
	do{
    printf("Enter number of process:");
    while(scanf("%d",&n)!=1){     //Total number of process
	c=getchar();
    printf("\t\tINVALID ENTRY ! Please try again\n\n");
    while ( getchar() !='\n');
    printf("Enter number of process:");
}
if(n<=0)
printf("\t\tINVALID ENTRY ! Please try again\n\n");
}while(n<=0);
	
	
    int p[n],wt[n],at[n],atp,tp,d,i,j,k,l,m,tn,pos,tbt=0;
    float pr[n],bt[n],temp,awt=0,atat=0;  
    //p[]--> to store the process number
    //wt[]--> to store the waiting time for every process, initially waiting time for all the process is zero
    //at[]--> to store the arrival time of process
	//pr[]--> to store the priority of every process
	//bt[]--> to store the burst time of every process
	//tbt-->  total burst time
	//awt,atat--> average waiting time, average turn around time
	 
    void swap(pos,l)  //function to swap all array values parallely
    {
    	temp=pr[l];
        pr[l]=pr[pos];
        pr[pos]=temp;
        
        temp=bt[l];
        bt[l]=bt[pos];
        bt[pos]=temp;
 
        temp=p[l];
        p[l]=p[pos];
        p[pos]=temp;
        
        temp=wt[l];
        wt[l]=wt[pos];
        wt[pos]=temp;
        
        temp=at[l];
        at[l]=at[pos];
        at[pos]=temp;
	}
	
	void delarray() // function to delete a top element from all the arrays.
	{
		for(d=0;d<n-1;d++)
    	{
    		p[d]=p[d+1];
    		wt[d]=wt[d+1];
    		pr[d]=pr[d+1];
    		bt[d]=bt[d+1];
    		at[d]=at[d+1];
		}
	}
	
    
	
    tn=n;
    
    printf("\nEnter Arrival and Burst time :\n\n");
    for(i=0;i<n;i++)   //taking input from the user in bt[] and at[] array
    {
    	printf("For p%d\n",i+1);
		do{
        printf("  Arrival :");
        while(scanf("%d",&at[i])!=1){     
		c=getchar();
    	printf("\tInvalid Arrival time please enter again\n");
    	while ( getchar() !='\n');
    	printf("  Arrival :");
		}
        if(at[i]<0)   //arrival time can not be less than zero
        printf("\tInvalid Arrival time please enter again\n");
        }while(at[i]<0);
        do{
        	
        printf("  Burst :");
        while(scanf("%f",&bt[i])!=1){     
		c=getchar();
    	printf("\tInvalid burst time please enter again\n");
    	while ( getchar() !='\n');
    	 printf("  Burst :");
		}
        if(bt[i]<=0) //burst time can not be less than or equal to zero
        printf("\tInvalid burst time please enter again\n");
    }while(bt[i]<=0);
    p[i]=i+1;
    }
    printf("\n\n_-_-_-_-_-_-_-_-_-_-_-_-___SOLUTION___-_-_-_-_-_-_-_-_-_-_-_-\n\n");
    
    for(l=0;l<n;l++)  //Sorting all the arrays on the basis of arrival time in ascending order
    {
    pos=l;
        for(m=l+1;m<n;m++)
        {
            if(at[m]<at[pos])
                pos=m;
        }
        swap(pos,l);
        
    }
    tbt=at[0];
    
    for(i=0;i<n;i++) //calculating total burst time (max time program will take for all the process)
    {
    	tbt=tbt+bt[i];
    	if(at[i+1]>tbt)
    	tbt=at[i+1];	
		} 
  
    for(i=0;i<tbt;i++)  //loop starting from zero to total burst time
    {
    	for(j=0;j<n;j++)  //calculating waiting time for each process
    	{
        if(at[j]<=i)
    	wt[j]=i-at[j];
    	else
    	wt[j]=-100;	 //if at this time process is not there in the system then the waiting time will be in negative
		}
		
		for(k=0;k<n;k++) //calculating priority every time  for every process
		{
			pr[k]=(1+(wt[k]/bt[k]));	
		}
		
		
		for(l=0;l<n;l++) // sorting all the arrays on the basis of priority in descending order.
    {
        pos=l;
        for(m=l+1;m<n;m++)
        {
            if(pr[m]>pr[pos])
                pos=m;
        }
        
        swap(pos,l);
        }
    
    
    if(g==i)  // it will compare the i with global value if i==g then it means CPU is free at this time
              // we can run another process and if it is not equal to zero it will ignore this.     
    
    {
    	if(wt[0]<0)
    	{             //if waiting time of process is less than zero means it is not in the system
        g=g+1;       // it will increment  the value of g and and continue this iteration
        continue;
    	}
    
    
    
    	int wt1=wt[0];
    	int tat1=wt[0]+bt[0];
    	g=i+bt[0];
    	tp=p[0];
    	delarray();  // delete the top element of all the arrays
		n=n-1;
    	         
    	if(tp!=atp){ //print the process number, waiting time and arrival time
		printf("Process p%d running from %d to %d and waiting time: %d turn around time: %d \n",tp,i,g,wt1,tat1);
		awt=awt+wt1;
		atat=atat+tat1;
	}
		atp=tp;
			
}		
	} 
	//print average waiting and turn around time
	printf("\n################################################################\n");
	printf("\nAverage waitnig time: %f \n",awt/tn);
	printf("Average Turn Around time: %f \n",atat/tn);

}
  
