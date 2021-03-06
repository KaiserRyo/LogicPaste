#ifndef LOGICPASTEAPP_H
#define LOGICPASTEAPP_H

#include <bb/cascades/Application>
#include <QtNetwork/QNetworkAccessManager>

#include "Pastebin.h"
#include "PasteModel.h"

using namespace bb::cascades;

// Forward declarations
namespace bb { namespace cascades {
class TabbedPane;
class NavigationPane;
class Page;
class Sheet;
} }

class FormatDropDown;

class LogicPasteApp : public QObject {
    Q_OBJECT

public:
    LogicPasteApp(Application *app);
    virtual ~LogicPasteApp();

public slots:
    void onRequestLogin();
    void onRequestLogout();
    void onCreateAccount();

    void onProcessLogin(QString username, QString password);
    void onSubmitPaste();
    void onOpenHistoryPaste(QString pasteKey);
    void onOpenTrendingPaste(QString pasteKey);
    void onDeleteHistoryPaste(QString pasteKey);
    void onOpenUrlInBrowser(QString urlString);
    void onCopyText(QString text);

private slots:
    void onPopFinished(bb::cascades::Page *page);
    void onAboutActionTriggered();
    void onSheetPageClosed();
    void onLoginComplete(QString apiKey);
    void onLoginFailed(QString message);
    void onLoginCanceled();
    void onHistoryRefreshComplete(bool success);
    void onTrendingRefreshComplete(bool success);
    void onPasteComplete(QString pasteUrl);
    void onPasteFailed(QString message);
    void onUserDetailsUpdated();
    void onUserDetailsError(QString message);
    void onUserAvatarUpdated();
    void onConnectionSettingsChanged();
    void onPasteSettingsChanged();
    void onFormatterSettingsChanged();
    void onActivePaneChanged(bb::cascades::AbstractPane *activePane);
    void onEditPaste(PasteListing pasteListing, QByteArray rawPaste);
    void onDeletePasteError(PasteListing pasteListing, QString message);

signals:
    void loginFailed(QString message);
    void settingsUpdated();

private:
    TabbedPane *tabbedPane_;
    Page *pastePage_;
    NavigationPane *historyNav_;
    Page *historyPage_;
    NavigationPane *trendingNav_;
    Page *trendingPage_;
    Page *settingsPage_;
    Sheet *loginSheet_;

    PasteModel *pasteModel_;
    bool ignoreSettingsEvent_;

    static FormatDropDown* replaceDropDown(Page *page, const QString& objectName);
    void openPaste(NavigationPane *nav, QString pasteKey);
    void refreshPastePageDefaults();
    void refreshMainActions();
};

#endif // LOGICPASTEAPP_H
