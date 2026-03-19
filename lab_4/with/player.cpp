#include "player.h"

Player::Player() : Entry() {}

void Player::init(const QStringList& parts) {
    qDebug() << "Player::init";
    if(parts.size() < 4) {
        qWarning() << "Match::init: not enough fields!";
        return;
    }

    setType(parseType(parts[0]));
    setId(parts[1].toInt());
    setName(parts[2]);
    setTeam(parts[3].toInt());
}

QString Player::assemble() const {
    qDebug() << "Player::assemble";
    QStringList parts;

    parts.append(parseTypeToString(getType()));
    parts.append(QString::number(getId(), 10));
    parts.append(getName());
    parts.append(QString::number(getTeam(), 10));

    return parts.join("\t");
}

void Player::setName(const QString& name) {
    qDebug() << "Player::init";
    m_name = name;
}

QString Player::getName() const {
    qDebug() << "Player::getName";
    return m_name;
}

void Player::setTeam(const int id) {
    qDebug() << "Player::setTeam";
    m_teamId = id;
}

int Player::getTeam() const {
    qDebug() << "Player::getTeam";
    return m_teamId;
}
