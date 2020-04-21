#ifndef QDATATABLESQL_H
#define QDATATABLESQL_H

#pragma once

# include <QWidget>
# include <QFrame>
# include <QLabel>
# include <QMouseEvent>
# include <QtUiPlugin/QDesignerExportWidget>

class QDESIGNER_WIDGET_EXPORT QDataTableSQL : public QWidget
{
    Q_OBJECT

public:
    explicit QDataTableSQL(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint()        const override;
    
protected:
    void mousePressEvent(QMouseEvent * event) override;
    
private:
    uint8_t pix_w = 42;
    uint8_t pix_h = 42;
};

#endif
