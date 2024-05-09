#include "platewidget.h"
#include "ui_platewidget.h"


PlateWidget::PlateWidget(User u, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlateWidget)
{
    ui->setupUi(this);

    currentUser = u;
    myHelper::FormInCenter(this);//窗体居中显示
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    ui->titleWidget->set_lab_Title("成都迪迈沃克光电科技有限公司");
    ui->titleWidget->setShowMaxBtn(true);
//    ui->titleWidget->defaultMax();
    init();
}

PlateWidget::~PlateWidget()
{
    delete ui;
}

void PlateWidget::init()
{
    initConnect();
    initPushbuttonByFrame(ui->frame);//菜单切换
    initPushbuttonByFrame(ui->frame3);//用户管理
    initPushbuttonByGroup(ui->defineGroup);
    initPushbuttonByGroup(ui->pointGroup);
    ui->roleName_7->setText(currentUser.role);
    ui->userName_7->setText(currentUser.name);
    QDate measureDates = QDate::currentDate();
    ui->startTime->setDate(measureDates);
    ui->endTime->setDate(measureDates);
    ui->dateTimeEdit->setText(QDate::currentDate().toString("yyyy-MM-dd"));

    ui->pointTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->pointTable->setSelectionBehavior(QAbstractItemView::SelectItems);
    ui->mainStackedWidget->setCurrentWidget(ui->autoPage);
    ui->startDetectionBtn->hide();
    changeWidgetButtonStyle(ui->autoModeBtn);
    loadPointCodeList(ui->measurePointCodeList);
    initPointDefineChart(1500,2000);
    initPLC();


}

