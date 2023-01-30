#include<stdio.h>
#include<stdlib.h>
/*
Purpose:merge different arrays together; at the same time, sort the original arrrays
Return: the array that is merged
Parameter:
	left:the left array
	right:the right array
	leftLength:the size of the left array
	rightLength:the size of the right array
*/
int * merge(int * left, int * right,int leftLength,int rightLength){
	/*
	i:the index of total array
	i_l:the index of the left array
	i_r:the index of the rigt array
	*/
	int i,i_l,i_r;
	
	int *result;
	
	result=malloc((leftLength+rightLength)*sizeof(int));
	for (i=0,i_l=0,i_r=0;i<leftLength+rightLength;i++){
		if(i_l>=leftLength){
			result[i]=right[i_r++];
		}
		else if(i_r>=rightLength){
			result[i]=left[i_l++];
		}
		else if(left[i_l]>right[i_r]){
			result[i]=right[i_r++];
		}
		else{
			result[i]=left[i_l++];
		}
	}
	return result;
}
/*
Purpose:divide the whole array into different halfarrays.
Return: the pointer to an array
Parameter:
	1,oriArray:the original data of the array
	2,opArray:the array that need to be merge sorted
	4,start:the start index
	5,end:the end index
	6,length:the length of the opArray
*/
int * mergeSort(int *oriArray,int *opArray,int start,int end, int length){
	int i,j;
	int mid;
	int *left;
	int *right;
	if(length<2)return opArray;
	mid=(start+end)/2;
	left=malloc(sizeof(int)*(mid-start+1));
	right=malloc(sizeof(int)*(end-mid));
	/*copy to the left of the array*/
	for(i=start,j=0;i<mid+1;i++,j++){
		left[j]=oriArray[i];
	}
	/*copy to the right of the array*/
	for(i=mid+1,j=0;i<end+1;i++,j++){
		right[j]=oriArray[i];
	}
	return merge(mergeSort(oriArray,left,start,mid,mid-start+1),mergeSort(oriArray,right,mid+1,end,end-mid),mid-start+1,end-mid);
}

int main(){
	int i;
	int arr[8] = { 18,65,99,12,19,3,25,70 };
	int *sortArr=malloc(sizeof(int)*8);
	sortArr = mergeSort(arr, arr, 0, 7, 8);
	for (i = 0; i < 8; i++) {
		printf("%d,\t", *(sortArr + i));
	}
	printf("\n");
	return 0;
}