#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "geocode_data_manager.h"

namespace Ui {
    class Form;
}


//structure for save markers data
struct SMarker
{
    SMarker()
    {
        east = 0;
        north = 0;
        caption = "";
    };
    SMarker(double _east, double _north, QString _caption)
    {
        east = _east; north = _north; caption = _caption;
    };

    double east;
    double north;
    QString caption;
};


class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();



private slots:
    void goClicked();

    void showCoordinates(double east, double north, bool saveMarker = true);
    //set marker to map and save marker in markers list
    void setMarker(double east, double north, QString caption);
    void errorOccured(const QString&);



    void on_lwMarkers_currentRowChanged(int currentRow);

    void on_pbRemoveMarker_clicked();

    void on_zoomSpinBox_valueChanged(int arg1);

private:
    void getCoordinates(const QString& address);


private:
    Ui::Form *ui;
    GeocodeDataManager m_geocodeDataManager;
    //markers list
    QList <SMarker*> m_markers;
};

#endif // FORM_H
