/*
 * main.cpp
 *
 *  Created on: Jun 13, 2012
 *      Author: claus
 *
  */
#include "cPWM.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	cout << "Hello Beagle!" << endl;

	cPWM::cPWM* a[3];

	for (int i=0; i<3; i++)
	{
		a[i] = new cPWM::cPWM(i);
	}

	a[0]->Period(20000000);
	a[0]->DutyA(  1000000);
	a[0]->Polarity(1);
	a[0]->Run();
	usleep(100000);	//pausa de 0.1s=100,000us
	a[0]->DutyA( 1500000);
	a[0]->Stop();
	for (int i=0; i<3; i++)
	{
		delete(a[i]);
	}

	return 0;

}

