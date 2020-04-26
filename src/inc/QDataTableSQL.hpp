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
#ifndef QDATATABLESQL_H
#define QDATATABLESQL_H

#pragma once

# include <QWidget>
# include <QFrame>
# include <QLabel>
# include <QResizeEvent>
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
    void mousePressEvent(QMouseEvent  * event) override;
    void resizeEvent    (QResizeEvent * event) override;
    
private:
    inline uint8_t getControlWidth () const { return static_cast<uint8_t>(pix_w); }
    inline uint8_t getControlHeight() const { return static_cast<uint8_t>(pix_h); }
    
    static uint8_t pix_w;
    static uint8_t pix_h;
};

#endif
