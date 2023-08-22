#include <stdio.h>
//histogramArray(int *arr, int size);
printMaxPartAscending(int *arr2, int size2);
void main() {
    //int size1=14;
    //int arr1[14]={13, 1, 3, 4, 7, 3, 13, 9, 13, 5, 4, 1, 4, 13};
    //histogramArray(arr1, size1);
    int arr2[10]={10,9,8,7,6,5,4,3,2,1};
    int size2=10;
    printMaxPartAscending(arr2,size2);
}
int histogramArray(int *arr, int size){
    int sum[size];
    for (int i = 0; i <= size; i++) {
        sum[i]=0;}
    for (int i=0;i<size;i++){
        sum[*(arr+i)]++;
        }
    for (int i = 0; i <= size; i++) {
        if (sum[i]) {
            printf("%d ", i);
            for (int j = 0; j < sum[i]; j++) {
                printf("%c", '*');
            }
            printf("\n");
        }

    }
}
int printMaxPartAscending(int *arr, int size) {
    int counter=0, j=0,max=0, max_id=0,max_id_starts=0;
    for (int i=0; i<size;i++){
         while(arr[i]<arr[i+1]){
            counter++;
            i++;
        }
         if(counter>max){
             max=counter;
             max_id=i;
         }
        counter=0;

    }
    max_id_starts=max_id-max;
    if (max==0)
        printf("No such segment");
    else {
        for (int i = max_id_starts; i <= max_id; i++)
            printf("%d ", arr[i]);
    }
}