#include "realDigitalClock.h"

void RealDigitalClock::setTime(const QString& timeData) {
    qDebug() << "RealDigitalClock::setTime(const QString&)";
    QTime t = QTime::fromString(timeData, "hh:mm:ss");
    if (!t.isValid()) {
        qDebug() << "Invalid time format!";
        return;
    }
    m_currentTime = t;
}

void RealDigitalClock::setTime(const QTime& timeData) {
    qDebug() << "RealDigitalClock::setTime(const QTime&)";
    if (!timeData.isValid()) {
        qDebug() << "Invalid time format!";
        return;
    }
    m_currentTime = timeData;
}

QTime RealDigitalClock::getTime() const {
    qDebug() << "RealDigitalClock::getTime";
    return m_currentTime;
}
