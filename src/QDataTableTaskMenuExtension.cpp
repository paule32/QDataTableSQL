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

# include "QDataTablePropertySheetExtensionWidget.hpp"
# include "QDataTablePropertySheetDialog.hpp"

# include "QDataTableTaskMenuExtension.hpp"
# include "QDataTableTaskMenuExtensionFactory.hpp"

# include <QtDesigner/QDesignerFormEditorInterface>
# include <QAction>

QDataTableTaskMenuExtension::
QDataTableTaskMenuExtension(
      QDataTablePropertySheetExtensionWidget * dlg
    , QObject * parent)
    : QObject(parent  )
    , editStateAction (new QAction("About Framework", this))
    , sheetWidget(dlg )
{
    connect(editStateAction,
	&QAction::triggered, this,
	&QDataTableTaskMenuExtension::editState);
}

void
QDataTableTaskMenuExtension::editState()
{
    QDataTablePropertySheetDialog dialog(sheetWidget);
    dialog.exec();
}

QAction *        QDataTableTaskMenuExtension::preferredEditAction() const { return editStateAction; }
QList<QAction *> QDataTableTaskMenuExtension::taskActions()         const { return QList<QAction *>{editStateAction}; }

#if 0
QDataTableTaskMenuExtensionFactory::
QDataTableTaskMenuExtensionFactory(
      QExtensionManager *parent)
    : QExtensionFactory (parent)
{
}
#endif