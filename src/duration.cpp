#include "duration.h"

/* Constructor */
Duration::Duration() {
    time = 0;
    alarm = 0;
    alarmHasBeenSet = false;
}

/* Contructor with given time */
Duration::Duration(int t) {
    assert(t >= 0);
    alarm = 0;
    alarmHasBeenSet = false;
    time = t;
}

/* Checks time */
int Duration::getDuration() {
    return time;
}

/* Checks alarm */
int Duration::getAlarm() {
    return alarm;
}

/* Checks if alarm has been set */
bool Duration::checkAlarm() {
    return alarmHasBeenSet;
}

/* Add 1 to time */
bool Duration::tick() {
    time++;
    return checkAndUpdateAlarm();
}

/* Add given number to time */
bool Duration::tick(int t) {
    assert(t > 0);
    time += t;
    return checkAndUpdateAlarm();
}

/* Set alarm */
void Duration::setAlarm(int t) {
    assert(t > time);
    alarm = t;
    alarmHasBeenSet = true;
}

/* Checks and resets alarm if necessary */
bool Duration::checkAndUpdateAlarm() {
    if(alarmHasBeenSet == false) {
        return false;
    } else {
        if(time >= alarm) {
            alarm = 0;
            alarmHasBeenSet = false;
            return true;
        } else {
            return false;
        }
    }
}





