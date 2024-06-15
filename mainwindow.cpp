#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include <QRect>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , playerScore(0)
    , aiScore(0)
    , ballXDir(-7)
    , ballYDir(-7)
    , ballSpeed(7)
    , aiSpeed(5)
    , collisionCount(0)
    , isPaused(false)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGame);
    timer->start(16);
    resetBall();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (!isPaused) {
        int mouseY = event->y();
        int gameFrameY = ui->gameFrame->geometry().topLeft().y() + ui->centralwidget->geometry().topLeft().y();
        int gameFrameHeight = ui->gameFrame->height();
        if (mouseY > gameFrameY && mouseY < gameFrameY + gameFrameHeight) {
            ui->playerPaddle->move(ui->playerPaddle->x(), mouseY - ui->playerPaddle->height() / 2);
        }
    }
}

void MainWindow::updateGame()
{
    if (isPaused) return;

    ui->ball->move(ui->ball->x() + ballXDir, ui->ball->y() + ballYDir);

    checkCollisions();

    moveAI();

    ui->scoreLabel->setText(QString::number(playerScore) + ":" + QString::number(aiScore));
}

void MainWindow::on_pauseButton_clicked()
{
    isPaused = !isPaused;
    ui->pauseButton->setText(isPaused ? "Play" : "Pause");
}

void MainWindow::resetBall()
{
    ui->ball->move(ui->gameFrame->width() / 2, ui->gameFrame->height() / 2);
    ballXDir = -ballSpeed;
    ballYDir = -ballSpeed;
    ballSpeed = 7;
    collisionCount = 0;
}

void MainWindow::checkCollisions()
{
    QRect ballRect = ui->ball->geometry();
    QRect playerPaddleRect = ui->playerPaddle->geometry();
    QRect aiPaddleRect = ui->aiPaddle->geometry();

    ballRect.translate(ui->ball->parentWidget()->geometry().topLeft());
    playerPaddleRect.translate(ui->playerPaddle->parentWidget()->geometry().topLeft());
    aiPaddleRect.translate(ui->aiPaddle->parentWidget()->geometry().topLeft());

    if (ballRect.intersects(playerPaddleRect)) {
        ballXDir = ballSpeed;
        collisionCount++;
        increaseBallSpeed();
    } else if (ballRect.intersects(aiPaddleRect)) {
        ballXDir = -ballSpeed;
        collisionCount++;
        increaseBallSpeed();
    } else if (ballRect.left() <= ui->gameFrame->geometry().left()) {
        aiScore++;
        resetBall();
    } else if (ballRect.right() >= ui->gameFrame->geometry().right()) {
        playerScore++;
        resetBall();
    }

    if (ballRect.top() <= ui->gameFrame->geometry().top() || ballRect.bottom() >= ui->gameFrame->geometry().bottom()) {
        ballYDir = -ballYDir;
    }
}

void MainWindow::moveAI()
{
    int ballY = ui->ball->y();
    int aiPaddleY = ui->aiPaddle->y();
    if (ballY < aiPaddleY) {
        ui->aiPaddle->move(ui->aiPaddle->x(), aiPaddleY - aiSpeed);
    } else if (ballY > aiPaddleY + ui->aiPaddle->height()) {
        ui->aiPaddle->move(ui->aiPaddle->x(), aiPaddleY + aiSpeed);
    }
}

void MainWindow::increaseBallSpeed()
{
    if (collisionCount % 2 == 0) {
        ballSpeed = std::min(ballSpeed * 1.1, 21.0);
        if (ballXDir > 0)
            ballXDir = ballSpeed;
        else
            ballXDir = -ballSpeed;

        if (ballYDir > 0)
            ballYDir = ballSpeed;
        else
            ballYDir = -ballSpeed;
    }
}
