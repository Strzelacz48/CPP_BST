#include <string.h>

template<class T>
class compare_types {
    public:
        static bool compare(T x, T y) { return x<y; }
        static bool equal(T x, T y) { return x==y; }
};

template <>
class compare_types<const char*> {
    public:
        static bool compare(const char* x, const char* y) { return strcmp(x, y)<=0; }
        static bool equal(const char* x, const char* y) { return strcmp(x, y)==0; }
};

template <>
class compare_types<char*> {
    public:
        static bool compare(char* x, char* y) { return strcmp(x, y)<=0; }
        static bool equal(char* x, char* y) { return strcmp(x, y)==0; }
};

template <class T>
class compare_types<T*> {
    public:
        static bool compare(T *x, T *y) { return (*x)<=(*y); }
        static bool equal(T *x, T *y) { return (*x)==(*y); }
};
