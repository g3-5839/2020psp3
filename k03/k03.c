#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start = 0, pos = 0;
    int text_len = 0, key_len = 0;
    int i = 0, j = 0;
    int table[256];

    while(text[text_len] != '\0'){
        text_len++;
    }

    while(key[key_len] != '\0'){
        key_len++;
    }

    for(i = 0; i < 256; i++){
        table[i] = key_len;
    }

    for(j = 0; j < key_len; j++){
        table[key[j]] = key_len - j -1;
    }

    for(start = 0; start < text_len; start++){
        for(pos = 0; pos < key_len; pos++){
            if(text[start+pos] == key[pos]) {
                if(pos == key_len - 1){
                return &text[start];
                }
            } else {
                break;
            }
        }
    }
    
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int table[256];
    int index = 0, index2 = 0, key_index = 0;
    int text_len = 0, key_len = 0;
    int i;

    while(text[text_len] != '\0'){
        text_len++;
    }

    while(key[key_len] != '\0'){
        key_len++;
    }

    for(i = 0; i < 256; i++){
        table[i] = key_len;
    }

    for(i = 0; i < key_len; i++){
        table[key[i]] = key_len - i - 1;
    }

    index = key_len - 1;

    while(index < text_len){
        index2 = index;
        for(key_index = key_len - 1; key_index >= 0; key_index--){
            index--;
            if(text[index] == key[key_index]){
                 if(key_index == 0){
                    return &text[index];
                }
            } else {
                break;
            }
        }

        index = index + table[text[index]];

        if(index <= index2){
            index = index2 + 1;
        }

    }

    return NULL;

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}