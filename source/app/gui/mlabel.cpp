#include "mlabel.hpp"

MLabel::MLabel(QWidget * parent) : QLabel(parent) {
	m_fontName = "SimSun";
	setBackgroundRole(QPalette::Text);
	QPalette labelPalette;
	labelPalette.setColor(QPalette::WindowText, QColor(0x999999));
	QFont labelfont(m_fontName);
	labelfont.setPixelSize(14);
	setPalette(labelPalette);
	setFont(labelfont);
}

MLabel::MLabel(const QString &text, QWidget *parent, const QString& fontName) : QLabel(text, parent)
{
	m_fontName = fontName;
	setBackgroundRole(QPalette::Text);
	QPalette labelPalette;
	labelPalette.setColor(QPalette::WindowText, QColor(0x999999));
	QFont labelfont(fontName);
	labelfont.setPixelSize(14);
	setPalette(labelPalette);
	setFont(labelfont);
}

void MLabel::setFontSize(int fontsize)
{
	QFont labelfont(m_fontName);
	QPalette labelPalette;
	labelPalette.setColor(QPalette::WindowText, QColor(0x999999));
	labelfont.setPixelSize(fontsize);
	setPalette(labelPalette);
	setFont(labelfont);
}

MLabel::~MLabel() {

}