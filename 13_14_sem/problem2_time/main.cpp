///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

/*
Describe the “Time” structure with three fields: hours, minutes
and seconds. Define a subtraction operation such that
the result is an object of type time containing
how much time is between the first and second event. If
the second event is later than the first, the answer should be equal to
zero, otherwise return a time structure containing the difference
between these events (hours, minutes, seconds).
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

struct Time {
    int hours, minutes, seconds;
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    static Time subtract(Time t1, Time t2) {
        int total_seconds_1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
        int total_seconds_2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

        int diff = std::max(0, total_seconds_1 - total_seconds_2);

        int hours = diff / 3600;
        diff %= 3600;
        int minutes = diff / 60;
        int seconds = diff % 60;

        return Time(hours, minutes, seconds);
    }

    void display() {
        std::cout << hours << "h:" << minutes << "m:" << seconds << "s\n";
    }
};

int main() {

    Time startTime(10, 30, 0);
    Time endTime(9, 45, 30);
    Time laterTime(11, 0, 0);

    Time diff = Time::subtract(startTime, endTime);
    std::cout << "Difference: ";
    diff.display();

    Time diff2 = Time::subtract(startTime, laterTime);
    std::cout << "Difference: ";
    diff2.display();

    return 0;
}