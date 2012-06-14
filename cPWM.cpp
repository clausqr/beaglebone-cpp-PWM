/*
 * cPWM.cpp
 *
 *  Created on: Jun 13, 2012
 *      Author: claus
 *
 *  Simple c++ class wrapper for beaglebone PWM eHRPWM interface
 *
 */

#include "cPWM.h"
#include <iostream>
#include <fstream>
#include <sstream>

//using namespace std;

namespace cPWM {


//Constructor, n is the id of the PWMSS
cPWM::cPWM(int id)
{
	std::cout << "called cPWM constructor" << std::endl;
	cPWM::id = id;

	std::stringstream sysfsfile_dutyA;
	std::stringstream sysfsfile_dutyB;
	std::stringstream sysfsfile_period;
	std::stringstream sysfsfile_polarity;
	std::stringstream sysfsfile_run;
	std::stringstream sysfsfile_request;

	sysfsfile_dutyA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_DUTY;
	sysfsfile_dutyB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_DUTY;
	sysfsfile_period << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_PERIOD;
	sysfsfile_polarity << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_POLARITY;
	sysfsfile_run << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_RUN;
	sysfsfile_request << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_REQUEST;

	std::cout << "new PWM with id " << id << std::endl;
	std::cout << "using DutyA file " << sysfsfile_dutyA.str() << std::endl;
	std::cout << "using DutyB file " << sysfsfile_dutyB.str() << std::endl;
	std::cout << "using period file " << sysfsfile_period.str() << std::endl;
	std::cout << "using polarity file " << sysfsfile_polarity.str() << std::endl;
	std::cout << "using run file " << sysfsfile_run.str() << std::endl;
	std::cout << "using request file " << sysfsfile_request.str() << std::endl;

	sysfsfid_dutyA.open(sysfsfile_dutyA.str().c_str());
	sysfsfid_dutyB.open(sysfsfile_dutyB.str().c_str());
	sysfsfid_period.open(sysfsfile_period.str().c_str());
	sysfsfid_polarity.open(sysfsfile_polarity.str().c_str());
	sysfsfid_run.open(sysfsfile_run.str().c_str());
	sysfsfid_request.open(sysfsfile_request.str().c_str());


}

int cPWM::DutyA(int d)
{
		std::cout << "PWM"<< id << "A, duty cycle set to " << d << std::endl;
		cPWM::dutyA = d;
		sysfsfid_dutyA << d << std::endl;
		return 1;
	}
int cPWM::DutyB(int d)
{
		std::cout << "PWM"<< id << "B, duty cycle set to " << d << std::endl;
		cPWM::dutyB = d;
		sysfsfid_dutyB << d << std::endl;
		return 1;
	}


/*
 * Period in ns
 */
int cPWM::Period(int d)
{
		std::cout << "PWM"<< id << ", period set to " << d << std::endl;
		cPWM::period = d;
		sysfsfid_period << d << std::endl;
		return 1;
	}

int cPWM::Polarity(int d)
{
		std::cout << "PWM"<< id << ", polarity set to " << d << std::endl;
		cPWM::polarity = d;
		sysfsfid_polarity << d << std::endl;
		return 1;
	}

int cPWM::Run()
{
	std::cout << "PWM"<< id << " started" << std::endl;
	sysfsfid_run << "1" << std::endl;
	return 1;
}

int cPWM::Stop()
{
	std::cout << "PWM"<< id << " stopped" << std::endl;
	sysfsfid_run << "0" << std::endl;
	return 1;
}
cPWM::~cPWM()
{
	std::cout << "called cPWM destructor of cPWM " << id << std::endl;
}

} /* namespace cPWM */
