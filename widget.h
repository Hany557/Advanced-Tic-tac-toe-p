#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>
#include <QStringList>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    // Login Page
    void on_loginButton_clicked();
    void on_signupLoginPageButton_clicked();
    void on_showLoginPasswordCheckBox_toggled(bool checked);
    void on_noWorriesButton_clicked();

    // Sign-Up Page
    void on_registerButton_clicked();
    void on_showSignupPasswordCheckBox_toggled(bool checked);
    void on_loginButtonSignupPage_clicked();

    // Main Page
    void on_playerVsAiButton_clicked();
    void on_playerVsPlayerButton_clicked();
    void on_myAccountButton_clicked();
    void on_myGameHistoryButton_clicked();

    // Password Reset Page
    void on_resetPasswordButton_clicked();
    void on_showResetNewPasswordCheckBox_toggled(bool checked);
    void on_backButtonReset_clicked();

    // Personal Info Page
    void on_backButtonAccount_clicked();
    void on_changePasswordButton_clicked();
    void on_logoutButtonAccount_clicked();

    // Game Board Page
    void on_resetGameboardButton_clicked();
    void on_backButtonGamePage_clicked();
    void handleButtonClick();

    // Game History Page
    void on_replayGameButton_clicked();
    void on_deleteGameButton_clicked();
    void on_backButtonHistory_clicked();

private:
    Ui::Widget *ui;
    bool isVsAI; // Flag to indicate if the game is Player vs AI
    QString currentUser; // Store the current logged-in user
    QStringList moveHistory; // Track moves made during the game

    // AI-related methods
    int minimax(int board[3][3], bool isMaximizing);
    QPoint findBestMove(int board[3][3]);
    bool isMovesLeft(int board[3][3]);
    int evaluateBoard(int board[3][3]);

    // Game-related methods
    int checkWin();
    bool isBoardFull();
    void resetBoard();
    QPushButton* getButton(int row, int col);
    void showWinnerMessage(int winResult);

    // Database related methods
    void initializeDatabase();
    bool registerUser(const QString &username, const QString &password, const QString &firstName, const QString &lastName, const QString &securityQuestion, const QString &securityAnswer);
    bool authenticateUser(const QString &username, const QString &password);

    // Game history related methods
    void loadGameHistory();
    void saveGameHistory(const QString& player1, const QString& player2, const QString& result, const QStringList& moves);
    void replayGame(int gameId);
    void deleteGame(int gameId);

    // Toggle password visibility
    void togglePasswordVisibility(QLineEdit* lineEdit, bool visible);
};

#endif // WIDGET_H
