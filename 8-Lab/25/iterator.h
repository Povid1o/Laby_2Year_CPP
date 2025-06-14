#pragma once
template<class Arr>
class ArrIterator {
    Arr& arr_;
    std::size_t pos_;
public:
    ArrIterator(Arr& a, std::size_t p):arr_(a),pos_(p){}
    auto& operator*()  { return arr_[pos_]; }
    ArrIterator& operator++(){ ++pos_; return *this; }
    bool operator!=(const ArrIterator& o) const { return pos_!=o.pos_; }
};
