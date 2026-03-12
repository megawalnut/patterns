#ifndef UTILS_H
#define UTILS_H

#include <QMap>
#include <QFile>

#include "types.h"
#include "player.h"
#include "team.h"
#include "match.h"


static inline Entry* createConcreteClass(const Types type) {
    qDebug() << "Utils::createConcreteClass";
    static const QMap<Types, std::function<Entry*()>> mapCreating {
        {Types::Type_Player, []() { return new Player{}; }},
        {Types::Type_Team,   []() { return new Team{};   }},
        {Types::Type_Match,  []() { return new Match{};  }}
    };
    if(!mapCreating.contains(type)) {
        qWarning() << "Cannot find this type!";
        return nullptr;
    }
    return mapCreating[type]();
}

std::vector<QStringList> fromFile(QString filePath, std::vector<QString>& fileTolines) {
    qDebug() << "Utils::fromFile";
    std::vector<QStringList> entries;
    QFile file(filePath);
    QTextStream in(&file);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Utils::fromFile::Cannot open file " << file.fileName();
        file.close();
        return entries;
    }

    while(!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if(line.isEmpty()) {
            qDebug() << "Utils::fromFile::Line is empty!";
            continue;
        };
        fileTolines.push_back(line);

        QStringList parts = line.split("\t");
        entries.push_back(parts);
    }
    file.close();
    return entries;
}

bool toFile(QString filePath, const std::vector<QString>& entries) {
    qDebug() << "Utils::toFile";
    QFile file(filePath);
    QTextStream out(&file);

    if(!file.open(QFile::WriteOnly | QFile::Truncate)) {
        qDebug() << "Utils::toFile::Cannot open file " << file.fileName();
        file.close();
        return false;
    }

    for(const auto& entry : entries)
        out << entry << "\n";
    file.close();
    return true;
}

#endif // UTILS_H
