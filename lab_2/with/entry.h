#ifndef ENTRY_H
#define ENTRY_H

#include <QDebug>
#include <QStringList>

#include "types.h"

// The base class for all types(Player, Match, Team)

class Entry {
public:
    explicit Entry() = default;
    virtual ~Entry() = default;

    virtual void init(const QStringList& partsOfEntry) {}
    virtual QString assemble() const { return QString{}; }

    void setId(const int id) {
        qDebug() << "Entry::setId";
        m_id = id;
    }

    int getId() const {
        qDebug() << "Entry::getId";
        return m_id;
    }

    void setType(const Types type) {
        qDebug() << "Entry::setType";
        m_type = type;
    }

    Types getType() const {
        qDebug() << "Entry::getType";
        return m_type;
    }
private:
    int m_id = 0; //base id
    Types m_type = Types::Type_Unknown;  //base type
};

#endif // ENTRY_H

