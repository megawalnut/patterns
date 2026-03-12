#ifndef TEAM_H
#define TEAM_H

#include "entry.h"
#include "player.h"

class Team : public Entry {
public:
    explicit Team();

    void init(const QStringList& partsOfEntry) override;
    QString assemble() const override;

    void setName(const QString& name);
    QString getName() const;
    void clear();
    std::size_t size() const;

    void addPlayer(const Player& player);
    std::optional<Player> getPlayer(const int id) const;
    QSet<int> getPlayerIds() const;
    std::vector<Player> getPlayers() const;
private:
    QString m_name;
    std::vector<Player> m_players;
    QSet<int> m_playerIds;
};

#endif // TEAM_H
