#ifndef __TRADINGVIEWCHART__
#define __TRADINGVIEWCHART__

#include <QWidget>
#include <QWebEngineView>

class TradingViewChart : public QWidget
{
    Q_OBJECT
public:
    explicit TradingViewChart(QWidget *parent = nullptr);

private:
    QWebEngineView *webView;
};

#endif
