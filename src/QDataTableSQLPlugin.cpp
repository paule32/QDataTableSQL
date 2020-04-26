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
# include "QDataTableSQLPlugin.hpp"

# include "QDataTablePropertySheetExtensionWidget.hpp"
# include "QDataTablePropertySheetExtension.hpp"

# include "QDataTableTaskMenuExtension.hpp"
# include "QDataTableTaskMenuExtensionFactory.hpp"

# include <QtDesigner/QDesignerFormEditorInterface>
# include <QtDesigner/QExtensionManager>
# include <QtDesigner/QExtensionFactory>
# include <QtPlugin>

QDataTableSQLPlugin::QDataTableSQLPlugin(QObject *parent)
    : QObject(parent)
{
}

void QDataTableSQLPlugin::initialize(QDesignerFormEditorInterface * formEditor)
{
    if (initialized)
        return;

    QExtensionManager * manager = formEditor->extensionManager();
    Q_ASSERT(manager != 0);

    manager->registerExtensions(
    new      QDataTableTaskMenuExtensionFactory(manager),
    Q_TYPEID(QDesignerTaskMenuExtension));
     
#if 0
    if (nullptr == sheetWidget)
    sheetWidget  = new QDataTablePropertySheetExtensionWidget();
    
    // access
    QDesignerPropertySheetExtension * propertySheet  = nullptr;
    propertySheet = qt_extension<
    QDataTablePropertySheetExtension*>(manager, sheetWidget);

    // menu
    manager->registerExtensions(
    new      QDataTableTaskMenuExtensionFactory(manager),
    Q_TYPEID(QDesignerTaskMenuExtension));

    // property page
    manager->registerExtensions(
    new      QDataTablePropertySheetExtensionFactory(manager),
    Q_TYPEID(QDesignerPropertySheetExtension));
#endif

    initialized = true;
}

bool QDataTableSQLPlugin::isInitialized() const
{
    return initialized;
}

QWidget * QDataTableSQLPlugin::createWidget(QWidget *parent)
{
    QDataTablePropertySheetExtensionWidget * prop = new
    QDataTablePropertySheetExtensionWidget(parent);

//    QDataTableSQL * prop = new
//    QDataTableSQL(parent);
    
    return prop;
}

QString QDataTableSQLPlugin::name() const
{
    return QStringLiteral("QDataTableSQL");
}

QString QDataTableSQLPlugin::group() const
{
    return QStringLiteral("KALLUP - Database");
}

QIcon QDataTableSQLPlugin::icon() const
{
    return QIcon(":/img/sql-icon.png");
}

QString QDataTableSQLPlugin::toolTip() const
{
    return QString();
}

QString QDataTableSQLPlugin::whatsThis() const
{
    return QString();
}

bool QDataTableSQLPlugin::isContainer() const
{
    return false;
}

QString QDataTableSQLPlugin::domXml() const
{
    return QLatin1String(
    "<ui language=\"c++\">\n"
    "<widget class=\"QDataTableSQL\" name=\"dataTableSQL\"/>\n"
    "   <customwidgets>\n"
    "       <customwidget>\n"
    "           <class>QDataTableSQL</class>\n"
    "           <propertyspecifications>\n"
    "               <tooltip name=\"state\">QDataTableSQL state</tooltip>\n"
    "           </propertyspecifications>\n"
    "       </customwidget>\n"
    "   <customwidgets>\n"
    "</widget>\n"
    "</ui>\n");
}

QString QDataTableSQLPlugin::includeFile() const
{
    return QStringLiteral("QDataTableSQL.hpp");
}

