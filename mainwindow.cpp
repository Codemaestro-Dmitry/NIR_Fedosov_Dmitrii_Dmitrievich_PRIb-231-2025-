#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<QGraphicsEllipseItem>
#include<QGraphicsLineItem>
#include<QJsonDocument>
#include<QJsonArray>
#include<QJsonObject>
#include<QFile>
#include<QMap>
#include<QGraphicsTextItem>
#include<QPair>
#include<QDebug>
#include<QDir>
#include<QCoreApplication>
#include<QVector>
#include<QPair>
#include<queue>
#include<limits>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->label_error->hide();
    ui->label_from->setText(QString::number(MainWindow::start_alg));
    ui->label_to->setText(QString::number(MainWindow::end_alg));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - MainWindow - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void MainWindow::loadGraphFromCustomJson(const QString &filePath) {
    scene->clear(); // Очищаем сцену перед загрузкой нового графа

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл:" << filePath;
        ui->label_error->setText("Не удалось открыть файл!");
        ui->label_error->show();
        return;
    } else {
        ui->label_error->hide();
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        qDebug() << "JSON не является массивом!";
        ui->label_error->setText("Ошибка: JSON должен быть массивом узлов!");
        return;
    }

    QJsonArray array = doc.array();
    qDebug() << "Количество узлов:" << array.size();
    MainWindow::kol_dot = array.size();

    QMap<int, QPointF> nodePositions;
    const double scale = 30.0;
    const int nodeRadius = 10;

    // 1. Создаём узлы (вершины графа)
    for (int i = 0; i < array.size(); ++i) {
        QJsonObject nodeObj = array[i].toObject();
        double x = nodeObj["X"].toDouble() * scale;
        double y = -nodeObj["Y"].toDouble() * scale;
        int nodeId = i + 1; // Нумерация с 1

        QPointF pos(x, y);
        nodePositions[nodeId] = pos;

        // Создаём графический элемент вершины
        QGraphicsEllipseItem *ellipse = scene->addEllipse(
            x - nodeRadius, y - nodeRadius,
            nodeRadius * 2, nodeRadius * 2,
            QPen(Qt::black), QBrush(Qt::white)
            );
        ellipse->setData(0, nodeId); // Сохраняем ID в данных элемента

        // Добавляем текст с номером вершины
        QGraphicsTextItem *text = scene->addText(QString::number(nodeId));
        text->setPos(x + nodeRadius + 2, y - nodeRadius);
        text->setData(0, nodeId); // Связываем текст с вершиной

        qDebug() << "Узел" << nodeId << "на позиции" << pos;
    }

    // 2. Создаём рёбра графа
    for (int i = 0; i < array.size(); ++i) {
        QJsonObject nodeObj = array[i].toObject();
        int fromId = i + 1;

        QJsonArray connections = nodeObj["svaz"].toArray();
        QJsonArray weights = nodeObj["ves"].toArray();

        for (int j = 0; j < connections.size(); ++j) {
            int toId = connections[j].toInt();
            int weight = weights[j].toInt();

            // Проверяем, чтобы не дублировать рёбра (A->B и B->A)
            if (nodePositions.contains(fromId) && nodePositions.contains(toId) && fromId < toId) {
                QLineF line(nodePositions[fromId], nodePositions[toId]);

                // Создаём линию ребра
                QGraphicsLineItem *edgeLine = scene->addLine(line, QPen(Qt::gray, 2));
                edgeLine->setData(0, fromId); // Сохраняем начальную вершину
                edgeLine->setData(1, toId);   // Сохраняем конечную вершину
                edgeLine->setData(2, weight); // Сохраняем вес ребра
                edgeLine->setZValue(-1);     // Отправляем рёбра на задний план

                // Добавляем текст с весом ребра
                QPointF midPoint = line.pointAt(0.5);
                QGraphicsTextItem *weightText = scene->addText(QString::number(weight));
                weightText->setDefaultTextColor(Qt::darkGray);
                weightText->setPos(midPoint);
                weightText->setData(0, fromId); // Связываем с ребром
                weightText->setData(1, toId);
                weightText->setZValue(1);       // Текст поверх других элементов

                qDebug() << "Ребро:" << fromId << "->" << toId << "вес:" << weight;
            }
        }
    }

    // 3. Масштабируем сцену
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    ui->graphicsView->centerOn(scene->itemsBoundingRect().center());
}

