#include <stdio.h>
//histogramArray(int *arr, int size);
//printMaxPartAscending(int *arr2, int size2);
//checkSaddleElement(int arr[][10],int row_s,int col_s);
//rotateMatrix90(int arr[][3], int row_s,int col_s);
//void rotateString(char myString[], int step, int dirc);
int check(char matr[][8], int row_s, int col_s, int row, int col, char word[], int len, char cross);
int countWords(char matr[][8], int row_s, int col_s, char word[]);
void decipher(char seq[]);
int main() {
    //int size1=14;
    //int arr1[14]={13, 1, 3, 4, 7, 3, 13, 9, 13, 5, 4, 1, 4, 13};
    //histogramArray(arr1, size1);
    //int arr2[10]={10,9,8,7,6,5,4,3,2,1};
    //int size2=10;
    //printMaxPartAscending(arr2,size2);
    /* int arr[8][10]={{1, 2, 0, 3, 9, 4, 5, 3, 6, 7},
                     {2 ,4 ,3, 5, 9, 0, 2, 3, 4, 1},
                     {5, 3, 4, 7, 6, 1, 9, 0, 4, 2},
                     {6, 9, 7, 8, 6, 7, 7, 4, 5, 6},
                     {8, 3, 1, 9, 2, 0, 6, 2, 8, 2},
                     {2, 7, 3, 0, 3, 6, 3, 1, 5, 3},
                     {8, 2, 5, 9, 7, 7, 8, 3, 7, 3},
                     {1, 7, 4, 8, 5, 8, 5, 0, 0, 6}};*/
    //int row_s=3, col_s=3;
    //ans=checkSaddleElement(arr,row_s,col_s);
    //int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    //rotateMatrix90(arr,row_s,col_s);
    //for (int i = 0; i <row_s; i++){
    //for(int j=0;j<col_s;j++){
    //printf("%d ",arr[i][j]);
    // }
    /*char str[] = "refdeeae";
    rotateString(str, 10, 1);  // Rotate right by 2 steps
    printf("%s\n", str);      // Output: "fdeeaere"

    char matrix[][8] = {
            {'a', 'w', 'o', 'r', 'd', 'b', 'c', 'w'},
            {'d', 'o', 'o', 'e', 'f', 'h', 'i', 'o'},
            {'j', 'r', 'k', 'r', 'w', 'l', 'w', 'r'},
            {'m', 'd', 'n', 'o', 'd', 'o', 'o', 'd'},
            {'p', 'q', 'r', 's', 'w', 'o', 'r', 'd'},
            {'t', 'u', 'v', 'w', 'x', 'y', 'd', 'd'}
    };
    int row_s=6, col_s=8,counter;
    char word[]="word";
    counter=countWords(matrix,row_s,col_s,word);
    printf("%d",counter);
     */
    char seq[]="Btwlzx Dqqes Eq|pj4 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt5";
    decipher(seq);
    printf("Deciphered: %s\n", seq);
    return 0;
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
int checkSaddleElement(int arr[][10],int row_s,int col_s){
    int min_r=arr[0][0],min_r_id=0,min_c_id=0,k=0;
    for (int i=0;i<row_s;i++){
        min_r=arr[i][0];
        for (int j=0;j<col_s;j++){
            if (min_r > arr[i][j]){
                min_r=arr[i][j];
                min_r_id=i;
                min_c_id=j;
            }}
        if (min_r_id==0){
            k=1;
        }
        while((min_r > arr[k][min_c_id])) {
            k++;
            if (k==min_r_id)
                k++;
            i++;
            if (k==row_s){
                return 1;
            }}
        k=0;
    }
    return 0;

            }
int rotateMatrix90(int arr[][3], int row_s,int col_s){
    int *p, rot[row_s][col_s];
    for (int j=0;j<col_s;j++){
        for(int i=1;i<=row_s;i++){
            rot[j][i-1]=arr[row_s-i][j];
        }
    }
    for (int i = 0; i <row_s; i++){
        for(int j=0;j<col_s;j++){
            arr[i][j]=rot[i][j];
        }
    }
}

void rotateString(char myString[], int step, int dirc) {
    int length = 0, step_mod;
    while (myString[length] != '\0') {
        length++;
    }
    step_mod = step % length;
    char move[step_mod];
    for (int i = 0; i < step_mod; i++) {
        if (dirc == 1) {
            move[i] = myString[i];
        } else if (dirc == 2) {
            move[i] = myString[length - step_mod - i];
        }}
        for (int i = 0; i < length - step_mod; i++) {
            if (dirc == 1) {
                myString[i] = myString[i + step_mod];
            } else if (dirc == 2) {
                myString[length - i - 1] = myString[length - i - 3];
            }
        }
        for (int i = 0; i < step_mod; i++) {
            if (dirc == 1) {
                myString[length - step_mod + i] = move[i];
            } else if (dirc == 2) {
                myString[i] = move[i];
            }
        }
        }
int countWords(char matr[][8],int row_s,int col_s,char word[]) {
    int length=0, k = 0, flag = 0;
    while (word[length] != '\0') {
        length++;
    }
    for (int i = 0; i < row_s; i++) {
        for (int j = 0; j < col_s; j++) {
            if (matr[i][j] == word[k]) {
                flag+=check(matr,row_s,col_s,i,j+1,word,length,'r');
                flag+=check(matr,row_s,col_s,i+1,j,word,length,'c');
                flag+=check(matr,row_s,col_s,i+1,j+1,word,length,'x');
            }
            k = 0;
        }

    }
    return flag;
}
int check(char matr[][8],int row_s,int col_s,int row,int col,char word[],int len,char cross) {
    int k = 1, c = 0;
    while (matr[row][col] == word[k]) { // {
        if (cross == 'r') {
            k++;
            col++;
        }
        else if (cross=='c'){
            k++;
            row++;
        }
        else if (cross == 'x') {
            k++;
            col++;
            row++;
        }
        if (word[k] == '\0') {
            c++;
            break;
        }
    }
    return c;
}
void decipher(char seq[]){
    int len=0,k,i=1;
    while(seq[len]!='\0'){
        if (seq[len]==' '){
            len++;
            i=1;
        } else {
            k=seq[len];
            seq[len]=(char)(k-i);
            i++;
            len++;
        }

    }
}
