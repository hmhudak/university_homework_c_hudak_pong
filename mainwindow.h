#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void updateGame();
    void on_pauseButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int playerScore;
    int aiScore;
    int ballXDir;
    int ballYDir;
    int ballSpeed;
    int aiSpeed;
    int collisionCount;
    bool isPaused;
    void resetBall();
    void checkCollisions();
    void moveAI();
    void increaseBallSpeed();
};

#endif // MAINWINDOW_H
