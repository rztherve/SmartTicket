#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

class Database {
public:
    Database();
    bool open(const QString &path);
    bool init();
    QSqlDatabase db() const { return m_db; }

private:
    QSqlDatabase m_db;
};

#endif // DATABASE_H
