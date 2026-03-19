#include "adapter.h"

Adapter::Adapter(AnalogClock* other) : DigitalClock(), m_analog{other} {
    qDebug() << "Adapter::Adapter";
}

void Adapter::setTime(const QString& timeData) {
    qDebug() << "Adapter::setTime(const QString&)";
    const QTime time = QTime::fromString(timeData, "hh:mm:ss");
    if (!time.isValid()) {
        qDebug() << "Invalid time format!";
        return;
    }

    m_analog->setMidnight(time.hour() < 12 ? true : false);
    m_analog->rotateSecondsHand(time.second() * 6);
    m_analog->rotateMinuteHand(time.minute() * 6);
    m_analog->rotateHourHand(time.hour() % 12 * 30);
}

void Adapter::setTime(const QTime& timeData) {
    qDebug() << "Adapter::setTime(const QString&)";
    if (!timeData.isValid()) {
        qDebug() << "Invalid time format!";
        return;
    }

    m_analog->setMidnight(timeData.hour() < 12 ? true : false);
    m_analog->rotateSecondsHand(timeData.second() * 6);
    m_analog->rotateMinuteHand(timeData.minute() * 6);
    m_analog->rotateHourHand(timeData.hour() % 12 * 30);
}

QTime Adapter::getTime() const {
    qDebug() << "Adapter::getTime";
    QTime result;

    const int seconds = m_analog->getSecongsAngle() / 6;
    const int minutes = m_analog->getMinutesAngle() / 6;
    const int hours = m_analog->getHoursAngle() / 30 + (!m_analog->getMidnight() ? 12 : 0);

    result = QTime(0,0,0).addSecs(hours * 3600 + minutes * 60 + seconds);
    return result;
}
