#include "userdata.h"

#include <qobject.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qstandardpaths.h>
#include <qvariant.h>

#include <QDir>
#include <QSqlError>
#include <QStandardPaths>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <memory>

#include "note.h"
const static char* dbName = "userData.db";
const static char* resultTableName = "result";
const static char* noteTableName = "note";
std::unique_ptr<UserData> UserData::_instance;

void UserData::InsertResult(const ExerciseResult& res)
{
    QString path =
        QString("%1/%2").arg(QStandardPaths::standardLocations(QStandardPaths::AppDataLocation)[0]).arg(dbName);

    QSqlDatabase db = QSqlDatabase::addDatabase(path);

    for (int i = 0; i < res.goals.size(); i++)
    {
        int octave = res.goals[i].octave;
        int pitch = static_cast<int>(res.goals[i].pitch);
        int tries = res.tries[i].second;
        int time = res.tries[i].first;
        QSqlQuery query;
        query.prepare("INSERT INTO notes"
                      " (:note, :tries, :time)");
        query.bindValue(":note", pitch);
    }
}

UserData& UserData::instance()
{
    if (!_instance)
        _instance = std::unique_ptr<UserData>(new UserData());
    return *_instance;
}

UserData::UserData()
{
    createDB();
}
void UserData::createDB()
{
    QString path =
        // QString("%1/%2").arg(QStandardPaths::standardLocations(QStandardPaths::AppDataLocation)[0]).arg(dbName);
        QString("%1").arg(dbName);
    // if (QDir().exists(path))
    //     return;
    // QDir().mkpath(QStandardPaths::standardLocations(QStandardPaths::AppDataLocation)[0]);
    // std::cout << "db saved to " << path.toStdString() << std::endl;
    // QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // db.setDatabaseName(path);
    // db.open();

    // db.exec("create table result "
    //         "(id datetime primary key, "
    //         "noteId integer, "
    //         "tries integer, "
    //         "time integer)");
    // auto a = db.exec("create table note "
    //                  "(id integer primary key, "
    //                  "letter varchar, "
    //                  "octave integer, "
    //                  "accidental integer)");
    // std::cout << a.lastError().text().toStdString() << std::endl;
    int octave = 0;
    int note = (int)Pitch::A;

    int keys = 0;
    bool sharp = false;
    while (keys < 88)
    {
        Note n = Note::getNote(21 + keys);

        std::cout << "\t\t" << keys << ": " << n.getStr().toStdString() << std::endl;
    }
    // // db.commit();
}