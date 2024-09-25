#include"grilledes.hh"
GridWidget::GridWidget(int rows, int columns, QWidget *parent)
    : QWidget(parent)
    , rows_(rows)
    , columns_(columns) {
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    buttons_.reserve(rows_ * columns_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < columns_; ++j) {
            QPushButton *button = new QPushButton(this);
            button->setFixedSize(100,100);
            button->setStyleSheet("background-color: white; border: 1px solid black;");

            // Save the button and its position in the grid
            buttons_.push_back({ button, i, j });

            gridLayout->addWidget(button, i, j);


            connect(button, &QPushButton::clicked, this, [=]() {
                onButtonClicked(buttons_[i * columns_ + j].row, buttons_[i * columns_ + j].column);
            });
        }
    }
}
