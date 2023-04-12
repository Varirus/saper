#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H

enum GameMode
{
    DEBUG,
    EASY,
    NORMAL,
    HARD
};
enum GameState
{
    RUNNING,
    FINISHED_WIN,
    FINISHED_LOSS
};

struct Field
{
    bool hasMine;    // If field has mine
    bool hasFlag;    // if field is flagged
    bool isRevealed; // If field is revealed
};

class MinesweeperBoard
{
    int height;    // Height of the board
    int width;     // Width of the board
    GameMode mode; // GameMode of the game

    Field board[100][100]; // Array of fields
    int mineCount;         // Number of bombs on the board
    int unreaveled;        // Number of unrevealed fields
    GameState state;       // State of the game

public:
    // GETTERS
    //
    /**
        @return Width of the board
     */
    int getWidth() const;

    /**
        @return Height of the board
     */
    int getHeight() const;

    /**
        @return Number of bombs on the board
     */
    int getMineCount() const;

    /**
        @return State of the board
     */
    GameState getGameState() const;

    /**
        @brief Construct a new MinesweeperBoard object. Sets bombs on the board, height and width of the board.
     */
    MinesweeperBoard(int h = 10, int w = 10, GameMode m = NORMAL);

    /**
        @brief Function initialize board of a size height*width. All fields are not revealed, have no bomb and no flag.
     */
    void initialize_board();

    /**
        @brief Function sets ranndomly bombs depending on GameMode.

        @note For GameMode = DEBUG, bombs are set on the 1st row.
     */
    void setMines();

    /**
        @brief Function prints debug view. Every field with 3 attributes: @ hasMine, isReaveled and hasFlag.
     */
    void debug_display() const;

    /**
        @brief Function checks if field exists.

        @param row row number
        @param col column number

        @return \b True - if field is in board
     */
    bool fieldExist(int row, int col) const;

    /**
        @brief Function counts mines around field.

        @param row row number
        @param col col number

        @return number of mines around field \n
        @return \b -1 - if field out of board \n
        @return \b -1 - if field is not revealed
     */
    int countMines(int row, int col) const;

    /**
        @brief Function checks if field has a flag.

        @param row row number
        @param col col number

        @return \b True - if field has a flag \n
        @return \b False - if field doesn't have a flag \n
        @return \b False - if field doesn't exist \n
        @return \b False - if field is revealed
     */
    bool hasFlag(int row, int col) const;

    /**
        @brief Function toggles flag on the field.

        @note Operation will fail if: \n
        @note - field doesn't exist \n
        @note - field is revealed \n
        @note - game is finished

        @param row row number
        @param col col number
     */
    void toggleFlag(int row, int col);

    /**
        @brief Function reveals field.

        @note Operation will fail if: \n
        @note - field doesn't exist \n
        @note - field is revealed \n
        @note - field is flagged \n
        @note - game is finished

        @param row row number
        @param col col number
     */
    void revealField(int row, int col);

    /**
        @brief Function recursively reveal fields around given field.

        @param row row number
        @param col col number
     */
    void recursiveReveal(int row, int col);

    /**
        @brief Function relocates bomb from the field.

        @param row row number
        @param col col number
     */
    void relocateMine(int row, int col);

    /**
        @brief Function toggles flags on all unrevealed fields.
     */
    void toggleFlagOnRemainingFields();

    /**
        @brief Function checks if field has a flag.

        @param row row number
        @param col col number

        @return \b True - if field is reaveled \n
        @return \b False - if field doesn't exist \n
        @return \b False - if field is not revealed
     */
    bool isRevealed(int row, int col) const;

    /**
        @brief Function returns informations about field.

        @param row row number
        @param col col number

        @return \b '#' - field doesn't exist \n
        @return \b 'F' - field is flagged and not revealed \n
        @return \b '_' - field is not revealed and not flagged \n
        @return \b 'x' - field has mine and is revealed \n
        @return \b ' ' - field is revealed and has no mine around \n
        @return \b '1.....8' -  field is revealed and has mines around
     */
    char getFieldInfo(int row, int col) const;
};

#endif