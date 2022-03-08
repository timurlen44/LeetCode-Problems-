#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
bool bool_arr[257];//ascıı tablosu 256 karakter ben 257 karakterlik bir hash array'i oluşturdum
/*
Runtime: 20 ms, faster than 31.43% of C online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 5.8 MB, less than 97.02% of C online submissions for Longest Substring Without Repeating Characters.

*/
int lengthOfLongestSubstring(char * s){
    int str_size = strlen(s);
    int longest_substring_size = 0;
    int temp_longest_substring_size = 0;
    int i = 0,y = 0,x = 0;
    for(;i<str_size;i++){
        for(y = i;y<str_size;y++){
            //printf("s[y]-96 = %d",s[y]-96);
            if(bool_arr[s[y]] == 0){//
                bool_arr[s[y]] = 1;
                temp_longest_substring_size++;
            }
            else{
                break;
            }
        }
        for(x = i;x<=y;x++){
                    bool_arr[s[x]] = 0;//bool arrayini temizliyoruz;
        }
        if(longest_substring_size < temp_longest_substring_size){
        longest_substring_size = temp_longest_substring_size;
        }
        temp_longest_substring_size = 0;
    }
    return longest_substring_size;
}
int main() {
     char arr1[] = "abcabcbb";
     printf("%s Result = %d\n",arr1,lengthOfLongestSubstring(arr1));
     char arr2[] = "bbbbb";
     printf("%s Result = %d\n",arr2,lengthOfLongestSubstring(arr2));
     char arr3[] = "pwwkew";
     printf("%s Result = %d\n",arr3,lengthOfLongestSubstring(arr3));
     char arr4[] = "au";
     printf("%s Result = %d\n",arr4,lengthOfLongestSubstring(arr4));
     printf("%s Result = %d\n",arr4,lengthOfLongestSubstring(arr4));

    //printf("%d,%d,%d",'A','a',122-97);
    //printf
    //for(int a = 'a')
}
