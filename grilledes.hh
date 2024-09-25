#ifndef GRILLEDES_HH
#define GRILLEDES_HH

#include <piece.hh>
#include<grille.hh>
#include <QPushButton>

#include <QPushButton>
#include <QGridLayout>
#include <QGridLayout>
#include <QPushButton>

class GridWidget : public QWidget {
    Q_OBJECT

public:
    GridWidget(int rows, int columns, QWidget *parent = nullptr);

signals:
    void buttonClicked(int row, int column);

public slots:
    void onButtonClicked(int row, int column) {
        emit buttonClicked(row, column);
    }

private:
    struct GridButton {
        QPushButton *button;
        int row;
        int column;
    };

    int rows_;
    int columns_;
    std::vector<GridButton> buttons_;
};

#endif // GRILLEDES_HH
