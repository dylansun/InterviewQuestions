#include <stdio.h>
void quicksort(int array[], int firstIndex, int lastIndex)
{
    int pivotIndex , temp, index1, index2;
    if(firstIndex < lastIndex)
    {
        pivotIndex = firstIndex;
        index1 = firstIndex;
        index2 = lastIndex;

        // sorting in ascending order with quick sort
        while(index1 < index2)
        {
            while(array[index1] <= array[pivotIndex]&& index1 < lastIndex)
            {
                index1 ++;
            }
            while(array[index2]> array[pivotIndex])
            {
                index2 --;
            }
            if(index1 < index2)
            {
                // swap
                temp = array[index1];
                array[index1]= array[index2];
                array[index2]= temp;
            }
        }

        // At the end of fist iteration, swap pivot elements with index2
        // elements.
        temp = array[pivotIndex];
        array[pivotIndex] = array[index2];
        array[index2]=temp;

        // recursive call for quicksort, with partitioning
        quicksort(array, firstIndex, index2-1);
        quicksort(array, index2+1,lastIndex);
    }
}

int main()
{
    int i =0;
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    quicksort(array, 0, 9);
    while(i <10){
        printf("%d ", array[i]);
        i++;
    }
    printf("\n");
    return 0;
}
