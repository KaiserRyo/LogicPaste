#include "AppSettings.h"

#include <QtCore/QMutex>

AppSettings *AppSettings::instance_ = NULL;

AppSettings* AppSettings::instance()
{
    static QMutex mutex;
    if(!instance_) {
        mutex.lock();
        if(!instance_) {
            instance_ = new AppSettings();
        }
        mutex.unlock();
    }
    return instance_;
}

AppSettings::AppSettings()
{
}

void AppSettings::sync()
{
    settings_.sync();
}

void AppSettings::removeUserData()
{
    settings_.remove("ignore_error_certs");
    settings_.remove("api_user_name");
    settings_.remove("api_user_key");
    settings_.remove("user_avatar_url");
    settings_.remove("user_website");
    settings_.remove("user_email");
    settings_.remove("user_location");
    settings_.remove("user_account_type");
    settings_.remove("user_format_short");
    settings_.remove("user_expiration");
    settings_.remove("user_private");
    settings_.remove("user_avatar_image");
}

bool AppSettings::useSsl() const
{
    return settings_.value("use_ssl", true).toBool();
}
void AppSettings::setUseSsl(bool value)
{
    settings_.setValue("use_ssl", value);
}

QStringList AppSettings::ignoreErrorCerts() const
{
    return settings_.value("ignore_error_certs").toStringList();
}
void AppSettings::setIgnoreErrorCerts(const QStringList& serials)
{
    settings_.setValue("ignore_error_certs", serials);
}

QString AppSettings::username() const
{
    return settings_.value("api_user_name", "").toString();
}
void AppSettings::setUsername(const QString& username)
{
    settings_.setValue("api_user_name", username);
}

QString AppSettings::apiKey() const
{
    return settings_.value("api_user_key", "").toString();
}
void AppSettings::setApiKey(const QString& apiKey)
{
    settings_.setValue("api_user_key", apiKey);
}

QString AppSettings::avatarUrl() const
{
    return settings_.value("user_avatar_url", "").toString();
}
void AppSettings::setAvatarUrl(const QString& avatarUrl)
{
    settings_.setValue("user_avatar_url", avatarUrl);
}

QString AppSettings::website() const
{
    return settings_.value("user_website", "").toString();
}
void AppSettings::setWebsite(const QString& website)
{
    settings_.setValue("user_website", website);
}

QString AppSettings::email() const
{
    return settings_.value("user_email", "").toString();
}
void AppSettings::setEmail(const QString& email)
{
    settings_.setValue("user_email", email);
}

QString AppSettings::location() const
{
    return settings_.value("user_location", "").toString();
}
void AppSettings::setLocation(const QString& location)
{
    settings_.setValue("user_location", location);
}

AppSettings::AccountType AppSettings::accountType() const
{
    return static_cast<AppSettings::AccountType>(settings_.value("user_account_type", 0).toInt());
}
void AppSettings::setAccountType(const AppSettings::AccountType accountType)
{
    settings_.setValue("user_account_type", static_cast<int>(accountType));
}

QString AppSettings::pasteFormatShort() const
{
    return settings_.value("user_format_short", "").toString();
}
void AppSettings::setPasteFormatShort(const QString& pasteFormatShort)
{
    settings_.setValue("user_format_short", pasteFormatShort);
}

QString AppSettings::pasteExpiration() const
{
    return settings_.value("user_expiration", "").toString();
}
void AppSettings::setPasteExpiration(const QString& pasteExpiration)
{
    settings_.setValue("user_expiration", pasteExpiration);
}

PasteListing::Visibility AppSettings::pasteVisibility() const
{
    return static_cast<PasteListing::Visibility>(settings_.value("user_private", 0).toInt());
}
void AppSettings::setPasteVisibility(const PasteListing::Visibility pasteVisibility)
{
    settings_.setValue("user_private", static_cast<int>(pasteVisibility));
}

bool AppSettings::formatterEnabled() const
{
    return settings_.value("formatter_enabled", true).toBool();
}
void AppSettings::setFormatterEnabled(bool enabled)
{
    settings_.setValue("formatter_enabled", enabled);
}

bool AppSettings::formatterLineNumbering() const
{
    return settings_.value("formatter_line_numbering", true).toBool();
}
void AppSettings::setFormatterLineNumbering(bool lineNumbering)
{
    settings_.setValue("formatter_line_numbering", lineNumbering);
}

QString AppSettings::formatterStyle() const
{
    return settings_.value("formatter_style", "tango").toString();
}
void AppSettings::setFormatterStyle(const QString& style)
{
    settings_.setValue("formatter_style", style);
}


QByteArray AppSettings::avatarImage() const
{
    return settings_.value("user_avatar_image").toByteArray();
}
void AppSettings::setAvatarImage(const QByteArray& data)
{
    settings_.setValue("user_avatar_image", data);
}

QStringList AppSettings::recentFormats() const
{
    return settings_.value("recent_formats").toStringList();
}

void AppSettings::setRecentFormats(const QStringList& recentFormats)
{
    settings_.setValue("recent_formats", recentFormats);
}
