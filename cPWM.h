// $Id$
/**
 * @file cPWM.h
 * Simple C++ class wrapper for beaglebone PWM eHRPWM interface header file
 *
 * @author claus
 *  Created on: Jun 13, 2012
 *      Author: claus http://quadrotordiaries.blogspot.com
 *
 */
// $Log$

#ifndef CPWM_H_
#define CPWM_H_

#include <fstream>

namespace cPWM {

class cPWM {
private:
    int id;
    int dutyA;
    int dutyB;
    int period;
    cPWM::Polarity polarityA;
    cPWM::Polarity polarityB;
    int runA;
    int runB;
    /*****************************************
	 *
	 * sysfs tree:
	 *
ehrpwm.0:0
│   ├── duty_ns
│   ├── period_ns
│   ├── polarity
│   ├── request
│   ├── run
├── ehrpwm.0:1 -> ../../devices/platform/omap/ehrpwm.0/pwm/ehrpwm.0:1
│   ├── duty_ns
│   ├── period_ns
│   ├── polarity
│   ├── request
│   ├── run
	 *
std::stringstream sysfs_file;

Define files to match sysfs tree:
	 */
		#define SYSFS_EHRPWM_PREFIX "/sys/class/pwm/ehrpwm."
		#define SYSFS_EHRPWM_SUFFIX_A ":0"
		#define SYSFS_EHRPWM_SUFFIX_B ":1"
        #define SYSFS_EHRPWM_DUTY_NS "duty_ns"
        #define SYSFS_EHRPWM_DUTY_PERCENT "duty_percent"
        #define SYSFS_EHRPWM_PERIOD_NS "period_ns"
        #define SYSFS_EHRPWM_PERIOD_FREQ "period_freq"
		#define SYSFS_EHRPWM_POLARITY "polarity"
		#define SYSFS_EHRPWM_RUN "run"
		#define SYSFS_EHRPWM_REQUEST "request"

        std::ofstream sysfsfid_dutyA_ns;
        std::ofstream sysfsfid_dutyA_percent;
        std::ofstream sysfsfid_dutyB_ns;
        std::ofstream sysfsfid_dutyB_percent;
        std::ofstream sysfsfid_period_ns;
        std::ofstream sysfsfid_period_freq;
		std::ofstream sysfsfid_polarityA;
		std::ofstream sysfsfid_runA;
		std::ofstream sysfsfid_requestA;
		std::ofstream sysfsfid_polarityB;
		std::ofstream sysfsfid_runB;
		std::ofstream sysfsfid_requestB;

public:
    enum Polarity
    {
        ActiveHigh,
        ActiveLow
    };

	cPWM(int id);
    virtual ~cPWM();

    void DutyA_ns(unsigned int nanoseconds);
    void DutyA_percent(unsigned int percent);  //TODO: check if floats are possible

    void DutyB_ns(unsigned int nanoseconds);
    void DutyB_percent(unsigned int percent); //TODO: check if floats are possible

    void Period_ns(unsigned int nanoseconds);
    void Period_freq(unsigned int freq_Hz);

    void PolarityA(cPWM::Polarity polarity);
    void RunA();
    void StopA();
    void PolarityB(cPWM::Polarity polarity);
    void RunB();
    void StopB();
};

} /* namespace cPWM */
#endif /* CPWM_H_ */
