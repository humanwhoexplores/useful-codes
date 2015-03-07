void quicksort(int first,int last)
{
    int pivot,j,temp,i;
 
     if(first<last){
         pivot=first;
         i=first;
         j=last;
 
         while(i<j){
             while(frog[i]<=frog[pivot]&&i<last)
                 i++;
             while(frog[j]>frog[pivot])
                 j--;
             if(i<j){
                 temp=frog[i];
                  frog[i]=frog[j];
                  frog[j]=temp;
                 temp=pos[i];
                 pos[i]=pos[j];
                 pos[j]=temp;
             }
         }
 
         temp=frog[pivot];
         frog[pivot]=frog[j];
         frog[j]=temp;
          temp=pos[pivot];
          pos[pivot]=pos[j];
          pos[j]=temp;
         quicksort(first,j-1);
         quicksort(j+1,last);
    }
}   

