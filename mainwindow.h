#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<fstream>
#include<istream>
#include<Windows.h>
#include<time.h>
#include<iomanip>
#include"json.hpp"
#include<QDir>
#include<QDebug>

QVector<QPair<int, int>> dijkstra(QVector<QVector<int>>* graph, int start, int end);

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_draw_basic_graf_clicked();

    void on_pushButton_from_plus_clicked();

    void on_pushButton_from_minus_clicked();

    void on_pushButton_to_plus_clicked();

    void on_pushButton_to_minus_clicked();

    void on_pushButton_generate_path_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int start_alg = 1, end_alg = 2;
    int kol_dot = 0;
    QString path_file = "";
    QMap<int, QPointF> nodePositions; // координаты всех вершин
    QGraphicsScene *scene;
    void loadGraphFromCustomJson(const QString &filePath);
    void highlightDijkstraPath(int start, int end);
    void highlightNode(int nodeId, const QColor& color);
};
#endif // MAINWINDOW_H
