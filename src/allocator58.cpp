/*
 * @Author: rzk ruanzk2098@gmial.com
 * @Date: 2025-02-21 10:24:41
 * @LastEditors: rzk ruanzk2098@gmial.com
 * @LastEditTime: 2025-02-21 10:49:07
 * @FilePath: /cplusplus/src/allocator58.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
using std::size_t;
//#define __USE_MALLOC


 # ifdef __USE_MALLOC 

 template <int __inst>
 class __malloc_alloc_template {
 
 private:
   static void* _S_oom_malloc(size_t);
   static void* _S_oom_realloc(void*, size_t);

 #ifndef __STL_STATIC_TEMPLATE_MEMBER_BUG
   static void (* __malloc_alloc_oom_handler)();
 #endif
 
 public:
 
   static void* allocate(size_t __n)
   {
        void* __result = malloc(__n);
        if (nullptr == __result) __result = _S_oom_malloc(__n); //oom: out of memory
        return __result;
   }
 
   static void deallocate(void* __p, size_t /* __n */)
   {
     free(__p);
   }
 
   static void* reallocate(void* __p, size_t /* old_sz */, size_t __new_sz)
   {
     void* __result = realloc(__p, __new_sz);
     if (0 == __result) __result = _S_oom_realloc(__p, __new_sz);
     return __result;
   }
 
   static void (* __set_malloc_handler(void (*__f)()))()
   {
     void (* __old)() = __malloc_alloc_oom_handler;
     __malloc_alloc_oom_handler = __f;
     return(__old);
   }
 
 };

 typedef __malloc_alloc_template<0> malloc_alloc;

 typedef malloc_alloc alloc;
 typedef malloc_alloc single_client_alloc;

 # else

 template <bool threads, int inst>
 class __default_alloc_template {
   
    union _Obj {   //链表的结构
        union _Obj* _M_free_list_link;
        char _M_client_data[1];    /* The client sees this.        */
   };
    # if defined(__SUNPRO_CC) || defined(__GNUC__) || defined(__HP_aCC)
            static _Obj*  _S_free_list[]; 
    # else
            static _Obj*  _S_free_list[16]; 
    # endif
 public:
   /* __n must be > 0      */
   static void* allocate(size_t __n)
   {
        void* __ret = 0;
    
        if (__n >  128) {
        __ret = malloc_alloc::allocate(__n); //上一个分支的申请
        }
        else {
        //_Obj* volatile * __my_free_list
        _Obj*  * __my_free_list
            = _S_free_list + _S_freelist_index(__n);
        // Acquire the lock here with a constructor call.
        // This ensures that it is released in exit or during stack
        // unwinding.
    #ifndef _NOTHREADS
        /*REFERENCED*/
        _Lock __lock_instance;
    #endif
        _Obj* __RESTRICT __result = *__my_free_list;
        if (__result == 0)
            __ret = _S_refill(_S_round_up(__n));
        else {
            *__my_free_list = __result -> _M_free_list_link;
            __ret = __result;
        }
        }
    
        return __ret;
   };
 
 } ;


 typedef __default_alloc_template<__NODE_ALLOCATOR_THREADS, 0> alloc;

 #endif
template <class _Tp>
class allocator {
    typedef alloc _Alloc;          // The underlying allocator.
    public:
      typedef size_t     size_type;
      typedef ptrdiff_t  difference_type;
      typedef _Tp*       pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp&       reference;
      typedef const _Tp& const_reference;
      typedef _Tp        value_type;
    
      template <class _Tp1> 
      struct rebind {
        typedef allocator<_Tp1> other;
      };

    // __n is permitted to be 0.  The C++ standard says nothing about what
   // the return value is when __n == 0.
    _Tp* allocate(size_type __n, const void* nullptr) {
        return __n != 0 ? static_cast<_Tp*>(_Alloc::allocate(__n * sizeof(_Tp))) : 0;
  }
    
};
