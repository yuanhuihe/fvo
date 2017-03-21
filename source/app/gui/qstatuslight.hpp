#pragma once
#include <QtWidgets>
#include <QLabel>

class QStatuslight : public QLabel {
	Q_OBJECT
public:
	enum statusLightType {
		NONE_LIGHT,
		COLLECTION,
		STANDBY,
		DATA_EXCEPTION,
		DISABLE,
	};
	Q_ENUM(statusLightType)
public:
	QStatuslight(QStatuslight::statusLightType Lighttype = NONE_LIGHT, QWidget * parent = Q_NULLPTR, int bdevice = false);
	~QStatuslight();
	void		changeLightStatus(QStatuslight::statusLightType Lighttype);
	void		setBreathLightInterval(int timeInterval);
private:
	void		setDisableLight();
	void		setCollection();
	void		setStandBy();
	void		setNoneLight();
	void		setdataAnomalies();
private:
	int			m_timeInterval;
	bool		m_bDeepColor;
	QTimer		*breathtimer;
	QMovie		*Breathmovie;
};
