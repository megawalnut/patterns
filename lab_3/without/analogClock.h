#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QTime>

class AnalogClock {
public:
    explicit AnalogClock() = default;

    void rotateSecondsHand(const int degrees);
    void rotateMinuteHand(const int degrees);
    void rotateHourHand(const int degrees);

    int getSecongsAngle() const;
    int getMinutesAngle() const;
    int getHoursAngle() const;

    void setMidnight(const bool midnight);
    bool getMidnight() const;

private:
    int m_secondAngle = 0;
    int m_minuteAngle = 0;
    int m_hourAngle = 0;
    bool m_isMidnight = false;
};

#endif // ANALOGCLOCK_H
