#include <cstdlib>
#include "chromosome.h"
#include "baseTM.h"
#include <iostream>

//srand(unsigned(0));

chromosome::chromosome(){
	_length=0;
	_fitness=0;
	_evaluated=false;
}
chromosome::chromosome(const int& l, TuringMachine* machine){
	do{
		_gene.clear();
		for(int i=0;i<l;i++)
			_gene.push_back(machine->getInst((int)( machine->getSetSize()*(double(rand())/RAND_MAX))));
	}while(!machine->qualify(_gene));
	
	_length=l;
	_fitness=0;
	_evaluated=false;
}
chromosome::chromosome(const string& s,TuringMachine* machine){
	_gene=s;
	_length=s.size();
	_fitness=0;
	_evaluated=false;
}
chromosome::~chromosome(){}

bool chromosome::cmp(chromosome a,chromosome b){return a._fitness>b._fitness;}

void chromosome::evaluate(TuringMachine* machine, string target){
	_fitness=0;
	machine->init(_gene,"");
	if(machine->run()>0){
		_output=machine->getOutput();
		for(unsigned i=0;i<target.size();i++){
			if(i>machine->getOutput().size())break;
			int tmp=target[i]-machine->getOutput()[i];
			if(tmp<0)tmp*=-1;
			_fitness+=256-tmp;
		}
		int tmp=target.size()-machine->getOutput().size();
		if(tmp<0)tmp*=-1;
		_fitness+=10*((double)target.size()-tmp)/target.size();
	}
	_evaluated=true;
}
bool chromosome::evaluated(){return _evaluated;} 
string chromosome::getGene(){return _gene;}
char chromosome::getVal(int index){return _gene[index];}
void chromosome::setVal(int index, char value){_gene[index]=value;}
int chromosome::getLength(){return _length;}
string chromosome::getInput(){return _input;}
string chromosome::getOutput(){return _output;}
double chromosome::getFit(){return _fitness;}






