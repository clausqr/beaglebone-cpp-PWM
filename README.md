beaglebone-cpp-PWM
==================

beaglebone C++ wrapper for the PWM subsystem

This class wraps the PWM functionality of the beaglebone exposed through sysfs on 3.2+ kernels.

It should save you from writing to the filesystem, you can access the PWM subsystem using this class.

By now only eHRPWM is implemented, and you should follow all the steps described in http://processors.wiki.ti.com/index.php/AM335x_PWM_Driver%27s_Guide
for example:

cPWM p(1);            //initialize eHRPWM1

p.Period(20000000);   //set period to 20ms (the period is in ns)

p.DutyA(1500000);     //set duty cycle of eHRPWM1A pin to 1.5ms

p.RunA();            //go!


It also lacks the clock setup, and you should run the awesome setPWMReg.py from dwatts' http://www.gigamegablog.com/ prior to using this class, and configure the pin mux according to your liking.
I think the pin mux configuration is something wider than the PWM subsystem, so it's OK to do it this way.