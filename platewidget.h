#ifndef PLATEWIDGET_H
#define PLATEWIDGET_H

#include <QWidget>
#include "myhelper.h"
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QtCharts>
#include <QChartView>
#include <QScatterSeries>
#include <QValueAxis>
#include <QGraphicsScene>
#include "BaseGraphicsview.h"
#include "qtstreambuf.h"
#include "Snap7_sdk/plc_siemens.h"
#include "Snap7_sdk/s7.h"
#include <QColor>
#include <QtXlsx/xlsxdocument.h>
#include <QtXlsx/xlsxworksheet.h>

QT_BEGIN_NAMESPACE
namespace Ui { class PlateWidget; }
QT_END_NAMESPACE

class PlateWidget : public QWidget
{
        Q_OBJECT

    public:
        PlateWidget(User u,QWidget *parent = nullptr);
        ~PlateWidget();
        void init();
        void initConnect();
        void initPLC();
        void initCamera();
        void lockUiOperation();
        void readControllerObject();
        void initPushbuttonByFrame(QFrame* frame);
        void initPushbuttonByFrame_slot();
        void changeWidgetButtonStyle(QPushButton* checkButton);
        void initPushbuttonByGroup(QGroupBox* box);
        void initPushbuttonByGroup_slot();
        void showUserTable(QVector<User> users);
        bool isAdmin();
        void getMeasureDataByCode(const QString measureCode);
        void getHardnessDataByCode(const QString measureCode);
        void loadPointCodeList(QComboBox* box);
        void initPointDefineChart(qreal xMax, qreal yMax);
        void initPointDefineChart(qreal xMax, qreal yMax, QVector<QPointF> p_point);
        void initAutoDetectChart(qreal xMax, qreal yMax, QVector<QPointF> p_point);
        void initAutoDetectChart(qreal xMax, qreal yMax, QVector<QPointF> p_point, QString hardness);
        void manualModeGetData();
        void autoModeGetData();

        void prepareToDetection();
        void initAutoDetectChart(qreal xMax, qreal yMax);
        double calculateDiameter(int hardness);
        void writeStandardDataToExcel(int standardHardness, double standardDiameter);
        void writeWarningMessage(const QString& warningMessage);
private slots:
        void on_userTable_itemChanged(QTableWidgetItem *item);
        void plateToDetection();

protected slots:
        void closeEvent(QCloseEvent* event);
    private:
        Ui::PlateWidget *ui;
        QTimer systemTime;
        User currentUser;
        PLC_Siemens *snap7_plc = nullptr;
        int writeDbNum;//写入DB块号
        int readDbNum;//读取DB块号
        int readCountDbNum; //读取数量DB块号
        bool controllerInitStatus;
        //手/自动状态
        bool isManual = false;
        bool isAuto = true;
        bool isManualHardness = false;
        bool isManualBlock = false;
        QTimer timeReadController;
        QTimer manualModeDataTimer;
        QTimer autoModeDataTimer;
        ControllerObject controllerObject;//实时PLC数据
        ControllerObject oneConObject;//只处理一次的PLC对象
        bool loadMeasureProCodeList = false;
        DataOper oper;
        bool isShowUserTable = true;
        bool isLoadPointCodeList = false;
        bool isMeasuringStatus = false;
        bool isCompletionReceived = false;
        double widthMin = 0;
        double lengthMin = 0;
        bool isPointCodeListChange = false;
        QScatterSeries *pointDefineSeries;
        QScatterSeries *autoDetectSeries;
        QChart *chart;
        QChart *autoChart;
        QValueAxis *axisX;
        QValueAxis *axisY;
        QValueAxis *autoAxisX;
        QValueAxis *autoAxisY;
        std::shared_ptr<qtStreamBuf> buffer;
        QVector<hardnessList> hardnesses;
        PointList p;
        QVector<QPointF> allPoints;
        QVector<QPointF> xPoints,yPoints; //每一行第一个点和每一列最后一个点
        //pdf导出
//        QSharedPointer<QtRPT> report;
//        QString reportXML = nullptr;
        QString manualHardnessStr;
        QString manualBlockStr;
        QString xMax;
        QString yMax;
        QString warning;
        bool isManualing = false;
        int serialNum = 0;
        bool isTransitting = false;

};
#endif // PLATEWIDGET_H
