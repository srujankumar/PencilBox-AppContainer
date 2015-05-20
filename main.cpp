#include <QApplication>
#include <QWebView>

#include "commandapi.h"

int main(int argc, char *argv[])
{
    QApplication app( argc, argv );

    QWebView *view = new QWebView();

    CommandApi *commandapi = new CommandApi( view );
    commandapi->setWebView( view );

    view->setUrl( QUrl( "http://localhost/angular" ) );
    view->showMaximized();

    return app.exec();
}