QVector<QPair<int, int>> dijkstra(QVector<QVector<int>>* graph, int start, int end) {
    int n = graph->size();
    QVector<int> dist(n, std::numeric_limits<int>::max());
    QVector<int> parent(n, -1);

    // Используем std::priority_queue с Qt-совместимыми типами
    std::priority_queue<QPair<int, int>,
                        QVector<QPair<int, int>>,
                        std::greater<QPair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (int v = 0; v < n; ++v) {
            int weight = (*graph)[u][v];
            if (weight > 0) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    // Восстановление пути
    if (parent[end] == -1) {
        return {};
    }

    QVector<QPair<int, int>> path;
    for (int v = end; v != start; v = parent[v]) {
        path.append({parent[v], v});
    }

    std::reverse(path.begin(), path.end());
    return path;
}

void MainWindow::highlightDijkstraPath(int start, int end)
{
    if (!scene)
    {
        qDebug() << "Сцена не инициализирована!";
        return;
    }

    // 1. Получаем матрицу смежности из текущего графа на сцене
    QVector<QVector<int>> adjacencyMatrix;
    QMap<int, QPointF> nodePositions;

    // Собираем все узлы (предполагаем, что они уже есть на сцене)
    for (const auto& item : scene->items()) {
        if (auto ellipse = dynamic_cast<QGraphicsEllipseItem*>(item))
        {
            int nodeId = ellipse->data(0).toInt(); // Предполагаем, что ID хранится в данных элемента
            nodePositions[nodeId] = ellipse->rect().center();
        }
    }

    // Инициализируем матрицу смежности (заполняем нулями)
    int nodeCount = nodePositions.size();
    adjacencyMatrix.resize(nodeCount);
    for (int i = 0; i < nodeCount; ++i)
    {
        adjacencyMatrix[i].resize(nodeCount, 0);
    }

    // Заполняем матрицу весами рёбер (из линий на сцене)
    for (const auto& item : scene->items())
    {
        if (auto line = dynamic_cast<QGraphicsLineItem*>(item))
        {
            // Находим начальную и конечную вершины ребра (можно хранить в данных линии)
            int fromId = line->data(0).toInt();
            int toId = line->data(1).toInt();
            int weight = line->data(2).toInt(); // Вес ребра

            if (fromId > 0 && toId > 0 && fromId <= nodeCount && toId <= nodeCount)
            {
                adjacencyMatrix[fromId - 1][toId - 1] = weight;
                adjacencyMatrix[toId - 1][fromId - 1] = weight; // Для неориентированного графа
            }
        }
    }

    // 2. Применяем алгоритм Дейкстры
    auto path = dijkstra(&adjacencyMatrix, start - 1, end - 1); // Индексация с 0
    qDebug()<<" - - - - - - - - - ";
    if (path.isEmpty()) {
        qDebug() << "Путь не найден!";
        ui->label_error->setText("Путь не найден!");
        ui->label_error->show();
        return;
    }

    // 3. Перерисовываем рёбра пути зелёным цветом
    for (const auto& edge : path)
    {
        int u = edge.first + 1;  // Переводим обратно в 1-индексацию
        int v = edge.second + 1;

        // Ищем линию, соответствующую ребру u-v
        for (auto item : scene->items())
        {
            if (auto line = dynamic_cast<QGraphicsLineItem*>(item)) {
                int lineFrom = line->data(0).toInt();
                int lineTo = line->data(1).toInt();

                if ((lineFrom == u && lineTo == v) || (lineFrom == v && lineTo == u)) {
                    line->setPen(QPen(Qt::green, 3)); // Выделяем зелёным
                    break;
                }
            }
        }
    }

    int weight_alg = 0;
    for(int i=0;i<path.size();i++)
    {
        weight_alg+= adjacencyMatrix[path[i].first][path[i].second];
    }

    ui->label_ves->setText(QString::number(weight_alg));

    // 4. Выделяем начальную и конечную вершины
    highlightNode(start, Qt::blue);
    highlightNode(end, Qt::red);

    qDebug() << "Путь выделен: от" << start << "до" << end;
}

// Вспомогательная функция для выделения вершины
void MainWindow::highlightNode(int nodeId, const QColor& color) {
    for (auto item : scene->items()) {
        if (auto ellipse = dynamic_cast<QGraphicsEllipseItem*>(item)) {
            if (ellipse->data(0).toInt() == nodeId) {
                ellipse->setBrush(QBrush(color));
                break;
            }
        }
    }
}

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - Слоты - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void MainWindow::on_pushButton_draw_basic_graf_clicked()
{
    MainWindow::loadGraphFromCustomJson(QCoreApplication::applicationDirPath() + "/file.json");
    MainWindow::path_file = QCoreApplication::applicationDirPath() + "/file.json";
}

void MainWindow::on_pushButton_from_plus_clicked()
{
    if(MainWindow::start_alg+1 <= MainWindow::kol_dot)
    {
        MainWindow::start_alg++;
    }
    ui->label_from->setText(QString::number(MainWindow::start_alg));
}

void MainWindow::on_pushButton_from_minus_clicked()
{
    if(MainWindow::start_alg-1 > 0)
    {
        MainWindow::start_alg--;
    }

    ui->label_from->setText(QString::number(MainWindow::start_alg));
}

void MainWindow::on_pushButton_to_plus_clicked()
{
    if(MainWindow::end_alg+1 <= MainWindow::kol_dot)
    {
        MainWindow::end_alg++;
    }
    ui->label_to->setText(QString::number(MainWindow::end_alg));
}

void MainWindow::on_pushButton_to_minus_clicked()
{
    if(MainWindow::end_alg-1 > 0)
    {
        MainWindow::end_alg--;
    }

    ui->label_to->setText(QString::number(MainWindow::end_alg));
}


void MainWindow::on_pushButton_generate_path_clicked()
{
    MainWindow::loadGraphFromCustomJson(MainWindow::path_file);
    MainWindow::highlightDijkstraPath(MainWindow::start_alg, MainWindow::end_alg);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    MainWindow::loadGraphFromCustomJson(arg1);
    MainWindow::path_file = arg1;
}

