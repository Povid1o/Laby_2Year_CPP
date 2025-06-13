#include <iostream>
#include "collection.h"

struct ListError { virtual void dump() const = 0; virtual ~ListError(){} };

struct BadPtr    : ListError { void dump() const override { std::cout<<"Bad list pointer\n"; } };
struct BadIndex  : ListError { void dump() const override { std::cout<<"Illegal index\n"; } };
struct ListFull  : ListError { void dump() const override { std::cout<<"List is full\n"; } };

int main(){
    PointerArray<ListError> errs;
    errs.push_back(new BadPtr);
    errs.push_back(new BadIndex);
    errs.push_back(new ListFull);

    for(auto e: errs) e->dump();
    return 0;
}
