#include<bits/stdc++.h>
void quicksort(int number[50],int first,int last){
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j)
         {
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

void quicksort_with_pivot(int number[25],int first,int last ,int pivot){
   int i, j, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j)
         {
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, count, number[50], pivot;
    char p;
    printf("CODE BY PRERANA CHAVAN\nSCHOLAR NUMBER:20U03070\n");
   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);
   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++){

      scanf("%d",&number[i]);
   }
   printf("do you want to input pivot (y/n): ");
    
   scanf("\n%c",&p);
  
   if (p == 'y' || p == 'Y')
    {
        printf("Enter Pivot: ");
        scanf("%d",&pivot);
        quicksort_with_pivot(number,0,count-1,pivot);
    }
    else if(p == 'n'|| p == 'N')
    {
        quicksort(number,0,count-1);
    }
    else{
        return 0;
    }
   
   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d\n",number[i]);
   return 0;
}