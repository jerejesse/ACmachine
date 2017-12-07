#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <string>
#include "baseTM.h"

class chromosome{
public:
	chromosome();
	chromosome(const int&, TuringMachine*);
	chromosome(const string&, TuringMachine*);
	~chromosome();

	static bool cmp(chromosome, chromosome);

	void evaluate(TuringMachine*, string);
	bool evaluated();
	string getGene();
	char getVal(int);
	void setVal(int,char);
	int getLength();
	string getInput();
	string getOutput();
	double getFit();

private:
	string _gene;
	int _length;
	string _input;
	string _output;
	double _fitness;
	bool _evaluated;
};

#endif
