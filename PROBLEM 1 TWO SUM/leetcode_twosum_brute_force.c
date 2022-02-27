#include<stdio.h>
#include<stdlib.h>
//The solution of the leetcode two sum problem with brute force
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int number = 0;
    *returnSize = 2;
	int* return_arr = (int*)malloc(sizeof(int)*2);
	for(int c = 0;c<numsSize-1;c++){
        number = target - nums[c];
		for(int c2 =c+1;c2<numsSize;c2++){
			if(nums[c2] == number){
				return_arr[0] = c,
				return_arr[1] = c2;
				return return_arr;
			}
		}
	}
	return NULL;
}
int main(){
	int arr[5] = {-1,-2,-3,-4,-5};
	int *return_arr = NULL;
	int returnSize = 0;
	int target = -3;
	return_arr = twoSum(arr, 5, target,&returnSize);
	if(return_arr == NULL){
		puts("null");
	}
	else{
		printf("indexies = %d,%d size = %d\n",return_arr[0],return_arr[1],returnSize);
	}
}
