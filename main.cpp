/*
 * main.cpp
 *
 *  Created on: Jun 13, 2012
 *      Author: claus
 *
  */
#include "cPWM.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello Beagle!" << endl;

	cPWM::cPWM* a[3];

	for (int i=0; i<3; i++)
	{
		a[i] = new cPWM::cPWM(i);
	}

	a[0]->DutyA(100);
	a[0]->DutyB(150);
	a[0]->Period(120);
	a[0]->Polarity(1);
	a[0]->Run();
	a[0]->DutyB(160);
	a[0]->DutyA(231);
	a[0]->Stop();
	for (int i=0; i<3; i++)
	{
		delete(a[i]);
	}

	return 0;

}

