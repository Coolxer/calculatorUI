#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_b_zero_clicked();
    void on_b_one_clicked();
    void on_b_two_clicked();
    void on_b_three_clicked();
    void on_b_four_clicked();
    void on_b_five_clicked();
    void on_b_six_clicked();
    void on_b_seven_clicked();
    void on_b_eight_clicked();
    void on_b_nine_clicked();
    void on_b_comma_clicked();
    void on_b_equal_clicked();
    void on_b_plus_clicked();
    void on_b_minus_clicked();
    void on_b_multiply_clicked();
    void on_b_divide_clicked();
    void on_b_square_clicked();
    void on_b_squareRoot_clicked();
    void on_b_oneBack_clicked();
    void on_b_mPlus_clicked();
    void on_b_mRelease_clicked();
    void on_b_mClear_clicked();
    void on_b_clear_clicked();

private:
    Ui::MainWindow *ui;

    enum Operation {nothing, add, minus, multiply, divide, square, squareRoot};
    Operation operation;

    QString result;
    QString x, y;
    QString memoryTab[5];

    int memWriteIndex;
    int memReadIndex;


    void addition(float x, float y);
    void subtraction(float x, float y);
    void division(float x, float y);
    void multiplication(float x, float y);
    void squaring(float x, float y);
    void squareRooting(float x);

    void screenUpdate(QString a);
};

#endif // MAINWINDOW_H
