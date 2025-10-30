#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QList>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "database.h"

class Ticket {
public:
    int id;
    QString type;
    double price;
    QString createdAt;

    Ticket() : id(0), price(0.0) {}
    Ticket(const QString &type, double price);

    bool save(Database &db);
    static QList<Ticket> getAll(Database &db);
};

#endif // TICKET_H
