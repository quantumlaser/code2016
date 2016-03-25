int findmostappear(int *a,int len)
{
  int candidate=0,count=0;
  for(int i=0;i<len;i++)
  {
     if(count==0)
     {
       candidate=a[i];
       count=1;
     }
     else
     {
       if(candidate==a[i])
           count++;
       else
           count--;
     }
  }
  return candidate;
}