#include "analogClock.h"

void AnalogClock::rotateSecondsHand(int degrees) {
    qDebug() << "AnalogClock::rotateSecondsHand";
    m_secondAngle = degrees;
}

void AnalogClock::rotateMinuteHand(int degrees) {
    qDebug() << "AnalogClock::rotateMinuteHand";
    m_minuteAngle = degrees;
}

void AnalogClock::rotateHourHand(int degrees) {
    qDebug() << "AnalogClock::rotateHourHand";
    m_hourAngle = degrees;
}

int AnalogClock::getSecongsAngle() const {
    qDebug() << "AnalogClock::getSecongsAngle";
    return m_secondAngle;
}

int AnalogClock::getMinutesAngle() const {
    qDebug() << "AnalogClock::getMinutesAngle";
    return m_minuteAngle;
}

int AnalogClock::getHoursAngle() const {
    qDebug() << "AnalogClock::getHoursAngle";
    return m_hourAngle;
}

void AnalogClock::setMidnight(const bool midnight) {
    qDebug() << "AnalogClock::setMidnight";
    m_isMidnight = midnight;
}

bool AnalogClock::getMidnight() const {
    qDebug() << "AnalogClock::getMidnight";
    return m_isMidnight;
}
