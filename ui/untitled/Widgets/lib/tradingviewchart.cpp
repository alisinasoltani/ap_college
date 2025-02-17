#include "../include/tradingviewchart.h"

#include <QWidget>
#include <QWebEngineView>

TradingViewChart::TradingViewChart(QWidget *parent)
    : QWidget{parent}
{
    webView = new QWebEngineView(this);

    // Add the QWebEngineView to the layout of the main window
    setCentralWidget(webView);

    // Load the TradingView widget with your HTML code
    // Example: Replace this with the HTML code or URL you want to embed
    QString html = R"(
    <html>
    <head>
        <script type="text/javascript" src="https://s3.tradingview.com/tv.js"></script>
    </head>
    <body>
        <div id="tv_chart_container"></div>
        <script type="text/javascript">
            new TradingView.widget({
                "autosize": true,
                "symbol": "NASDAQ:AAPL",
                "interval": "D",
                "container_id": "tv_chart_container",
                "datafeed": new TradingView.Datafeeds.UDFCompatibleDatafeed("https://demo_feed.tradingview.com"),
                "library_path": "https://s3.tradingview.com",
                "locale": "en",
                "enabled_features": ["study_templates"],
                "disabled_features": ["use_localstorage_for_settings"]
            });
        </script>
    </body>
    </html>
    )";
    // Load the HTML content into the web view
    webView->setHtml(html);

}
