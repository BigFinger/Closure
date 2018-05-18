#include "config.h"

class CLOSURE_EXPORT RefCountedThreadSafeBase {
public:
    bool HasOneRef() const;

protected:
    RefCountedThreadSafeBase();
    ~RefCountedThreadSafeBase();
    
protected:
    void AddRef() const;
    bool Release() const;

private:
    mutable int ref_count_;
    mutable bool in_dtor_;
};

