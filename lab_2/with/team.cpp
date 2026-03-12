#include "team.h"

Team::Team() : Entry() {}

void Team::init(const QStringList& parts) {
    qDebug() << "Team::init";
    if(parts.size() < 3) {
        qWarning() << "Match::init: not enough fields!";
        return;
    }

    setType(parseType(parts[0]));
    setId(parts[1].toInt());
    setName(parts[2]);
    for(int i = 3; i < parts.size(); ++i) {
        m_playerIds.insert(parts[i].toInt());
    }
}

QString Team::assemble() const {
    qDebug() << "Team::assemble";
    QStringList parts;

    parts.append(parseTypeToString(getType()));
    parts.append(QString::number(getId(), 10));
    parts.append(getName());
    for(const auto& playerId : m_playerIds) {
        parts.append(QString::number(playerId, 10));
    }

    return parts.join("\t");
}

void Team::setName(const QString& name) {
    qDebug() << "Team::setName";
    m_name = name;
}

QString Team::getName() const {
    qDebug() << "Team::getName";
    return m_name;
}

void Team::clear() {
    qDebug() << "Team::clear";
    m_players.clear();
}

std::size_t Team::size() const {
    qDebug() << "Team::size";
    return m_players.size();
}

void Team::addPlayer(const Player& player) {
    qDebug() << "Team::addPlayer";
    m_players.push_back(player);
}

std::optional<Player> Team::getPlayer(const int id) const {
    qDebug() << "Team::getPlayer";
    auto it = std::find_if(m_players.cbegin(), m_players.cend(), [id](const Player& player){ return player.getId() == id; });

    if(it != m_players.cend())
        return *it;
    qWarning() << "Team::getPlayer: not this player!";
    return std::nullopt;
}

QSet<int> Team::getPlayerIds() const {
    qDebug() << "Team::getPlayerIds";
    return m_playerIds;
}

std::vector<Player> Team::getPlayers() const {
    qDebug() << "Team::getPlayers";
    return m_players;
}
