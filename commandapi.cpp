#include <QWebView>
#include <QWebFrame>
#include <QProcess>
#include <QDebug>
#include <QString>

#include "commandapi.h"

CommandApi::CommandApi( QObject *parent )
    : QObject( parent )
{
    prevProcess = NULL;
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
  //Close running app, added for tablets
    if(prevProcess && prevProcess->state() != QProcess::NotRunning){
        prevProcess->terminate();
    }
    QObject *command = new QObject();
    QProcess *myProcess = new QProcess(command);
    prevProcess = myProcess;
    myProcess->start(param);
}
