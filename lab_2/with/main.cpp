#include <QFile>

#include "utils.h"

int main(int argc, char *argv[]) {
    Q_UNUSED(argc); Q_UNUSED(argv);
    qDebug() << "Main::main";

    std::multimap<Types, Entry*> entries;
    std::vector<Player> players;
    std::vector<Team> teams;

    std::vector<QString> fileTolines;
    QString filePath("/home/mikhail/projs/pattern/lab_2/in.tsv");
    std::vector<QStringList> parts = fromFile(filePath, fileTolines);

    for(const auto& part : parts) {
        if(part.isEmpty()) {
            qDebug() << "Main::main::Part is empty!";
            continue;
        }

        Types type = parseType(part[0]);
        Entry* entry = createConcreteClass(type);
        if(entry) {
            entry->init(part);
            entries.insert({type, entry});
        }
        if(type == Types::Type_Player) {
            players.push_back(*static_cast<Player*>(entry));
        }
        if(type == Types::Type_Team) {
            teams.push_back(*static_cast<Team*>(entry));
        }
    }

    for(const auto& [key, value]: entries) {
        if(key != Types::Type_Team)
            continue;
        Team* team = static_cast<Team*>(value);
        QSet<int> ids = team->getPlayerIds();
        for (const auto& p : players) {
            auto it = std::find_if(ids.cbegin(), ids.cend(), [&p](const int id){ return p.getId() == id; });
            if(it == ids.cend()) {
                qWarning() << QString("Main::main::Cannot find player with id %1").arg(p.getId());
            }
            team->addPlayer(p);
        }
    }

    for(const auto& [key, value]: entries) {
        if(key != Types::Type_Match)
            continue;
        Match* match = static_cast<Match*>(value);

        int team1 = match->getTeam1();
        auto it1 = std::find_if(teams.cbegin(), teams.cend(), [team1](const Team& t){ return team1 == t.getId(); });
        if(it1 == teams.cend()) {
            qWarning() << QString("Main::main::Cannot find team with id %1").arg(team1);
        }
        match->setTeam1(*it1);

        int team2 = match->getTeam2();
        auto it2 = std::find_if(teams.cbegin(), teams.cend(), [team2](const Team& t){ return team2 == t.getId(); });
        if(it2 == teams.cend()) {
            qWarning() << QString("Main::main::Cannot find team with id %1").arg(team2);
        }
        match->setTeam1(*it2);
    }

    filePath = "/home/mikhail/projs/pattern/lab_2/ou.tsv";
    std::vector<QString> etriesToFile;

    for(const auto& entry : entries) {
        etriesToFile.emplace_back(entry.second->assemble());
    }

    bool ok = toFile(filePath, etriesToFile);
    if(!ok) {
        qWarning() << "Main::Failed load to file";
        for(const auto& [key, value]: entries)
            delete value;
        return 1;
    }

    qDebug() << "Main::main::Success!";
    for(const auto& [key, value]: entries)
        delete value;

    qDebug() << "fileTolines";
    for(const auto& l : fileTolines) {
        qDebug() << l;
    }

    qDebug() << "etriesToFile";
    for(const auto& l : etriesToFile) {
        qDebug() << l;
    }

    return 0;
}
