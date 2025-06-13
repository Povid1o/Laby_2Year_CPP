#include <iostream>
#include "collection.h"

struct IOError { virtual ~IOError(){}; virtual void log() const = 0; };

struct NoMem      : IOError { void log() const override { std::cout<<"Not enough memory\n"; } };
struct ReadError  : IOError { void log() const override { std::cout<<"File read error\n"; } };
struct WriteError : IOError { void log() const override { std::cout<<"File write error\n"; } };

int main(){
    PointerArray<IOError> errs(3);
    errs[0]=new NoMem;
    errs[1]=new ReadError;
    errs[2]=new WriteError;

    for(auto e: errs) e->log();
    return 0;
}
