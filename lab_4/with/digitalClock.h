#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QTime>

class DigitalClock {
public:
    virtual void setTime(const QString& timeData) = 0;
    virtual void setTime(const QTime& timeData) = 0;

    virtual QTime getTime() const = 0;

    virtual ~DigitalClock() = default;
};

#endif // DIGITALCLOCK_H
