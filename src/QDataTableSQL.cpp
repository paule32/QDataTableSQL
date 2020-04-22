#include "QDataTableSQL.hpp"

# include <QImage>
# include <QPixmap>
# include <QPalette>
# include <QBrush>
# include <QLabel>
# include <QDialog>
# include <QMessageBox>
# include <QVBoxLayout>
# include <QWizardPage>
# include <QMouseEvent>

uint8_t QDataTableSQL::pix_w = 42;
uint8_t QDataTableSQL::pix_h = 42;

QDataTableSQL::QDataTableSQL(QWidget *parent)
    : QWidget(parent)
{
    setAutoFillBackground(true);
    setMouseTracking(true);

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setMargin (0);

    QPixmap pix(":/img/sql-icon.png");
    pix_w = pix.width ();
    pix_h = pix.height();

    QLabel * lbl = new QLabel();
    lbl->setPixmap(pix);
    lbl->resize(42,42);
    lbl->move  ( 0, 0);

    layout->addWidget(lbl);    
    setLayout(layout);
    
    setWindowTitle("DataTableSQL");
}

QSize QDataTableSQL::minimumSizeHint() const { return QSize(pix_w, pix_h); }
QSize QDataTableSQL::sizeHint()        const { return QSize(pix_w, pix_h); }

void
QDataTableSQL::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    QMessageBox::information(0,"swewewewewe","ssdsdsdsds");
    if (event->button() == Qt::LeftButton) {
        QDialog * dia = new QDialog(this);
        dia->setModal(true);
        dia->show();
    
    #if 0
        auto * page = new QWizardPage;
        page->setTitle("Test");

        auto * layout = new QVBoxLayout;
        page->setLayout(layout);

        QWizard wizard;
        wizard.addPage(page);
        wizard.show();
    #endif
    }
}

void
QDataTableSQL::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    resize(
        getControlWidth (),
        getControlHeight());
}

