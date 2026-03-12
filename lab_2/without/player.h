#ifndef PLAYER_H
#define PLAYER_H

#include "entry.h"

class Team;    //forward declaration

class Player : public Entry {
public:
    explicit Player();

    void init(const QStringList& partsOfEntry) override;
    QString assemble() const override;

    void setName(const QString& name);
    QString getName() const;
    void setTeam(const int team_id);
    int getTeam() const;
private:
    QString m_name;
    int m_teamId = 0;     // base id

};

#endif // PLAYER_H
