//
// Created by David Mrnustik on 14/3/22.
//

#ifndef ASCIITABLE_QT_ASCII_TABLE_H
#define ASCIITABLE_QT_ASCII_TABLE_H
#define DEFAULT_COLUMN_SIZE 5
#define DEFAULT_TABLE_SIZE 128

#include <vector>
#include <string>
#include <unordered_map>

typedef std::vector<std::string> row_type;
typedef std::vector<row_type> table_type;

enum class num_base { o, d, h };

static std::unordered_map<std::string, std::string> characters {
    {"0", "NULL"},
    {"1", "SOH"},
    {"2", "STX"},
    {"3", "ETX"},
    {"4", "EOT"},
    {"5", "ENQ"},
    {"6", "ACK"},
    {"7", "BEL"},
    {"8", "BS"},
    {"9", "TAB"},
    {"10", "LF"},
    {"11", "VF"},
    {"12", "FF"},
    {"13", "CR"},
    {"14", "SO"},
    {"15", "SI"},
    {"16", "DLE"},
    {"17", "DC1"},
    {"18", "DC2"},
    {"19", "DC3"},
    {"20", "DC4"},
    {"21", "NAK"},
    {"22", "SYN"},
    {"23", "ETB"},
    {"24", "CAN"},
    {"25", "EM"},
    {"26", "SUB"},
    {"27", "ESC"},
    {"28", "FS"},
    {"29", "GS"},
    {"30", "RS"},
    {"31", "US"},
    {"32", "SPACE"},
    {"127", "DEL"}
};

static std::unordered_map<std::string, std::string> description {
    {"0", "Null"},
    {"1", "Start of Heading"},
    {"2", "Start of Text"},
    {"3", "End or Text"},
    {"4", "End of Transmission"},
    {"5", "Enquiry"},
    {"6", "Acknowledge"},
    {"7", "Bell"},
    {"8", "Backspace"},
    {"9", "Horizontal Tab"},
    {"10", "NL Line Feed, New Line"},
    {"11", "Vertical Tab"},
    {"12", "NP Form Feed, New Page"},
    {"13", "Carriage Return"},
    {"14", "Shift Out"},
    {"15", "Shift In"},
    {"16", "Date Link Escape"},
    {"17", "Device Control 1"},
    {"18", "Device Control 2"},
    {"19", "Device Control 3"},
    {"20", "Device Control 4"},
    {"21", "Negative Acknowledge"},
    {"22", "Synchronous Idle"},
    {"23", "End of Transmission Block"},
    {"24", "Cancel"},
    {"25", "End of Medium"},
    {"26", "Substitute"},
    {"27", "Escape"},
    {"28", "File Separator"},
    {"29", "Group Separator"},
    {"30", "Record Separator"},
    {"31", "Unit Separator"},
    {"32", "Space"},
    {"33", "Exclamation Mark"},
    {"34", "Double Quote"},
    {"35", "Hash or Number"},
    {"36", "Dollar Sign"},
    {"37", "Percentage"},
    {"38", "Ampersand"},
    {"39", "Single Quote"},
    {"40", "Left Parenthesis"},
    {"41", "Right Parenthesis"},
    {"42", "Asterisk"},
    {"43", "Plus Sign"},
    {"44", "Comma"},
    {"45", "Minus Sign"},
    {"46", "Period"},
    {"47", "Slash"},
    {"48", "Zero"},
    {"49", "Number One"},
    {"50", "Number Two"},
    {"51", "Number Three"},
    {"52", "Number Four"},
    {"53", "Number Five"},
    {"54", "Number Six"},
    {"55", "Number Seven"},
    {"56", "Number Eight"},
    {"57", "Number Nine"},
    {"58", "Colon"},
    {"59", "Semicolon"},
    {"60", "Less Than"},
    {"61", "Equals Sign"},
    {"62", "Greater Than"},
    {"63", "Question Mark"},
    {"64", "At Sign"},
    {"65", "Upper Case Letter A"},
    {"66", "Upper Case Letter B"},
    {"67", "Upper Case Letter C"},
    {"68", "Upper Case Letter D"},
    {"69", "Upper Case Letter E"},
    {"70", "Upper Case Letter F"},
    {"71", "Upper Case Letter G"},
    {"72", "Upper Case Letter H"},
    {"73", "Upper Case Letter I"},
    {"74", "Upper Case Letter J"},
    {"75", "Upper Case Letter K"},
    {"76", "Upper Case Letter L"},
    {"77", "Upper Case Letter M"},
    {"78", "Upper Case Letter N"},
    {"79", "Upper Case Letter O"},
    {"80", "Upper Case Letter P"},
    {"81", "Upper Case Letter Q"},
    {"82", "Upper Case Letter R"},
    {"83", "Upper Case Letter S"},
    {"84", "Upper Case Letter T"},
    {"85", "Upper Case Letter U"},
    {"86", "Upper Case Letter V"},
    {"87", "Upper Case Letter W"},
    {"88", "Upper Case Letter X"},
    {"89", "Upper Case Letter Y"},
    {"90", "Upper Case Letter Z"},
    {"91", "Left Square Bracket"},
    {"92", "Backslash"},
    {"93", "Right Square Bracket"},
    {"94", "Caret or Circumflex"},
    {"95", "Underscore"},
    {"96", "Grave Accent"},
    {"97", "Lower Case Letter a"},
    {"98", "Lower Case Letter b"},
    {"99", "Lower Case Letter c"},
    {"100", "Lower Case Letter d"},
    {"101", "Lower Case Letter e"},
    {"102", "Lower Case Letter f"},
    {"103", "Lower Case Letter g"},
    {"104", "Lower Case Letter h"},
    {"105", "Lower Case Letter i"},
    {"106", "Lower Case Letter j"},
    {"107", "Lower Case Letter k"},
    {"108", "Lower Case Letter l"},
    {"109", "Lower Case Letter m"},
    {"110", "Lower Case Letter n"},
    {"111", "Lower Case Letter o"},
    {"112", "Lower Case Letter p"},
    {"113", "Lower Case Letter q"},
    {"114", "Lower Case Letter r"},
    {"115", "Lower Case Letter s"},
    {"116", "Lower Case Letter t"},
    {"117", "Lower Case Letter u"},
    {"118", "Lower Case Letter v"},
    {"119", "Lower Case Letter w"},
    {"120", "Lower Case Letter x"},
    {"121", "Lower Case Letter y"},
    {"122", "Lower Case Letter z"},
    {"123", "Left Curly Bracket"},
    {"124", "Vertical Bar"},
    {"125", "Right Curly Bracket"},
    {"126", "Tilde"},
    {"127", "Delete"}
};

