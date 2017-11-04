#ifndef CURVE_H
#define CURVE_H

#include <QWidget>
#include "qcustomplot.h"
#include "common.h"

enum ChartType{
    BarChart = 0,
    LineChart
};

class Curve : public QCustomPlot
{
    Q_OBJECT
public:
    explicit Curve(ChartType chart = ChartType::LineChart, QWidget *parent = nullptr);
    void setTickerLables(const QVector<QString> &tickers);
    void setNames(const QVector<QString> &names);
    void setData(const QVector<QVector<double> > &data);

signals:

public slots:
    void onLegendClick(QCPLegend *, QCPAbstractLegendItem *);
    void onPlottableClick(QCPAbstractPlottable *plottable);

private:
    void setPlotAxisAndLegend();
    void setBars();
    void setLine();

    ChartType m_chartType;
    QVector<double> m_ticker;
    QVector<QString> m_tickerLabels;
    QVector<QString> m_names;
    QVector<QVector<double> > m_data;

    QCPBarsGroup *m_barGroup;
    QVector<QCPBars *> m_bars;
    QVector<QCPGraph *> m_graphs;
};

#endif // CURVE_H
