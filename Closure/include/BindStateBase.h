#include "config.h"
#include "RefCountedThreadSafe.h"

class BindStateBase : public RefCountedThreadSafe<BindStateBase> {
protected:
    friend class RefCountedThreadSafe<BindStateBase>;
    virtual ~BindStateBase();

public:
    int mParamCount;
    const void* mInvokerPtr;
};
