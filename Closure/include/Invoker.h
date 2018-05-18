#include "config.h"

template<int NumBound, typename Storage, typename RunType>
struct Invoker;

template<typename StorageType, typename R>
struct Invoker<0, StorageType, R()>{
    typedef R(RunType)(BindStateBase*);
    typedef R(UnboundRunType)();
    static R Run(BindStateBase* base) {
        StorageType* storage = static_cast<StorageType*>(base);
        return InvokeHelper<StorageType::IsWeakCall::value, R, class StorageType::RunnableType, void()>::MakeItSo(storage->runnable_);
    }
};