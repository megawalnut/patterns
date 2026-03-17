#include <QObject>

#include "analogClock.h"
#include "realDigitalClock.h"

void convertTimeToAngle(AnalogClock& clock, const QString& timeData) {
    qDebug() << "Main::convertTimeToAngle";

    const QTime time = QTime::fromString(timeData);
    if (!time.isValid()) {
        qDebug() << "Invalid time format!";
        return;
    }

    clock.setMidnight(time.hour() < 12 ? true : false);
    clock.rotateSecondsHand(time.second() * 6);
    clock.rotateMinuteHand(time.minute() * 6);
    clock.rotateHourHand(time.hour() % 12 * 30);
}

QTime convertTimeFromAngle(const AnalogClock& clock) {
    qDebug() << "Main::convertTimeFromAngle";
    QTime result;

    const int seconds = clock.getSecongsAngle() / 6;
    const int minutes = clock.getMinutesAngle() / 6;
    const int hours = clock.getHoursAngle() / 30 + (!clock.getMidnight() ? 12 : 0);

    result = QTime(0,0,0).addSecs(hours * 3600 + minutes * 60 + seconds);
    return result;
}

int main(int argc, char *argv[]) {
    Q_UNUSED(argc); Q_UNUSED(argv);

    //Creating real digital clock
    RealDigitalClock realDigital{};
    realDigital.setTime("23:11:08");

    //Creating analog clock
    AnalogClock baseClock;
    convertTimeToAngle(baseClock, "23:11:08");

    QString str1 = realDigital.getTime().toString();
    QString str2 = convertTimeFromAngle(baseClock).toString();

    qDebug() << QString("DigitalClock - %1 ").arg(str1);
    qDebug() << QString("AnalogClock  - %1 (without Adapter)").arg(str2);

    return 0;
}
