#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QGraphicsItem>
#include <QtWidgets>
#include <QWidget>
#include <vector>

#include "palette.h"
#include "paintarea.h"

enum BUTTON {ELLIPSE=0, RECTANGLE, TRIANGLE, LINE, CURVE, POLYGON};
class QGroupBox;
namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_allButtons_clicked();

public slots:

signals:
    void clicked(int x);
    void ShiftOn(bool);

private:
    Ui::MainWindow *ui;
    QScrollArea* view;
    PaintArea *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    std::vector <QPushButton*> allButtons;
    Palette *palette;
    QToolBar *mToolbar;
    QSlider *slider;
    QComboBox *penPattern;
    QComboBox *brushPattern;
    QLabel* label;

    QVBoxLayout *createToolsGroup();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
