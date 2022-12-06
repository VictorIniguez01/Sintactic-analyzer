#include "parser.hpp"

extern int yylex(); 

parser::parser(){
    
    controller[stseq][_ptcoma] = {_err};
    controller[stseq][_id] = {st, stseq_};
    controller[stseq][_dospts] = {_err};
    controller[stseq][_interr] = {_err};
    controller[stseq][_condi] = {_err};
    controller[stseq][_or] = {_err};
    controller[stseq][_and] = {_err};
    controller[stseq][_igual] = {_err};
    controller[stseq][_nigual] = {_err};
    controller[stseq][_not] = {_err};
    controller[stseq][_dparen] = {_err};
    controller[stseq][_iparen] = {_err};
    controller[stseq][_false] = {_err};
    controller[stseq][_true] = {_err};
    controller[stseq][_result] = {st, stseq_};
    controller[stseq][_of] = {_err};

    controller[stseq_][_ptcoma] = {_ptcoma, stseq};
    controller[stseq_][_id] = {_err};
    controller[stseq_][_dospts] = {_err};
    controller[stseq_][_interr] = {_err};
    controller[stseq_][_condi] = {_err};
    controller[stseq_][_or] = {_err};
    controller[stseq_][_and] = {_err};
    controller[stseq_][_igual] = {_err};
    controller[stseq_][_nigual] = {_err};
    controller[stseq_][_not] = {_err};
    controller[stseq_][_dparen] = {_err};
    controller[stseq_][_iparen] = {_err};
    controller[stseq_][_false] = {_err};
    controller[stseq_][_true] = {_err};
    controller[stseq_][_result] = {_err};
    controller[stseq_][_of] = {};

    controller[st][_ptcoma] = {_err};
    controller[st][_id] = {assign};
    controller[st][_dospts] = {_err};
    controller[st][_interr] = {_err};
    controller[st][_condi] = {_err};
    controller[st][_or] = {_err};
    controller[st][_and] = {_err};
    controller[st][_igual] = {_err};
    controller[st][_nigual] = {_err};
    controller[st][_not] = {_err};
    controller[st][_dparen] = {_err};
    controller[st][_iparen] = {_err};
    controller[st][_false] = {_err};
    controller[st][_true] = {_err};
    controller[st][_result] = {output};
    controller[st][_of] = {_err};

    controller[assign][_ptcoma] = {_err};
    controller[assign][_id] = {_id, _dospts, quest};
    controller[assign][_dospts] = {_err};
    controller[assign][_interr] = {_err};
    controller[assign][_condi] = {_err};
    controller[assign][_or] = {_err};
    controller[assign][_and] = {_err};
    controller[assign][_igual] = {_err};
    controller[assign][_nigual] = {_err};
    controller[assign][_not] = {_err};
    controller[assign][_dparen] = {_err};
    controller[assign][_iparen] = {_err};
    controller[assign][_false] = {_err};
    controller[assign][_true] = {_err};
    controller[assign][_result] = {_err};
    controller[assign][_of] = {_err};

    controller[quest][_ptcoma] = {_err};
    controller[quest][_id] = {argue, quest_};
    controller[quest][_dospts] = {_err};
    controller[quest][_interr] = {_err};
    controller[quest][_condi] = {_err};
    controller[quest][_or] = {_err};
    controller[quest][_and] = {_err};
    controller[quest][_igual] = {_err};
    controller[quest][_nigual] = {_err};
    controller[quest][_not] = {argue, quest_};
    controller[quest][_dparen] = {_err};
    controller[quest][_iparen] = {argue, quest_};
    controller[quest][_false] = {argue, quest_};
    controller[quest][_true] = {argue, quest_};
    controller[quest][_result] = {_err};
    controller[quest][_of] = {_err};

    controller[quest_][_ptcoma] = {};
    controller[quest_][_id] = {_err};
    controller[quest_][_dospts] = {};
    controller[quest_][_interr] = {_interr, quest, _dospts, quest};
    controller[quest_][_condi] = {_err};
    controller[quest_][_or] = {_err};
    controller[quest_][_and] = {_err};
    controller[quest_][_igual] = {_err};
    controller[quest_][_nigual] = {_err};
    controller[quest_][_not] = {_err};
    controller[quest_][_dparen] = {};
    controller[quest_][_iparen] = {_err};
    controller[quest_][_false] = {_err};
    controller[quest_][_true] = {_err};
    controller[quest_][_result] = {_err};
    controller[quest_][_of] = {};

    controller[argue][_ptcoma] = {_err};
    controller[argue][_id] = {prop, argue_};
    controller[argue][_dospts] = {_err};
    controller[argue][_interr] = {_err};
    controller[argue][_condi] = {_err};
    controller[argue][_or] = {_err};
    controller[argue][_and] = {_err};
    controller[argue][_igual] = {_err};
    controller[argue][_nigual] = {_err};
    controller[argue][_not] = {prop, argue_};
    controller[argue][_dparen] = {_err};
    controller[argue][_iparen] = {prop, argue_};
    controller[argue][_false] = {prop, argue_};
    controller[argue][_true] = {prop, argue_};
    controller[argue][_result] = {_err};
    controller[argue][_of] = {_err};

    controller[argue_][_ptcoma] = {};
    controller[argue_][_id] = {_err};
    controller[argue_][_dospts] = {};
    controller[argue_][_interr] = {};
    controller[argue_][_condi] = {_condi, prop};
    controller[argue_][_or] = {_err};
    controller[argue_][_and] = {_err};
    controller[argue_][_igual] = {_err};
    controller[argue_][_nigual] = {_err};
    controller[argue_][_not] = {_err};
    controller[argue_][_dparen] = {};
    controller[argue_][_iparen] = {_err};
    controller[argue_][_false] = {_err};
    controller[argue_][_true] = {_err};
    controller[argue_][_result] = {_err};
    controller[argue_][_of] = {};

    controller[prop][_ptcoma] = {_err};
    controller[prop][_id] = {clause, prop_};
    controller[prop][_dospts] = {_err};
    controller[prop][_interr] = {_err};
    controller[prop][_condi] = {_err};
    controller[prop][_or] = {_err};
    controller[prop][_and] = {_err};
    controller[prop][_igual] = {_err};
    controller[prop][_nigual] = {_err};
    controller[prop][_not] = {clause, prop_};
    controller[prop][_dparen] = {_err};
    controller[prop][_iparen] = {clause, prop_};
    controller[prop][_false] = {clause, prop_};
    controller[prop][_true] = {clause, prop_};
    controller[prop][_result] = {_err};
    controller[prop][_of] = {_err};

    controller[prop_][_ptcoma] = {};
    controller[prop_][_id] = {_err};
    controller[prop_][_dospts] = {};
    controller[prop_][_interr] = {};
    controller[prop_][_condi] = {};
    controller[prop_][_or] = {_or, prop};
    controller[prop_][_and] = {_err};
    controller[prop_][_igual] = {_err};
    controller[prop_][_nigual] = {_err};
    controller[prop_][_not] = {_err};
    controller[prop_][_dparen] = {};
    controller[prop_][_iparen] = {_err};
    controller[prop_][_false] = {_err};
    controller[prop_][_true] = {_err};
    controller[prop_][_result] = {_err};
    controller[prop_][_of] = {};

    controller[clause][_ptcoma] = {_err};
    controller[clause][_id] = {equiv, clause_};
    controller[clause][_dospts] = {_err};
    controller[clause][_interr] = {_err};
    controller[clause][_condi] = {_err};
    controller[clause][_or] = {_err};
    controller[clause][_and] = {_err};
    controller[clause][_igual] = {_err};
    controller[clause][_nigual] = {_err};
    controller[clause][_not] = {equiv, clause_};
    controller[clause][_dparen] = {_err};
    controller[clause][_iparen] = {equiv, clause_};
    controller[clause][_false] = {equiv, clause_};
    controller[clause][_true] = {equiv, clause_};
    controller[clause][_result] = {_err};
    controller[clause][_of] = {_err};

    controller[clause_][_ptcoma] = {};
    controller[clause_][_id] = {_err};
    controller[clause_][_dospts] = {};
    controller[clause_][_interr] = {};
    controller[clause_][_condi] = {};
    controller[clause_][_or] = {};
    controller[clause_][_and] = {_and, clause};
    controller[clause_][_igual] = {_err};
    controller[clause_][_nigual] = {_err};
    controller[clause_][_not] = {_err};
    controller[clause_][_dparen] = {};
    controller[clause_][_iparen] = {_err};
    controller[clause_][_false] = {_err};
    controller[clause_][_true] = {_err};
    controller[clause_][_result] = {_err};
    controller[clause_][_of] = {};

    controller[equiv][_ptcoma] = {_err};
    controller[equiv][_id] = {atom, equiv_};
    controller[equiv][_dospts] = {_err};
    controller[equiv][_interr] = {_err};
    controller[equiv][_condi] = {_err};
    controller[equiv][_or] = {_err};
    controller[equiv][_and] = {_err};
    controller[equiv][_igual] = {_err};
    controller[equiv][_nigual] = {_err};
    controller[equiv][_not] = {atom, equiv_};
    controller[equiv][_dparen] = {_err};
    controller[equiv][_iparen] = {atom, equiv_};
    controller[equiv][_false] = {atom, equiv_};
    controller[equiv][_true] = {atom, equiv_};
    controller[equiv][_result] = {_err};
    controller[equiv][_of] = {_err};

    controller[equiv_][_ptcoma] = {};
    controller[equiv_][_id] = {_err};
    controller[equiv_][_dospts] = {};
    controller[equiv_][_interr] = {};
    controller[equiv_][_condi] = {};
    controller[equiv_][_or] = {};
    controller[equiv_][_and] = {};
    controller[equiv_][_igual] = {_igual, atom};
    controller[equiv_][_nigual] = {_nigual, atom};
    controller[equiv_][_not] = {_err};
    controller[equiv_][_dparen] = {};
    controller[equiv_][_iparen] = {_err};
    controller[equiv_][_false] = {_err};
    controller[equiv_][_true] = {_err};
    controller[equiv_][_result] = {_err};
    controller[equiv_][_of] = {};

    controller[atom][_ptcoma] = {_err};
    controller[atom][_id] = {_id};
    controller[atom][_dospts] = {_err};
    controller[atom][_interr] = {_err};
    controller[atom][_condi] = {_err};
    controller[atom][_or] = {_err};
    controller[atom][_and] = {_err};
    controller[atom][_igual] = {_err};
    controller[atom][_nigual] = {_err};
    controller[atom][_not] = {_not, atom};
    controller[atom][_dparen] = {_err};
    controller[atom][_iparen] = {_iparen, quest, _dparen};
    controller[atom][_false] = {_false};
    controller[atom][_true] = {_true};
    controller[atom][_result] = {_err};
    controller[atom][_of] = {_err};

    controller[output][_ptcoma] = {_err};
    controller[output][_id] = {_err};
    controller[output][_dospts] = {_err};
    controller[output][_interr] = {_err};
    controller[output][_condi] = {_err};
    controller[output][_or] = {_err};
    controller[output][_and] = {_err};
    controller[output][_igual] = {_err};
    controller[output][_nigual] = {_err};
    controller[output][_not] = {_err};
    controller[output][_dparen] = {_err};
    controller[output][_iparen] = {_err};
    controller[output][_false] = {_err};
    controller[output][_true] = {_err};
    controller[output][_result] = {_result, quest};
    controller[output][_of] = {_err};
}


bool parser::LL1(){

    stack pila;
    int x;

    int token = yylex();
    pila.push(stseq);

    do{
        
        x = pila.pop();

        if(x <= 100){
            if(x == token)  token = yylex();
                else return false;
        }
        
        production aux = controller[x][token];

        if(search(aux, _err)) return false;
            else insert(pila, aux);
        
    }while(!pila.empty());

    return (token == _of);
}

void parser::insert(stack &pila, production aux){

    for(auto rit = aux.crbegin(); rit != aux.crend(); rit++)
        pila.push(*rit);
}


bool parser::search(production a, int x){

    for(production::iterator it = a.begin(); it < a.end(); it++)
        return (x == *it) ? true: false;
}