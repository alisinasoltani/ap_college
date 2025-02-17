#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonObject>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();
    // Users
    bool initializeDatabase();
    QJsonObject createUser(const QJsonObject &userData);
    QJsonObject getUser(int userId);
    QJsonObject updateUser(int userId, const QJsonObject &userData);
    bool deleteUser(int userId);

    // Orders
    QJsonObject createOrder(const QJsonObject &orderData);
    QJsonObject getOrder(int orderId);
    QJsonObject updateOrder(int orderId, const QJsonObject &orderData);
    bool deleteOrder(int orderId);

    // Requests
    QJsonObject createRequest(const QJsonObject &requestData);
    QJsonObject getRequest(int requestId);
    bool deleteRequest(int requestId);

    // Wallets
    QJsonObject createWallet(const QJsonObject &walletData);
    QJsonObject getWallet(int walletId);
    QJsonObject updateWallet(int walletId, const QJsonObject &walletData);
    bool deleteWallet(int walletId);
private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
