#include <stdio.h>
#include <stdlib.h>

struct array
{
    int a[10];
    int size;
    int len;
};
void displaythearray(struct array arr)
{
    int i;
    for(i=0;i<arr.len;i++)
    {
        printf("%d ",arr.a[i]);
    }
    printf("\n");
}
void insert(struct array *arr,int x)
{
    for(int i=arr->len-1;i>=0;i--)
    {
        if(arr->a[i]>x)
        {
            arr->a[i+1]=arr->a[i];
        }
        else
        {
            arr->a[i+1]=x;
            break;
        }
    }
    arr->len++;
}
int sorted(struct array arr)
{
    for(int i=0;i<arr.len-1;i++)
    {
        if(arr.a[i]>arr.a[i+1])
            return 0;
    }
    return 1;
}
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void negonleft(struct array *arr)
{
    int i=0,j=arr->len-1;
    while(i<j){
    while(arr->a[i]<0)
    {
        i++;
    }
    while(arr->a[j]>=0)
    {
        j--;
    }
    if(i<j)
    {
        swap(&arr->a[i],&arr->a[j]);
    }
    }
}
int main()
{
   struct array arr={{2,4,-2,8,-7,12,14,-3},10,8};
  // displaythearray(arr);
   insert(&arr,7);
   displaythearray(arr);
   printf("%d\n",sorted(arr));
  negonleft(&arr);
  displaythearray(arr);




}
