#include <QWebView>
#include <QWebFrame>
#include <QProcess>

#include "commandapi.h"

CommandApi::CommandApi( QObject *parent )
    : QObject( parent )
{

}

void CommandApi::setWebView( QWebView *view )
{
    QWebPage *page = view->page();
    frame = page->mainFrame();

    attachObject();
    connect( frame, SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(attachObject()) );
}

void CommandApi::attachObject()
{
    frame->addToJavaScriptWindowObject( QString("CommandApi"), this );
}

void CommandApi::invokeCommand( const QString &param)
{
    QObject *command = new QObject();
    QProcess *myProcess = new QProcess(command);
    myProcess->start(param);
}
