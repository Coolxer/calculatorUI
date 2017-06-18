#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operation = nothing;
    memWriteIndex = -1;
    memReadIndex = -1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_zero_clicked()
{
    if(operation == 0)
    {
        x += "0";
        screenUpdate(x);
    }
    else
    {
        y += "0";
        screenUpdate(y);
    }
}

void MainWindow::on_b_one_clicked()
{
    if(operation == 0)
    {
        x += "1";
        screenUpdate(x);
    }
    else
    {
        y += "1";
        screenUpdate(y);
    }
}

void MainWindow::on_b_two_clicked()
{
    if(operation == 0)
    {
        x += "2";
        screenUpdate(x);
    }
    else
    {
        y += "2";
        screenUpdate(y);
    }
}

void MainWindow::on_b_three_clicked()
{
    if(operation == 0)
    {
        x += "3";
        screenUpdate(x);
    }
    else
    {
        y += "3";
        screenUpdate(y);
    }
}

void MainWindow::on_b_four_clicked()
{
    if(operation == 0)
    {
        x += "4";
        screenUpdate(x);
    }
    else
    {
        y += "4";
        screenUpdate(y);
    }
}

void MainWindow::on_b_five_clicked()
{
    if(operation == 0)
    {
        x += "5";
        screenUpdate(x);
    }
    else
    {
        y += "5";
        screenUpdate(y);
    }
}

void MainWindow::on_b_six_clicked()
{
    if(operation == 0)
    {
        x += "6";
        screenUpdate(x);
    }
    else
    {
        y += "6";
        screenUpdate(y);
    }
}

void MainWindow::on_b_seven_clicked()
{
    if(operation == 0)
    {
        x += "7";
        screenUpdate(x);
    }
    else
    {
        y += "7";
        screenUpdate(y);
    }
}

void MainWindow::on_b_eight_clicked()
{
    if(operation == 0)
    {
        x += "8";
        screenUpdate(x);
    }
    else
    {
        y += "8";
        screenUpdate(y);
    }
}

void MainWindow::on_b_nine_clicked()
{
    if(operation == 0)
    {
        x += "9";
        screenUpdate(x);
    }
    else
    {
        y += "9";
        screenUpdate(y);
    }
}

void MainWindow::on_b_comma_clicked()
{
    if(operation == 0)
    {
        x += ".";
        screenUpdate(x);
    }
    else
    {
        y += ".";
        screenUpdate(y);
    }
}

void MainWindow::on_b_equal_clicked()
{
    float a = x.toFloat();
    float b = y.toFloat();
    float c = result.toFloat();

    switch(operation)
    {
    case 0:
        break;
    case 1:
        c = a + b;
        break;
    case 2:
        c = a - b;
        break;
    case 3:
        c = a * b;
        break;
    case 4:
        c = a / b;
        break;
    case 5:
        c = pow(a,2);
        break;
    case 6:
        c = sqrt(a);
        break;
    }
    result = QString::number(c);
    screenUpdate(result);
    x.clear();
    y.clear();
    operation = nothing;
}

void MainWindow::on_b_plus_clicked()
{
    if(!result.isEmpty())
        x = result;
    operation = add;
}

void MainWindow::on_b_minus_clicked()
{
    if(!result.isEmpty())
        x = result;
    operation = minus;
}

void MainWindow::on_b_multiply_clicked()
{
    if(!result.isEmpty())
        x = result;
    operation = multiply;
}

void MainWindow::on_b_divide_clicked()
{
    if(!result.isEmpty())
        x = result;
    operation = divide;
}

void MainWindow::on_b_square_clicked()
{
    if(!result.isEmpty())
        x = result;
    operation = square;
}

void MainWindow::on_b_squareRoot_clicked()
{
    if(!result.isEmpty())
        x = result;
    operation = squareRoot;
}

void MainWindow::on_b_oneBack_clicked()
{
    if(result.isEmpty())
    {
        if(operation == 0)
        {
            x = x.left(x.length()-1);
            screenUpdate(x);
        }
        else
        {
            y = y.left(y.length()-1);
            screenUpdate(y);
        }
    }
}

void MainWindow::on_b_mPlus_clicked()
{
    memWriteIndex++;

    if(memWriteIndex == 5)
        memWriteIndex = 0;

    if(ui->screen->text() == result)
        memoryTab[memWriteIndex] = result;
    else if(ui->screen->text() == x)
        memoryTab[memWriteIndex] = x;
    else if(ui->screen->text() == y)
        memoryTab[memWriteIndex] = y;
}

void MainWindow::on_b_mRelease_clicked()
{
    memReadIndex++;

    if(memReadIndex == 5)
        memReadIndex = 0;

    if(operation == 0)
    {
        x = memoryTab[memReadIndex];
        screenUpdate(x);
    }
    else
    {
        y = memoryTab[memReadIndex];
        screenUpdate(y);
    }

}

void MainWindow::on_b_mClear_clicked()
{
    for(int i=0; i<5; i++)
        memoryTab[i] = "0";
}

void MainWindow::on_b_clear_clicked()
{
   ui->screen->setText("0");
   x.clear();
   y.clear();
   result.clear();
}

void MainWindow::screenUpdate(QString a)
{
    ui->screen->setText(a);
}
