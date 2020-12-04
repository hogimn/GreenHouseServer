#ifndef __MDS2450_MG995__
#define __MDS2450_MG995__

struct pwm_duty_t 
{
    int pulse_width; // nsec
    int period;      // nsec
};

#define MG995_PWM_IOCTL_MAGIC 'p'
#define MG995_PWM_PERIOD       20000000
#define MG995_PWM_DEGREE_0     400000
#define MG995_PWM_DEGREE_45    900000
#define MG995_PWM_DEGREE_90    1450000
#define MG995_PWM_DEGREE_135   1950000
#define MG995_PWM_DEGREE_180   2400000

#define MG995_PWM_ENABLE   _IO(MG995_PWM_IOCTL_MAGIC, 0)
#define MG995_PWM_DISABLE  _IO(MG995_PWM_IOCTL_MAGIC, 1)
#define MG995_PWM_DUTYRATE _IOW(MG995_PWM_IOCTL_MAGIC, 2, struct pwm_duty_t)
#define MG995_PWM_IOCTL_MAXNR 3

#define MG995_PWM_PATH "/dev/mds2450_mg995"

#endif