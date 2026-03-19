#ifndef ADAPTER_H
#define ADAPTER_H

#include "digitalClock.h"
#include "analogClock.h"

class Adapter : public DigitalClock {
public:
    explicit Adapter(AnalogClock* other);

    void setTime(const QString& timeData) override;
    void setTime(const QTime& timeData) override;

    QTime getTime() const override;
private:
    AnalogClock* m_analog;
};

#endif // ADAPTER_H
