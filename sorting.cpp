//vedhant 106117035
#include<iostream>

using namespace std;
void mergesort(int a[],int l,int r);
void merge(int a[],int l,int mid,int r);

int main()
{
    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>arr[i];
    mergesort(arr,0,n-1);
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
}

void mergesort(int a[],int l,int r)
{
    int mid=(l+r)/2;
    if(l<r)
    {
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
    }
    merge(a,l,mid,r);
}
void merge(int a[],int l,int mid,int r)
{
   int temp[100],k=0;
   int i=l,j=mid+1;
   while(i<=mid&&j<=r)
   {
       if(a[i]<a[j])
       {
           temp[k++]=a[i];
           ++i;
       }
       else
       {
           temp[k++]=a[j];
           ++j;
       }
   }
   while(i<=mid)
       temp[k++]=a[i++];
   while(j<=r)
       temp[k++]=a[j++];

   for(i=l,k=0;i<=mid;++i)
    a[i]=temp[k++];
   for(i=mid+1;i<=r;++i)
    a[i]=temp[k++];

}
