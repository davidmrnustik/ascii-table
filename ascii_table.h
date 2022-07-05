//
// Created by David Mrnustik on 14/3/22.
//

#ifndef ASCIITABLE_QT_ASCII_TABLE_H
#define ASCIITABLE_QT_ASCII_TABLE_H
#define DEFAULT_COLUMN_SIZE 5
#define DEFAULT_TABLE_SIZE 128

#include <vector>
#include <string>

typedef std::vector<std::string> row_type;
typedef std::vector<row_type> table_type;

enum class num_base { o, d, h };

class AsciiTable {

public:
    void setFormat(const int &val);
    int format() const { return m_format; }
    void formatChanged();

    AsciiTable();
    AsciiTable(int format);
    void createTable();
    void formatTable();
    void printTable();
    table_type getData();
    std::string getStringData();
    int getColumns();

private:
    static std::string getStringFromInt(const std::string &s, num_base base);
    static std::string binString(char a);
    void recalculateColumns();
    table_type m_table;
    int m_format = 1;
    int m_columns {};
    const row_type header {{"Dec", "Oct", "Hex", "Binary", "C"}};
};

#endif //ASCIITABLE_QT_ASCII_TABLE_H
