#ifndef SINGLETON_H_
#define SINGLETON_H_

template <typename T>
class Singleton {
public:
    static T *getInstance() {
        static T instance;
        return &instance;
    }
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
    Singleton(Singleton &rhs) = delete;
    Singleton &operator=(const Singleton &rhs) = delete;
};

#endif