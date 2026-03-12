#ifndef TYPES_H
#define TYPES_H

#include <QString>
#include <QDebug>

enum Types : int {
    Type_Unknown = 0,
    Type_Player,
    Type_Team,
    Type_Match
};

static inline Types parseType(const QString& type) {
    qDebug() << "Utils::parseType";
    static const QMap<QString, Types> mapTypes {
        {"player", Types::Type_Player},
        {"team",   Types::Type_Team},
        {"match",  Types::Type_Match}
    };
    return mapTypes.value(type.toLower(), Types::Type_Unknown);
}

static inline QString parseTypeToString(const Types type) {
    qDebug() << "Utils::parseType";
    static const QMap<Types, QString> mapTypes {
        {Types::Type_Player, "player"},
        {Types::Type_Team, "team"},
        {Types::Type_Match, "match"}
    };
    return mapTypes.value(type, "unknown");
}

#endif // TYPES_H
