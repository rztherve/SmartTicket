#include "ticket.h"

Ticket::Ticket(const QString &type, double price)
    : type(type), price(price) {}

bool Ticket::save(Database &db) {
    QSqlQuery query(db.db());
    query.prepare("INSERT INTO tickets (type, price) VALUES (:type, :price)");
    query.bindValue(":type", type);
    query.bindValue(":price", price);

    if (!query.exec()) {
        qWarning() << "Erreur lors de l'insertion du ticket:" << query.lastError().text();
        return false;
    }

    qDebug() << "🎫 Ticket inséré:" << type << "-" << price;
    return true;
}

QList<Ticket> Ticket::getAll(Database &db) {
    QList<Ticket> list;
    QSqlQuery query(db.db());
    query.prepare("SELECT id, type, price, created_at FROM tickets ORDER BY id DESC");

    if (!query.exec()) {
        qWarning() << "Erreur SELECT:" << query.lastError().text();
        return list;
    }

    while (query.next()) {
        Ticket t;
        t.id = query.value(0).toInt();
        t.type = query.value(1).toString();
        t.price = query.value(2).toDouble();
        t.createdAt = query.value(3).toString();
        list.append(t);
    }

    return list;
}
