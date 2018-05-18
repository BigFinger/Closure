#include "config.h"
#include "BindStateBase.h"
#include "scoped_refptr.h"

class CLOSURE_EXPORT CallbackBase {
public:
    explicit CallbackBase(BindStateBase* bind_state);
protected:
    ~CallbackBase();

public:
    bool is_null() const;
    void Reset();

protected:
    typedef void (*InvokeFuncStorage)(void);
    bool Equals(const CallbackBase& other) const;
    explicit CallbackBase(BindStateBase* bind_state);

protected:
    scoped_refptr<BindStateBase> bind_state_;
    InvokeFuncStorage polymorphic_invoke_;

public:
    bool FunctorAndPtrEquals(const CallbackBase& other) const;
};