/*
 * @Author: rzk ruanzk2098@gmial.com
 * @Date: 2024-12-05 20:01:15
 * @LastEditors: rzk ruanzk2098@gmial.com
 * @LastEditTime: 2025-02-10 15:59:24
 * @FilePath: /cplusplus/src/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AElude
 * 
 *//*  */
#include<iostream>

#include<list>
using std::list;
using std::cout;
using std::endl;
void print(list<int>&num){
    for(auto & i : num){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

   list<int>num1{1,3,5,7,9};
   list<int>num2{2,4};

   auto it = num1.begin();
   //auto it1 = num1.begin()+1;
   auto it2 = num2.begin();
   it2++;
   num1.splice(it, num2 ,it2 , num2.end() );
   print(num1);
   print(num2);
}