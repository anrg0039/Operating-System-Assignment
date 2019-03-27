#include<stdio.h>
int g;
void main()
{
    int p[20],wt[20],at[20],atp,tp,d,i,j,k,l,m,n,tn,pos,tbt=0;
    float pr[20],bt[20],temp,awt=0,atat=0;
	
    printf("Enter number of process:");
    scanf("%d",&n);
    if(n<=0)
    tn=n;
    printf("\nEnter Arrival and Burst time :\n");
    for(i=0;i<n;i++)
    {
    	
	
    	printf("For p%d\n",i+1);
        printf("  Arrival :");
        scanf("%d",&at[i]);
        printf("\n  Burst :");
        scanf("%f",&bt[i]);
        p[i]=i+1;        
        tbt=tbt+bt[i];
        
    
    }
    
    for(l=0;l<n;l++)
    {
    pos=l;
        for(m=l+1;m<n;m++)
        {
            if(at[m]<at[pos])
                pos=m;
        }
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
     
  
    for(i=0;i<tbt;i++)
    {
    	for(j=0;j<n;j++)
    	{
        if(at[j]<=i)
    	wt[j]=i-at[j];
    	else
    	wt[j]=-1000;	
		}
		
		for(k=0;k<n;k++)
		{
			pr[k]=(1+(wt[k]/bt[k]));	
		}
		
		
		for(l=0;l<n;l++)
    {
        pos=l;
        for(m=l+1;m<n;m++)
        {
            if(pr[m]>pr[pos])
                pos=m;
        }
        
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
    
    
    if(g==i)
    {
    	
    	int wt1=wt[0];
    	int tat1=wt[0]+bt[0];
    	g=i+bt[0];
    	tp=p[0];
    	for(d=0;d<n-1;d++)
    	{
    		p[d]=p[d+1];
    		wt[d]=wt[d+1];
    		pr[d]=pr[d+1];
    		bt[d]=bt[d+1];
    		at[d]=at[d+1];
		}
		n=n-1;
    	
    	if(tp!=atp){
		printf("Process p%d waiting time: %d turn around time: %d \n",tp,wt1,tat1);
		awt=awt+wt1;
		atat=atat+tat1;
	}
		atp=tp;
			
}		
	}
	printf("\n################################################################\n");
	printf("Average waitnig time: %f \n",awt/tn);
	printf("Average Turn Around time: %f \n",atat/tn);

}
  
