#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Get the primary screen geometry
    QScreen *screen = QApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    
    // Define optimal window size (consistent with UI design)
    const int windowWidth = 700;
    const int windowHeight = 500;
    const int spacing = 20; // Spacing between windows
    
    // Calculate positions to center windows on screen with spacing
    int totalWidth = windowWidth * 2 + spacing;
    int startX = (screenGeometry.width() - totalWidth) / 2;
    int startY = (screenGeometry.height() - windowHeight) / 2;
    
    // Ensure windows fit on screen
    if (startX < 0) {
        startX = 10;
    }
    if (startY < 0) {
        startY = 10;
    }
    
    // Create and configure first window
    MainWindow w;
    w.setWindowTitle("Main Window 1");
    w.resize(windowWidth, windowHeight);
    w.move(startX, startY);
    w.show();
    
    // Create and configure second window
    MainWindow w2;
    w2.setWindowTitle("Main Window 2");
    w2.resize(windowWidth, windowHeight);
    w2.move(startX + windowWidth + spacing, startY);
    w2.show();
    
    return a.exec();
}
