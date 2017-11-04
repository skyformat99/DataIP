#include "Curve.h"

Curve::Curve(ChartType chart,QWidget *parent) : QCustomPlot(parent)
{
    m_chartType = chart;
    connect(this, SIGNAL(legendClick(QCPLegend *, QCPAbstractLegendItem *, QMouseEvent *)),
                this, SLOT(onLegendClick(QCPLegend *, QCPAbstractLegendItem *)));
    connect(this, SIGNAL(plottableClick(QCPAbstractPlottable *, QMouseEvent *)),
            this, SLOT(onPlottableClick(QCPAbstractPlottable *)));
}

void Curve::setTickerLables(const QVector<QString> &tickers)
{
    m_tickerLabels = tickers;
    for(int i = 0, len = tickers.size(); i != len; ++i)
        m_ticker.push_back(i + 1);

    setPlotAxisAndLegend();
}

void Curve::setNames(const QVector<QString> &names)
{
    m_names = names;
}

void Curve::setData(const QVector<QVector<double> > &data)
{
    m_data = data;
    if(m_chartType == ChartType::BarChart)
        setBars();
    else if(m_chartType == ChartType::LineChart)
        setLine();
}

void Curve::onLegendClick(QCPLegend *, QCPAbstractLegendItem *item)
{
    if(!item)
        return ;

    QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem *>(item);
    if(!plItem)
        return ;

    QString name = plItem->plottable()->name();
    for(int i = 0, len = m_names.size(); i != len; ++i)
    {
        if(m_names[i] == name)
        {
            if(m_chartType == ChartType::BarChart)
            {
                m_bars[i]->setSelected(true);
            }
            else if(m_chartType == ChartType::LineChart)
            {
                m_graphs[i]->setSelected(true);
            }
        }
    }
}

void Curve::onPlottableClick(QCPAbstractPlottable *plottable)
{
    if(!plottable)
        return;

    if(m_chartType == ChartType::BarChart)
    {
        QCPBars *bar = qobject_cast<QCPBars *>(plottable);
        if(!bar)
            return;

        for(int i = 0, len = m_bars.size(); i != len; ++i)
        {
            if(m_bars[i] == bar)
            {
                this->legend->item(i)->setSelected(true);
            }
        }
    }
    else if(m_chartType == ChartType::LineChart)
    {
        QCPGraph *graph = qobject_cast<QCPGraph *>(plottable);
        if(!graph)
            return;

        for(int i = 0, len = m_graphs.size(); i != len; ++i)
        {
            if(m_graphs[i] == graph)
            {
                this->legend->item(i)->setSelected(true);
            }
        }
    }
}

void Curve::setPlotAxisAndLegend()
{
    this->xAxis->setAutoTicks(false);
    this->xAxis->setAutoTickLabels(false);
    this->xAxis->setTickVector(m_ticker);
    this->xAxis->setTickVectorLabels(m_tickerLabels);
    this->xAxis->setTickLabelRotation(60);
    this->xAxis->setTickLength(0, 4);
    this->xAxis->setSubTickCount(0);
    this->xAxis->grid()->setVisible(false);
    this->xAxis->setRange(0, m_ticker.size() + 2);
    this->xAxis->setLabel(tr("表格数据展示"));
    this->xAxis->setLabelColor(QColor(Qt::red));
    this->xAxis->setAutoTickStep(false);
    this->xAxis->setTickStep(1);

    this->yAxis->setRange(0, 100);
    this->yAxis->setPadding(5);
    this->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(Qt::blue));
    this->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    this->yAxis->grid()->setSubGridPen(gridPen);

    this->legend->setVisible(true);
    this->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignRight);
    this->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    this->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    this->legend->setFont(legendFont);
    this->setInteractions(QCP::iSelectPlottables | QCP::iSelectLegend);
}

void Curve::setBars()
{
    QVector<QColor> colors, brushs;
    colors << QColor(77,164,246) << QColor(106,140,63) << QColor(239,65,15) << QColor(94,183,62);
    brushs << QColor(77,164,246,50) << QColor(106,140,63,50) << QColor(239,65,15,50) << QColor(94,183,62,50);

    m_barGroup = new QCPBarsGroup(this);
    for(int i = 0, len = m_names.size(); i != len; ++i)
    {
        QCPBars *bar = new QCPBars(this->xAxis, this->yAxis);
        bar->setName(m_names[i]);
        m_barGroup->append(bar);
        m_bars.push_back(bar);

        bar->setPen(QPen(colors[i]));
        bar->setBrush(QBrush(brushs[i]));
        bar->setWidth(0.15);

        bar->setData(m_ticker, m_data[i]);

        this->addPlottable(bar);
    }
}

void Curve::setLine()
{
    QVector<QColor> colors;
    colors << QColor(77,164,246) << QColor(106,140,63) << QColor(239,65,15) << QColor(94,183,62);

    for(int i = 0, len = m_names.size(); i != len; ++i)
    {
        QCPGraph *graph = this->addGraph(this->xAxis, this->yAxis);
        graph->setName(m_names[i]);
        m_graphs.push_back(graph);

        graph->setLineStyle(QCPGraph::lsLine);
        graph->setScatterStyle(QCPScatterStyle::ssCircle);
        QPen pen(colors[i]);
        pen.setWidthF(2.0);
        graph->setPen(pen);

        graph->setData(m_ticker, m_data[i]);
    }
}
