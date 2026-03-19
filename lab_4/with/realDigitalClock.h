#ifndef REALDIGITALCLOCK_H
#define REALDIGITALCLOCK_H

#include "digitalClock.h"

class RealDigitalClock : public DigitalClock {
public:
    explicit RealDigitalClock() = default;

    void setTime(const QString& timeData) override;
    void setTime(const QTime& timeData) override;

    QTime getTime() const override;
private:
    QTime m_currentTime;
};

#endif // REALDIGITALCLOCK_H
