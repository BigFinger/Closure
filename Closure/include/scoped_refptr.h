#include "config.h"

template<class T>
class scoped_refptr {
public:
    typedef T element_type;
    scoped_refptr();
    scoped_refptr(T* p);
    scoped_refptr(const scoped_refptr<T>& r);

    template <typename U>
    scoped_refptr(const scoped_refptr<U>& r);
    ~scoped_refptr();

public:
    T* get() const;
    operator T*() const;
    T* operator->() const;
    scoped_refptr<T>& operator=(T* p);
    scoped_refptr<T>& operator=(const scoped_refptr<T>& r);
    template<class U>
    scoped_refptr<T>& operator=(const scoped_refptr<U>& r);
    
public:
    void swap(T** pp);
    void swap(scoped_refptr<T>& r);

protected:
    T* ptr_;
};