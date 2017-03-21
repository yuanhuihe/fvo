#include "qstatuslight.hpp"

QStatuslight::QStatuslight(QStatuslight::statusLightType Lighttype, QWidget * parent, int bdevice)
	: QLabel(parent)
	, m_timeInterval(1000)
	, m_bDeepColor(false)
	, breathtimer(NULL) {
	setAlignment(Qt::AlignCenter);
	if (bdevice)
	{
		Breathmovie = new QMovie(":/Perceptron/Resources/button/breath_gray.gif", QByteArray("gif"), this);
	}
	else
	{
		Breathmovie = new QMovie(":/Perceptron/Resources/button/breath.gif", QByteArray("gif"), this);
	}
	
	changeLightStatus(Lighttype);
}

void QStatuslight::changeLightStatus(QStatuslight::statusLightType Lighttype)
{
	switch (Lighttype)
	{
	case COLLECTION:
		setCollection();
		break;
	case DISABLE:
		setDisableLight();
		break;
	case DATA_EXCEPTION:
		setdataAnomalies();
		break;
	case STANDBY:
		setStandBy();
		break;
	default:
		setNoneLight();
		break;
	}
}

void QStatuslight::setCollection()
{
	this->setMovie(Breathmovie);
	setToolTip(tr("Active"));
	Breathmovie->start();
}

void QStatuslight::setStandBy()
{
	Breathmovie->stop();
	this->setPixmap(QPixmap(":/Perceptron/Resources/button/standby.png"));
	setToolTip(tr("Sleep"));
}

void QStatuslight::setNoneLight()
{
	Breathmovie->stop();
	this->setPixmap(QPixmap(""));
	setToolTip("");
}

void QStatuslight::setdataAnomalies()
{
	Breathmovie->stop();
	this->setPixmap(QPixmap(":/Perceptron/Resources/button/unused.png"));
	setToolTip(tr("Data Abnormal"));
}

void QStatuslight::setDisableLight()
{
	Breathmovie->stop();
	this->setPixmap(QPixmap(":/Perceptron/Resources/button/disable.png"));
	setToolTip(tr("Disable"));
}

QStatuslight::~QStatuslight() {
	
}
