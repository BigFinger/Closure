#include "config.h"

template<class T, T v>
struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
};

template<class T, T v>
struct integral_const {
    static const T value = v;
    typedef T value_type;
    typedef integral_const<T, v> type;
};

template <class T, T v> 
const T integral_constant<T, v>::value;

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

typedef char YesType;

struct NoType 
{
    YesType dummy[2];
};

#define MOVE_ONLY_TYPE_FOR_CPP_03(type, rvalue_type) \
private: \
struct rvalue_type { \
    explicit rvalue_type(type* object) : object(object) {} \
    type* object; \
}; \
    type(type&); \
    void operator=(type&); \
public: \
    operator rvalue_type() { return rvalue_type(this); } \
    type Pass() { return type(rvalue_type(this)); } \
    typedef void MoveOnlyTypeForCPP03; \
private: