#include <QObject>

#include "adapter.h"
#include "realDigitalClock.h"

int main(int argc, char *argv[]) {
    Q_UNUSED(argc); Q_UNUSED(argv);

    //Creating real digital clock
    DigitalClock* realDigital = new RealDigitalClock();
    realDigital->setTime("12:10:18");

    //Creating analog clock
    AnalogClock* analog = new AnalogClock();
    DigitalClock* analogDigitalClock = new Adapter(analog);
    analogDigitalClock->setTime("12:10:18");

    QString str1 = realDigital->getTime().toString();
    QString str2 = analogDigitalClock->getTime().toString();

    qDebug() << QString("DigitalClock - %1 ").arg(str1);
    qDebug() << QString("AnalogClock  - %1 (Adapter)").arg(str2);

    delete analogDigitalClock;
    delete analog;

    return 0;
}
