#include "config.h"
#include "TemplateUtil.h"

template <class T> 
struct IsMoveOnlyType {
    template <class U>
    static YesType Test(const class U::MoveOnlyTypeForCPP03*);

    template <class U>
    static NoType Test(...);

    static const bool value = sizeof(Test<T>(0)) == sizeof(YesType) && !is_const<T>::value;
};