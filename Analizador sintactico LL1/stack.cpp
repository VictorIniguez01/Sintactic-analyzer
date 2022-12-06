#include "stack.hpp"


stack::stack(){

    n = 1;
    s = 0;
    buffer = new int[n];
}

stack::~stack(){ delete [] buffer; }

void stack::push(int newValue){

    if(full()){

        n *= 2;
        int *t = new int[n];

        for(int i = 0; i < size(); i++) t[i] = buffer[i];

        delete [] buffer;
        buffer = t;
    }

    buffer[s] = newValue;
    s++;
}

int stack::pop(){

    if(empty()){
        
        printf("POP DENIED ");
        return 0;
    } else if(size() == (capacity() / 4)){
        
        n /= 2;
        int *t = new int[n];

        for(int i = 0; i < size(); i++) t[i] = buffer[i];

        delete [] buffer;
        buffer = t;
    }

    s--;
    return buffer[s];
}

int stack::top(){

    if(empty()){ return 0; }
    return buffer[s - 1];
}

void stack::print(){

    cout << "[";
    for(int i = 0; i < n; i++){ (i < size()) ? printf(" %i", buffer[i]) : printf("  "); }
    cout << " ]\n";
}