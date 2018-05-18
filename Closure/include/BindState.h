#include "config.h"
#include "Invoker.h"

template<class Runnable, class RunType, class BoundArgsType>
struct BindState;

template<class Runnable, class RunType>
struct BindState<Runnable, RunType, void> : public BindStateBase{
    typedef Runnable RunnableType;
    typedef false_type IsWeakCall;
    typedef Invoker<0, BindState, RunType> InvokerType;
    typedef typename InvokerType::UnboundRunType UnboundRunType;
};