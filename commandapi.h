#ifndef COMMANDAPI_H
#define COMMANDAPI_H

#include <qobject.h>

class QWebView;
class QWebFrame;

class CommandApi : public QObject
{
    Q_OBJECT
public:
    CommandApi( QObject *parent );

    void setWebView( QWebView *view );

public slots:
    void invokeCommand( const QString &param );

private slots:
    void attachObject();

private:
    QWebFrame *frame;
};

#endif // COMMANDAPI_H

