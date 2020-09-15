#include "udpserver.h"
#include  <QHostAddress>
#include <QMessageBox>
#include <QDateTime>
udpserver::udpserver(QWidget *parent,Qt::WindowFlags f)
	: QDialog(parent,f)
{
	setWindowTitle(tr("UDP Server"));
	send = new QTextEdit(this);
	send->setFocusPolicy(Qt::NoFocus);
	TimeLabel = new QLabel(QStringLiteral("���룺"), this);
	TextLineEdit = new QLineEdit(this);
	StartBtn = new QPushButton(QStringLiteral("����"), this);
	mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(send);
	mainLayout->addWidget(TimeLabel);
	mainLayout->addWidget(TextLineEdit);
	mainLayout->addWidget(StartBtn);
	connect(StartBtn, SIGNAL(clicked()), this, SLOT(StartBtnClicked()));
	port = 5555;
	//isStarted = false;
	udpSocket = new QUdpSocket(this);
	//timer = new QTimer(this);
	//connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
}
udpserver::~udpserver()
{

}
void udpserver::StartBtnClicked()
{
	//if (!isStarted)
	//{
		if (TextLineEdit->text() == "")
		{
			QMessageBox::information(this, tr("error"), QStringLiteral("���͵����ݲ���Ϊ�գ�"));
		}
		else
		{
			//StartBtn->setText(QStringLiteral("ֹͣ"));
			//timer->start(1000);
			QDateTime time=QDateTime::currentDateTime();
			QString currenttime = time.toString("yyyy-MM-dd hh:mm:ss");
			QString str= TextLineEdit->text();
			QString msg = currenttime + QStringLiteral(":  ") + str;
			send->insertPlainText(msg + "\n");
			int length = 0;
			if (msg == "")
			{
				return;
			}
			if ((length = udpSocket->writeDatagram(msg.toLatin1(), msg.length(), QHostAddress::Broadcast, port)) != msg.length())
			{
				return;
			}
			isStarted = true;
		}
	//}
	//else
	//{
		//StartBtn->setText(QStringLiteral("����"));
		//isStarted = false;
		//timer->stop();
	//}
}
/*void udpserver::timeout()
{
	QString msg = TextLineEdit->text();
	send->insertPlainText(msg + "\t");
	int length = 0;
	if (msg == "")
	{
		return;
	}
	if ((length = udpSocket->writeDatagram(msg.toLatin1(), msg.length(), QHostAddress::Broadcast, port)) != msg.length())
	{
		return;
	}
}*/