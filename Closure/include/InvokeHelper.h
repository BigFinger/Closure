#include "config.h"

/* 执行类型的模板特化 */

template <bool IsWeakCall, class ReturnType, class Runnable, class ArgsType>
struct InvokeHelper;

template <class ReturnType, class Runnable>
struct InvokeHelper<false, ReturnType, Runnable, void()> 
{
    static ReturnType MakeItSo(Runnable runnable) 
    {
        return runnable.Run();
    }
};

template <class Runnable>
struct InvokeHelper<false, void, Runnable, void()> {

    static void MakeItSo(Runnable runnable) 
    {
        runnable.Run();
    }
};

template <class ReturnType, class Runnable, class A1>
struct InvokeHelper<false, ReturnType, Runnable, void()> 
{
    static ReturnType MakeItSo(Runnable runnable, A1 a1) 
    {
        runnable.Run(CallbackForward(a1));
    }
};

template <typename Runnable,typename A1>
struct InvokeHelper<false, void, Runnable, void(A1)>  
{
        static void MakeItSo(Runnable runnable, A1 a1) 
        {
            runnable.Run(CallbackForward(a1));
        }
};

template <typename Runnable, typename BoundWeakPtr>
struct InvokeHelper<true, void, Runnable, void(BoundWeakPtr)>  
{
        static void MakeItSo(Runnable runnable, BoundWeakPtr weak_ptr) 
        {
            if (!weak_ptr.get()) 
            {
                return;
            }
            runnable.Run(weak_ptr.get());
        }
};

template <typename ReturnType, typename Runnable,typename A1, typename A2>
struct InvokeHelper<false, ReturnType, Runnable, void(A1, A2)>  
{
        static ReturnType MakeItSo(Runnable runnable, A1 a1, A2 a2) 
        {
            return runnable.Run(CallbackForward(a1), CallbackForward(a2));
        }
};

template <typename Runnable,typename A1, typename A2>
struct InvokeHelper<false, void, Runnable, void(A1, A2)>  
{
        static void MakeItSo(Runnable runnable, A1 a1, A2 a2) 
        {
            runnable.Run(CallbackForward(a1), CallbackForward(a2));
        }
};

template <typename Runnable, typename BoundWeakPtr, typename A2>
struct InvokeHelper<true, void, Runnable, void(BoundWeakPtr, A2)>  
{
        static void MakeItSo(Runnable runnable, BoundWeakPtr weak_ptr, A2 a2) 
        {
            if (!weak_ptr.get()) 
            {
                return;
            }
            runnable.Run(weak_ptr.get(), CallbackForward(a2));
        }
};

template <typename ReturnType, typename Runnable,typename A1, typename A2, typename A3>
struct InvokeHelper<false, ReturnType, Runnable, void(A1, A2, A3)>  
{
        static ReturnType MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3) 
        {
            return runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3));
        }
};

template <typename Runnable,typename A1, typename A2, typename A3>
struct InvokeHelper<false, void, Runnable, void(A1, A2, A3)>  
{
        static void MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3) 
        {
            runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3));
        }
};

template <typename Runnable, typename BoundWeakPtr, typename A2, typename A3>
struct InvokeHelper<true, void, Runnable, void(BoundWeakPtr, A2, A3)>  
{
        static void MakeItSo(Runnable runnable, BoundWeakPtr weak_ptr, A2 a2, A3 a3) 
        {
            if (!weak_ptr.get()) 
            {
                return;
            }
            runnable.Run(weak_ptr.get(), CallbackForward(a2), CallbackForward(a3));
        }
};

template <typename ReturnType, typename Runnable,typename A1, typename A2, typename A3, typename A4>
struct InvokeHelper<false, ReturnType, Runnable, void(A1, A2, A3, A4)> 
{
        static ReturnType MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4)
        {
            return runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4));
        }
};

template <typename Runnable,typename A1, typename A2, typename A3, typename A4>
struct InvokeHelper<false, void, Runnable, void(A1, A2, A3, A4)>  
{
        static void MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4) 
        {
            runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3),  CallbackForward(a4));
        }
};

