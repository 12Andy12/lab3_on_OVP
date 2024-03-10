#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "docwindow.h"

void MainWindow::slotAbout()
{
    QMessageBox::about(this, "Application", "IP-017\nKostin ANdrey and Izvekov Ivan");
}

void MainWindow::slotChangeWindowTitle(const QString& str)
{
    setWindowTitle(str);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMenu* pmnuFile = new QMenu("&File");
    QMenu* pmnuHelp = new QMenu("&Help");
    DocWindowIK* pdoc = new DocWindowIK();

    pmnuFile->addAction("&Open...",
                        pdoc,
                        SLOT(slotLoad()),
                        QKeySequence("CTRL+O")
                        );
    pmnuFile->addAction("&Save...",
                        pdoc,
                        SLOT(slotSave()),
                        QKeySequence("CTRL+S")
                        );
    pmnuFile->addAction("&SaveASS...",
                        pdoc,
                        SLOT(slotSaveAs()),
                        QKeySequence("CTRL+A")
                        );
    pmnuHelp->addAction("&About...",
                        this,
                        SLOT(slotAbout()),
                        QKeySequence("Qt::Key_F1")
                        );
    pmnuFile->addAction("&Color...",
                        pdoc,
                        SLOT(slotColor()),
                        QKeySequence("Qt::Key_F2")
                        );

    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);

    setCentralWidget(pdoc);
    connect(pdoc,
            SIGNAL(changeWindowTitle(const QString&)),
            SLOT(slotChangeWindowTitle(const QString&))
            );

    statusBar()->showMessage("Ready",4000);
    //ui->centralWidget->setT
}

MainWindow::~MainWindow()
{
    delete ui;
}
