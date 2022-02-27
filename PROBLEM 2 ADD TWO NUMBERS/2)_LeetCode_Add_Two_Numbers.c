#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2){
    int size = sizeof(struct ListNode);
    struct ListNode *sum_head = (struct ListNode *)malloc(size);
    sum_head->next = NULL;
    struct ListNode *sum_iter = sum_head;
    int temp = l2->val+l1->val;
    //l2 = l2->next;
    //l1 = l1->next;
    sum_iter->val = temp%10,
    temp /=10;
    while(l1->next != NULL && l2->next != NULL){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,
        l1 = l1->next,
        l2 = l2->next,
        temp += l1->val+l2->val,
        sum_iter->val = temp%10,
        temp /= 10;
    }
    while(l1->next != NULL){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,
        l1 = l1->next;
        temp += l1->val,
        sum_iter->val = temp%10,
        temp /= 10;
    }
    while(l2->next != NULL){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,
        l2 = l2->next,
        temp += l2->val,
        sum_iter->val = temp%10,
        temp /= 10;
    }
    while(temp != 0){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,
        sum_iter->val = temp%10,
        temp /= 10;
    }
    return sum_head;
}

/*
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2){
    int size = sizeof(struct ListNode);
    struct ListNode *sum_head = (struct ListNode *)malloc(size);
    sum_head->next = NULL;
    struct ListNode *sum_iter = sum_head;
    //int temp = 0;
    int temp = l2->val+l1->val;

        l2 = l2->next;
        l1 = l1->next;

    sum_iter->val = temp%10,
    temp /=10;

    while(l1 != NULL && l2 != NULL){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,

        temp += l1->val+l2->val,
        sum_iter->val = temp%10,
        temp /= 10,
        l1 = l1->next,
        l2 = l2->next;
    }
    while(l1 != NULL){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,

        temp += l1->val,
        sum_iter->val = temp%10,

        temp /= 10,

        l1 = l1->next;
    }
    while(l2 != NULL){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,
        temp += l2->val,
        sum_iter->val = temp%10,
        temp /= 10,
        l2 = l2->next;
    }

    while(temp != 0){
        sum_iter->next = (struct ListNode *)malloc(size),
        sum_iter = sum_iter->next,
        sum_iter->next = NULL,
        sum_iter->val = temp%10,
        temp /= 10;
    }

    return sum_head;
}
*/
struct ListNode *fill_list(struct ListNode *l1,int sayi){
    int size = sizeof(struct ListNode);
    struct ListNode *iter_l1 = NULL;
    if(l1 == NULL){
        l1 = (struct ListNode *)malloc(size);
        l1->val = sayi%10;
        sayi /= 10;
    }
    iter_l1 = l1;
    while(sayi != 0){
        iter_l1->next = (struct ListNode *)malloc(size);
        iter_l1 = iter_l1->next;
        iter_l1->val = sayi%10;
        sayi /= 10;
    }
    return l1;
}
void print_list(struct ListNode * l){
if(l == NULL){
puts("null");
}
    while(l != NULL){
        printf("%d-",l->val);
        l = l->next;
    }
    putchar('\n');
}
int main(){
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *sum = NULL;
    size_t size = sizeof(struct ListNode);
    l1 = fill_list(l1,243);
    l2 = fill_list(l2,564);
    sum = addTwoNumbers(l1,l2);
    /*if(sum == NULL){
        puts("sum == null");
    }
    else{
    printf("sum deger = %d\n",sum->val);
    }

    if(sum->next == NULL){
        puts("sum next== null");
    }
    else{
    printf("sum next deger = %d\n",sum->next->val);
    }*/
    //print_list(l1);
    //print_list(l2);
    print_list(sum);
}
