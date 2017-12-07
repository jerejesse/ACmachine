
#ifndef BRAIN_PLUS
#define BRAIN_PLUS

#include <string>
#include <stack>
#include "baseTM.h"

class brainPlus :public TuringMachine{
public:
	brainPlus(string inst);
	~brainPlus(){}
	
	void specificInit();
	int instExec(string&, string&, int&, int&, string&, int&, string&);
	bool qualify(string&);
	char _storage;
	stack<int> _stack;
};


#endif
