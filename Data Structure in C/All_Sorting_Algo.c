#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int *temp;
	*temp=*a;
	*a=*b;
	*b=*temp;
}
//Stable Algorithm = Order of elements which have same value will not change after sorting
//Inplce Algorithm = You are not using extra space equal to or more than the size of array while sorting
//BUBBLE SORT(Stable,Inplace)
//Best case=O(n)
//Avg/Worst=O(n^2)
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

//SELECTION SORT(Stable,Inplace)
//Best/Avg/Worst case=O(n^2)
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

//INSERTION SORT(Stable,Inplace)
//Best = O(n)
//Avg/Worst = O(n^2)
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

//QUICK SORT(Not Stable,Inplace)
//Best/Avg case=O(nlogn)
//Worst= O(n^2)
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

//MERGE SORT(Stable,Not Inplace)
//Best case=O(nlogn)
//Worst/Avg = O(nlogn)
int merge(int arr[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int i=0,j=0,k=0;
    int *a1,*a2;
    a1=(int *)malloc(sizeof(int)*n1);
    a2=(int *)malloc(sizeof(int)*n2);
    for(i=0;i<n1;i++){
        a1[i]=arr[low+i];
    }
    for(j=0;j<n2;j++){
        a2[j]=arr[mid+1+j];
    }
    i=0;j=0;k=low;
    while(i<n1 && j<n2){
        if(a1[i]<a[j])
            arr[k++]=a1[i++];
        else
            arr[k++]=a2[j++];
    }
    while(i<n1){
        arr[k++]=a1[i++];
    }
    while(j<n2){
        arr[k++]=a2[j++];
    }
}

int mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

//TIM SORT
//BEST case = O(n)
//Worst/Avg = O(nlogn)
void timSort(int arr,int n){

}


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