void PlateWidget::initConnect()
{
    //更新系统时间
    connect(&systemTime, &QTimer::timeout, [this](){
        QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->systemTime_7->setText(currentDateTime);
    });
    systemTime.start(1000);

    //发送钢板类型
    connect(ui->measurePointCodeList,QOverload<const QString &>::of(&QComboBox::currentIndexChanged),[=](const QString& plateType){
        if(controllerInitStatus == false)
        {
            return;
        }
        if(plateType == "钢板类型")
        {
            return;
        }
        int typeIndex;
        if(plateType == "类型1")
        {
            typeIndex = 1;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型2")
        {
            typeIndex = 2;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型3")
        {
            typeIndex = 3;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型4")
        {
            typeIndex = 4;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型5")
        {
            typeIndex = 5;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型6")
        {
            typeIndex = 6;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        //规定类型7为长类型钢板
        if(plateType == "类型7")
        {
            typeIndex = 7;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型8")
        {
            typeIndex = 8;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型9")
        {
            typeIndex = 9;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型10")
        {
            typeIndex = 10;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型11")
        {
            typeIndex = 11;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型12")
        {
            typeIndex = 12;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型13")
        {
            typeIndex = 13;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型14")
        {
            typeIndex = 14;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型15")
        {
            typeIndex = 15;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }
        if(plateType == "类型16")
        {
            typeIndex = 16;
            byte typeBuffer[2];
            S7_SetWordAt(typeBuffer,0,static_cast<uint16_t>(typeIndex));
            snap7_plc->DBWrite(writeDbNum,0,2,&typeBuffer);
        }

        //        //发送长、短类型给plc
        //        int plateControllType;
        //        if(typeIndex <= 6 && typeIndex >= 1)
        //        {
        //            //短类型
        //            plateControllType = 0;
        //            byte plateControllTypeBuffer[2];
        //            S7_SetWordAt(plateControllTypeBuffer,0,static_cast<uint16_t>(plateControllType));
        //            snap7_plc->DBWrite(writeDbNum,2,2,&plateControllTypeBuffer);

        //        }
        //        if(typeIndex == 7)
        //        {
        //            //长类型
        //            plateControllType = 1;
        //            byte plateControllTypeBuffer[2];
        //            S7_SetWordAt(plateControllTypeBuffer,0,static_cast<uint16_t>(plateControllType));
        //            snap7_plc->DBWrite(writeDbNum,2,2,&plateControllTypeBuffer);

        //        }

    });
    //自动检测--根据点位编号获取点位信息列表
    connect(ui->measurePointCodeList, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),[=](const QString & code){
        isPointCodeListChange = true;
        QVector<PointList> p_list;
        PointInfo p_info;
        QVector<QPointF> p_point;
        QVector<QPointF> showPoints;
        oper.getPointInfoByCode(p_info, code);
        oper.getPointListByCode(p_list, code);
        int pointListSize = p_list.size();
        QString val = QString("%1-%2").arg(p_info.D_thick_std).arg(p_info.U_thick_std);
        ui->thickStdVal->setText(val);
        QString p_code = p_info.pointCode;
        ui->numEdit->setText(p_code);
        QStringList serialNums = p_code.split("-");
        QString num = serialNums.last();
        ui->serialNum->setText(num);
        for (int i = 0; i < pointListSize; i++) {
            if (p_list[i].yVal != 0 && p_list[i].xVal != 0) {
                showPoints.push_back(QPointF(p_list[i].yVal, p_list[i].xVal));
            }

        }
        for(int i = 0; i < pointListSize; i++)
        {
            p_point.push_back(QPointF(p_list[i].yVal, p_list[i].xVal));
        }
        QVector<QPointF> firstPoints;
        QVector<QPointF> secondPoints;
        for(int i=0;i<p_point.size() / 2;i++)
        {
            if(p_point[i].x()!=0&&p_point[i].y()!=0)
            {
                firstPoints.push_back(QPointF(-p_point[i].x(),p_point[i].y()));
            }

        }

        for(int i=p_point.size()/2;i<p_point.size();i++)
        {
            if(p_point[i].x()!=0&&p_point[i].y()!=0)
            {
                secondPoints.push_back(QPointF(-p_point[i].x(),p_point[i].y()));
            }

        }
        if(code == "钢板类型")
        {
            ui->firstSet->hide();
            ui->secondSet->hide();
            ui->measureCount->setText(QString::number(0));
        }
        else
        {
            ui->firstSet->show();
            ui->secondSet->show();
        }

        connect(ui->firstSet,&QRadioButton::clicked,this,[=](){
            initAutoDetectChart(p_info.width,p_info.length,firstPoints);
            ui->secondSet->setChecked(false);
        });
        connect(ui->secondSet,&QRadioButton::clicked,this,[=](){
            initAutoDetectChart(p_info.width,p_info.length,secondPoints);
            ui->firstSet->setChecked(false);
        });
        initAutoDetectChart(p_info.width,p_info.length);

    });



    //点位定义--根据点位编号获取点位信息列表
    connect(ui->pointCodeList, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),[=](const QString & code){
        //qDebug() << "pointCodeList connect: " << code;
        isPointCodeListChange = true;
        PointInfo p_info;
        QVector<PointList> p_list;
        oper.getPointInfoByCode(p_info, code);
        oper.getPointListByCode(p_list, code);
        int pointListSize = p_list.size();
        QVector<QPointF> p_point;
        ui->pointCode->setText(p_info.plateType);
        ui->length->setValue(p_info.length);
        ui->width->setValue(p_info.width);
        ui->thick->setValue(p_info.thick);
        if(code == "钢板类型")
        {
            ui->xMaxScale->setText("");
            ui->yMaxScale->setText("");
        }
        if(p_info.width!=0)
        {
            ui->xMaxScale->setText(QString::number(p_info.width - 100));
        }
        if(ui->length->text().toDouble() > 7980)
        {
            ui->yMaxScale->setText(QString::number(7710));
        }
        if(ui->length->text().toDouble() > 2000 && ui->length->text().toDouble() < 7980)
        {
            ui->yMaxScale->setText(QString::number(p_info.length - 270));
        }
        ui->D_thick_std->setValue(p_info.D_thick_std);
        ui->U_thick_std->setValue(p_info.U_thick_std);
        ui->localNum->setText(p_info.pointCode);

        for(int i = 0; i < pointListSize; i++){
            if (p_list[i].yVal != 0 && p_list[i].xVal != 0) {
                p_point.push_back(QPointF(p_list[i].yVal, p_list[i].xVal));
            }
        }
        initPointDefineChart(p_info.width,p_info.length,p_point);

        isPointCodeListChange = false;
    });
    //点位定义，长度改变事件，用于更新点位图
    connect(ui->length, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [=](double length){
        if(isPointCodeListChange == true){
            return;
        }
        if(isLoadPointCodeList == true){
            return;
        }
        if(length <= 0 || ui->width->value() <= 0){
            return;
        }
        if(ui->length->text().toDouble() > 7980)
        {
            yMax = QString::number(7710);
        }
        if(ui->length->text().toDouble() > 2000 && ui->length->text().toDouble() < 7980)
        {

            yMax = QString::number(length - 270);
        }
        ui->yMaxScale->setText(yMax);
        initPointDefineChart(ui->width->value(),length);
    });
    //点位定义，宽度改变事件，用于更新点位图
    connect(ui->width, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [=](double width){
        if(isPointCodeListChange == true){
            return;
        }
        if(isLoadPointCodeList == true){
            return;
        }
        if(width <= 0 || ui->length->value() <= 0){
            return;
        }
        xMax = QString::number(width - 100);
        ui->xMaxScale->setText(xMax);
        initPointDefineChart(width,ui->length->value());

    });
    //根据抽检间隔判断是否进行抽检
    connect(ui->measureInterval,QOverload<int>::of(&QSpinBox::valueChanged),this,[=](int interval){
        if(!controllerInitStatus)
        {
            return;
        }
        if(!isAuto)
        {
            return;
        }
        // 获取编码器计数值
        int countValue = ui->measureCount->text().toInt();

        // 判断是否需要进行抽检
        int n = interval;

        bool requiresSampling = false;
        if(countValue%n==0 && countValue!=0)
        {
            requiresSampling = true;
        }
        else
        {
            requiresSampling = false;
        }
        if (requiresSampling) {
            myHelper::ShowMessageBoxInfo("此钢板需要进行抽检！");
        } else {
            myHelper::ShowMessageBoxInfo("此钢板不需要进行抽检！");
        }
    });
    //流水号处理

    connect(ui->measureCount,&QLineEdit::textChanged,this,[=](const QString& text){

        if(ui->measurePointCodeList->currentText() != "钢板类型")
        {
            int newValue = text.toInt();
            if (serialNum != newValue) {
                QString seriesNumText = ui->serialNum->text();
                QString newSeriesNumText = text.rightJustified(seriesNumText.size(), '0');
                ui->serialNum->setText(newSeriesNumText);
                serialNum = newValue;

                QString numText = ui->numEdit->text();
                QStringList sections = numText.split('-');
                sections.last() = QString::number(newValue % 1000).rightJustified(3, '0');
                QString newNumText = sections.join('-');
                ui->numEdit->setText(newNumText);
            }
        }


    });


    //测量开始日期修改事件
    connect(ui->startTime,&QDateEdit::dateChanged,[this](const QDate &date){
        QString endTime = ui->endTime->date().toString("yyyy-MM-dd");
        QStringList codeList;
        oper.getCodeListByDate(codeList, date.toString("yyyy-MM-dd"), endTime);
        loadMeasureProCodeList = true;
        ui->resultCodeList->clear();
        ui->resultCodeList->addItem("选择测量类型");
        ui->resultCodeList->addItems(codeList);
        loadMeasureProCodeList = false;
    });

    //测量结束日期修改事件
    connect(ui->endTime,&QDateEdit::dateChanged,[this](const QDate &date){
        QString startTime = ui->startTime->date().toString("yyyy-MM-dd");
        QStringList codeList;
        oper.getCodeListByDate(codeList, startTime, date.toString("yyyy-MM-dd"));
        loadMeasureProCodeList = true;
        ui->resultCodeList->clear();
        ui->resultCodeList->addItem("选择类型");
        ui->resultCodeList->addItems(codeList);
        loadMeasureProCodeList = false;
    });
    //根据编号查询检测数据
    connect(ui->resultCodeList, QOverload<const QString &>::of(&QComboBox::currentIndexChanged), [this](const QString &measureCode){

        if(loadMeasureProCodeList == true){
            return;
        }
        getMeasureDataByCode(measureCode);
    });

    //点位定义，表格改变事件，用于更新点位图
    connect(ui->pointTable, &QTableWidget::itemChanged, [=](QTableWidgetItem *item){
        //从配置文件读取允许预设坐标的最大值和最小值
        double minXcoordinate = ui->xMinScale->text().toDouble();
        double minYcoordinate = ui->yMinScale->text().toDouble();
        double maxXcoordinate = ui->xMaxScale->text().toDouble();
        double maxYcoordinate = ui->yMaxScale->text().toDouble();
        if(isPointCodeListChange == true){
            return;
        }
        if(isLoadPointCodeList == true){
            return;
        }

        //判断值是否合格
        if(item->column() >= 0 && item->row() >= 0 && item->column() < 6 && item->row() < 3){
            QString coordinateText = item->text();
            QStringList coordinates = coordinateText.split(",");
            if(coordinates.size() != 2){
                return;
            }
            double xCoordinate = coordinates[0].toDouble(); // 获取X坐标
            double yCoordinate = coordinates[1].toDouble(); // 获取Y坐标

            //输入点位超出范围了

            if(xCoordinate < minXcoordinate)
            {
                myHelper::ShowMessageBoxInfo("输入的X坐标小于了范围的最小值！");
                QTableWidgetItem* currentItem = ui->pointTable->currentItem();
                if(currentItem)
                {
                    currentItem->setText("");

                }
                return;
            }
            if(xCoordinate > maxXcoordinate)
            {
                myHelper::ShowMessageBoxInfo("输入的X坐标超过了范围的最大值！");
                QTableWidgetItem* currentItem = ui->pointTable->currentItem();
                if(currentItem)
                {
                    currentItem->setText("");

                }
                return;
            }
            if(yCoordinate < minYcoordinate)
            {
                myHelper::ShowMessageBoxInfo("输入的Y坐标小于了范围的最小值！");
                QTableWidgetItem* currentItem = ui->pointTable->currentItem();
                if(currentItem)
                {
                    currentItem->setText("");

                }
                return;
            }
            if(yCoordinate > maxYcoordinate)
            {
                myHelper::ShowMessageBoxInfo("输入的Y坐标超过了范围的最大值！");
                QTableWidgetItem* currentItem = ui->pointTable->currentItem();
                if(currentItem)
                {
                    currentItem->setText("");
                }
                return;
            }
            QPointF centerPoint(yCoordinate, xCoordinate);
            pointDefineSeries->append(centerPoint.x(), centerPoint.y());
        }
    });
    //切换手动模式
    connect(ui->manualModeBtn,&QPushButton::clicked,this,[this](){
        //        if(isMeasuringStatus == true)
        //        {
        //            return;
        //        }
        isManual = true;
        isAuto = false;
    });
    //切换为自动模式
    connect(ui->autoModeBtn, &QPushButton::clicked, this, [=]() {
        int reply = myHelper::ShowMessageBoxQuesion("请确认手动测硬度是否已经结束，并且夹持气缸已经松开，工作台面已经下降到位？");
        if(reply == QDialog::Accepted)
        {
            isManualing = false;
            if (!controllerInitStatus) {
                return;
            }
            int autoMode = 0;
            byte autoChangeBuffer[2];
            S7_SetWordAt(autoChangeBuffer, 0, static_cast<uint16_t>(autoMode));
            int res = snap7_plc->DBWrite(writeDbNum, 4, 2, &autoChangeBuffer);
            if (res == 0 ) {
                isAuto = true;
                isManual = false;
                isManualBlock = false;
                isManualHardness = false;

                ui->label_manualBlock->setStyleSheet("background-color:gray;border-radius: 15px");
                ui->label_manualHardness->setStyleSheet("background-color:gray;border-radius: 15px");
                ui->manualHardness->setStyleSheet(hoverPushButtonStyle);
                ui->manualStdBlock->setStyleSheet(hoverPushButtonStyle);

            }
        }
        if(reply == QDialog::Rejected)
        {
            isManualing = true;

        }

    });
    //故障清除
    connect(ui->cancelWarningBtn,&QPushButton::clicked,this,[this](){
        if(!controllerInitStatus)
        {
            return;
        }
        if(oneConObject.warningStatus == 0)
        {
            myHelper::ShowMessageBoxInfo("设备正常，无需清除故障！");
            return;
        }
        int clearWarningSignal = 1;
        byte clearWarningSignalBuffer[2];
        S7_SetWordAt(clearWarningSignalBuffer,0,static_cast<uint16_t>(clearWarningSignal));
        int res = snap7_plc->DBWrite(writeDbNum,20,2,&clearWarningSignalBuffer);
        if(res == 0)
        {
            //warning = "background-color:gray;border-radius: 26px;";
            ui->warningLabel->setPixmap(QPixmap(":/img/images/normalAlarm.png"));
            QTimer::singleShot(200,this,[=](){
                int clearSignal = 0;
                byte clearSignalBuffer[2];
                S7_SetWordAt(clearSignalBuffer,0,static_cast<uint16_t>(clearSignal));
                snap7_plc->DBWrite(writeDbNum,20,2,&clearSignalBuffer);
            });
        }
    });
    //开始检测按钮
    connect(ui->startDetectionBtn,&QPushButton::clicked,this,[this](){

        if(!controllerInitStatus)
        {
            return;
        }
        if(isMeasuringStatus)
        {
            myHelper::ShowMessageBoxInfo("正在检测中。。。");
            return;
        }

        int typeIndex = ui->measurePointCodeList->currentIndex();
        ui->measurePointTable->setRowCount(0);
        //发送点位数据和检测类型
        int reply =  myHelper::ShowMessageBoxQuesion("确定要检测此类型钢板吗？");
        if(reply == QDialog::Accepted)
        {

            //从数据库查询点位
            QVector<PointList> p_list;
            QVector<QPointF> p_points;
            oper.getPointListByCode(p_list, ui->measurePointCodeList->currentText());
            //第一套点位分组
            QVector<QPointF> p1;
            QVector<QPointF> p2;
            QVector<QPointF> p3;
            //第二套点位分组
            QVector<QPointF> p4;
            QVector<QPointF> p5;
            QVector<QPointF> p6;
            QVector<QPointF> firstSet;
            QVector<QPointF> secondSet;
            for(int i=0;i<p_list.size();i++)
            {
                p_points.push_back(QPointF(p_list[i].xVal, p_list[i].yVal));
            }
            for(int i=0;i<p_points.size()/2;i++)
            {
                firstSet.push_back(p_points[i]);
            }
            for(int j=p_points.size()/2;j<p_points.size();j++)
            {
                secondSet.push_back(p_points[j]);
            }

            for(int i = 0; i < 3; ++i){
                QVector<QPointF>::const_iterator First = firstSet.begin() + i*6;
                QVector<QPointF>::const_iterator Second = firstSet.begin() + (i+1)*6;
                vector<QPointF> tempP1;
                tempP1.assign(First, Second);
                if(i == 0){
                    p1.clear();
                    p1 = QVector<QPointF>::fromStdVector(tempP1);

                }else if(i == 1){
                    p2.clear();
                    p2 = QVector<QPointF>::fromStdVector(tempP1);
                }else if(i == 2){
                    p3.clear();
                    p3 = QVector<QPointF>::fromStdVector(tempP1);
                }
            }

            for(int i = 0; i < 3; ++i){
                QVector<QPointF>::const_iterator First = secondSet.begin() + i*6;
                QVector<QPointF>::const_iterator Second = secondSet.begin() + (i+1)*6;
                vector<QPointF> tempP2;
                tempP2.assign(First, Second);
                if(i == 0){
                    p4.clear();
                    p4 = QVector<QPointF>::fromStdVector(tempP2);

                }else if(i == 1){
                    p5.clear();
                    p5 = QVector<QPointF>::fromStdVector(tempP2);
                }else if(i == 2){
                    p6.clear();
                    p6 = QVector<QPointF>::fromStdVector(tempP2);
                }
            }

            int xfirstCount = 0;
            int yfirstCount = 0;
            int xSecondCount = 0;
            int ySecondCount = 0;

            //选中第一套点位
            if(ui->firstSet->isChecked())
            {
                qDebug() << "第一套点位集合：";
                qDebug() << p1;
                qDebug() << p2;
                qDebug() << p3;
                for(int i = 0; i < 6; i++){
                    if(p1[i].y() != 0){
                        yfirstCount = yfirstCount + 1;
                        if(typeIndex <= 6 && typeIndex >= 1){
                            p1[i].setY(p1[i].y() + 30);
                            //                            p2[i].setY(p2[i].y() + 30);
                            //                        p3[i].setY(p3[i].y() - 200);
                        }
                        else if(typeIndex == 7){
                            p1[i].setY(p1[i].y() - 1000);
                            //                            p2[i].setY(p2[i].y() - 1000);
                            //                        p3[i].setY(p3[i].y() - 1000);
                        }
                        if(typeIndex == 8)
                        {
                            p1[i].setY(p1[i].y() + 30);
                        }
                        if(typeIndex == 9)
                        {
                            p1[i].setY(p1[i].y() + 30);
                        }
                        if(p1[i].x()!=0)
                        {
                            p1[i].setX(2266 - p1[i].x());
                        }
                        if(p2[i].x()!=0)
                        {
                            p2[i].setX(2266 - p2[i].x());
                        }
                        if(p3[i].x()!=0)
                        {
                            p3[i].setX(2266 - p3[i].x());
                        }

                    }


                    //发送Y1-Y6
                    byte Y_buffer[2]; // 存储非零y坐标的个数的字节缓冲区
                    S7_SetWordAt(Y_buffer, 0, static_cast<uint16_t>(p1[i].y()));
                    snap7_plc->DBWrite(writeDbNum, 26+2*i, 2, &Y_buffer);

                    //发送Y1-X1 Y1-X2 Y1-X3 .。。。。。
                    qDebug() << QString("y%1: %2------%3").arg(i+1).arg(26+2*i).arg(p1[i].y());
                    qDebug() << "x1:" << 38+6*i << p1[i].x();
                    qDebug() << "x2:" << 40+6*i << p2[i].x();
                    qDebug() << "x3:" << 42+6*i << p3[i].x();

                    byte X1_buffer[2];
                    S7_SetWordAt(X1_buffer, 0, static_cast<uint16_t>(p1[i].x()));
                    snap7_plc->DBWrite(writeDbNum, 38+6*i, 2, &X1_buffer);


                    byte X2_buffer[2];
                    S7_SetWordAt(X2_buffer, 0, static_cast<uint16_t>(p2[i].x()));
                    snap7_plc->DBWrite(writeDbNum, 40+6*i, 2, &X2_buffer);

                    byte X3_buffer[2];
                    S7_SetWordAt(X3_buffer, 0, static_cast<uint16_t>(p3[i].x()));
                    snap7_plc->DBWrite(writeDbNum, 42+6*i, 2, &X3_buffer);

                }
                qDebug() << "第一套y个数:" << yfirstCount;
                //计算X轴个数
                for(int i = 0; i < 6; i++){
                    if(p1[i].y() != 0){
                        xfirstCount = xfirstCount + 1;
                        break;
                    }
                }
                for(int i = 0; i < 6; i++){
                    if(p2[i].y() != 0){
                        xfirstCount = xfirstCount + 1;
                        break;
                    }
                }
                for(int i = 0; i < 6; i++){
                    if(p3[i].y() != 0){
                        xfirstCount = xfirstCount + 1;
                        break;
                    }
                }
                qDebug() <<"第一套x个数" << xfirstCount;
                //发送X轴个数
                byte XCount_buffer[2];
                S7_SetWordAt(XCount_buffer, 0, static_cast<uint16_t>(xfirstCount));
                snap7_plc->DBWrite(writeDbNum, 24, 2, &XCount_buffer);
                //发送Y轴个数
                byte YCount_buffer[2];
                S7_SetWordAt(YCount_buffer, 0, static_cast<uint16_t>(yfirstCount));
                snap7_plc->DBWrite(writeDbNum, 22, 2, &YCount_buffer);
                // 自动测硬度启动
                int startDetection = 1;
                byte startDetectionBuffer[2];
                S7_SetWordAt(startDetectionBuffer, 0, static_cast<uint16_t>(startDetection));
                int res = snap7_plc->DBWrite(writeDbNum, 74, 2, &startDetectionBuffer);
                if (res == 0) {
                    isMeasuringStatus = true;
                    ui->startDetectionBtn->setText("正在检测");
                    ui->startDetectionBtn->setStyleSheet("QPushButton{"
                                                         "color: #ffffff;"
                                                         "background-color: green;"
                                                         "border-width: 1px;"
                                                         "border-color: #183881;"
                                                         "border-style: solid;"
                                                         "padding: 5px;"
                                                         "border-radius:5px;"
                                                         "font: 25pt \"Microsoft YaHei\";"
                                                         "font-size:40pt}");
                    QTimer::singleShot(200, this, [=]() {
                        // 200ms 后自动清零
                        int endDetection = 0;  // 不自动测试硬度
                        byte endDetectionBuffer[2];
                        S7_SetWordAt(endDetectionBuffer, 0, static_cast<uint16_t>(endDetection));
                        snap7_plc->DBWrite(writeDbNum, 74, 2, &endDetectionBuffer);
                    });
                }
            }
            //选中第二套点位
            if(ui->secondSet->isChecked())
            {
                qDebug() << "第二套点位集合：";
                qDebug() << p4;
                qDebug() << p5;
                qDebug() << p6;
                for(int i = 0; i < 6; i++){
                    if(p4[i].y() != 0){
                        ySecondCount = ySecondCount + 1;
                        if(typeIndex <= 6 && typeIndex >= 1){
                            p4[i].setY(p4[i].y() + 30);
                            //                        p2[i].setY(p2[i].y() - 200);
                            //                        p3[i].setY(p3[i].y() - 200);
                        }
                        if(typeIndex == 7){
                            p4[i].setY(p4[i].y() - 1000);
                            //                        p2[i].setY(p2[i].y() - 1000);
                            //                        p3[i].setY(p3[i].y() - 1000);
                        }
                        if(typeIndex == 8)
                        {
                            p1[i].setY(p1[i].y() + 30);
                        }
                        if(typeIndex == 9)
                        {
                            p1[i].setY(p1[i].y() + 30);
                        }
                        if(p4[i].x()!=0)
                        {
                            p4[i].setX(2266 - p4[i].x());
                        }
                        if(p5[i].x()!=0)
                        {
                            p5[i].setX(2266 - p5[i].x());
                        }
                        if(p6[i].x()!=0)
                        {
                            p6[i].setX(2266 - p6[i].x());
                        }

                    }

                    //发送Y1-Y6
                    byte Y_buffer[2]; // 存储非零y坐标的个数的字节缓冲区
                    S7_SetWordAt(Y_buffer, 0, static_cast<uint16_t>(p4[i].y()));
                    snap7_plc->DBWrite(writeDbNum, 26+2*i, 2, &Y_buffer);

                    //发送Y1-X1 Y1-X2 Y1-X3 .。。。。。
                    qDebug() << QString("y%1: %2------%3").arg(i+1).arg(26+2*i).arg(p4[i].y());
                    qDebug() << "x1:" << 38+6*i << p4[i].x();
                    qDebug() << "x2:" << 40+6*i << p5[i].x();
                    qDebug() << "x3:" << 42+6*i << p6[i].x();

                    byte X1_buffer[2];
                    S7_SetWordAt(X1_buffer, 0, static_cast<uint16_t>(p4[i].x()));
                    snap7_plc->DBWrite(writeDbNum, 38+6*i, 2, &X1_buffer);


                    byte X2_buffer[2];
                    S7_SetWordAt(X2_buffer, 0, static_cast<uint16_t>(p5[i].x()));
                    snap7_plc->DBWrite(writeDbNum, 40+6*i, 2, &X2_buffer);

                    byte X3_buffer[2];
                    S7_SetWordAt(X3_buffer, 0, static_cast<uint16_t>(p6[i].x()));
                    snap7_plc->DBWrite(writeDbNum, 42+6*i, 2, &X3_buffer);

                }
                qDebug() << "第二套y个数：" <<ySecondCount;
                //计算X轴个数
                for(int i = 0; i < 6; i++){
                    if(p4[i].y() != 0){
                        xSecondCount = xSecondCount + 1;
                        break;
                    }
                }
                for(int i = 0; i < 6; i++){
                    if(p5[i].y() != 0){
                        xSecondCount = xSecondCount + 1;
                        break;
                    }
                }
                for(int i = 0; i < 6; i++){
                    if(p6[i].y() != 0){
                        xSecondCount = xSecondCount + 1;
                        break;
                    }
                }

                qDebug() << "第二套x个数" << xSecondCount;
                //发送X轴个数
                byte XCount_buffer[2];
                S7_SetWordAt(XCount_buffer, 0, static_cast<uint16_t>(xSecondCount));
                snap7_plc->DBWrite(writeDbNum, 24, 2, &XCount_buffer);
                //发送Y轴个数
                byte YCount_buffer[2];
                S7_SetWordAt(YCount_buffer, 0, static_cast<uint16_t>(ySecondCount));
                snap7_plc->DBWrite(writeDbNum, 22, 2, &YCount_buffer);
                // 自动测硬度启动
                int startDetection = 1;
                byte startDetectionBuffer[2];
                S7_SetWordAt(startDetectionBuffer, 0, static_cast<uint16_t>(startDetection));
                int res = snap7_plc->DBWrite(writeDbNum, 74, 2, &startDetectionBuffer);
                if (res == 0) {
                    isMeasuringStatus = true;
                    ui->startDetectionBtn->setText("正在检测");
                    ui->startDetectionBtn->setStyleSheet("QPushButton{"
                                                         "color: #ffffff;"
                                                         "background-color: green;"
                                                         "border-width: 1px;"
                                                         "border-color: #183881;"
                                                         "border-style: solid;"
                                                         "padding: 5px;"
                                                         "border-radius:5px;"
                                                         "font: 25pt \"Microsoft YaHei\";"
                                                         "font-size:40pt}");
                    QTimer::singleShot(200, this, [=]() {
                        // 200ms 后自动清零
                        int endDetection = 0;  // 不自动测试硬度
                        byte endDetectionBuffer[2];
                        S7_SetWordAt(endDetectionBuffer, 0, static_cast<uint16_t>(endDetection));
                        snap7_plc->DBWrite(writeDbNum, 74, 2, &endDetectionBuffer);
                    });
                }
            }

        }
    });
    //切换手动打硬度
    connect(ui->manualHardness,&QPushButton::clicked,this,[=](){
        int reply = myHelper::ShowMessageBoxQuesion("请确认是手动测硬度模式而不是手动测标块模式！请再次确认！");
        if(reply == QDialog::Accepted)
        {
            if(controllerInitStatus == false)
            {
                return;
            }
            if(isAuto){
                myHelper::ShowMessageBoxInfo("请切换手动模式");
                return;
            }
            if(isMeasuringStatus){
                myHelper::ShowMessageBoxInfo("正在自动检测中。。。");
                return;
            }
            if(isManualHardness)
            {
                myHelper::ShowMessageBoxInfo("已经处于手动打硬度模式");
                return;
            }
            if(oneConObject.modelChange == 0)
            {
                myHelper::ShowMessageBoxInfo("当前为原厂模式，请先切换为新模式！");
                return;
            }
            int manualHardnessMode = 1;
            byte manualHardnessBuffer[2];
            S7_SetWordAt(manualHardnessBuffer,0,static_cast<uint16_t>(manualHardnessMode));
            snap7_plc->DBWrite(writeDbNum,4,2,&manualHardnessBuffer);
        }
        if(reply == QDialog::Rejected)
        {
            return;
        }


    });
    //台面上升并夹持钢板
    connect(ui->risingAndClampBtn,&QPushButton::clicked,this,[=](){
        if(!controllerInitStatus)
        {
            return;
        }
        if(!isManualHardness)
        {
            myHelper::ShowMessageBoxInfo("请先切换到手动测硬度模式！");
            return;
        }
        int reply = myHelper::ShowMessageBoxQuesion("请检测并确认工作台上是否存在钢板(有钢板点击“确定”，没有钢板点击“取消”)!");
        if(reply == QDialog::Accepted)
        {
            int risingSignal = 1;
            byte risingSignalBuffer[2];
            S7_SetWordAt(risingSignalBuffer, 0, static_cast<uint16_t>(risingSignal));
            int res = snap7_plc->DBWrite(writeDbNum, 78, 2, &risingSignalBuffer);
            if (res == 0) {
                ui->risingAndClampBtn->setStyleSheet(pushButtonGreenStyle);
                ui->dropingAndloosingBtn->setStyleSheet(hoverPushButtonStyle);
                QTimer::singleShot(200, this, [=]() {
                    // 200ms 后自动清零
                    int risingSignalEnd = 0;
                    byte risingSignalEndBuffer[2];
                    S7_SetWordAt(risingSignalEndBuffer, 0, static_cast<uint16_t>(risingSignalEnd));
                    snap7_plc->DBWrite(writeDbNum, 78, 2, &risingSignalEndBuffer);
                    ui->risingAndClampBtn->setStyleSheet(hoverPushButtonStyle);
                });
            }
        }
    });
    //台面下降并松开夹持
    connect(ui->dropingAndloosingBtn,&QPushButton::clicked,this,[=](){
        if(!controllerInitStatus)
        {
            return;
        }
        if(!isManualHardness)
        {
            myHelper::ShowMessageBoxInfo("请先切换到手动测硬度模式！");
            return;
        }
        int loosingSignal = 1;
        byte loosingSignalBuffer[2];
        S7_SetWordAt(loosingSignalBuffer, 0, static_cast<uint16_t>(loosingSignal));
        int res = snap7_plc->DBWrite(writeDbNum, 80, 2, &loosingSignalBuffer);
        if (res == 0) {
            ui->risingAndClampBtn->setStyleSheet(hoverPushButtonStyle);
            ui->dropingAndloosingBtn->setStyleSheet(pushButtonGreenStyle);
            QTimer::singleShot(200, this, [=]() {
                // 200ms 后自动清零
                int loosingSignalEnd = 0;
                byte loosingSignalEndBuffer[2];
                S7_SetWordAt(loosingSignalEndBuffer, 0, static_cast<uint16_t>(loosingSignalEnd));
                snap7_plc->DBWrite(writeDbNum, 80, 2, &loosingSignalEndBuffer);
                ui->dropingAndloosingBtn->setStyleSheet(hoverPushButtonStyle);
            });
        }

    });
    //手动测硬度模式数据导出
    connect(ui->exportManualDataBtn,&QPushButton::clicked,this,[=](){

        if(ui->manualTableWidget->rowCount()==0)
        {
            myHelper::ShowMessageBoxInfo("没有数据可供导出！");
            return;
        }
        QXlsx::Document xlsx;

        int columnCount = ui->manualTableWidget->colorCount();
        int rowCount = ui->manualTableWidget->rowCount();
        // 写入表列名
        for (int column = 0; column < columnCount; ++column) {
            QTableWidgetItem* headerItem = ui->manualTableWidget->horizontalHeaderItem(column);
            if (headerItem != nullptr) {
                QString headerText = headerItem->text();
                xlsx.write(1, column + 1, headerText);
            }
        }

        // 写入表格数据
        for (int row = 0; row < rowCount; ++row) {
            for (int column = 0; column < columnCount; ++column) {
                QTableWidgetItem* item = ui->manualTableWidget->item(row, column);
                if (item != nullptr) {
                    QString text = item->text();
                    xlsx.write(row + 2, column + 1, text);
                }
            }
        }
        QString filePath = QFileDialog::getSaveFileName(this, "保存Excel文件", "", "Excel 文件 (*.xlsx)");
        if (!filePath.isEmpty()) {
            if (xlsx.saveAs(filePath)) {
                myHelper::ShowMessageBoxInfo("导出成功！");
            } else {
                myHelper::ShowMessageBoxError("导出失败！");
            }
        }

    });
    //修改表格
    connect(ui->tableWidget,&QTableWidget::itemChanged,[=](QTableWidgetItem *item){
        int col = item->column();
        if(col==6)
        {
            QString data = item->text();
            if(data=="合格")
            {
                QColor okColor("#00B700");
                item->setBackgroundColor(okColor);
            }
            if(data=="不合格")
            {
                QColor ngColor("#DB0000");
                item->setBackgroundColor(ngColor);
            }

        }
    });
    //最终数据导出Excel表格
    connect(ui->exportBtn, &QPushButton::clicked, this, [=]() {
        if(isMeasuringStatus)
        {
            myHelper::ShowMessageBoxInfo("正在测量中。。。");
        }
        // 检查表格中是否有数据
        if (ui->tableWidget->rowCount() == 0) {
            myHelper::ShowMessageBoxInfo("没有数据可供导出！");
            return;
        }

        // 创建Excel文档对象
        QXlsx::Document xlsx;

        // 获取表格列数和行数
        int columnCount = ui->tableWidget->columnCount();
        int rowCount = ui->tableWidget->rowCount();

        // 写入表列名
        QStringList headerLabels;
        for (int column = 0; column < columnCount; ++column) {
            QTableWidgetItem* headerItem = ui->tableWidget->horizontalHeaderItem(column);
            if (headerItem != nullptr) {
                QString headerText = headerItem->text();
                headerLabels.append(headerText);

                xlsx.write(1, column + 1, headerText);
            }
        }

        // 写入表格数据
        for (int row = 0; row < rowCount; ++row) {
            for (int column = 0; column < columnCount; ++column) {
                QTableWidgetItem* item = ui->tableWidget->item(row, column);
                if (item != nullptr) {
                    QString text = item->text();
                    xlsx.write(row + 2, column + 1, text);
                }
            }
        }

        // 设置列宽和自动筛选
        for (int column = 0; column < columnCount; ++column) {
            xlsx.setColumnWidth(column + 1, 15);
        }
        // 弹出文件保存对话框并导出Excel文件
        QString filePath = QFileDialog::getSaveFileName(this, "保存Excel文件", "", "Excel 文件 (*.xlsx)");
        if (!filePath.isEmpty()) {
            if (xlsx.saveAs(filePath)) {
                myHelper::ShowMessageBoxInfo("导出成功！");
            } else {
                myHelper::ShowMessageBoxError("导出失败！");
            }
        }
    });
    //切换手动打标块
    connect(ui->manualStdBlock,&QPushButton::clicked,this,[=](){
        int reply = myHelper::ShowMessageBoxQuesion("请确认是手动测标块模式而不是手动测硬度模式！只有硬度仪打硬度处于停止状态，方可切换到手动手动打标块。请再次确认！");
        if(reply == QDialog::Accepted)
        {
            if(controllerInitStatus == false)
            {
                return;
            }
            if(isAuto){
                myHelper::ShowMessageBoxInfo("请切换手动模式");
                return;
            }
            if(isMeasuringStatus == true){
                myHelper::ShowMessageBoxInfo("正在自动检测中。。。");
                return;
            }
            if(isManualBlock)
            {
                myHelper::ShowMessageBoxInfo("已经处于手动打标块模式");
                return;
            }
            if(oneConObject.modelChange == 0)
            {
                myHelper::ShowMessageBoxInfo("当前为原厂模式，请先切换为新模式！");
                return;
            }
            int manualBlockMode = 2;
            byte manualBlockBuffer[2];
            S7_SetWordAt(manualBlockBuffer,0,static_cast<uint16_t>(manualBlockMode));
            snap7_plc->DBWrite(writeDbNum,4,2,&manualBlockBuffer);
        }

        if(reply == QDialog::Rejected)
        {
            return;
        }


    });
    //下料床传输至待检区
    connect(ui->cuttingBedToPendingArea,&QPushButton::clicked,this,&PlateWidget::plateToDetection);

}
//初始化PLC连接
void PlateWidget::initPLC()
{
    snap7_plc = new PLC_Siemens(this);
    snap7_plc->setConnectType(CONNTYPE_OP);//设置连接方式，避免变成软件连不上PLC了，必须在连接之前设置
    int ok = snap7_plc->connectByIP(myHelper::readSettings("GPLC/IP").toString(),
                                    myHelper::readSettings("GPLC/Rack").toInt(),
                                    myHelper::readSettings("GPLC/Slot").toInt());
    readDbNum = myHelper::readSettings("GPLC/readDB").toInt();//11
    writeDbNum = myHelper::readSettings("GPLC/writeDB").toInt();//12
    readCountDbNum = myHelper::readSettings("GPLC/readCountDB").toInt(); //22
    //    QString error = snap7_plc->ErrorText(ok);
    //    qDebug() << "snap7_plc connect :" << error;
    if(ok == 0){
        ui->label_3->setStyleSheet(normal_radius);
        controllerInitStatus = true;
        int autoMode = 0;
        byte autoChangeBuffer[2];
        S7_SetWordAt(autoChangeBuffer,0, static_cast<uint16_t>(autoMode));
        snap7_plc->DBWrite(writeDbNum,4,2,&autoChangeBuffer);

        connect(&timeReadController, &QTimer::timeout, [this](){
            readControllerObject();
        });
        timeReadController.start(100);
    }else{
        ui->label_3->setStyleSheet(fail_radius);
        controllerInitStatus = false;
        ui->manualHardness->setEnabled(false);
        ui->manualStdBlock->setEnabled(false);
        //        ui->startDetectionBtn->setEnabled(false);
        ui->risingAndClampBtn->setEnabled(false);
        ui->dropingAndloosingBtn->setEnabled(false);
        ui->cancelWarningBtn->setEnabled(false);
        ui->cuttingBedToPendingArea->setEnabled(false);
    }
}
//窗口关闭事件
void PlateWidget::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event)
    if(isMeasuringStatus == true){
        myHelper::ShowMessageBoxInfo("正在检测中,不能关闭程序");
        event->ignore();
    }else{
        event->accept();
    }
}

//读取PLC数据
void PlateWidget::readControllerObject()
{

    //DB11
    byte readByte[72]; // 假设需要读取的数据长度为 46字节 (24 个 Word)
    snap7_plc->DBRead(readDbNum, 0, 72, readByte); // 从偏移量 26 开始读取 48 字节的数据,读到72
    //新旧模式状态显示
    //    qDebug() << oneConObject.modelChange;
    if(oneConObject.modelChange == 0)
    {
        ui->label_oldMode->setStyleSheet(normal_radius);
    }
    controllerObject.modelChange = S7_GetWordAt(readByte,26);
    if(S7_GetWordAt(readByte,26) != oneConObject.modelChange)
    {
        oneConObject.modelChange = S7_GetWordAt(readByte,26);
        //旧模式状态----------0
        if(oneConObject.modelChange == 0)
        {
            ui->label_oldMode->setStyleSheet(normal_radius);
            ui->label_newMode->setStyleSheet("background-color:gray;border-radius: 15px");
        }
        //新模式状态----------1

        if(oneConObject.modelChange == 1)
        {
            ui->label_newMode->setStyleSheet(normal_radius);
            ui->label_oldMode->setStyleSheet("background-color:gray;border-radius: 15px");
        }
    }
    //plc返回的x坐标
    controllerObject.xCoordinate = S7_GetWordAt(readByte,64);
    if(S7_GetWordAt(readByte,64) != oneConObject.xCoordinate)
    {
        oneConObject.xCoordinate = S7_GetWordAt(readByte,64);
    }
    //plc返回的y坐标
    controllerObject.yCoordinate = S7_GetWordAt(readByte,66);
    if(S7_GetWordAt(readByte,66) != oneConObject.yCoordinate)
    {
        oneConObject.yCoordinate = S7_GetWordAt(readByte,66);
    }
    //plc返回的硬度值
    controllerObject.hardness = S7_GetWordAt(readByte,28);
    if(S7_GetWordAt(readByte,28) != oneConObject.hardness)
    {
        oneConObject.hardness = S7_GetWordAt(readByte,28);
    }
    //plc返回的硬度仪状态
    controllerObject.hardnessStatus = S7_GetWordAt(readByte,30);
    if(S7_GetWordAt(readByte,30) != oneConObject.hardnessStatus)
    {
        oneConObject.hardnessStatus = S7_GetWordAt(readByte,30);
        //手动模式数据显示
        if(oneConObject.hardnessStatus == 3 && oneConObject.hardness!=0 && isManualHardness)
        {
            manualModeGetData();
        }
        //自动模式数据显示
        if(oneConObject.hardnessStatus == 3 && oneConObject.hardness != 0 && isMeasuringStatus)
        {
            autoModeGetData();
        }
        //标准硬度值显示
        if(oneConObject.hardnessStatus == 3 && oneConObject.hardness!=0 && isManualBlock)
        {
            ui->Edit_standardHardness->setText(QString::number(oneConObject.hardness / 10));
            ui->Edit_standardDiameter->setText(QString::number(calculateDiameter(oneConObject.hardness / 10),'f',3));
            //将标准数据保存为Excel
            int standardHardness = oneConObject.hardness / 10;
            double standardDiameter = QString::number(calculateDiameter(oneConObject.hardness / 10),'f',3).toDouble();
            writeStandardDataToExcel(standardHardness,standardDiameter);
        }
    }
    //    qDebug() << controllerObject.modelChange;
    //手动切换到自动状态返回
    controllerObject.manualToAuto = S7_GetWordAt(readByte,32);
    if(S7_GetWordAt(readByte,32) != oneConObject.manualToAuto)
    {
        oneConObject.manualToAuto = S7_GetWordAt(readByte,32);

    }
    //手动测硬度状态返回
    controllerObject.manualToHardness = S7_GetWordAt(readByte,34);
    if(S7_GetWordAt(readByte,34) != oneConObject.manualToHardness)
    {
        oneConObject.manualToHardness = S7_GetWordAt(readByte,34);
        if(oneConObject.manualToHardness == 1)
        {
            ui->manualHardness->setStyleSheet(pushButtonGreenStyle);
            isManualHardness = true;
            ui->manualStdBlock->setStyleSheet(hoverPushButtonStyle);
            manualHardnessStr = normal_radius;
            manualBlockStr = "background-color:gray;border-radius: 15px";
            ui->label_manualHardness->setStyleSheet(manualHardnessStr);
            ui->label_manualBlock->setStyleSheet(manualBlockStr);
        }
        if(oneConObject.manualToHardness == 0)
        {
            isManualHardness = false;
        }

    }
    //手动测标块状态返回
    controllerObject.manualToBlock = S7_GetWordAt(readByte,36);
    if(S7_GetWordAt(readByte,36) != oneConObject.manualToBlock)
    {
        oneConObject.manualToBlock = S7_GetWordAt(readByte,36);
        if(oneConObject.manualToBlock == 1)
        {
            ui->manualStdBlock->setStyleSheet(pushButtonGreenStyle);
            isManualBlock = true;
            ui->manualHardness->setStyleSheet(hoverPushButtonStyle);
            manualHardnessStr = "background-color:gray;border-radius: 15px";
            manualBlockStr = normal_radius;
            ui->label_manualHardness->setStyleSheet(manualHardnessStr);
            ui->label_manualBlock->setStyleSheet(manualBlockStr);
        }
        if(oneConObject.manualToBlock == 0)
        {
            isManualBlock = false;
        }
    }
    //报警提示
    controllerObject.warningStatus = S7_GetWordAt(readByte,38);
    if(S7_GetWordAt(readByte,38) != oneConObject.warningStatus)
    {
        oneConObject.warningStatus = S7_GetWordAt(readByte,38);
        if(oneConObject.warningStatus == 1)
        {
//            warning = "background-color:#F42215;border-radius: 26px";
//            ui->warningLabel->setStyleSheet(warning);
            ui->warningLabel->setPixmap(QPixmap(":/img/images/redAlarm.png"));
        }
        if(oneConObject.warningStatus == 0)
        {
//            warning = "background-color:gray;border-radius: 26px";
//            ui->warningLabel->setStyleSheet(warning);
            ui->warningLabel->setPixmap(QPixmap(":/img/images/normalAlarm.png"));
        }
    }
    //自动检测完成信号返回
    controllerObject.autoDetectionFinish = S7_GetWordAt(readByte,40);
    if(S7_GetWordAt(readByte,40) != oneConObject.autoDetectionFinish)
    {
        oneConObject.autoDetectionFinish = S7_GetWordAt(readByte,40);
        if(oneConObject.autoDetectionFinish == 1)
        {
            myHelper::ShowMessageBoxInfo("检测完成！");
            ui->startDetectionBtn->setText("开始检测");
            ui->startDetectionBtn->setStyleSheet("QPushButton{"
                                                 "color: #000000;"
                                                 "background-color: #A49E97;"
                                                 "border-width: 1px;"
                                                 "border-color: #183881;"
                                                 "border-style: solid;"
                                                 "padding: 5px;"
                                                 "border-radius:5px;"
                                                 "font: 25pt \"Microsoft YaHei\";"
                                                 "font-size:40pt}");
            isMeasuringStatus = false;
            ui->startDetectionBtn->hide();
            //X,Y清零
            for(int i=0;i<6;i++)
            {
                byte clearYBuffer[2];
                S7_SetWordAt(clearYBuffer, 0, static_cast<uint16_t>(0));
                snap7_plc->DBWrite(writeDbNum, 26+2*i, 2, &clearYBuffer);

                byte clearX1Buffer[2];
                S7_SetWordAt(clearX1Buffer, 0, static_cast<uint16_t>(0));
                snap7_plc->DBWrite(writeDbNum, 38+6*i, 2, &clearX1Buffer);


                byte clearX2Buffer[2];
                S7_SetWordAt(clearX2Buffer, 0, static_cast<uint16_t>(0));
                snap7_plc->DBWrite(writeDbNum, 40+6*i, 2, &clearX2Buffer);

                byte clearX3Buffer[2];
                S7_SetWordAt(clearX3Buffer, 0, static_cast<uint16_t>(0));
                snap7_plc->DBWrite(writeDbNum, 42+6*i, 2, &clearX3Buffer);

            }
            //X，Y个数清零

            byte clearXCountBuffer[2];
            S7_SetWordAt(clearXCountBuffer, 0, 0);
            snap7_plc->DBWrite(writeDbNum, 24, 2, &clearXCountBuffer);

            byte clearYCountBuffer[2];
            S7_SetWordAt(clearYCountBuffer, 0, 0);
            snap7_plc->DBWrite(writeDbNum, 22, 2, &clearYCountBuffer);

        }
    }
    controllerObject.manualDetectingBlock = S7_GetWordAt(readByte,42);
    if(S7_GetWordAt(readByte,42) != oneConObject.manualDetectingBlock)
    {
        oneConObject.manualDetectingBlock = S7_GetWordAt(readByte,42);
        if(oneConObject.manualDetectingBlock == 1)
        {
            isManualBlock = true;
        }
    }
    controllerObject.manualDetectingHardness = S7_GetWordAt(readByte,44);
    if(S7_GetWordAt(readByte,44) != oneConObject.manualDetectingHardness)
    {
        oneConObject.manualDetectingHardness = S7_GetWordAt(readByte,44);
        if(oneConObject.manualDetectingHardness == 1)
        {
            isManualHardness = true;
        }
    }
    controllerObject.plateBlanking = S7_GetWordAt(readByte,46);
    //暂时未处理
    if(S7_GetWordAt(readByte,46) != oneConObject.plateBlanking)
    {
        oneConObject.plateBlanking = S7_GetWordAt(readByte,46);
    }
    controllerObject.airSupplyWarning = S7_GetWordAt(readByte,48);
    if(S7_GetWordAt(readByte,48) != oneConObject.airSupplyWarning)
    {
        oneConObject.airSupplyWarning = S7_GetWordAt(readByte,48);
        if(oneConObject.airSupplyWarning == 1)
        {
            myHelper::ShowMessageBoxError("气源压力报警！");
            writeWarningMessage(QString("气源压力报警！"));
            return;
        }
    }
    controllerObject.hardnessDeviceWarning = S7_GetWordAt(readByte,50);
    if(S7_GetWordAt(readByte,50) != oneConObject.hardnessDeviceWarning)
    {
        oneConObject.hardnessDeviceWarning = S7_GetWordAt(readByte,50);
        if(oneConObject.hardnessDeviceWarning == 1)
        {
            myHelper::ShowMessageBoxError("硬度仪异常报警！");
            writeWarningMessage(QString("硬度仪异常报警！"));
            return;
        }
    }
    controllerObject.oldModeContactorWarning = S7_GetWordAt(readByte,52);
    if(S7_GetWordAt(readByte,52) != oneConObject.oldModeContactorWarning)
    {
        oneConObject.oldModeContactorWarning = S7_GetWordAt(readByte,52);
        if(oneConObject.oldModeContactorWarning == 1)
        {
            myHelper::ShowMessageBoxError("原厂回路接触器报警！");
            writeWarningMessage(QString("原厂回路接触器报警！"));
            return;
        }
    }
    controllerObject.newModeContactorWarning = S7_GetWordAt(readByte,54);
    if(S7_GetWordAt(readByte,54) != oneConObject.newModeContactorWarning)
    {
        oneConObject.newModeContactorWarning = S7_GetWordAt(readByte,54);
        if(oneConObject.newModeContactorWarning == 1)
        {
            myHelper::ShowMessageBoxError("新控制回路接触器报警！");
            writeWarningMessage(QString("新控制回路接触器报警！"));
            return;
        }
    }
    controllerObject.hardnessDeviceEmergency = S7_GetWordAt(readByte,56);
    if(S7_GetWordAt(readByte,56) != oneConObject.hardnessDeviceEmergency)
    {
        oneConObject.hardnessDeviceEmergency = S7_GetWordAt(readByte,56);

        if(oneConObject.hardnessDeviceEmergency == 1)
        {
            isMeasuringStatus = false;
            myHelper::ShowMessageBoxError("硬度仪控制盒急停按下报警！");
            ui->startDetectionBtn->setText("开始检测");
            ui->startDetectionBtn->setStyleSheet("QPushButton:hover{background-color: #0550A4;color: #ffffff;"
                                                 "border-radius:5px;font: 25pt \"Microsoft YaHei\";font-size:40pt}");
            writeWarningMessage(QString("硬度仪控制盒急停按下报警！"));
            return;

        }
    }
    controllerObject.modeChangeEmergency = S7_GetWordAt(readByte,58);
    if(S7_GetWordAt(readByte,58) != oneConObject.modeChangeEmergency)
    {
        oneConObject.modeChangeEmergency = S7_GetWordAt(readByte,58);

        if(oneConObject.modeChangeEmergency == 1)
        {
            isMeasuringStatus = false;
            myHelper::ShowMessageBoxError("模式切换控制盒急停按下报警！");
            ui->startDetectionBtn->setText("开始检测");
            ui->startDetectionBtn->setStyleSheet("QPushButton:hover{background-color: #0550A4;color: #ffffff;"
                                                 "border-radius:5px;font: 25pt \"Microsoft YaHei\";font-size:40pt}");
            writeWarningMessage(QString("模式切换控制盒急停按下报警！"));
            return;
        }
    }
    controllerObject.netWorkWarning = S7_GetWordAt(readByte,60);
    if(S7_GetWordAt(readByte,60) != oneConObject.netWorkWarning)
    {
        oneConObject.netWorkWarning = S7_GetWordAt(readByte,60);

        if(oneConObject.netWorkWarning == 1)
        {
            ui->networkStatus->setPixmap(QPixmap(":/img/images/offline.png"));
            myHelper::ShowMessageBoxError("硬度仪控制柜与机房网络通讯故障！");
            writeWarningMessage(QString("硬度仪控制柜与机房网络通讯故障！"));
            return;
        }
        if(oneConObject.netWorkWarning == 0)
        {
            ui->networkStatus->setPixmap(QPixmap(":/img/images/online.png"));
        }
    }
    controllerObject.hardnessDeviceContactorEmergency = S7_GetWordAt(readByte,62);
    if(S7_GetWordAt(readByte,62) != oneConObject.hardnessDeviceContactorEmergency)
    {
        oneConObject.hardnessDeviceContactorEmergency = S7_GetWordAt(readByte,62);

        if(oneConObject.hardnessDeviceContactorEmergency == 1)
        {
            isMeasuringStatus = false;
            myHelper::ShowMessageBoxError("硬度仪控制柜急停报警！");
            writeWarningMessage(QString("硬度仪控制柜急停报警！"));
            return;
        }
    }
    //    qDebug() << "硬度仪状态：" << controllerObject.hardnessStatus << "硬度值：" << controllerObject.hardness / 10 << "x坐标：" << 2266 -  controllerObject.xCoordinate
    //             << "y坐标：" << controllerObject.yCoordinate - 30;
    controllerObject.plateToBlankingBedStop = S7_GetWordAt(readByte,68);
    if(S7_GetWordAt(readByte,68) != oneConObject.plateToBlankingBedStop)
    {
        oneConObject.plateToBlankingBedStop = S7_GetWordAt(readByte,68);
        if(oneConObject.plateToBlankingBedStop == 1 && isAuto)
        {
            myHelper::ShowMessageBoxInfo("钢板已经到达下料区！");
        }
    }
    controllerObject.plateToDetectionBedStop = S7_GetWordAt(readByte,70);
    if(S7_GetWordAt(readByte,70) != oneConObject.plateToDetectionBedStop)
    {
        oneConObject.plateToDetectionBedStop = S7_GetWordAt(readByte,70);
        if(oneConObject.plateToDetectionBedStop == 1 && isAuto)
        {
            prepareToDetection();
        }
    }
    //DB22
    byte readCountByte[26];
    snap7_plc->DBRead(readCountDbNum,0,26,readCountByte);

    controllerObject.oneCount = S7_GetWordAt(readCountByte,0);
    controllerObject.twoCount = S7_GetWordAt(readCountByte,2);
    controllerObject.threeCount = S7_GetWordAt(readCountByte,4);
    controllerObject.fourCount = S7_GetWordAt(readCountByte,6);
    controllerObject.fiveCount = S7_GetWordAt(readCountByte,8);
    controllerObject.sixCount = S7_GetWordAt(readCountByte,10);
    controllerObject.sevenCount = S7_GetWordAt(readCountByte,12);
    controllerObject.eightCount = S7_GetWordAt(readCountByte,14);
    controllerObject.nineCount = S7_GetWordAt(readCountByte,16);
    controllerObject.tenCount = S7_GetWordAt(readCountByte,18);
    controllerObject.elevenCount = S7_GetWordAt(readCountByte,20);
    controllerObject.twelveCount = S7_GetWordAt(readCountByte,22);
    controllerObject.allCount = S7_GetWordAt(readCountByte,24);
    controllerObject.thriteenCount = S7_GetWordAt(readCountByte,26);
    controllerObject.forteenCount = S7_GetWordAt(readCountByte,28);
    controllerObject.fivteenCount = S7_GetWordAt(readCountByte,30);
    controllerObject.sixteenCount = S7_GetWordAt(readCountByte,32);
    ui->measureAllCount->setText(QString::number(controllerObject.allCount));
    if(ui->measurePointCodeList->currentText() == "类型1")
    {
        ui->measureCount->setText(QString::number(controllerObject.oneCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型2")
    {
        ui->measureCount->setText(QString::number(controllerObject.twoCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型3")
    {
        ui->measureCount->setText(QString::number(controllerObject.threeCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型4")
    {
        ui->measureCount->setText(QString::number(controllerObject.fourCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型5")
    {
        ui->measureCount->setText(QString::number(controllerObject.fiveCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型6")
    {
        ui->measureCount->setText(QString::number(controllerObject.sixCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型7")
    {
        ui->measureCount->setText(QString::number(controllerObject.sevenCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型8")
    {
        ui->measureCount->setText(QString::number(controllerObject.eightCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型9")
    {
        ui->measureCount->setText(QString::number(controllerObject.nineCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型10")
    {
        ui->measureCount->setText(QString::number(controllerObject.tenCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型11")
    {
        ui->measureCount->setText(QString::number(controllerObject.elevenCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型12")
    {
        ui->measureCount->setText(QString::number(controllerObject.twelveCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型13")
    {
        ui->measureCount->setText(QString::number(controllerObject.thriteenCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型14")
    {
        ui->measureCount->setText(QString::number(controllerObject.forteenCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型15")
    {
        ui->measureCount->setText(QString::number(controllerObject.fivteenCount));
    }
    if(ui->measurePointCodeList->currentText() == "类型16")
    {
        ui->measureCount->setText(QString::number(controllerObject.sixteenCount));
    }

}
//加载点位编号列表
void PlateWidget::loadPointCodeList(QComboBox *box)
{
    isLoadPointCodeList = true;
    QStringList pointCodeList;
    oper.getPointCodeList(pointCodeList);
    box->clear();
    box->addItem("钢板类型");
    box->addItems(pointCodeList);
    isLoadPointCodeList = false;
}


//初始化widget里面的pushbutton
void PlateWidget::initPushbuttonByFrame(QFrame* frame)
{
    QList<QPushButton *> btns = frame->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btns) {
        connect(btn, &QPushButton::clicked, this, &PlateWidget::initPushbuttonByFrame_slot);
    }
}
//响应widget里面的pushbutton函数
void PlateWidget::initPushbuttonByFrame_slot()
{
    QPushButton *btn = (QPushButton *)sender();
    QString objName = btn->objectName();

    //自动模式
    if(objName == "autoModeBtn"){
        if(isMeasuringStatus == true)
        {
            myHelper::ShowMessageBoxInfo("正在检测中。。。");
            return;
        }
        if(isManualing == true)
        {
            return;
        }
        ui->mainStackedWidget->setCurrentWidget(ui->autoPage);
        changeWidgetButtonStyle(ui->autoModeBtn);
        loadPointCodeList(ui->measurePointCodeList);
    }
    //手动模式
    if(objName == "manualModeBtn")
    {
        if(isMeasuringStatus == true)
        {
            myHelper::ShowMessageBoxInfo("正在检测中。。。");
            return;
        }
        ui->mainStackedWidget->setCurrentWidget(ui->manualPage);
        changeWidgetButtonStyle(ui->manualModeBtn);
    }
    //点位定义
    if(objName == "pointDefinitionBtn"){
        if(isAdmin() == false){
            myHelper::ShowMessageBoxInfo("只有管理员账号才可以操作");
            return;
        }
        if(isMeasuringStatus == true)
        {
            myHelper::ShowMessageBoxInfo("正在检测中。。。");
            return;
        }
        ui->mainStackedWidget->setCurrentWidget(ui->pointDefinitionPage);
        changeWidgetButtonStyle(ui->pointDefinitionBtn);
        loadPointCodeList(ui->pointCodeList);
    }
    //数据查询
    if(objName == "dataQUeryBtn"){

        if(isMeasuringStatus == true){
            myHelper::ShowMessageBoxInfo("正在检测中。。。");
            return;
        }
        ui->mainStackedWidget->setCurrentWidget(ui->dataQueryPage);
        //更新当天编号列表
        QStringList codeList;
        QString startTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        QString endTime = QDateTime::currentDateTime().toString("yyyy-MM-dd");
        oper.getCodeListByDate(codeList, startTime, endTime);
        loadMeasureProCodeList = true;
        ui->resultCodeList->clear();
        ui->resultCodeList->addItem("选择类型");
        ui->resultCodeList->addItems(codeList);
        loadMeasureProCodeList = false;
        changeWidgetButtonStyle(ui->dataQUeryBtn);
    }
    //用户管理-- 界面跳转
    if(objName == "userMangerBtn"){
        if(isAdmin() == false){
            myHelper::ShowMessageBoxInfo("只有管理员账号才可以操作");
            return;
        }
        if(isMeasuringStatus == true)
        {
            myHelper::ShowMessageBoxInfo("正在检测中。。。");
            return;
        }
        ui->mainStackedWidget->setCurrentWidget(ui->userPage);
        changeWidgetButtonStyle(ui->userMangerBtn);

        QVector<User> users;
        oper.queryAllUser(users);
        showUserTable(users);
    }
    //用户管理-- 新增按钮
    if(objName == "addUserBtn"){
        isShowUserTable = true;
        int rowCount = ui->userTable->rowCount();
        ui->userTable->insertRow(rowCount);

        QTableWidgetItem *item0 = new QTableWidgetItem();
        item0->setFlags(item0->flags() & 33);
        item0->setTextAlignment(Qt::AlignCenter);
        item0->setText(QString::number(rowCount + 1));

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setTextAlignment(Qt::AlignCenter);
        item1->setText("");

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setTextAlignment(Qt::AlignCenter);
        item2->setText("1");

        ui->userTable->setItem(rowCount, 0, item0);
        ui->userTable->setItem(rowCount, 1, item1);
        ui->userTable->setItem(rowCount, 2, item2);

        QStringList roleList;
        roleList.append("管理员");
        roleList.append("操作员");
        QComboBox *box = new QComboBox();
        box->addItems(roleList);
        ui->userTable->setCellWidget(rowCount, 3, box);

        QCheckBox *cheeck = new QCheckBox();
        cheeck->setText("是否可用");
        cheeck->setChecked(true);
        ui->userTable->setCellWidget(rowCount, 4, cheeck);

        ui->userTable->clearSelection();
        ui->userTable->setCurrentItem(nullptr);

        isShowUserTable = false;
    }
    //用户管理-- 删除按钮
    if(objName == "deleteUserBtn"){
        int currentRow = ui->userTable->currentRow();
        if(currentRow == -1){
            myHelper::ShowMessageBoxInfo("选择需要删除的行");
        }else{
            //删除数据库
            if((ui->userTable->item(currentRow, 1) != nullptr) && (!ui->userTable->item(currentRow, 1)->text().remove(QRegExp("\\s")).isEmpty())){
                oper.deleteUser(ui->userTable->item(currentRow, 1)->text());
            }
            ui->userTable->removeRow(currentRow);
            ui->userTable->clearSelection();
            ui->userTable->setCurrentItem(nullptr);
        }

    }
    //用户管理-- 保存按钮
    if(objName == "saveUserBtn"){
        QVector<User> users;
        for(int i = 0; i < ui->userTable->rowCount(); i++){
            User user;
            for(int j = 1; j < ui->userTable->columnCount(); j++){
                if(j == 1){
                    if(ui->userTable->item(i, j) == nullptr ||  ui->userTable->item(i, j)->text().remove(QRegExp("\\s")).isEmpty()){
                        myHelper::ShowMessageBoxInfo("账号不能为空");
                        return;
                    }else{
                        user.name = ui->userTable->item(i, j)->text();
                    }
                }
                if(j == 2){
                    if(ui->userTable->item(i, j) == nullptr ||  ui->userTable->item(i, j)->text().remove(QRegExp("\\s")).isEmpty()){
                        user.pwd = "0";
                    }else{
                        user.pwd = ui->userTable->item(i, j)->text();
                    }
                }
                if(j == 3){
                    QComboBox *box = dynamic_cast<QComboBox*>(ui->userTable->cellWidget(i, j));
                    user.role = box->currentText();
                }
                if(j == 4){
                    QCheckBox *box = (QCheckBox*)ui->userTable->cellWidget(i, j);
                    user.is_used = box->isChecked() ? "1" : "0";
                }

            }
            users.push_back(user);
        }
        int ok = oper.saveUsers(users);
        if(ok == 0){
            myHelper::ShowMessageBoxInfo("保存成功");
            QVector<User> users;
            oper.queryAllUser(users);
            showUserTable(users);
            ui->userTable->clearSelection();
            ui->userTable->setCurrentItem(nullptr);
        }else{
            myHelper::ShowMessageBoxInfo("保存失败");
        }

    }


}
//更改菜单栏按钮选中状态
void PlateWidget::changeWidgetButtonStyle(QPushButton * checkButton)
{
    QList<QPushButton *> btns = ui->frame->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btns) {
        if(btn == checkButton){
            btn->setStyleSheet(pushButtonGreenStyle);
        }else{
            btn->setStyleSheet(defaultPushButtonStyle);
            btn->setStyleSheet(hoverPushButtonStyle);
            btn->setStyleSheet(disablePushButtonStyle);
        }
    }
}
//初始化groupBox里面的pushbutton
void PlateWidget::initPushbuttonByGroup(QGroupBox* box)
{
    QList<QPushButton *> btns = box->findChildren<QPushButton *>();
    foreach (QPushButton * btn, btns) {
        connect(btn, &QPushButton::clicked, this, &PlateWidget::initPushbuttonByGroup_slot);
    }
}
//响应groupBox里面的pushbutton函数
void PlateWidget::initPushbuttonByGroup_slot()
{
    QPushButton *btn = (QPushButton *)sender();
    QString objName = btn->objectName();
    //保存点位信息
    if(objName == "savePointInfoBtn"){
        QString plateType = ui->pointCode->text();
        if(plateType.isEmpty())
        {
            myHelper::ShowMessageBoxInfo("钢板类型为空，请输入钢板类型！");
            return;
        }
        QString val = QString("%1-%2").arg(ui->D_thick_std->text()).arg(ui->U_thick_std->text());
        ui->thickStdVal->setText(val);
        PointInfo pp_info;
        oper.getPointInfoByCode(pp_info, plateType);
        //        if(pp_info.pointCode != nullptr){
        //            myHelper::ShowMessageBoxInfo("当前类型已经存在");
        //            return;
        //        }
        double length = ui->length->value();
        double width = ui->width->value();
        double thick = ui->thick->value();
        double D_thick_std = ui->D_thick_std->value();
        double U_thick_std = ui->U_thick_std->value();
        QString pointCode = ui->numberEdit->text();
        if(pointCode.isEmpty())
        {
            myHelper::ShowMessageBoxInfo("编号为空，请输入编号！");
            return;
        }
        if(D_thick_std == 0 || U_thick_std == 0)
        {
            myHelper::ShowMessageBoxInfo("硬度标准不能为0，请重新输入！");
            return;
        }
        if(thick == 0)
        {
            myHelper::ShowMessageBoxInfo("厚度不能为0，请重新输入！");
            return;
        }

        PointInfo p_info;
        p_info.plateType = plateType;
        p_info.length = length;
        p_info.width = width;
        p_info.thick = thick;
        p_info.D_thick_std = D_thick_std;
        p_info.U_thick_std = U_thick_std;
        p_info.pointCode = pointCode;
        oper.savePointInfo(p_info);
        QVector<PointList> p_list;
        int row = ui->pointTable->rowCount();
        int col = ui->pointTable->columnCount();

        for(int i = 0; i < row; i++){
            PointList p;
            p.plateType = plateType;

            for(int j = 0; j < col; j++){
                QTableWidgetItem* item = ui->pointTable->item(i, j);
                if(item == nullptr || item->text().remove(QRegExp("\\s")).isEmpty()){
                    p.xVal = 0;
                    p.yVal = 0;
                }else
                {
                    QStringList coords = item->text().split(',');
                    double xVal = coords.value(0).toDouble();
                    double yVal = coords.value(1).toDouble();

                    p.xVal = xVal;
                    p.yVal = yVal;
                }

                p_list.push_back(p);
            }
        }
        if(oper.savePointList(p_list) == 0){
            myHelper::ShowMessageBoxInfo("保存点位信息成功");
            loadPointCodeList(ui->pointCodeList);
            loadPointCodeList(ui->measurePointCodeList);

        }

    }
    //更新点位信息
    //    if(objName == "updatePointInfoBtn"){
    //        QString plateType = ui->pointCode->text();
    //        QString val = QString("%1-%2").arg(ui->D_thick_std->text()).arg(ui->U_thick_std->text());
    //        ui->thickStdVal->setText(val);
    //        double length = ui->length->value();
    //        double width = ui->width->value();
    //        double thick = ui->thick->value();
    //        double D_thick_std = ui->D_thick_std->value();
    //        double U_thick_std = ui->U_thick_std->value();
    //        QString pointCode = ui->localNum->text();
    //        PointInfo p_info;
    //        p_info.plateType = plateType;
    //        p_info.length = length;
    //        p_info.width = width;
    //        p_info.thick = thick;
    //        p_info.D_thick_std = D_thick_std;
    //        p_info.U_thick_std = U_thick_std;
    //        p_info.pointCode = pointCode;
    //        oper.savePointInfo(p_info);

    //        if(oper.updatePointInfoBCode(p_info) == 0){
    //            myHelper::ShowMessageBoxInfo("更新点位信息成功");
    //            loadPointCodeList(ui->pointCodeList);
    //            loadPointCodeList(ui->measurePointCodeList);
    //            pointDefineSeries->clear();
    //        }
    //    }
    //删除点位信息
    if(objName == "deletePointInfoBtn"){
        if(myHelper::ShowMessageBoxQuesion("确定删除点位信息吗？") == 1){
            if(oper.deletePointInfoByCode(ui->pointCode->text()) == 0){
                myHelper::ShowMessageBoxInfo("删除点位信息成功");
                loadPointCodeList(ui->pointCodeList);
                loadPointCodeList(ui->measurePointCodeList);
                pointDefineSeries->clear();
            }
        }

    }
    //增加一个点位
    if(objName == "addRowBtn"){
        int rowCount = ui->pointTable->rowCount();

        if(rowCount < 3)
        {
            ui->pointTable->insertRow(rowCount);

        }else
        {
            myHelper::ShowMessageBoxInfo("达到最大定义点位行数!");
            return;
        }
    }
    //删除一个点位
    if(objName == "deleteRowBtn"){
        QList<QTableWidgetItem *> items = ui->pointTable->selectedItems();
        if (items.size() != 1) {
            myHelper::ShowMessageBoxInfo("请选择一个单元格以清除数据");
            return;
        }

        QTableWidgetItem *item = items.first();
        int row = item->row();
        int col = item->column();

        if (ui->pointTable->item(row, col) != nullptr) {
            QString cellText = ui->pointTable->item(row, col)->text();
            QStringList coordinates = cellText.split(",");

            if (coordinates.size() == 2) {
                double xVal = coordinates[0].toDouble();
                double yVal = coordinates[1].toDouble();
                pointDefineSeries->remove(QPointF(yVal, xVal));

                // 清空选中的单元格数据
                ui->pointTable->item(row, col)->setText("");
            }
        }
    }

}
//显示用户列表
void PlateWidget::showUserTable(QVector<User> users)
{
    isShowUserTable = true;
    int row = users.size();
    int col = ui->userTable->columnCount();
    ui->userTable->setRowCount(row);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(j == 0 || j == 1 || j == 2){
                QTableWidgetItem *item = new QTableWidgetItem();
                item->setTextAlignment(Qt::AlignCenter);
                if(j == 0){
                    item->setFlags(item->flags() & 33);
                    item->setText(QString::number(i + 1));
                }
                if(j == 1){
                    item->setFlags(item->flags() & 33);
                    item->setText(users[i].name);
                }
                if(j == 2){
                    item->setText(users[i].pwd);
                }
                ui->userTable->setItem(i, j, item);
            }else{
                if(j == 3){
                    QStringList roleList;
                    roleList.append("管理员");
                    roleList.append("操作员");
                    QComboBox *box = new QComboBox();
                    box->addItems(roleList);
                    box->setCurrentText(users[i].role);
                    ui->userTable->setCellWidget(i, j, box);
                }
                if(j == 4){
                    QCheckBox *cheeck = new QCheckBox();
                    cheeck->setText("是否可用");
                    if(users[i].is_used.compare("0") == 0){
                        cheeck->setChecked(false);
                    }else{
                        cheeck->setChecked(true);
                    }
                    ui->userTable->setCellWidget(i, j, cheeck);
                }
            }
        }
    }
    isShowUserTable = false;
}
//判断当前账号是否存在
void PlateWidget::on_userTable_itemChanged(QTableWidgetItem *item)
{
    if(isShowUserTable == true){
        return;
    }
    QString name = nullptr;
    if(item == nullptr ||  item->text().remove(QRegExp("\\s")).isEmpty()){
        return;
    }else{
        name = item->text();
        for(int i = 0; i < ui->userTable->rowCount(); i++){
            if(ui->userTable->item(i, 1) == nullptr ||  ui->userTable->item(i, 1)->text().remove(QRegExp("\\s")).isEmpty() || item->row() == i){
                continue;
            }else{
                if(name.compare(ui->userTable->item(i, 1)->text()) == 0){
                    myHelper::ShowMessageBoxInfo("当前账号已经存在");
                    item->setText(" ");
                    return;
                }
            }
        }
    }
}
//判断当前用户是否是管理员
bool PlateWidget::isAdmin()
{
    if(currentUser.role == "管理员"){//管理员
        return true;
    }else{//操作员
        return false;
    }
}
//实时显示数据到表格上
void PlateWidget::getMeasureDataByCode(const QString measureCode)
{
    hardnesses.clear();
    oper.getHardnessListByID(hardnesses,measureCode);
    int row = hardnesses.size();
    ui->tableWidget->setRowCount(row);
    int col = ui->tableWidget->columnCount();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            QTableWidgetItem *item = new QTableWidgetItem();
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags() & 33);
            if(j == 0){
                item->setText(hardnesses[i].plateType);
            }
            if(j == 1)
            {
                item->setText(hardnesses[i].id);
            }
            if(j == 2){
                item->setText(QString::number(hardnesses[i].xCoordinate));
            }
            if(j == 3)
            {
                item->setText(QString::number(hardnesses[i].yCoordinate));
            }
            if(j == 4){
                if(isAdmin() == true)
                {
                    item->setFlags(item->flags()|Qt::ItemIsEditable);
                }
                item->setText(QString::number(hardnesses[i].hardness));

            }
            if(j==5)
            {
                if(isAdmin() == true)
                {
                    item->setFlags(item->flags()|Qt::ItemIsEditable);
                }
                item->setText(QString::number(hardnesses[i].diameter,'f',3));
            }
            if(j == 6)
            {
                if(isAdmin() == true)
                {
                    item->setFlags(item->flags()|Qt::ItemIsEditable);
                }

                item->setText(hardnesses[i].result);
                if(item->text() == "合格")
                {
                    QColor okColor("#00B700");
                    item->setBackgroundColor(okColor);
                }
                if(item->text() == "不合格")
                {
                    QColor ngColor("#DB0000");
                    item->setBackgroundColor(ngColor);
                }
            }
            if(j == 7)
            {

                item->setText(hardnesses[i].time);
            }
            if(j == 8)
            {
                item->setText(hardnesses[i].oper);
            }
            ui->tableWidget->setItem(i, j, item);
        }
    }

}


//初始化点位定义点位图
void PlateWidget::initPointDefineChart(qreal xMax, qreal yMax)
{
    pointDefineSeries = new QScatterSeries();
    pointDefineSeries->setPointLabelsVisible(true);
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(pointDefineSeries);
    axisX = new QValueAxis;
    axisX->setLabelFormat("%.1f"); // 设置横轴标签格式为保留两位小数
    axisX->setTitleText("Y轴");
    axisX->setTickCount(11);
    axisX->setRange(0, yMax); // 设置横轴范围的初始值
    chart->addAxis(axisX, Qt::AlignBottom);
    pointDefineSeries->attachAxis(axisX);

    axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f"); // 设置纵轴标签格式为保留两位小数
    axisY->setTitleText("X轴");
    axisY->setTickCount(11);
    axisY->setRange(0, xMax); // 设置纵轴范围的初始值
    chart->addAxis(axisY, Qt::AlignLeft);
    pointDefineSeries->attachAxis(axisY);
    QChartView *pointDefineChartView = new QChartView(chart);
    pointDefineChartView->setRenderHint(QPainter::Antialiasing);
    QGraphicsScene *scene = new QGraphicsScene();
    pointDefineChartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pointDefineChartView->setRenderHint(QPainter::Antialiasing);
    pointDefineChartView->resize(1450,430);
    ui->pointView->setScene(scene);
    scene->addWidget(pointDefineChartView);
}

void PlateWidget::initPointDefineChart(qreal xMax, qreal yMax, QVector<QPointF> p_point)
{
    pointDefineSeries = new QScatterSeries();
    pointDefineSeries->setPointLabelsVisible(true);
    int size = p_point.size();
    for(int i=0;i<size;i++)
    {
        pointDefineSeries->append(p_point[i]);
    }
    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(pointDefineSeries);

    axisX = new QValueAxis;
    axisX->setLabelFormat("%.1f"); // 设置横轴标签格式为保留1位小数
    axisX->setTitleText("Y轴");
    axisX->setTickCount(11);
    axisX->setRange(0, yMax); // 设置横轴范围的初始值
    chart->addAxis(axisX, Qt::AlignBottom);
    pointDefineSeries->attachAxis(axisX);

    axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f"); // 设置纵轴标签格式为保留两位小数
    axisY->setTitleText("X轴");
    axisY->setTickCount(11);
    axisY->setRange(0, xMax); // 设置纵轴范围的初始值
    chart->addAxis(axisY, Qt::AlignLeft);
    pointDefineSeries->attachAxis(axisY);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QGraphicsScene *scene = new QGraphicsScene();
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1450,430);
    ui->pointView->setScene(scene);
    scene->addWidget(chartView);

}
void PlateWidget::initAutoDetectChart(qreal xMax, qreal yMax)
{
    autoDetectSeries = new QScatterSeries();
    autoDetectSeries->setPointLabelsVisible(true);

    autoChart = new QChart();
    autoChart->legend()->hide();
    autoChart->addSeries(autoDetectSeries);

    autoAxisX = new QValueAxis;
    autoAxisX->setLabelFormat("%.1f"); // 设置横轴标签格式为保留两位小数
    autoAxisX->setTitleText("Y轴(负号仅代表方向)");
    autoAxisX->setTickCount(11);
    autoAxisX->setRange(-yMax, 0); // 设置横轴范围的初始值
    autoChart->addAxis(autoAxisX, Qt::AlignBottom);
    autoDetectSeries->attachAxis(autoAxisX);

    autoAxisY = new QValueAxis;
    autoAxisY->setLabelFormat("%.1f"); // 设置纵轴标签格式为保留两位小数
    autoAxisY->setTitleText("X轴");
    autoAxisY->setTickCount(11);
    autoAxisY->setRange(0, xMax); // 设置纵轴范围的初始值
    autoChart->addAxis(autoAxisY, Qt::AlignRight);
    autoDetectSeries->attachAxis(autoAxisY);
    QChartView *chartView = new QChartView(autoChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QGraphicsScene *scene = new QGraphicsScene();
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1040,650);
    ui->pointResultView->setScene(scene);
    scene->addWidget(chartView);

}
//初始化自动检测模式点位图
void PlateWidget::initAutoDetectChart(qreal xMax, qreal yMax, QVector<QPointF> p_point)
{
    autoDetectSeries = new QScatterSeries();
    autoDetectSeries->setPointLabelsVisible(true);
    int size = p_point.size();
    for(int i=0;i<size;i++)
    {
        autoDetectSeries->append(p_point[i]);
    }
    autoChart = new QChart();
    autoChart->legend()->hide();
    autoChart->addSeries(autoDetectSeries);

    autoAxisX = new QValueAxis;
    autoAxisX->setLabelFormat("%.1f"); // 设置横轴标签格式为保留两位小数
    autoAxisX->setTitleText("Y轴(负号仅代表方向)");
    autoAxisX->setTickCount(11);
    autoAxisX->setRange(-yMax, 0); // 设置横轴范围的初始值
    autoChart->addAxis(autoAxisX, Qt::AlignBottom);
    autoDetectSeries->attachAxis(autoAxisX);

    autoAxisY = new QValueAxis;
    autoAxisY->setLabelFormat("%.1f"); // 设置纵轴标签格式为保留两位小数
    autoAxisY->setTitleText("X轴");
    autoAxisY->setTickCount(11);
    autoAxisY->setRange(0, xMax); // 设置纵轴范围的初始值
    autoChart->addAxis(autoAxisY, Qt::AlignRight);
    autoDetectSeries->attachAxis(autoAxisY);

    QChartView *chartView = new QChartView(autoChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QGraphicsScene *scene = new QGraphicsScene();
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1040,650);
    ui->pointResultView->setScene(scene);
    scene->addWidget(chartView);
}
//计算压痕直径
double PlateWidget::calculateDiameter(int hardness)
{
    int D = 10,P = 3000;
    double a = M_PI * pow(D,2) * hardness - 2*P;
    double b = M_PI * D * hardness;
    double c = pow(a/b,2);
    double d = pow(D,2);
    double diameter = sqrt(d-c);
    return diameter;
}
//将标块数据写入Excel
void PlateWidget::writeStandardDataToExcel(int standardHardness, double standardDiameter)
{
    QString currentTime = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    QString fileName = "标准硬度值_" + currentTime + ".xlsx";
    QString filePath = QDir::homePath() +"/Desktop/标准硬度值数据/"+fileName;
    QXlsx::Document xlsx;
    xlsx.write("A1","Hardness(HB)");
    xlsx.write("B1","Diameter(mm)");
    xlsx.write("A2",standardHardness);
    xlsx.write("B2",standardDiameter);
    if(xlsx.saveAs(filePath) == true)
    {
        myHelper::ShowMessageBoxInfo("导入标准硬度值数据成功！");
    }


}
//记录报警日志
void PlateWidget::writeWarningMessage(const QString &warningMessage)
{
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString logMessage = currentTime +":"+ warningMessage;
    QString currentPath = QDir::currentPath();
    QString filePath = currentPath + "/warningMessage.log";
    QFile file(filePath);
    if(file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream textStream(&file);
        textStream.setCodec("UTF-8");
        textStream << logMessage << endl;
        file.close();
    }
}

void PlateWidget::initAutoDetectChart(qreal xMax, qreal yMax, QVector<QPointF> p_point, QString hardness)
{
    autoDetectSeries = new QScatterSeries();
    autoDetectSeries->setPointLabelsVisible(true);
    QColor color = QColor(Qt::blue);
    double hardnessDouble = hardness.toDouble();
    QStringList hardnessSTDList = ui->thickStdVal->text().split("-");
    double D_hardness = QString(hardnessSTDList.at(0)).toDouble();
    double U_hardness = QString(hardnessSTDList.at(1)).toDouble();
    //在硬度范围内,设置点为绿色
    if(hardnessDouble >= D_hardness && hardnessDouble <= U_hardness)
    {
        color = QColor(Qt::green);
    }
    //没在硬度范围内,设置点为红色
    else if(hardnessDouble < D_hardness || hardnessDouble > U_hardness)
    {
        color = QColor(Qt::red);
    }
    int size = p_point.size();
    for(int i=0;i<size;i++)
    {
        autoDetectSeries->append(p_point[i]);
        autoDetectSeries->setPointLabelsFormat(QString("HB:%3").arg(hardness));
        autoDetectSeries->setColor(color);
    }
    autoChart = new QChart();
    autoChart->legend()->hide();
    autoChart->addSeries(autoDetectSeries);

    autoAxisX = new QValueAxis;
    autoAxisX->setLabelFormat("%.1f"); // 设置横轴标签格式为保留两位小数
    autoAxisX->setTitleText("Y轴");
    autoAxisX->setTickCount(11);
    autoAxisX->setRange(0, yMax); // 设置横轴范围的初始值
    autoChart->addAxis(autoAxisX, Qt::AlignBottom);
    autoDetectSeries->attachAxis(autoAxisX);

    autoAxisY = new QValueAxis;
    autoAxisY->setLabelFormat("%.1f"); // 设置纵轴标签格式为保留两位小数
    autoAxisY->setTitleText("X轴");
    autoAxisY->setTickCount(11);
    autoAxisY->setRange(0, xMax); // 设置纵轴范围的初始值
    autoChart->addAxis(autoAxisY, Qt::AlignLeft);
    autoDetectSeries->attachAxis(autoAxisY);
    QChartView *chartView = new QChartView(autoChart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QGraphicsScene *scene = new QGraphicsScene();
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1300,650);
    ui->pointResultView->setScene(scene);
    scene->addWidget(chartView);
}
//手动模式实时数据
void PlateWidget::manualModeGetData()
{

    int row = ui->manualTableWidget->rowCount();
    ui->manualTableWidget->insertRow(row);
    for(int j=0;j<ui->manualTableWidget->columnCount();j++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() & 33);
        item->setTextAlignment(Qt::AlignHCenter);
        if(j==0)
        {
            item->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        }
        if(j==1)
        {
            item->setText(QString::number(oneConObject.hardness / 10));
        }
        if(j==2)
        {
            item->setText(QString::number(calculateDiameter(oneConObject.hardness / 10),'f',3));
        }
        ui->manualTableWidget->setItem(row,j,item);
    }
    //ui->manualTableWidget->scrollToBottom();

}

//自动模式实时数据
void PlateWidget::autoModeGetData()
{
    QVector<hardnessList> hardness_list;
    hardnessList list;
    list.hardness = oneConObject.hardness / 10;
    list.plateType = ui->measurePointCodeList->currentText();
    list.id = ui->numEdit->text();
    list.xCoordinate = 2266 - oneConObject.xCoordinate;
    if(ui->measurePointCodeList->currentIndex() == 7)
    {
        list.yCoordinate = oneConObject.yCoordinate + 1000;
    }
    if(ui->measurePointCodeList->currentIndex() >= 1 && ui->measurePointCodeList->currentIndex() <= 6)
    {
        list.yCoordinate = oneConObject.yCoordinate - 30;
    }
    list.oper = ui->userName_7->text();
    list.time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QStringList hardnessScale = ui->thickStdVal->text().split("-");
    QString minHardness = hardnessScale.at(0);
    int lowerHardness = minHardness.toInt();
    //    QString maxHardness = hardnessScale.at(1);
    //    int higherHardness = maxHardness.toInt();
    double d = calculateDiameter(oneConObject.hardness / 10);
    double diameter = QString::number(d,'f',3).toDouble();
    list.diameter = diameter;
    QString result;
    if(oneConObject.hardness/10 >= lowerHardness)
    {
        result = "合格";
    }
    if(oneConObject.hardness/10 < lowerHardness)
    {
        result = "不合格";
    }
    list.result = result;
    hardness_list.push_back(list);
    oper.saveHardnessList(hardness_list);
    int row = ui->measurePointTable->rowCount();
    ui->measurePointTable->insertRow(row);
    for(int j=0;j<ui->measurePointTable->columnCount();j++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() & 33);
        item->setTextAlignment(Qt::AlignHCenter);
        if(j==0)
        {
            item->setText(QString::number(2266 - oneConObject.xCoordinate));
        }
        if(j==1)
        {

            if(ui->measurePointCodeList->currentIndex() == 7)
            {
                item->setText(QString::number(oneConObject.yCoordinate + 1000));
            }
            if(ui->measurePointCodeList->currentIndex() >= 1 && ui->measurePointCodeList->currentIndex() <= 6)
            {
                item->setText(QString::number(oneConObject.yCoordinate - 30));
            }
        }
        if(j==2)
        {
            item->setText(QString::number(oneConObject.hardness / 10));
        }
        if(j==3)
        {
            item->setText(QString::number(diameter));
        }
        if(j==4)
        {
            if(oneConObject.hardness/10 >= lowerHardness)
            {
                item->setText("合格");
                item->setBackgroundColor(Qt::green);
            }
            if(oneConObject.hardness/10 < lowerHardness)
            {
                item->setText("不合格");
                item->setBackgroundColor(Qt::red);
            }

        }
        ui->measurePointTable->setItem(row,j,item);
    }
}

void PlateWidget::plateToDetection()
{
    if(controllerInitStatus == false)
    {
        return;
    }
    if(ui->measurePointCodeList->currentIndex() == 0)
    {
        myHelper::ShowMessageBoxError("还未选择钢板类型,请选择钢板类型！");

        return;
    }

    //radioButton都没选中
    if(!ui->firstSet->isChecked() && !ui->secondSet->isChecked())
    {
        myHelper::ShowMessageBoxError("请选择一套点位！");
        return;
    }
    if(ui->serialNum->text().isEmpty())
    {
        myHelper::ShowMessageBoxError("请输入流水号！");
        return;
    }
    int prepareToDetectSignal = 1;
    byte prepareToDetectBuffer[2];
    S7_SetWordAt(prepareToDetectBuffer, 0, static_cast<uint16_t>(prepareToDetectSignal));
    int res = snap7_plc->DBWrite(writeDbNum, 82, 2, &prepareToDetectBuffer);
    if(res == 0)
    {
        QTimer::singleShot(200,this,[=](){
            int clearSignal = 0;
            byte clearSignalBuffer[2];
            S7_SetWordAt(clearSignalBuffer, 0, static_cast<uint16_t>(clearSignal));
            snap7_plc->DBWrite(writeDbNum, 82, 2, &clearSignalBuffer);
        });
    }

}

void PlateWidget::prepareToDetection()
{

    int reply = myHelper::ShowMessageBoxQuesion("当前产品已经进入待检区，并且已经完成纠偏操作，是否需要进行检测？");
    if(reply == QDialog::Accepted)
    {
        ui->startDetectionBtn->show();
    }

}

