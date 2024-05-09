#ifndef PLATECHARTVIEW_H
#define PLATECHARTVIEW_H
#include <QtCharts/QChartView>
#include <QMouseEvent>
#include <QScatterSeries>
#include <myhelper.h>
#include <objectinfo.h>
QT_CHARTS_USE_NAMESPACE

class CustomChartView : public QChartView
{
public:
    CustomChartView(QChart *chart, QWidget *parent = nullptr)
        : QChartView(chart, parent)
    {}
    QVector<QPointF> allPoints;
protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        if (event->button() == Qt::LeftButton)
        {
            QPointF point = chart()->mapToValue(event->pos());
            QScatterSeries *scatterSeries = static_cast<QScatterSeries *>(chart()->series().first());
            if(scatterSeries->count() >= 3)
            {
                myHelper::ShowMessageBoxInfo("已经定义了最多的点位数，请删除部分点位后再添加。");
                return;
            }
            int yPointCount = 0;
            for (int i = 0; i < scatterSeries->count(); ++i)
            {
                if (scatterSeries->at(i).y() == point.y())
                {
                    yPointCount++;
                }
            }
            if (yPointCount >= 6)
            {
                myHelper::ShowMessageBoxInfo("已经定义了该X值上的最多点位数，请选择其他X值。");
                return;
            }
//            if (point.y() > maxXCoordinate)
//            {
//                myHelper::ShowMessageBoxInfo("点击的X坐标超过最大值，请选择更小的X值。");
//                return;
//            }

//            // 点击不能超过Y轴的最大值
//            if (point.x() > maxYCoordinate)
//            {
//                myHelper::ShowMessageBoxInfo("点击的Y坐标超过最大值，请选择更小的Y值。");
//                return;
//            }
            if (allPoints.contains(point))
            {
                myHelper::ShowMessageBoxInfo("该点位已经定义，请选择其他位置。");
                return;
            }
            else {
                scatterSeries->append(point);
                chart()->update();
                allPoints.append(point);
                for(int i=0;i<allPoints.size();i++)
                {
                    plist.xVal = allPoints[i].x();
                    plist.yVal = allPoints[i].y();
                }

            }
        }
        QChartView::mousePressEvent(event);
    }
private:
    PointList plist;

};


#endif // PLATECHARTVIEW_H
