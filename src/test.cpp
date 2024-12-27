/*
 * @Author: rzk ruanzk2098@gmial.com
 * @Date: 2024-12-05 20:01:15
 * @LastEditors: rzk ruanzk2098@gmial.com
 * @LastEditTime: 2024-12-05 21:08:23
 * @FilePath: /cplusplus/src/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AElude
 * 
 *//*  */
#include<iostream>

#include "myswap.h"
using namespace std;

int main(){

    // #ifdef Debug
    //     printf("debug \n");
    //     cout<<Debug<<endl;
    // #else 
    //     printf("no define debug \n");
    // #endif 
/*  */
    int a = 3 , b = 5;
    swap(a , b);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
        
}