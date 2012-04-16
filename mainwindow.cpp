#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));

    m_pForm = new Form(this);
    setCentralWidget(m_pForm);




}

MainWindow::~MainWindow()
{
    delete ui;
}
