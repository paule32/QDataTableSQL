// ------------------------------------------------------------------------------
// dBase4Linux 1.0
// RDP - Rapid Database Programming
//
// (c) 2015-2020 Jens Kallup
// MIT License
//
// Copyright (c) 2020 Jens Kallup
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// --------------------------------------------------------------------------------

# include "QDataTableSQL.hpp"

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

