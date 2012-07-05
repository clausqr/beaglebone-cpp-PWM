// $Id$
/**
 * @file example.cpp
 * Example implementation of the Simple C++ class wrapper for beaglebone PWM eHRPWM interface
 *
 * @author claus
 *  Created on: Jun 13, 2012
 *      Author: claus http://quadrotordiaries.blogspot.com
 *
 */
// $Log$

///  Example implementation of the Simple C++ class wrapper for beaglebone PWM eHRPWM interface

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
	/*
	a[0]->Period(20000000);
	a[0]->DutyA(  1000000);
	a[0]->Polarity(1);
	a[0]->Run();
	usleep(100000);	//pausa de 0.1s=100,000us
	a[0]->DutyA( 1500000);
	a[0]->Stop();
	 */
	for (int i=0; i<3; i++)
	{
		//	delete(a[i]);
		a[i]->Period(20000000);
		//usleep(100000);	//pausa de 0.1s=100,000us
		a[i]->DutyA(  1000000);
		//usleep(100000);	//pausa de 0.1s=100,000us
		a[i]->DutyB(  1000000);
		//usleep(100000);	//pausa de 0.1s=100,000us
		a[i]->PolarityA(1);
		//usleep(100000);	//pausa de 0.1s=100,000us
		a[i]->RunA();
		//usleep(100000);	//pausa de 0.1s=100,000us
		a[i]->RunB();
		//usleep(100000);	//pausa de 0.1s=100,000us

	}
	usleep(10000000);
	for (int i=0; i<3; i++)
	{
		a[i]->StopA();
		a[i]->StopB();
		//usleep(100000);	//pausa de 0.1s=100,000us
	}

	return 0;

}

