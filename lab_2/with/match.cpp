#include "match.h"

Match::Match() {}

void Match::init(const QStringList& parts) {
    qDebug() << "Match::init";
    if(parts.size() < 7) {
        qWarning() << "Match::init: not enough fields!";
        return;
    }

    setType(parseType(parts[0]));
    setId(parts[1].toInt());
    setDate(QDateTime::fromString(parts[2], "yyyy-MM-dd HH:mm"));
    setLocation(parts[3]);
    setResult(parts[4]);
    setTeam1(parts[5].toInt());
    setTeam2(parts[6].toInt());
}

QString Match::assemble() const {
    qDebug() << "Match::assemble";
    QStringList parts;

    parts.append(parseTypeToString(getType()));
    parts.append(QString::number(getId(), 10));
    parts.append(m_dateTime.toString("yyyy-MM-dd HH:mm"));
    parts.append(m_location);
    parts.append(m_result);
    parts.append(QString::number(m_teamIds.first, 10));
    parts.append(QString::number(m_teamIds.second, 10));

    return parts.join("\t");
}

void Match::setDate(const QDateTime& date) {
    qDebug() << "Match::setDate";
    m_dateTime = date;
}

QDateTime Match::getDate() const {
    qDebug() << "Match::getDate";
    return m_dateTime;
}

void Match::setLocation(const QString& location) {
    qDebug() << "Match::setLocation";
    m_location = location;
}

QString Match::getLocation() const {
    qDebug() << "Match::getLocation";
    return m_location;
}

void Match::setResult(const QString& result) {
    qDebug() << "Match::setResult";
    m_result = result;
}

QString Match::getResult() const {
    qDebug() << "Match::getResult";
    return m_result;
}

void Match::setTeam1(const int team_id) {
    qDebug() << "Match::setTeam1";
    m_teamIds.first = team_id;
}

void Match::setTeam1(const Team& team) {
    qDebug() << "Match::setTeam1";
    m_team1 = team;
}

int Match::getTeam1() const {
    qDebug() << "Match::getTeam1";
    return m_teamIds.first;
}

void Match::setTeam2(const int team_id) {
    qDebug() << "Match::setTeam2";
    m_teamIds.second = team_id;
}

void Match::setTeam2(const Team&  team) {
    qDebug() << "Match::setTeam1";
    m_team2 = team;
}

int Match::getTeam2() const {
    qDebug() << "Match::getTeam2";
    return m_teamIds.second;
}
