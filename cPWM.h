/*
 * cPWM.h
 *
 *  Created on: Jun 13, 2012
 *      Author: claus
 */

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
	int polarity;
	/*****************************************
ehrpwm.0:0
│   ├── duty_ns
│   ├── period_ns
│   ├── polarity
│   ├── request
│   ├── run
├── ehrpwm.0:1 -> ../../devices/platform/omap/ehrpwm.0/pwm/ehrpwm.0:1
│   ├── duty_ns
│   ├── period_ns
│   ├── polarity
│   ├── request
│   ├── run
	 *
std::stringstream sysfs_file;

	 */
		#define SYSFS_EHRPWM_PREFIX "/sys/class/pwm/ehrpwm."
		#define SYSFS_EHRPWM_SUFFIX_A ":0"
		#define SYSFS_EHRPWM_SUFFIX_B ":1"
		#define SYSFS_EHRPWM_DUTY "duty_ns"
		#define SYSFS_EHRPWM_PERIOD "period_ns"
		#define SYSFS_EHRPWM_POLARITY "polarity"
		#define SYSFS_EHRPWM_RUN "run"
		#define SYSFS_EHRPWM_REQUEST "request"

		std::ofstream sysfsfid_dutyA;
		std::ofstream sysfsfid_dutyB;
		std::ofstream sysfsfid_period;
		std::ofstream sysfsfid_polarity;
		std::ofstream sysfsfid_run;
		std::ofstream sysfsfid_request;


public:
	cPWM(int id);
	virtual ~cPWM();

	int DutyA(int d);
	int DutyB(int d);
	int Period(int d);
	int Polarity(int d);
	int Run();
	int Stop();
};

} /* namespace cPWM */
#endif /* CPWM_H_ */
