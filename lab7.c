#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, int arrCounter[][2], int *swapCounter){
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                for(int k = 0; k < n; k++){
                    if((arrCounter[k][0] == arr[j]) || (arrCounter[k][0] == arr[j+1])){
                        arrCounter[k][1]++;
                        *swapCounter = *swapCounter + 1;
                    }
                }
            }
        }
    }
}

void selectionSort(int arr[], int n, int arrCounter[][2], int *swapCounter){
    int i, j, minIndex, temp;

    for(i = 0; i < n-1; i++){
        minIndex = i;

        for(j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        for(int k = 0; k < n; k++){
            if(arrCounter[k][0] == arr[i]){
                arrCounter[k][1]++;
                *swapCounter = *swapCounter + 1;
            }
        }
    }
}

void printArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printSwapCount(int arrCount[][2], int n){
    for(int i = 0; i < n; i++){
        printf("%d: # of times %d is swapped \n", arrCount[i][0], arrCount[i][1]);
    }
}

int main(void){
    int arr1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr1Counter[][2] = {
        {97, 0},
        {16, 0},
        {45, 0},
        {63, 0},
        {13, 0},
        {22, 0},
        {7, 0},
        {58, 0},
        {72, 0},
    };
    int arr2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arr2Counter[][2] = {
        {90, 0},
        {80, 0},
        {70, 0},
        {60, 0},
        {50, 0},
        {40, 0},
        {30, 0},
        {20, 0},
        {10, 0},
    };
    int n = 9;
    int bubbleSwapCounter = 0;
    int selectionSwapCounter = 0;

    printf("Before Bubble Sorting: ");
    printArray(arr1, n);
    bubbleSort(arr1, n, arr1Counter, &bubbleSwapCounter);
    printf("After Bubble Sorting: ");
    printArray(arr1, n);
    printSwapCount(arr1Counter, n);
    printf("Total Number of Swaps in Bubble Sort: %d", bubbleSwapCounter);
    printf("\n\n");
    printf("Before Selection Sorting: ");
    printArray(arr2, n);
    selectionSort(arr2, n, arr2Counter, &selectionSwapCounter);
    printf("After Selection Sorting: ");
    printArray(arr2, n);
    printSwapCount(arr2Counter, n);
    printf("Total Number of Swaps in Selection Sort: %d", selectionSwapCounter);


    return 0;
}