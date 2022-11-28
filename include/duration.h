#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

class Duration
{
private:
    int time;
    int alarm;
    bool alarmHasBeenSet;
    bool checkAndUpdateAlarm();
public:
    Duration();
    Duration(int t);
    ~Duration();


    int getDuration();
    int getAlarm();
    bool checkAlarm();

    bool tick();
    
    bool tick(int t);

    void setAlarm(int t);

    
};







/*
Duration::Duration(args)
{
}

Duration::~Duration()
{
}*/
