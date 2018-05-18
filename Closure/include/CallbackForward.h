#include "config.h"

template <class T>
typename enable_if<!IsMoveOnlyType<T>::value, T>::type& CallbackForward(T& t) {
    return t;
}

template <class T>
typename enable_if<IsMoveOnlyType<T>::value, T>::type CallbackForward(T& t) {
    return t.Pass();
}