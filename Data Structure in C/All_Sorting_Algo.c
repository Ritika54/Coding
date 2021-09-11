#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int *temp;
	*temp=*a;
	*a=*b;
	*b=*temp;
}
void bubbleSort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int swapped=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped=1;
            }
        }
        if(swapped==0)
            break;
    }
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i;i<n;i++){
            if(arr[minIndex]>arr[j]){
                minIndex=j;
            }
        }
        swap(&arr[i],&arr[minIndex]);
    }
}

void insertionSort(int arr[],int n){
	int key,j;
	for(int i=1;i<=n-1;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int partition(int arr[],int low,int high){
    int pivot=low;
    while (low<high){
        do{
            low++;
        }while (arr[low]<=arr[pivot]);
        do{
            high--;
        }while (arr[high]>arr[pivot]);
        if(low<high){
            swap(arr[low],arr[high]);
        }
    }
    swap(arr[pivot],arr[high]);
    return high;
}

int quickSort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high+1);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }    
}

// int quickSort(int arr[],int low,int high){
//     int pivot,l,h;
//     pivot=low;
//     l=low;h=high;
//     low++;
//     while (low<=high)
//     {
//         while (arr[low]<arr[pivot])
//             low++;
//         while (arr[high]>=arr[pivot])
//             high--;
//         if(low<=high)
//            swap(arr[low],arr[high]);    
//     }
//     swap(arr[pivot],arr[high]);
//     pivot=high;
//     quickSort(arr,l,pivot-1);
//     quickSort(arr,pivot+1,h);
// }

int main(){
    int n;
    int *arr;
    printf("Enter size of array ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter elements \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    printf("Sorted array \n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}