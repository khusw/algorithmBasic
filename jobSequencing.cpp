
  // Greedy Algorithm - Job Sequencing problem
   // gain maximum profit

#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
    char id;
    int Deadline;
    int Profit;
};
bool comparision(Job a,Job b) 
{
    return a.Profit>b.Profit;  
}
void printJobScheduling(Job arr[],int n)
{
    sort(arr,arr+n,comparision);   

    int result[n];  
    int slot[n];    
    for(int i=0;i<n;i++)
        slot[i]=false;

    for(int i=0;i<n;i++)  //iterate all jobs
    {
      for(int j=/*min(n,arr[i].Deadline)-1*/ arr[i].Deadline-1;j>=0;j--)
      {
         if(slot[j]==false)  
           {
              result[j]=i;  
              slot[j]=true; 
              break;
           }
      }
    }

    for(int i=0;i<n;i++)  
    {
      if(slot[i])
          cout<<arr[result[i]].id<<" ";   //
    }
    cout<<endl;
}
int main()
{
    Job arr[]={{'a',4,100},{'b',3,19},{'c',2,27},{'d',1,25},{'e',3,15}};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<" Maximum profit sequence is : ";
    printJobScheduling(arr,n);

}
