#ifndef PASTEBIN_H
#define PASTEBIN_H

#include <QtCore/QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QList>

#include "PasteUser.h"
#include "PasteListing.h"

class QXmlStreamReader;

class Pastebin : public QObject {
    Q_OBJECT
public:
    explicit Pastebin(QObject *parent=0);
    virtual ~Pastebin();

    void login(const QString& username, const QString& password);

    void submitPaste(const QString& pasteContent, const QString& pasteTitle, const QString& format, const QString& expiration, const PasteListing::Visibility visibility);

    void requestUserDetails();
    void requestHistory();
    void requestTrending();

    void setApiKey(const QString& apiKey);
    QString apiKey() const;

signals:
    void loginComplete(QString apiKey);
    void loginFailed(QString message);
    void pasteComplete(QString pasteUrl);
    void pasteFailed(QString message);
    void userDetailsAvailable(PasteUser pasteUser);
    void historyAvailable(QList<PasteListing> *pasteList);
    void trendingAvailable(QList<PasteListing> *pasteList);

private slots:
    void onLoginFinished();
    void onSubmitPasteFinished();
    void onUserDetailsFinished();
    void onHistoryFinished();
    void onTrendingFinished();

private:
    void parseUserDetails(QXmlStreamReader& reader, PasteUser& pasteUser);
    bool processPasteListResponse(QNetworkReply *networkReply, QList<PasteListing> *pasteList);
    bool parsePasteList(QXmlStreamReader& reader, QList<PasteListing> *pasteList);
    void parsePasteElement(QXmlStreamReader& reader, QList<PasteListing> *pasteList);

    QNetworkAccessManager accessManager_;
    QString apiKey_;
};

#endif // PASTEBIN_H
