#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Main window widget
    QWidget *mainw = new QWidget;
    mainw->setWindowTitle("first qt window");
    //spinbox & slider
    QSpinBox *spin = new QSpinBox;
    QSpinBox *spin2 = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spin->setRange(1,50);
    spin2->setRange(51,100);
    slider->setRange(1,50);
    QObject::connect(spin, SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(spin2, SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));
    spin->setValue(10);
    spin->setValue(60);
    slider->setValue(10);
    //Label
    QLabel *qlable = new QLabel("Hello this is Lable");
    //Push button
    QPushButton *qpush = new QPushButton("quit me");
    QPushButton *qpush2 = new QPushButton("clicking me");
    //qpush->show();
    QObject::connect(qpush,SIGNAL(clicked()),&a,SLOT(quit()));
    QObject::connect(qpush2,SIGNAL(clicked()),&a,SLOT(quit()));
//    qlable->show();

    //Create layout
    QHBoxLayout *layout = new QHBoxLayout;
    //add widget to layout
    layout->addWidget(spin);
    layout->addWidget(spin2);
    layout->addWidget(slider);
    layout->addWidget(qlable);
    layout->addWidget(qpush);
    layout->addWidget(qpush2);

    //set layout for main window
    mainw->setLayout(layout);
    mainw->show();

    MainWindow w;
    w.show();
    
    return a.exec();
}
