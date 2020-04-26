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

#ifndef QDataTableTaskMenuExtension_HPP
#define QDataTableTaskMenuExtension_HPP

# pragma once

# include <QtDesigner/QDesignerTaskMenuExtension>
# include <QtDesigner/QExtensionFactory>

# include "QDataTablePropertySheetExtensionWidget.hpp"

class QAction;
class QExtensionManager;

class QDataTableTaskMenuExtension :
    public QObject,
    public QDesignerTaskMenuExtension
{
    Q_OBJECT
    Q_INTERFACES(QDesignerTaskMenuExtension)

public:
    explicit QDataTableTaskMenuExtension(
    QDataTablePropertySheetExtensionWidget * dlg,
    QObject *parent);

    QAction *preferredEditAction() const override;
    QList<QAction *> taskActions() const override;

private slots:
    void editState();
    
private:
    QDataTablePropertySheetExtensionWidget * sheetWidget;
    QAction * editStateAction;
};

#endif  // QDataTableTaskMenu_HPP

