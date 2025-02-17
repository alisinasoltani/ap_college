#include "DatabaseManager.h"
#include <QSqlRecord>
#include <QCoreApplication>
#include <QDir>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir(QCoreApplication::applicationDirPath()).filePath("cobitex.db");

    qDebug() << "Absolute database path:" << QDir(dbPath).absolutePath();
    m_db.setDatabaseName(dbPath);
}

DatabaseManager::~DatabaseManager() {
    if(m_db.isOpen()) m_db.close();
}

bool DatabaseManager::initializeDatabase() {
    if (!m_db.open()) {
        qCritical() << "Database error:" << m_db.lastError();
        return false;
    }
    QFileInfo dbFile(m_db.databaseName());
    qDebug() << "Database permissions:"
             << "Read:" << dbFile.isReadable()
             << "Write:" << dbFile.isWritable();
    QSqlQuery query;
    return query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username VARCHAR(12) NOT NULL,"
        "pass VARCHAR(12) NOT NULL,"
        "created_at DATETIME DEFAULT CURRENT_TIMESTAMP,"
        "role INTEGER DEFAULT 0,"
        "invitation_code VARCHAR(15) NOT NULL,"
        "invite_count INTEGER DEFAULT 0,"
        "invited_by VARCHAR(15),"
        "birthday DATETIME,"
        "national_code VARCHAR(10),"
        "email VARCHAR(50) NOT NULL,"
        "email_verified INTEGER DEFAULT 0)"
    );
}

QJsonObject DatabaseManager::createUser(const QJsonObject &userData) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO users (username, pass, invitation_code, email) "
        "VALUES (:username, :pass, :invitation_code, :email)"
    );

    query.bindValue(":username", userData["username"].toString());
    query.bindValue(":pass", userData["password"].toString());
    query.bindValue(":invitation_code", userData["invitation_code"].toString());
    query.bindValue(":email", userData["email"].toString());

    if(!query.exec()) {
        return {{"error", query.lastError().text()}};
    }

    return {{"id", query.lastInsertId().toInt()}, {"status", "created"}};
}

QJsonObject DatabaseManager::getUser(int userId) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE id = ?");
    query.addBindValue(userId);

    qDebug() << "Executing query:" << query.lastQuery();
    qDebug() << "Bound values:" << query.boundValues();

    if(!query.exec()) {
        qCritical() << "Query failed:" << query.lastError().text();
        return {{"error", "Database error"}};
    }

    if(!query.next()) {
        qDebug() << "No results for ID:" << userId;
        return {{"error", "User not found"}};
    }

    qDebug() << "Found user with ID:" << userId;

    QJsonObject user;
    for(int i=0; i<query.record().count(); i++) {
        user[query.record().fieldName(i)] = QJsonValue::fromVariant(query.value(i));
    }
    return user;
}

QJsonObject DatabaseManager::updateUser(int userId, const QJsonObject &userData) {
    QSqlQuery query;
    QStringList updates;
    QMap<QString, QVariant> bindValues;

    for(auto it = userData.begin(); it != userData.end(); ++it) {
        updates << QString("%1 = :%1").arg(it.key());
        bindValues[":"+it.key()] = it->toVariant();
    }

    query.prepare(QString("UPDATE users SET %1 WHERE id = :id").arg(updates.join(", ")));
    query.bindValue(":id", userId);

    for(auto it = bindValues.begin(); it != bindValues.end(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if(!query.exec()) {
        return {{"error", query.lastError().text()}};
    }
    return {{"status", "updated"}, {"affected_rows", query.numRowsAffected()}};
}

bool DatabaseManager::deleteUser(int userId) {
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (!query.exec()) {
        qCritical() << "Delete failed:" << query.lastError().text();
        return false;
    }

    qDebug() << "Rows affected by DELETE:" << query.numRowsAffected();
    return (query.numRowsAffected() > 0);
}

QJsonObject DatabaseManager::createOrder(const QJsonObject &orderData) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO orders (user_id, currency, type, created_at, accepted, sender, receiver) "
        "VALUES (:user_id, :currency, :type, :created_at, :accepted, :sender, :receiver)"
        );

    query.bindValue(":user_id", orderData["user_id"].toInt());
    query.bindValue(":currency", orderData["currency"].toString());
    query.bindValue(":type", orderData["type"].toString());
    query.bindValue(":created_at", QDateTime::currentDateTime());
    query.bindValue(":accepted", orderData["accepted"].toInt());
    query.bindValue(":sender", orderData["sender"].toString());
    query.bindValue(":receiver", orderData["receiver"].toString());

    if(!query.exec()) {
        return {{"error", query.lastError().text()}};
    }

    return {{"id", query.lastInsertId().toInt()}, {"status", "order_created"}};
}

