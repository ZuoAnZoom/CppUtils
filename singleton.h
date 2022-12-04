/**
 * @file signleton.h
 * @author cuishanyao (shanyao_work@163.com)
 * @brief thread safe sigleton
 * @version 0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <pthread.h>


namespace LANG {


/**
 * @brief Thread-safe, no-mannul destroy Singleton tmplate
 */
template<typename T>
class Singleton {
public:
    /**
     * @brief Get the singleton instance
     */
    static T* get() {
        pthread_once(&p_once_, &Singleton::new_);
        return instance_;
    }

private:
    Singleton();
    ~Singleton();

    /**
     * @brief construct the singleton instance
     */
    static void new_() { instance_ = new T(); }

    /**
     * @brief destruct the singleton instance
     * @note only work with gcc/clang
     */
    __attribute__((destructor))
    static void delete_() {
        typedef char T_must_be_complete[sizeof(T) == 0 ? -1 : 1];
        (void)sizeof(T_must_be_complete);
        delete instance_;
    }

private:
    static pthread_once_t p_once_;  // Initialization once control
    static T* instance_;
};

template<typename T>
pthread_once_t Singleton<T>::p_once_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::instance_ = NULL;

} // lang



/**
 * @brief Singleton helper, put in private
 */
#define MAKE_SINGLETON(Type)    \
    private:                    \
        Type() {}               \
        ~Type() {}              \
        friend class ::lang::Singleton<Type>