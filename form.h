#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "geocode_data_manager.h"

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();



private slots:
    void goClicked();

    void showCoordinates(double east, double north);
    void errorOccured(const QString&);



private:
    void getCoordinates(const QString& address);


private:
    Ui::Form *ui;
    GeocodeDataManager m_geocodeDataManager;
};

#endif // FORM_H