QJsonObject DatabaseManager::getOrder(int orderId) {
    QSqlQuery query;
    query.prepare("SELECT * FROM orders WHERE id = ?");
    query.addBindValue(orderId);

    if(!query.exec() || !query.next()) {
        return {{"error", "Order not found"}};
    }

    QJsonObject order;
    QSqlRecord record = query.record();
    for(int i = 0; i < record.count(); i++) {
        order[record.fieldName(i)] = QJsonValue::fromVariant(query.value(i));
    }
    return order;
}

bool DatabaseManager::deleteOrder(int orderId) {
    QSqlQuery query;
    query.prepare("DELETE FROM orders WHERE id = ?");
    query.addBindValue(orderId);
    return query.exec();
}

QJsonObject DatabaseManager::createRequest(const QJsonObject &requestData) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO requests (user_id, birthday, national_code) "
        "VALUES (:user_id, :birthday, :national_code)"
        );

    query.bindValue(":user_id", requestData["user_id"].toInt());
    query.bindValue(":birthday", requestData["birthday"].toString());
    query.bindValue(":national_code", requestData["national_code"].toInt());

    if(!query.exec()) {
        return {{"error", query.lastError().text()}};
    }
    return {{"id", query.lastInsertId().toInt()}};
}

QJsonObject DatabaseManager::getRequest(int requestId) {
    QSqlQuery query;
    query.prepare("SELECT * FROM requests WHERE id = ?");
    query.addBindValue(requestId);

    if(!query.exec() || !query.next()) {
        return {{"error", "Request not found"}};
    }

    QJsonObject request;
    QSqlRecord record = query.record();
    for(int i = 0; i < record.count(); i++) {
        request[record.fieldName(i)] = QJsonValue::fromVariant(query.value(i));
    }
    return request;
}

bool DatabaseManager::deleteRequest(int requestId) {
    QSqlQuery query;
    query.prepare("DELETE FROM requests WHERE id = ?");
    query.addBindValue(requestId);
    return query.exec();
}

QJsonObject DatabaseManager::createWallet(const QJsonObject &walletData) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO wallets (user_id, safe_word, created_at, public_add, currencies) "
        "VALUES (:user_id, :safe_word, :created_at, :public_add, :currencies)"
        );

    query.bindValue(":user_id", walletData["user_id"].toInt());
    query.bindValue(":safe_word", walletData["safe_word"].toString());
    query.bindValue(":created_at", QDateTime::currentDateTime());
    query.bindValue(":public_add", walletData["public_add"].toString());
    query.bindValue(":currencies", walletData["currencies"].toString());

    if(!query.exec()) {
        return {{"error", query.lastError().text()}};
    }
    return {{"id", query.lastInsertId().toInt()}};
}

QJsonObject DatabaseManager::getWallet(int walletId) {
    QSqlQuery query;
    query.prepare("SELECT * FROM wallets WHERE id = ?");
    query.addBindValue(walletId);

    if(!query.exec() || !query.next()) {
        return {{"error", "Wallet not found"}};
    }

    QJsonObject wallet;
    QSqlRecord record = query.record();
    for(int i = 0; i < record.count(); i++) {
        wallet[record.fieldName(i)] = QJsonValue::fromVariant(query.value(i));
    }
    return wallet;
}

QJsonObject DatabaseManager::updateWallet(int walletId, const QJsonObject &walletData) {
    QSqlQuery query;
    QStringList updates;
    QMap<QString, QVariant> bindValues;

    for(auto it = walletData.begin(); it != walletData.end(); ++it) {
        updates << QString("%1 = :%1").arg(it.key());
        bindValues[":" + it.key()] = it->toVariant();
    }

    query.prepare(QString("UPDATE wallets SET %1 WHERE id = :id").arg(updates.join(", ")));
    query.bindValue(":id", walletId);

    for(auto it = bindValues.begin(); it != bindValues.end(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if(!query.exec()) {
        return {{"error", query.lastError().text()}};
    }
    return {{"status", "updated"}, {"affected_rows", query.numRowsAffected()}};
}

bool DatabaseManager::deleteWallet(int walletId) {
    QSqlQuery query;
    query.prepare("DELETE FROM wallets WHERE id = ?");
    query.addBindValue(walletId);
    return query.exec();
}
