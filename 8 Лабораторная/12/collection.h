#pragma once
#include <vector>
#include <stdexcept>

template<class T>
class PointerArray {
    std::vector<T*> data_;
    bool           owns_;
public:
    using iterator       = typename std::vector<T*>::iterator;
    using const_iterator = typename std::vector<T*>::const_iterator;

    explicit PointerArray(std::size_t n = 0, bool owns = true)
        : data_(n, nullptr), owns_(owns) {}

    ~PointerArray() {
        if (owns_)
            for (T* p : data_) delete p;
    }

    /* --- базовый уровень --- */
    T*& operator[](std::size_t i) {
        if (i >= data_.size()) throw std::out_of_range("index");
        return data_[i];
    }
    T* operator[](std::size_t i) const {
        if (i >= data_.size()) throw std::out_of_range("index");
        return data_[i];
    }

    /* --- средний/сложный уровни --- */
    void push_back(T* p)                 { data_.push_back(p); }
    void insert(std::size_t pos, T* p)   { if (pos > data_.size()) throw std::out_of_range("insert"); data_.insert(begin()+pos,p); }
    void erase(std::size_t pos)          { if (pos >= data_.size()) throw std::out_of_range("erase"); if(owns_) delete data_[pos]; data_.erase(begin()+pos); }
    void resize(std::size_t n)           { if (n < data_.size() && owns_) for (std::size_t i=n;i<data_.size();++i) delete data_[i]; data_.resize(n,nullptr); }

    iterator begin()             { return data_.begin(); }
    iterator end()               { return data_.end();   }
    const_iterator begin() const { return data_.begin(); }
    const_iterator end()   const { return data_.end();   }
};
