
/*********************************************************************
*	FUNCTION:		Quick_Sort
*	DESCRIPTION:	Sort numbers in array using quick sort
*	INPUT:
*		Parameters:	list[] - array of numbers
*					high - top spot in array
*					low - bottom spot of array
*	OUTPUT:	
*	PROTOTYPE: void Quick_Sort(int list[], int high, int low);
*   IMPLEMENTED BY: Hennessy 
**********************************************************************/
void Quick_Sort/*(Version1)*/(int list[], int high, int low){

	int pivot;
	int listTemp;

	if(high>low){// stop condition check if high is still higer than low
		
		pivot = list[low];

		int left = low+1;
		int right = high;

		while(left <= right){
			if(list[left] <= pivot){
				left++;
			}
			else{// if left index is pointing at a value over pivot
				if(list[right]>pivot){
					right--;
				}
				else{// if both indexes are pointing at numbers that belong on the other side of the partition
					listTemp = list[left];
					list[left] = list[right];
					list[right] = listTemp;
				}
			}// end if list low > list 0
		}// end while low < high
			
		listTemp = list[right];// swaps pivot back into the middle point
		list[right] = list[low];
		list[low] = listTemp;

		Quick_Sort(list, right-1, low);
		Quick_Sort(list, high, right+1);
		
	}// end if high passes low
}

/*********************************************************************
*	FUNCTION:		Bubble_Sort
*	DESCRIPTION:	Sort numbers in array using bubble sort
*	INPUT:
*		Parameters:	list[] - array of numbers
*					high - top spot in array
*					low - bottom spot of array
*	OUTPUT:	
*		Return value: none
*	PROTOTYPE: void Bubble_Sort(int list[], int high, int low);
*   IMPLEMENTED BY: Hennessy 
**********************************************************************/
void Bubble_Sort(int list[], int high, int low){
	int listTemp;
	int top = high;
	bool sorted = false;

	for(int i = low; i < top && !sorted ; i++){
		sorted = true;
		for(int j =low; j < top; j ++){
			if(list [j] > list [j+1]){
				sorted = false;
				listTemp = list[j];
				list[j] = list[j+1];
				list[j+1] = listTemp;
			}
		}
	}
}

/*********************************************************************
*	FUNCTION:		Insert_Sort
*	DESCRIPTION:	Sort numbers in array using insertion sort
*	INPUT:
*		Parameters:	list[] - array of numbers
*					high - top spot in array
*					low - bottom spot of array
*	OUTPUT:	
*		Return:     list[] - sorted list of integers 
*	PROTOTYPE: void Insert_Sort(int list[], int high, int low);
*   IMPLEMENTED BY: Mickens 
**********************************************************************/
void Insert_Sort (int list[], int high, int low){ 

  int remainTopIdx = 1; 
  int lastIdx = high;         
  int insertValue = 0; 
  int currentIdx = 0; 
  int currentTemp = 0; 

  while (remainTopIdx <= lastIdx){

       insertValue = list[remainTopIdx]; 
       currentIdx = remainTopIdx - 1; 

       while ((currentIdx >= 0) && (insertValue < list[currentIdx])){ 
            currentTemp = list[currentIdx]; 
            list[currentIdx + 1] = currentTemp;
            currentIdx--; 
       } 

       list[currentIdx + 1] = insertValue; 
       remainTopIdx++; 
  } 

} 
/*********************************************************************
*	FUNCTION:		Merge_Sort
*	DESCRIPTION:	Sort numbers in array using merge sort
*	INPUT:
*		Parameters:	list[] - array of numbers
*					high - top spot in array
*					low - bottom spot of array
*	OUTPUT:	
*		Return:     list[] - sorted list of integers 
*	PROTOTYPE: void Merge_Sort(int list[], int high, int low);
*   IMPLEMENTED BY: Mickens 
**********************************************************************/
void Merge_Sort (int list[], int high, int low){ 

  int mid; 
 
  if (low < high){ 
  
       mid = ((low + high) / 2); 
       Merge_Sort(list, mid, low); 
       Merge_Sort(list, high, mid+1); 
       Merge(list, mid, high, low); 
  } 
} 
/*********************************************************************
*	FUNCTION:		Merge
*	DESCRIPTION:	Merge integers from two sorted list 
*	INPUT:
*		Parameters:	list[] - array of numbers
*                   midIdx - middle spot in array 
*					high - top spot in array
*					low - bottom spot of array
*	OUTPUT:	
*		Return:     list[]- sorted list of integers 
*	PROTOTYPE: void Merge_Sort(int list[], int high, int low);
*   IMPLEMENTED BY: Mickens 
**********************************************************************/
void Merge(int list[], int midIdx, int high, int low){ 

  int tempPos; 
  int leftIdx;
  int rightIdx;  
  int count; 
  static int temp[MAX_ARRAY_SIZE];
  
  // Copy master list to temporary list 
  for(count = low; count <= high; count++)
       temp[count] = list[count];

  tempPos = low; 
  leftIdx = low; 
  rightIdx = midIdx + 1; 

  // Merge two sorted arrays 
  while (leftIdx <= midIdx && rightIdx <= high){ 
       if (temp[leftIdx] <= temp [rightIdx]){ 
           list[tempPos] = temp[leftIdx];
           leftIdx++; 
       } 
       else {
           list[tempPos] = temp[rightIdx];
           rightIdx++; 
       } 
       tempPos++; 
   } 

   // Merge remaining elements in left array  
   while (leftIdx <= midIdx){ 
        list[tempPos] = temp[leftIdx]; 
        tempPos++; 
        leftIdx++; 
   } 
   
   // Merge remaining elements in right array 
   while (rightIdx <= high){ 
         list[tempPos] = temp[rightIdx]; 
         tempPos++; 
         rightIdx++; 
   }              

} 



