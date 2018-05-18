#include "config.h"

template<class T, typename Traits>
class RefCountedThreadSafe;

template<typename T>
struct DefaultRefCountedThreadSafeTraits {
    static void Destruct(const T* x){
        RefCountedThreadSafe<T, DefaultRefCountedThreadSafeTraits>::DeleteInternal(x);
    }
};