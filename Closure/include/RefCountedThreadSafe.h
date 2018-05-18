#include "config.h"

template<class T, typename Traits = DefaultRefCountedThreadSafeTraits<T> >
class CLOSURE_EXPORT RefCountedThreadSafe : public RefCountedThreadSafeBase {
public:
    RefCountedThreadSafe();

protected:
    ~RefCountedThreadSafe();

public:
    void AddRef() const;
    void Release() const;

private:
    friend struct DefaultRefCountedThreadSafeTraits<T>;
    static void  DeleteInternal(const T* x);
};