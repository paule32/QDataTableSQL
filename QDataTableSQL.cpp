#include "QDataTableSQL.hpp"

# include <QImage>
# include <QPixmap>
# include <QMessageBox>
# include <QVBoxLayout>
# include <QWizardPage>
# include <QMouseEvent>

QDataTableSQL::QDataTableSQL(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color:url(:/img/sql-icon.png);");

    QPixmap pix(":/img/sql-icon.png");
    pix_w = pix.width ();
    pix_h = pix.height();
    
    setWindowTitle(tr("DataTableSQL"));
}

QSize QDataTableSQL::minimumSizeHint() const { return QSize(pix_w, pix_h); }
QSize QDataTableSQL::sizeHint()        const { return QSize(pix_w, pix_h); }

void
QDataTableSQL::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QMessageBox::information(0,"swewewewewe","ssdsdsdsds");
    if (event->button() == Qt::LeftButton) {
        auto * page = new QWizardPage;
        page->setTitle("Test");

        auto * layout = new QVBoxLayout;
        page->setLayout(layout);

        QWizard wizard;
        wizard.addPage(page);
        wizard.show();
    }
}