template <typename Runnable, typename BoundWeakPtr, typename A2, typename A3,
    typename A4>
struct InvokeHelper<true, void, Runnable, void(BoundWeakPtr, A2, A3, A4)>  
{
        static void MakeItSo(Runnable runnable, BoundWeakPtr weak_ptr, A2 a2, A3 a3, A4 a4) 
        {
                if (!weak_ptr.get()) 
                {
                    return;
                }
                runnable.Run(weak_ptr.get(), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4));
        }
};

template <typename ReturnType, typename Runnable,typename A1, typename A2, typename A3, typename A4, typename A5>
struct InvokeHelper<false, ReturnType, Runnable, void(A1, A2, A3, A4, A5)>  
{
        static ReturnType MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5)
        {
                return runnable.Run(CallbackForward(a1), CallbackForward(a2),
                    CallbackForward(a3), CallbackForward(a4), CallbackForward(a5));
        }
};

template <typename Runnable,typename A1, typename A2, typename A3, typename A4, typename A5>
struct InvokeHelper<false, void, Runnable, void(A1, A2, A3, A4, A5)>  
{
        static void MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) 
        {
            runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5));
        }
};

template <typename Runnable, typename BoundWeakPtr, typename A2, typename A3, typename A4, typename A5>
struct InvokeHelper<true, void, Runnable, void(BoundWeakPtr, A2, A3, A4, A5)>  
{
        static void MakeItSo(Runnable runnable, BoundWeakPtr weak_ptr, A2 a2, A3 a3, A4 a4, A5 a5)
        {
                if (!weak_ptr.get()) 
                {
                    return;
                }
                runnable.Run(weak_ptr.get(), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5));
        }
};

template <typename ReturnType, typename Runnable,typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct InvokeHelper<false, ReturnType, Runnable, void(A1, A2, A3, A4, A5, A6)>  
{
        static ReturnType MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) 
        {
                return runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5), CallbackForward(a6));
        }
};

template <typename Runnable,typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
struct InvokeHelper<false, void, Runnable, void(A1, A2, A3, A4, A5, A6)>  
{
        static void MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) 
        {
                runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5), CallbackForward(a6));
        }
};

template <typename Runnable, typename BoundWeakPtr, typename A2, typename A3, typename A4, typename A5, typename A6>
struct InvokeHelper<true, void, Runnable, void(BoundWeakPtr, A2, A3, A4, A5, A6)>  
{
        static void MakeItSo(Runnable runnable, BoundWeakPtr weak_ptr, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) 
        {
                if (!weak_ptr.get()) 
                {
                    return;
                }
                runnable.Run(weak_ptr.get(), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5), CallbackForward(a6));
        }
};

template <typename ReturnType, typename Runnable,typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct InvokeHelper<false, ReturnType, Runnable, void(A1, A2, A3, A4, A5, A6, A7)>  
{
        static ReturnType MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4,
            A5 a5, A6 a6, A7 a7) 
        {
                return runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5), CallbackForward(a6), CallbackForward(a7));
        }
};

template <typename Runnable,typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct InvokeHelper<false, void, Runnable, void(A1, A2, A3, A4, A5, A6, A7)>  
{
        static void MakeItSo(Runnable runnable, A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7)
        {
                runnable.Run(CallbackForward(a1), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5), CallbackForward(a6), CallbackForward(a7));
        }
};

template <typename Runnable, typename BoundWeakPtr, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
struct InvokeHelper<true, void, Runnable, void(BoundWeakPtr, A2, A3, A4, A5, A6, A7)>  
{
        static void MakeItSo(Runnable runnable, BoundWeakPtr weak_ptr, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) 
        {
                if (!weak_ptr.get()) 
                {
                    return;
                }
                runnable.Run(weak_ptr.get(), CallbackForward(a2), CallbackForward(a3), CallbackForward(a4), CallbackForward(a5), CallbackForward(a6), CallbackForward(a7));
        }
};