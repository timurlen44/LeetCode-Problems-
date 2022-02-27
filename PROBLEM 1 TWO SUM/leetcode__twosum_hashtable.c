#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//The solution of the leetcode two sum problem with Hash Table
#define null NULL
int MAX = 0;

typedef struct hash_table HT;
struct hash_table{
	int data;
	int index;
	HT *next;
};

HT **ht = null;
unsigned int hash_code(int data){
	if(data >= 0)
	{
		return data%MAX;
	}
	return (MAX-data)%MAX;
}


void insert_hash_table(int data,int index){
	unsigned int hashCode = hash_code(data);
	if(ht[hashCode] == null){
		ht[hashCode] = (HT *)malloc(sizeof(HT));
		ht[hashCode]->next =null;
		ht[hashCode]->data = data;	
		ht[hashCode]->index = index;
	}
	else{
		HT *tmp = ht[hashCode];
		while(tmp->next != null){
			tmp = tmp->next;
		}
		tmp->next = malloc(sizeof(HT));
		tmp->next->next = null;
		tmp->next->data = data;
		tmp->next->index = index;
	}
	return;	
}
int find_in_hash_table(int data,int index){//eðer -1 dönmüþse aranan sayý bulunamamýþ demektir.
	unsigned int hashCode = hash_code(data);
	if(ht[hashCode] == null){
		return -1;
	}
	else{
		HT *tmp = ht[hashCode];
		
		do{
			if(tmp->data == data && tmp->index != index){
				return tmp->index;
			}
			tmp = tmp->next;
		}while(tmp != null);
	}
	return -1;	
}
void print_hash_table(){
	puts("BEGIN");
	for(int i = 0; i<MAX;i++){
		if(ht[i] == null)
			printf("ht[%d] = null\n",i);
		else{
			HT *tmp = ht[i];
			while(tmp != null){
				printf("ht[%d] = %d and index is = %d| ",i,tmp->data,tmp->index);
				tmp = tmp->next;
			}printf("\n");		
		}
			
	}
	puts("END\n\n");
	
}

HT **init_hash_table(HT **ht){
	for(int i = MAX-1;i>=0;i--){
		ht[i] = NULL;	
	}
	return ht;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){

	*returnSize = 2;
	MAX = numsSize;
	ht = (HT **)malloc(sizeof(HT*)*MAX);
	ht = init_hash_table(ht);
	
	int* return_arr = (int*)malloc(sizeof(int)*2);
		for(int i = 0;i<MAX;i++){

			insert_hash_table(nums[i],i);	
		}
		print_hash_table();
		int target2 = 0;
		int index = -1;
		for(int i = 0;i<MAX;i++){
			target2 = target - nums[i];
			index = find_in_hash_table(target2,i);	
			if(index != -1){
			return_arr[0] = i;
			return_arr[1] = index;
			return return_arr;
			}
		}
		return null;
}




int main(){
	int arr[5] = {-1,-2,-3,-4,-5};
	int *return_arr = null;
	int returnSize = 0;
	int target = -3;
	return_arr = twoSum(arr, 5, target,&returnSize);
	if(return_arr == null){
		puts(" Returned array is null");
	}
	else{
		printf("indexies = %d,%d size = %d\n",return_arr[0],return_arr[1],returnSize);
	}
}

