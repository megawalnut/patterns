#ifndef REALDIGITALCLOCK_H
#define REALDIGITALCLOCK_H

#include <QTime>

class RealDigitalClock {
public:
    explicit RealDigitalClock() = default;

    void setTime(const QString& timeData);
    void setTime(const QTime& timeData);

    QTime getTime() const;
private:
    QTime m_currentTime;
};

#endif // REALDIGITALCLOCK_H
