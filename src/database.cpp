#include "database.h"

Database::Database() {}

bool Database::open(const QString &path) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qWarning() << "❌ Impossible d'ouvrir la base de données:" << m_db.lastError().text();
        return false;
    }

    qDebug() << "✅ Base de données ouverte:" << path;
    return true;
}

bool Database::init() {
    QSqlQuery query;

    QString createTickets = R"(
        CREATE TABLE IF NOT EXISTS tickets (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            type TEXT NOT NULL,
            price REAL NOT NULL,
            created_at TEXT DEFAULT CURRENT_TIMESTAMP
        )
    )";

    if (!query.exec(createTickets)) {
        qWarning() << "Erreur création table tickets:" << query.lastError().text();
        return false;
    }

    QString createValidations = R"(
        CREATE TABLE IF NOT EXISTS validations (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            ticket_id INTEGER NOT NULL,
            validated_at TEXT DEFAULT CURRENT_TIMESTAMP,
            FOREIGN KEY(ticket_id) REFERENCES tickets(id)
        )
    )";

    if (!query.exec(createValidations)) {
        qWarning() << "Erreur création table validations:" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Tables créées / vérifiées avec succès.";
    return true;
}
