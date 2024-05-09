
#pragma execution_character_set("utf-8")
#ifndef OBJECTINFO_H
#define OBJECTINFO_H
#include <QString>
#include <QDebug>

class User
{
    public:
        User(){
            name = nullptr;
            pwd = nullptr;
            role = nullptr;
            is_used = nullptr;
        }
        friend QDebug& operator<<(QDebug out, const User& user)
        {
            out << "账号：" << user.name << "密码：" << user.pwd << "角色：" << user.role << "是否可用：" << user.is_used;
            return out;
        }
    public:
        QString name;
        QString pwd;
        QString role;
        QString is_used;
};

class PointInfo
{
    public:
        PointInfo(){
            plateType = nullptr;
            pointCode = nullptr;
            length = 0;
            width = 0;
            thick = 0;
            D_thick_std = 0;
            U_thick_std = 0;

        }
        friend QDebug& operator<<(QDebug out, const PointInfo& p)
        {
            out << "pointCode:" << p.pointCode <<"length:" << p.length <<"width:" << p.width << "thick:" << p.thick
                 << "D_thick_std:" << p.D_thick_std << "U_thick_std:" << p.U_thick_std ;
            return out;
        }
    public:
        QString plateType;
        QString pointCode;
        double D_thick_std;
        double U_thick_std;
        double length;
        double width;
        double thick;
};

class PointList
{
    public:
        PointList(){
            plateType = nullptr;
            xVal = 0;
            yVal = 0;
            startX = 0;
            startY = 0;
            xInterval = 0;
            yInterval = 0;
            xPointCount = 0;
            yPointCount = 0;
            hardness = 0;

        }
        friend QDebug& operator<<(QDebug out, const PointList& user)
        {
            out << "plateType:" << user.plateType <<"xVal:" << user.xVal <<"yVal:" << user.yVal;
            return out;
        }
    public:
        QString plateType;
        double xVal;
        double yVal;
        double startX,startY;
        double xInterval,yInterval;
        int xPointCount,yPointCount;
        int hardness;
        QVector<QPointF> points;
};

class hardnessList{
public:
    hardnessList(){
        plateType = nullptr;
        id = nullptr;
        xCoordinate = 0;
        yCoordinate = 0;
        hardness = 0;
        diameter = 0;
        time = nullptr;
        oper = nullptr;
        result = nullptr;
    }
    QString plateType;
    QString id;
    int hardness;
    double diameter;
    QString time;
    QString oper;
    int xCoordinate;
    int yCoordinate;
    QString result;

};

//板片定义
class Pro
{
    public:
        Pro(){
            code = nullptr;
            materials = nullptr;
            length = 0;
            width = 0;
            holeDiameterStd = 0;
            sphereDiameterStd = 0;
        }
    public:
        QString code;//编号
        QString materials;//材质
        double length;//长度
        double width;//宽度
        double holeDiameterStd;//孔径标准
        double sphereDiameterStd;//球径标准
        int xHoleCount;//x方向球个数
        int yHoleCount;//y方向球个数
};
//测量工程 主要是为了存储时间
class MeasurePro
{
    public:
        MeasurePro(){
            code = nullptr;
            time = nullptr;
        }
    public:
        QString code;//编号
        QString time;//检测时间
};
//孔径对象
class HoleDiameter
{
    public:
        HoleDiameter(){
            code = nullptr;//编号
            x = 0;//x坐标
            y = 0;//y坐标
            holeDiameterVal = 0;//孔直径
        }
    public:
        QString code;//编号
        double x;//x坐标
        double y;//y坐标
        double holeDiameterVal;//孔直径
};

//球径对象
class SphereDiameter
{
    public:
        SphereDiameter(){
            code = nullptr;//编号
            x = 0;//x坐标
            y = 0;//y坐标
            sphereDiameterVal = 0;//球直径
        }
    public:
        QString code;//编号
        double x;//x坐标
        double y;//y坐标
        double sphereDiameterVal;//球直径
};

//小球堆叠对象
class HeapUp
{
    public:
        HeapUp(){
            code = nullptr;//编号
            x = 0;//x坐标
            y = 0;//y坐标
        }
    public:
        QString code;//编号
        double x;//x坐标
        double y;//y坐标
};

//板片植球率
class Cover
{
    public:
        Cover(){
            code = nullptr;//编号
            coverVal = 0;
            outerLength = 0;//外层长度
            outerWidth = 0;//外层宽度
            innerLength = 0;//内层长度
            innerWidth = 0;//内层宽度

            width_y = 0;//板片横向宽度
            width_x = 0;//板片纵向宽度
        }
    public:
        QString code;//编号
        double coverVal;//植球率
        double outerLength;//外层长度
        double outerWidth;//外层宽度
        double innerLength;//内层长度
        double innerWidth;//内层宽度
        double width_y;//板片横向宽度
        double width_x;//板片纵向宽度
};
//控制系统读取对象
class ControllerObject
{
    public:
        ControllerObject(){

            oneCount = 0;
            twoCount = 0;
            threeCount = 0;
            fourCount = 0;
            fiveCount = 0;
            sixCount = 0;
            sevenCount = 0;
            eightCount = 0;
            nineCount = 0;
            tenCount = 0;
            elevenCount = 0;
            twelveCount = 0;
            allCount = 0;
            thriteenCount = 0;
            forteenCount = 0;
            fivteenCount = 0;
            sixteenCount = 0;
            hardness = 0;
            manualToAuto = 0;
            manualToHardness = 0;
            manualToBlock = 0;
            modelChange = 0;
        }
    public:


        int oneCount;  //第一种钢板计数
        int twoCount;  //第二种钢板计数
        int threeCount;//第三种钢板计数
        int fourCount; //第四种钢板计数
        int fiveCount; //第五种钢板计数
        int sixCount;  //第六种钢板计数
        int sevenCount;//第七种钢板计数
        int eightCount;//第八种钢板计数
        int nineCount; //第九种钢板计数
        int tenCount;  //第十种钢板计数
        int elevenCount;
        int twelveCount;
        int allCount; //所有累积计数
        int thriteenCount;
        int forteenCount;
        int fivteenCount;
        int sixteenCount;
        int hardness; //硬度仪返回值
        int hardnessStatus; //硬度仪状态
        int manualToAuto; //手动切换为自动状态
        int manualToHardness; //手动切换为手动打硬度状态
        int manualToBlock; //手动切换为手动打标快状态
        int modelChange; //新旧模式切换状态
        int warningStatus; //报警提示
        int autoDetectionFinish; //自动测量结束
        int manualDetectingBlock; //手动打标块硬度检测进行信号
        int manualDetectingHardness; //手动打钢板硬度检测进行信号
        int plateBlanking; //钢板吊走完成信号

        int airSupplyWarning;
        int hardnessDeviceWarning;
        int oldModeContactorWarning;
        int newModeContactorWarning;
        int hardnessDeviceEmergency;
        int modeChangeEmergency;
        int netWorkWarning;
        int hardnessDeviceContactorEmergency;


        int xCoordinate; //plc返回的x坐标
        int yCoordinate; //plc返回的y坐标
        int randomInspectionNum; //抽检信号

        int plateToBlankingBedStop; //钢板到下料床停止
        int plateToDetectionBedStop; //钢板到检测床终端停止
};


#endif // OBJECTINFO_H
