#pragma once
#include <QtWidgets>

#define			ADDRESS_BUTTON_WIDTH		98
#define			ADDRESS_BUTTON_HEIGHT		40

class IpEdit : public QWidget {
	Q_OBJECT

public:
	IpEdit(QWidget * parent = Q_NULLPTR);
	~IpEdit();
	void							SetDisable(bool disable);
	void							SetIp(QStringList ipaddress);
	QString							GetIp();
protected slots:
	void							slot_checkIpInput();
	void							slot_returnInput();
private:
	void							initLineEdit(QLineEdit* edit);
private:
	QLineEdit						*m_addressEditOne;
	QLineEdit						*m_addressEditTwo;
	QLineEdit						*m_addressEditThree;
	QLineEdit						*m_addressEditFour;
};
