// $Id$
/**
 * @file cPWM.cpp
 * Simple C++ class wrapper for beaglebone PWM eHRPWM interface
 *
 * @author claus
 *  Created on: Jun 13, 2012
 *      Author: claus http://quadrotordiaries.blogspot.com
 *
 */
// $Log$

///  Simple C++ class wrapper for beaglebone PWM eHRPWM interface

#include "cPWM.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace cPWM {


/**
 * This class wraps the PWMss of the beaglebone,
 * but it accesses the PWMss by means of the sysfs interface,
 * so probably other systems are supported as well.
 * The sysfs filenames are defined in cPWM.h.
 * The constructor just opens the sysfs files but doesn't write anything,
 * so in order to properly use the PWMss you need to follow all the steps
 * (frequency, period, polarity) before calling run.
 *
 * @param[in]	id	id of the PWMss to be initializaed. There are 3 of them, eHRPWM0 thru 2.
 * @return		a cPWM object
 *
 */
cPWM::cPWM(int id)
{
	///TODO: 	Add clock selection (mmap). By now you must use setPWMReg.py method
	///FIXME:	pin mux settings should be done here? or at a highet level?
	cPWM::id = id;

    std::stringstream sysfsfile_dutyA_ns;
    std::stringstream sysfsfile_dutyA_percent;

    std::stringstream sysfsfile_dutyB_ns;
    std::stringstream sysfsfile_dutyB_percent;

    std::stringstream sysfsfile_period_ns;
    std::stringstream sysfsfile_period_freq;

	std::stringstream sysfsfile_polarityA;
	std::stringstream sysfsfile_runA;
    std::stringstream sysfsfile_requestA;

    std::stringstream sysfsfile_polarityB;
	std::stringstream sysfsfile_runB;
	std::stringstream sysfsfile_requestB;

    sysfsfile_dutyA_ns << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_DUTY_NS;
    sysfsfile_dutyA_percent << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_DUTY_PERCENT;

    sysfsfile_dutyB_ns << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_DUTY_NS;
    sysfsfile_dutyB_percent << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_DUTY_PERCENT;

    sysfsfile_period_ns << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_PERIOD_NS;
    sysfsfile_period_freq << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_PERIOD_FREQ;

	sysfsfile_polarityA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_POLARITY;
	sysfsfile_runA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_RUN;
	sysfsfile_requestA << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_A << "/" << SYSFS_EHRPWM_REQUEST;

    sysfsfile_polarityB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_POLARITY;
	sysfsfile_runB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_RUN;
	sysfsfile_requestB << SYSFS_EHRPWM_PREFIX << id << SYSFS_EHRPWM_SUFFIX_B << "/" << SYSFS_EHRPWM_REQUEST;

    sysfsfid_dutyA_ns.open(sysfsfile_dutyA_ns.str().c_str());
    sysfsfid_dutyA_percent.open(sysfsfile_dutyA_percent.str().c_str());

    sysfsfid_dutyB_ns.open(sysfsfile_dutyB_ns.str().c_str());
    sysfsfid_dutyB_percent.open(sysfsfile_dutyB_percent.str().c_str());

    sysfsfid_period_ns.open(sysfsfile_period_ns.str().c_str());
    sysfsfid_period_freq.open(sysfsfile_period_freq.str().c_str());

	sysfsfid_polarityA.open(sysfsfile_polarityA.str().c_str());
	sysfsfid_runA.open(sysfsfile_runA.str().c_str());

    sysfsfid_requestA.open(sysfsfile_requestA.str().c_str());
	sysfsfid_polarityB.open(sysfsfile_polarityB.str().c_str());

    sysfsfid_runB.open(sysfsfile_runB.str().c_str());
	sysfsfid_requestB.open(sysfsfile_requestB.str().c_str());
}

/**
 * Set the duty cycle for A channel of the PWMss
 *
 * @param[in]	nanoseconds:	duty cycle time in nanoseconds for A channel
 *
 */
