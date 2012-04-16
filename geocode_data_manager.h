#ifndef GEOCODE_DATA_MANAGER_H
#define GEOCODE_DATA_MANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>


class GeocodeDataManager : public QObject
{
    Q_OBJECT
public:
    explicit GeocodeDataManager(QObject *parent = 0);

    void getCoordinates(const QString& address);

signals:
    void errorOccured(const QString&);
    void coordinatesReady(double east, double north);

private slots:
    void replyFinished(QNetworkReply* reply);

private:
    QNetworkAccessManager* m_pNetworkAccessManager;


};

#endif // GEOCODE_DATA_MANAGER_H
