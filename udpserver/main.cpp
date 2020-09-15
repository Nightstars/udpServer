#include "udpserver.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	udpserver w;
	w.show();
	return a.exec();
}
