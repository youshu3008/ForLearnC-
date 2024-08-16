#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <assert.h>

using namespace std;

char* strcpy(char *dst, const char *src) {
    assert(dst != nullptr && src != nullptr);
    char* result = dst;
    cout << (*dst++ = *src++) << endl;
    while((*dst++ = *src++) != '\0');
    return result;
}

int main(){
    const char* src = "hello world";
    char dst[50];  // 确保dst有足够的空间存储src字符串和空终止符。
    char* res = strcpy(dst, src);

    // 打印复制的字符串。
    cout << "复制的字符串: " << dst << endl;

    // 打印复制字符串中的每个字符。
    for(int i = 0; res[i] != '\0'; ++i){
        cout << "res[" << i << "]: " << res[i] << endl;
        cout << "*res= " << *res++ << endl;
    }

    return 0;
}