int cPWM::DutyA_ns(unsigned int nanoseconds)
{
        cPWM::DutyA_ns = nanoseconds;
        sysfsfid_dutyA_ns << nanoseconds << std::endl;
		return 1;
}

/**
 * Set the duty cycle for A channel of the PWMss
 *
 * @param[in]	percent:	duty cycle time in percent for A channel
 *
 */
int cPWM::DutyA_percent(int percent)
{
        cPWM::DutyA_percent = percent;
        sysfsfid_dutyA_percent << percent << std::endl;
        return 1;
}

/**
 * Set the duty cycle for B channel of the PWMss
 *
 * @param[in]	nanoseconds:	duty cycle time in nanoseconds for B channel
 *
 */
int cPWM::DutyB_ns(unsigned int nanoseconds)
{
        cPWM::dutyB_ns = nanoseconds;
        sysfsfid_dutyB_ns << nanoseconds << std::endl;
		return 1;
}


/**
 * Set the duty cycle for B channel of the PWMss
 *
 * @param[in]	percent:	duty cycle time in percent for B channel
 *
 */
int cPWM::DutyB_percent(unsigned int percent)
{
        cPWM::DutyB_percent = percent;
        sysfsfid_dutyB_percent << percent << std::endl;
        return 1;
}


/**
 * Set the period for the PWMss
 *
 * @param[in]	nanoseconds:	period time in nanoseconds
 *
 */
int cPWM::Period_ns(unsigned int nanoseconds)
{
        cPWM::Period_ns = nanoseconds;
        sysfsfid_period_ns << nanoseconds << std::endl;
		return 1;
}

/**
 * Set the period for the PWMss
 *
 * @param[in]	freq_Hz:	PWM frequency in Hz
 *
 */
int cPWM::Period_freq(unsigned int freq_Hz)
{
        cPWM::Period_freq = freq_Hz;
        sysfsfid_period_freq << freq_Hz<< std::endl;
        return 1;
}

/**
 * Set the polarity for the A channel of the PWMss
 *
 * @param[in]	polarity  polarity
 *
 */
int cPWM::PolarityA(Polarity polarity)
{
        switch (polarity)
        {
        case ActiveHigh:  sysfsfid_polarityA << 1 << std::endl;
                          break;
        case ActiveLow:   sysfsfid_polarityA << 0 << std::endl;
                          break;
        }
        cPWM::polarityA = polarity;

		return 1;
}

/**
 * Set the A channel to run status
 *
 *
 */
int cPWM::RunA()
{
	sysfsfid_runA << "1" << std::endl;
	cPWM::runA = 1;
	return 1;
}

/**
 * Stop the A channel
 *
 *
 */
int cPWM::StopA()
{
	sysfsfid_runA << "0" << std::endl;
	cPWM::runA = 0;
	return 1;
}

/**
 * Set the polarity for the B channel of the PWMss
 *
 * @param[in]	polarity  polarity
 *
 */
int cPWM::PolarityB(Polarity polarity)
{
    switch (polarity)
    {
    case ActiveHigh:  sysfsfid_polarityB << 1 << std::endl;
                      break;
    case ActiveLow:   sysfsfid_polarityB << 0 << std::endl;
                      break;
    }
    cPWM::polarityB = polarity;

    return 1;
}

/**
 * Set the B channel to run
 *
 */

int cPWM::RunB()
{
	cPWM::runB = 1;
	sysfsfid_runB << "1" << std::endl;
	return 1;
}

/**
 * Stop the B channel
 *
 */
int cPWM::StopB()
{
	cPWM::runB = 0;
	sysfsfid_runB << "0" << std::endl;
	return 1;
}

/**
 * cPWM Destructor, stops the PWMss
 *
 */
cPWM::~cPWM()
{
	sysfsfid_runA << "0" << std::endl;

	sysfsfid_runB << "0" << std::endl;
}

} /* namespace cPWM */
