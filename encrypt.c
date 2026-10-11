#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "hello my name is";

    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = str[i] - ((3*2)+1);
    }
    
    printf("%s",str);
    
    return 0;
}