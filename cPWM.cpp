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
	///TODO: 	Add clock selection (mmap). By now you must use setPWMReg.py method
	///FIXME:	pin mux settings should be done here? or at a highet level?
	std::cout << "called cPWM constructor" << std::endl;
	cPWM::id = id;

	std::stringstream sysfsfile_dutyA;
	std::stringstream sysfsfile_dutyB;
	std::stringstream sysfsfile_period;
	std::stringstream sysfsfile_polarityA;
	std::stringstream sysfsfile_runA;
	std::stringstream sysfsfile_requestA;
	std::stringstream sysfsfile_polarityB;
	std::stringstream sysfsfile_runB;
	std::stringstream sysfsfile_requestB;

	sysfsfile_dutyA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_DUTY;
	sysfsfile_dutyB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_DUTY;
	sysfsfile_period << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_PERIOD;
	sysfsfile_polarityA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_POLARITY;
	sysfsfile_runA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_RUN;
	sysfsfile_requestA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_REQUEST;
	sysfsfile_polarityB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_POLARITY;
	sysfsfile_runB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_RUN;
	sysfsfile_requestB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_REQUEST;

	std::cout << "new PWM with id " << id << std::endl;
	std::cout << "using DutyA file " << sysfsfile_dutyA.str() << std::endl;
	std::cout << "using DutyB file " << sysfsfile_dutyB.str() << std::endl;
	std::cout << "using Period file " << sysfsfile_period.str() << std::endl;
	std::cout << "using PolarityA file " << sysfsfile_polarityA.str() << std::endl;
	std::cout << "using RunA file " << sysfsfile_runA.str() << std::endl;
	std::cout << "using RequestA file " << sysfsfile_requestA.str() << std::endl;
	std::cout << "using PolarityB file " << sysfsfile_polarityB.str() << std::endl;
	std::cout << "using RunB file " << sysfsfile_runB.str() << std::endl;
	std::cout << "using RequestB file " << sysfsfile_requestB.str() << std::endl;

	sysfsfid_dutyA.open(sysfsfile_dutyA.str().c_str());
	sysfsfid_dutyB.open(sysfsfile_dutyB.str().c_str());
	sysfsfid_period.open(sysfsfile_period.str().c_str());
	sysfsfid_polarityA.open(sysfsfile_polarityA.str().c_str());
	sysfsfid_runA.open(sysfsfile_runA.str().c_str());
	sysfsfid_requestA.open(sysfsfile_requestA.str().c_str());
	sysfsfid_polarityB.open(sysfsfile_polarityB.str().c_str());
	sysfsfid_runB.open(sysfsfile_runB.str().c_str());
	sysfsfid_requestB.open(sysfsfile_requestB.str().c_str());


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

int cPWM::PolarityA(int d)
{
		std::cout << "PWMA"<< id << ", polarity set to " << d << std::endl;
		cPWM::polarityA = d;
		sysfsfid_polarityA << d << std::endl;
		return 1;
	}

int cPWM::RunA()
{
	std::cout << "PWMA"<< id << " started" << std::endl;
	sysfsfid_runA << "1" << std::endl;
	cPWM::runA = 1;
	return 1;
}

int cPWM::StopA()
{
	std::cout << "PWMA"<< id << " stopped" << std::endl;
	sysfsfid_runA << "0" << std::endl;
	cPWM::runA = 0;
	return 1;
}

int cPWM::PolarityB(int d)
{
		std::cout << "PWMB"<< id << ", polarity set to " << d << std::endl;
		cPWM::polarityB = d;
		sysfsfid_polarityB << d << std::endl;
		return 1;
	}

int cPWM::RunB()
{
	std::cout << "PWMB"<< id << " started" << std::endl;
	cPWM::runB = 1;
	sysfsfid_runB << "1" << std::endl;
	return 1;
}

int cPWM::StopB()
{
	std::cout << "PWMB"<< id << " stopped" << std::endl;
	cPWM::runB = 0;
	sysfsfid_runB << "0" << std::endl;
	return 1;
}

cPWM::~cPWM()
{
	std::cout << "PWMA"<< id << " stopped" << std::endl;
	sysfsfid_runA << "0" << std::endl;
	std::cout << "PWMB"<< id << " stopped" << std::endl;
	sysfsfid_runB << "0" << std::endl;
	std::cout << "called cPWM destructor of cPWM " << id << std::endl;
}

} /* namespace cPWM */
