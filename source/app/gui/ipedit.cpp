#include "ipedit.hpp"

IpEdit::IpEdit(QWidget * parent) : QWidget(parent) {
	m_addressEditOne = new QLineEdit(this);
	m_addressEditTwo = new QLineEdit(this);
	m_addressEditThree = new QLineEdit(this);
	m_addressEditFour = new QLineEdit(this);
	initLineEdit(m_addressEditOne);
	initLineEdit(m_addressEditTwo);
	initLineEdit(m_addressEditThree);
	initLineEdit(m_addressEditFour);

	QHBoxLayout *addressLayout = new QHBoxLayout(this);
	addressLayout->setContentsMargins(0, 0, 0, 0);
	addressLayout->setSpacing(0);
	addressLayout->addWidget(m_addressEditOne, 1);
	addressLayout->addWidget(m_addressEditTwo, 1);
	addressLayout->addWidget(m_addressEditThree, 1);
	addressLayout->addWidget(m_addressEditFour, 1);

	setFixedSize(((ADDRESS_BUTTON_WIDTH)* 4), (ADDRESS_BUTTON_HEIGHT));
	setLayout(addressLayout);
}

IpEdit::~IpEdit() {

}

void IpEdit::SetDisable(bool disable)
{
	m_addressEditOne->setDisabled(disable);
	m_addressEditTwo->setDisabled(disable);
	m_addressEditThree->setDisabled(disable);
	m_addressEditFour->setDisabled(disable);
}

void IpEdit::SetIp(QStringList ipaddress)
{
	if (ipaddress.size() < 4)
	{
		return;
	}
	m_addressEditOne->setText(ipaddress[0]);
	m_addressEditTwo->setText(ipaddress[1]);
	m_addressEditThree->setText(ipaddress[2]);
	m_addressEditFour->setText(ipaddress[3]);
}

QString IpEdit::GetIp()
{
	QString ip;
	ip.append(m_addressEditOne->text());
	ip.append(".");
	ip.append(m_addressEditTwo->text());
	ip.append(".");
	ip.append(m_addressEditThree->text());
	ip.append(".");
	ip.append(m_addressEditFour->text());

	if (m_addressEditOne->text().isEmpty() || m_addressEditTwo->text().isEmpty() || m_addressEditThree->text().isEmpty() || m_addressEditFour->text().isEmpty())
	{
		return "";
	}
	return ip;
}

void  IpEdit::slot_checkIpInput()
{
	// 	if (!m_addressEditOne->text().isEmpty() && m_addressEditOne->text().toInt() == 0)
	// 		m_addressEditOne->setText("0");
	// 	if (!m_addressEditTwo->text().isEmpty() && m_addressEditTwo->text().toInt() == 0)
	// 		m_addressEditTwo->setText("0");
	// 	if (!m_addressEditThree->text().isEmpty() && m_addressEditThree->text().toInt() == 0)
	// 		m_addressEditThree->setText("0");
	// 	if (!m_addressEditFour->text().isEmpty() && m_addressEditFour->text().toInt() == 0)
	// 		m_addressEditFour->setText("0");
	if ((m_addressEditOne->text()=="0" && m_addressEditOne->hasFocus()) || m_addressEditOne->text().endsWith('.') || (m_addressEditOne->text().size() == 3 && m_addressEditOne->hasFocus()))
	{
		m_addressEditOne->setText(m_addressEditOne->text().remove("."));
		m_addressEditTwo->setFocus();
	}
	if ((m_addressEditTwo->text() == "0" && m_addressEditTwo->hasFocus()) || m_addressEditTwo->text().endsWith('.') || (m_addressEditTwo->text().size() == 3 && m_addressEditTwo->hasFocus()))
	{
		m_addressEditTwo->setText(m_addressEditTwo->text().remove("."));
		m_addressEditThree->setFocus();
	}
	if ((m_addressEditThree->text() == "0" && m_addressEditThree->hasFocus()) || m_addressEditThree->text().endsWith('.') || (m_addressEditThree->text().size() == 3 && m_addressEditThree->hasFocus()))
	{
		m_addressEditThree->setText(m_addressEditThree->text().remove("."));
		m_addressEditFour->setFocus();
	}
	if ((m_addressEditFour->text() == "0" && m_addressEditFour->hasFocus()) || m_addressEditFour->text().endsWith('.') || (m_addressEditFour->text().size() == 3 && m_addressEditFour->hasFocus()))
	{
		m_addressEditFour->setText(m_addressEditFour->text().remove("."));
		m_addressEditFour->clearFocus();
	}
}

void  IpEdit::slot_returnInput()
{
	if (m_addressEditOne->hasFocus())
	{
		m_addressEditTwo->setFocus();
		return;
	}
	if (m_addressEditTwo->hasFocus())
	{
		m_addressEditThree->setFocus();
		return;
	}
	if (m_addressEditThree->hasFocus())
	{
		m_addressEditFour->setFocus();
		return;
	}
}

void  IpEdit::initLineEdit(QLineEdit* edit)
{
	//QIntValidator *LineValid = new QIntValidator(this);
	//LineValid->setRange(0, 255);

	//QRegExp ipreg("^(\d{0,1,2}|[1]\d{2}|2[0-5]\d|255)$");
	QRegExp ipreg("(1\\d{2}|2[0-4]\\d|25[0-5]|[1-9]\\d|\\d)");

	QRegExpValidator *valide = new QRegExpValidator(ipreg);
	edit->setValidator(valide);
	edit->setObjectName("grayedit");
	edit->setAlignment(Qt::AlignCenter);
	edit->setFixedSize((ADDRESS_BUTTON_WIDTH), (ADDRESS_BUTTON_HEIGHT));
	edit->setFont(QFont("Arial Regula", 18));
	connect(edit, &QLineEdit::textEdited, this, &IpEdit::slot_checkIpInput);
	connect(edit, &QLineEdit::returnPressed, this, &IpEdit::slot_returnInput);
}