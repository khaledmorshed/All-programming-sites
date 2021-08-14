#include <stdio.h>

unsigned int max_arr = 20;
unsigned long b[20] = {0};

void write_data(void);
long sum_array(long *_a);
void bubble_sort(long *_b);
long findNum(void);

int main(void){
    scanf("%Ld\n", &max_arr);
    write_data();

    bubble_sort(b);
    printf("%Ld\n", findNum());
    return 0;
}
void write_data(void){
    long count = 0;
    while(count < max_arr){
        scanf("%Ld", &b[count++]);
    }
}
long findNum(void){
    long temp = 0;
    long sumArray = sum_array(b);
    long max_number = (sumArray/2);
    long neg = sumArray%2;

    long sumArray_x2 = (b[0]*2);
    if(sumArray_x2 >= sumArray){
        long result =  (sumArray_x2 - sumArray);
        //printf("%Ld\n", result);
        return result;
    }

    long c = 0;
    for(int i = 0; i < max_arr; i++){
        c = b[0];
        for(int j = i; j < max_arr; j++){
            c += b[j];
            if(c > max_number){
                c -= b[j];
            }
            else if(c == max_number && neg == 0){
                //printf("%Ld\n", 0);
                return 0;
            }
        }
        if(c > temp){
            temp = c;
        }
    }
    long firstA01 = sumArray - temp;
    long secondA01 = temp;
    long result = sumArray - (temp *2);

    //printf("%Ld\n", result);
    return result;
}
void bubble_sort(long *_b){
    for(int i = (max_arr - 1);i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(_b[j] < _b[j + 1]){
                long temp = _b[j];
                _b[j] = _b[j + 1];
                _b[j + 1] = temp;
            }
        }
    }
}
long sum_array(long *_a){
    long sum_h = 0;
    long count = 0;
    while(count < max_arr){
        sum_h += _a[count++];
    }
    return sum_h;
}
