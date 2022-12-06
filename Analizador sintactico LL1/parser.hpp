#ifndef PARSER_HPP
#define PARSER_HPP


#include "scanner.hpp"
#include "stack.hpp"
#include <map>
#include <vector>


#define stseq   101
#define stseq_  102
#define st      103
#define assign  104
#define quest   105
#define quest_  106
#define argue   107
#define argue_  108
#define prop    109
#define prop_   110
#define clause  111
#define clause_ 112
#define equiv   113
#define equiv_  114
#define atom    115
#define output  116  


using namespace std;


typedef vector<int> production;

typedef map<int,production> row;
typedef map<int,row> table;

class parser{

    table controller;

public:

    parser();

    bool LL1();
    void insert(stack &, production);
    bool search(production , int);
};


#endif