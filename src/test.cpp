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

#include<map>
using std::map;
using std::multimap;
void test(){
    multimap<int ,int>mmp1;
    int arr[] = {-1,0,1,2,-1,-4};
    for(int i = 6-1;i>=0;--i){
        mmp1.emplace(arr[i] , i);
    }
    multimap<int ,int>mmp2;
    for(int i = 0;i<6;++i){
        mmp2.emplace(arr[i] , i);
    }

    for(auto it = mmp1.begin() ;it!= mmp1.end();++it){
        cout<<it->first<<"  "<<it->second<<endl;
    }
    cout<<"-----------------"<<endl;
    for(auto it = mmp2.begin() ;it!= mmp2.end();++it){
        cout<<it->first<<"  "<<it->second<<endl;
    }

    auto it = mmp1.find(-1);
    cout<<it->second<<endl;
    it = mmp2.find(-1);
    cout<<it->second<<endl;
}
int main(){
    test();
}