static std::unordered_map<std::string, std::string> htmlEntityNames {
    {"33", "&excl;"},
    {"34", "&quot;"},
    {"35", "&num;"},
    {"36", "&dollar;"},
    {"37", "&percnt;"},
    {"38", "&amp;"},
    {"39", "&apos;"},
    {"40", "&lpar;"},
    {"41", "&rpar;"},
    {"42", "&ast;"},
    {"43", "&plus;"},
    {"44", "&comma;"},
    {"45", "&minus;"},
    {"46", "&period;"},
    {"47", "&sol;"},
    {"58", "&colon;"},
    {"59", "&semi;"},
    {"60", "&lt;"},
    {"61", "&equals;"},
    {"62", "&gt;"},
    {"63", "&quest;"},
    {"64", "&commat;"},
    {"91", "&lsqb;"},
    {"92", "&bsol;"},
    {"93", "&rsqb;"},
    {"94", "&hat;"},
    {"95", "&lowbar;"},
    {"96", "&grave;"},
    {"123", "&lcub;"},
    {"124", "&verbar;"},
    {"125", "&rcub;"},
    {"126", "&tilde;"}
};

class AsciiTable {

public:
    void setFormat(const int &val);
    int format() const { return m_format; }
    void formatChanged();

    AsciiTable();
    AsciiTable(bool extended);
    AsciiTable(int format);
    void createTable(bool extended = false);
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
    const row_type header {{"Dec", "Oct", "Hex", "Binary", "Char", "Description"}};
    const row_type header_extended {{"Dec", "Oct", "Hex", "Binary", "HTML Code", "HTML Name", "Char", "Description"}};
};

#endif //ASCIITABLE_QT_ASCII_TABLE_H
