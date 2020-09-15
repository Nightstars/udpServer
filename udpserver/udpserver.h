#pragma once

#include <QtWidgets/QDialog>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>
#include <QTextEdit>

class udpserver : public QDialog
{
	Q_OBJECT

public:
	udpserver(QWidget *parent =0,Qt::WindowFlags f=0);
	~udpserver();
public slots:
	void StartBtnClicked();
	//void timeout();
private:
	QTextEdit *send;
	QLabel *TimeLabel;
	QLineEdit *TextLineEdit;
	QPushButton *StartBtn;
	QVBoxLayout *mainLayout;
	int port;
	bool isStarted;
	QUdpSocket * udpSocket;
	QTimer *timer;
	//QDateTime *time;
};
