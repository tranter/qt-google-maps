#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QWebFrame>
#include <QWebElement>
#include <QMessageBox>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    connect(ui->goButton, SIGNAL(clicked()), this, SLOT(goClicked()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(goClicked()));

    connect(&m_geocodeDataManager, SIGNAL(coordinatesReady(double,double)), this, SLOT(showCoordinates(double,double)));
    connect(&m_geocodeDataManager, SIGNAL(errorOccured(QString)), this, SLOT(errorOccured(QString)));

    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    ui->lineEdit->setText("");
    ui->webView->setUrl(QUrl("qrc:/html/google_maps.html"));
}

Form::~Form()
{
    delete ui;
}


void Form::showCoordinates(double east, double north)
{
    qDebug() << "Form, showCoordinates" << east << north;
    ui->webView->page()->currentFrame()->documentElement().evaluateJavaScript(
                QString("var myOptions = {") +
                QString("center: new google.maps.LatLng(%1, %2),").arg(north).arg(east) +
                QString("zoom: %1,").arg(ui->zoomSpinBox->value()) +
                QString("mapTypeId: google.maps.MapTypeId.ROADMAP,") +
                QString("panControl: true") +
                QString("};") +
                QString("var map = new google.maps.Map(document.getElementById(\"map_canvas\"), myOptions);")
                );
}

void Form::goClicked()
{
    QString address = ui->lineEdit->text();
    m_geocodeDataManager.getCoordinates(address.replace(" ", "+"));
}



void Form::errorOccured(const QString& error)
{
    QMessageBox::warning(this, tr("Geocode Error"), error);
}


