//
// Created by David Mrnustik on 14/3/22.
//

#ifndef ASCIITABLE_QT_ASCII_TABLE_H
#define ASCIITABLE_QT_ASCII_TABLE_H
#define DEFAULT_COLUMN_SIZE 5
#define DEFAULT_TABLE_SIZE 128

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::string> row_type;
typedef std::vector<row_type> table_type;

enum class num_base { o, d, h };

static std::map<std::string, std::string> characters {
    {"0", "NULL (null)"},
    {"1", "SOH (start of heading)"},
    {"2", "STX (start of text)"},
    {"3", "ETX (end or text)"},
    {"4", "EOT (end of transmission)"},
    {"5", "ENQ (enquiry)"},
    {"6", "ACK (acknowledge)"},
    {"7", "BEL (bell)"},
    {"8", "BS (backspace)"},
    {"9", "TAB (horizontal tab)"},
    {"10", "LF (NL line feed, new line)"},
    {"11", "VF (vertical tab)"},
    {"12", "FF (NP form feed, new page)"},
    {"13", "CR (carriage return)"},
    {"14", "SO (shift out)"},
    {"15", "SI (shift in)"},
    {"16", "DLE (date link escape)"},
    {"17", "DC1 (device control 1)"},
    {"18", "DC2 (device control 2)"},
    {"19", "DC3 (device control 3)"},
    {"20", "DC4 (device control 4)"},
    {"21", "NAK (negative acknowledge)"},
    {"22", "SYN (synchronous idle)"},
    {"23", "ETB (end of trans. block)"},
    {"24", "CAN (cancel)"},
    {"25", "EM (end of medium)"},
    {"26", "SUB (substitute)"},
    {"27", "ESC (escape)"},
    {"28", "FS (file separator)"},
    {"29", "GS (group separator)"},
    {"30", "RS (record separator)"},
    {"31", "US (unit separator)"},
    {"32", "SPACE"},
    {"127", "DEL"}
};

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
    const row_type header {{"Dec", "Oct", "Hex", "Binary", "Char"}};

};

#endif //ASCIITABLE_QT_ASCII_TABLE_H
