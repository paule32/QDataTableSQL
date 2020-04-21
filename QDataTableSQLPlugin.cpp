# include "QDataTableSQL.hpp"
# include "QDataTableSQLPlugin.hpp"

# include <QtDesigner/QDesignerFormEditorInterface>
# include <QtDesigner/QExtensionManager>
# include <QtPlugin>

QDataTableSQLPlugin::QDataTableSQLPlugin(QObject *parent)
    : QObject(parent)
{
}

void QDataTableSQLPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

/*
    QExtensionManager *manager = formEditor->extensionManager();
    Q_ASSERT(manager != 0);

    manager->registerExtensions(
        new QDataTableSQLFactory(manager),
        Q_TYPEID(QDesignerTaskMenuExtension));
*/
        
    initialized = true;
}

bool QDataTableSQLPlugin::isInitialized() const
{
    return initialized;
}

QWidget * QDataTableSQLPlugin::createWidget(QWidget *parent)
{
    auto *  sql = new QDataTableSQL(parent);
    return  sql ;
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
        " <widget class=\"QDataTableSQL\" name=\"dataTableSQL\">\n"
        "  <property name=\"geometry\">\n"
        "   <rect>\n"
        "    <x>0</x>\n"
        "    <y>0</y>\n"
        "    <width>42</width>\n"
        "    <height>42</height>\n"
        "   </rect>\n"
        "  </property>\n"
        "  <property name=\"toolTip\" >\n"
        "   <string>SQL Handle to a table</string>\n"
        "  </property>\n"
        "  <property name=\"whatsThis\" >\n"
        "   <string>SQL hidden component</string>\n"
        "  </property>\n"
        " </widget>\n"
        "</ui>\n"
        );
}

QString QDataTableSQLPlugin::includeFile() const
{
    return QStringLiteral("QDataTableSQL.hpp");
}
