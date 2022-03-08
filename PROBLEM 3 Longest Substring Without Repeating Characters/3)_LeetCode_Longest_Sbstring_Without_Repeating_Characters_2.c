#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdint.h>
#include<inttypes.h>
bool bool_arr[96];//ascıı tablosu 256 karakter ben 257 karakterlik bir hash array'i oluşturdum
uint64_t a[2]={0,0};
uint64_t shift = 1;
bool karsilastir(uint64_t sayi,uint64_t temp){
    if(sayi&(1<<temp)){return 1;}
    return 0;
    //if(a[(int)s[y]/(int)64]&((int64_t)1<<(temp)) == 0){
        //return 1;
    //}
}
/*
Runtime: 20 ms, faster than 31.43% of C online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 5.8 MB, less than 97.02% of C online submissions for Longest Substring Without Repeating Characters.
*/

int lengthOfLongestSubstring(char * s){
    int str_size = strlen(s);
    int longest_substring_size = 0;
    int temp_longest_substring_size = 0;
    int i = 0,y = 0,x = 0;
    int64_t temp = 0;
    for(;i<str_size;i++){
        for(y = i;y<str_size;y++){
            //printf("a[s[y]/64]&(1<<(s[y]%64)) = %llu | a[s[y]/64 = %llu | (1<<(s[y]%64) = %llu\n",a[s[y]/64]&(1<<(s[y]%64)),a[s[y]/64],(1<<(s[y]%64)));
            temp = ((int64_t)s[y])%64;
            printf("temp =%" PRId64 "\n", temp);

            if(a[0] == 0){puts("a[0] = 0");}
            if(a[1] == 0){puts("a[1] = 0");}
            printf("rrrr =%" PRId64 "\n", a[(int)s[y]/(int)64]&((int64_t)1<<(temp)) == (int64_t)0);
            //printf("r = %llu\n",a[(int)s[y]/64]&(1<<(temp)) == 0);
            printf("a[(int)s[y]/64] = %"PRId64"\n",a[(int)s[y]/64]);
            printf("(1<<(temp)) = %"PRId64"\n",((int64_t)1<<(temp)));
            if(a[(int)s[y]/(int)64]&((int64_t)1<<(temp)) == 0){
            puts("girdi");
                //printf("%d)s2[y] = %d |s[y]/64 = %d | s[y]%64 = %d\n",y,s[y],s[y]/64,s[y]%64);
                //printf("a1 = %llu\n",a[s[y]/64]);
                a[(int)s[y]/64] |= ((int64_t)1<<(temp));
                for(int j =0;j<2;j++){
                    for(int i = 63;i>=0;i--){
                        a[j]&(1<<i)? putchar('1'):putchar('0');
                    }
                    puts("");
                }
                //printf("a2 = %llu\n",a[s[y]/64]);
                temp_longest_substring_size++;
            }
            else{
                puts("girmez ağam");
                break;
            }
        }
        a[0] = 0;
        a[1] = 0;

        if(longest_substring_size < temp_longest_substring_size){
            longest_substring_size = temp_longest_substring_size;
        }
        temp_longest_substring_size = 0;
    }
    return longest_substring_size;
}
int main() {
/*
    uint64_t control_arr[2]={4,5};
    uint16_t s = ~(0<<0);
    printf("%d\n",3&(1<<0));
    printf("%d\n",3&(1<<1));
    printf("%d\n",3&(1<<2));
    printf("%d\n",s);
    s = ~(1<<0);
    printf("%d\n",s);
    //control_arr[0] |= 1<<63;
    int sayi = 127;
    sayi |= 0<<63;
    printf("sayi = %d | sayi/64 = %d | sayi%64 = %d",sayi,sayi/64,sayi%64);
    */
    /*
    for(int a =0;a<2;a++){
        for(int i = 63;i>=0;i--){
            control_arr[a]&(1<<i)? putchar('1'):putchar('0');
        }
        puts("");
    }*/
    //if((a[1]&(shift<<(127%64))) == 0){

    //if(a[1] == 0){puts("0");}
    //int8_t aa = 124%64;
    //printf("aa = %d\n",aa);
    //printf("aa = %d\n",124/64);
    //a[124/64] = 5;
  /*  a[124/64] |= (shift<<((uint64_t)124%64));
    printf("a = %llu\n",a);
    if(a[1] == 0){puts("0");}
    for(int indis = 1;indis<2;indis++){
        for(int i = 63;i>=0;i--){
        //printf("\ni = %d\n",i);
            a[1]&(1<<i)? putchar('1'):putchar('0');
        }
    }
*/
    //a[1]&(shift<<31);
     /*
     for(int j =0;j<2;j++){
                    for(int i = 63;i>=0;i--){
                        a[j]&(1<<i)? putchar('1'):putchar('0');
                    }
                    puts("");
                }
    */
  /*  if((a[1]&(shift<<31)) == 0){
                //printf("%d)s2[y] = %d |s[y]/64 = %d | s[y]%64 = %d\n",y,s[y],s[y]/64,s[y]%64);
                //printf("a1 = %llu\n",a[s[y]/64]);
                puts("ss");
                //a[1] |= (shift<<(127%64));
                a[1] |= (shift<<(31));
                for(int j =0;j<2;j++){
                    for(int i = 63;i>=0;i--){
                        a[j]&(1<<i)? putchar('1'):putchar('0');
                    }
                    puts("");
                }

                //printf("a2 = %llu\n",a[s[y]/64]);

            }
            else{
                puts("ne var lan");
                for(int j =0;j<2;j++){
                    for(uint64_t i = 63;i>=0;i--){
                        a[j]&(1<<i)? putchar('1'):putchar('0');
                    }
                    puts("");
                }
            }*/
  /*  char arr1[] = "abcabcbb";
    printf("%s Result = %d\n",arr1,lengthOfLongestSubstring(arr1));
    char arr2[] = "bbbbb";
    printf("%s Result = %d\n",arr2,lengthOfLongestSubstring(arr2));
    char arr3[] = "pwwkew";
    printf("%s Result = %d\n",arr3,lengthOfLongestSubstring(arr3));
    char arr4[] = "au";
    printf("%s Result = %d\n",arr4,lengthOfLongestSubstring(arr4));
    printf("%s Result = %d\n",arr4,lengthOfLongestSubstring(arr4));
*/
int64_t n = 1;
a[0] |= 1<<0;
a[1] = 1;
//a[0] |= n<<30;
//a[0] |= n<<31;
//a[0] |= n<<56;
//a[0] = 0;
int sayac = 0;
for(int i= 63;i>0;i--){
sayac++;
    if(a[0]&(1<<i)){putchar('1');}
    putchar('0');
    //a[0]&(int64_t)(n<<i) == 0?putchar('0'):putchar('1');
}
printf("\nsayac = %d\n\n",sayac);
/*
printf("sonuç = %d\n",karsilastir(a[0],0));
printf("sonuç = %d\n",karsilastir(a[0],1));
printf("sonuç = %d\n",karsilastir(a[0],30));
printf("sonuç = %d\n",karsilastir(a[0],31));
printf("sonuç = %d\n",karsilastir(a[0],56));*/
}




















/*
     char arr1[] = "abcabcbb";
     printf("%s Result = %d\n",arr1,lengthOfLongestSubstring(arr1));
     char arr2[] = "bbbbb";
     printf("%s Result = %d\n",arr2,lengthOfLongestSubstring(arr2));
     char arr3[] = "pwwkew";
     printf("%s Result = %d\n",arr3,lengthOfLongestSubstring(arr3));
     char arr4[] = "au";
     printf("%s Result = %d\n",arr4,lengthOfLongestSubstring(arr4));
     printf("%s Result = %d\n",arr4,lengthOfLongestSubstring(arr4));
    */
    //printf("%d ,%c ,%c",127-32,127,126);
    //printf("%d,%d,%d",'A','a',122-97);
    //printf
    //for(int a = 'a')
