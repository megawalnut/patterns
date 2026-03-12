#ifndef MATCH_H
#define MATCH_H

#include <QDateTime>

#include "team.h"

class Match : public Entry {
public:
    explicit Match();

    void init(const QStringList& partsOfEntry) override;
    QString assemble() const override;

    void setDate(const QDateTime& date);
    QDateTime getDate() const;
    void setLocation(const QString& location);
    QString getLocation() const;
    void setResult(const QString& result);
    QString getResult() const;

    void setTeam1(const int team_id);
    void setTeam1(const Team&  team);
    int getTeam1() const;
    void setTeam2(const Team&  team);
    void setTeam2(const int team_id);
    int getTeam2() const;
private:
    QDateTime m_dateTime = QDateTime::currentDateTime();
    QString m_location;
    QString m_result;
    Team m_team1;
    Team m_team2;
    std::pair<int, int> m_teamIds;
};

#endif // MATCH_H
