#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // 設定狀態列初始訊息
    ui->statusbar->showMessage("就緒 - 歡迎使用 MidtermAI 系統", 3000);
    
    // 連接按鈕信號到槽函數
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onProcessButtonClicked);
    connect(ui->actionButton, &QPushButton::clicked, this, &MainWindow::onActionButtonClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetButtonClicked);
    
    // 連接選單動作
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::onAboutTriggered);
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onProcessButtonClicked()
{
    QString name = ui->nameLineEdit->text();
    QString description = ui->descriptionTextEdit->toPlainText();
    
    if (name.isEmpty()) {
        ui->statusbar->showMessage("錯誤: 請輸入名稱", 3000);
        QMessageBox::warning(this, "輸入錯誤", "請先輸入名稱！");
        return;
    }
    
    ui->statusbar->showMessage("正在處理資料: " + name, 3000);
    QMessageBox::information(this, "處理完成", 
        QString("已成功處理資料\n名稱: %1\n描述: %2").arg(name).arg(description));
}

void MainWindow::onActionButtonClicked()
{
    ui->statusbar->showMessage("執行操作中...", 3000);
    QMessageBox::information(this, "執行操作", "操作已成功執行！");
}

void MainWindow::onResetButtonClicked()
{
    ui->nameLineEdit->clear();
    ui->descriptionTextEdit->clear();
    ui->statusbar->showMessage("已重置所有欄位", 3000);
}

void MainWindow::onAboutTriggered()
{
    QMessageBox::about(this, "關於 MidtermAI",
        "<h2>MidtermAI 系統</h2>"
        "<p>版本: 1.0.0</p>"
        "<p>智能應用系統 - 提供高效的AI解決方案</p>"
        "<p>© 2025 MidtermAI Team</p>");
}
