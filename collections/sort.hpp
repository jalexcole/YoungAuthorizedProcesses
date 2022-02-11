#pragma once

template <typename T: public IComparable>
void bubbleSort(T[] arr, int n) {
  T i, j;
  bool swapped;
   for (i = 0; i < n-1; i++) {
     swapped = false;
     for (j = 0; j < n-i-1; j++) {
        if (arr[j].compareTo(arr[j+1])) {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
  
     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

template <typename T: public IComparable>
void swap(T *xp, T *yp) {
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}