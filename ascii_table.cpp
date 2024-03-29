//
// Created by David Mrnustik on 14/3/22.
//

#include <iostream>
#include <sstream>
#include <math.h>
#include "ascii_table.h"

AsciiTable::AsciiTable() {
    createTable();
}

AsciiTable::AsciiTable(bool extended) {
    createTable(extended);
}

AsciiTable::AsciiTable(int format) : m_format(format)
{
    createTable();
    formatTable();
}

table_type AsciiTable::getData()
{
    return m_table;
}

std::string AsciiTable::getStringData()
{
    std::stringstream ss;

    ss << "[";

    for(int i = 0, l = m_table.size(); i < l; i++) {
        row_type row = m_table[i];
        ss << "[";

        for(int j = 0, ll = row.size(); j < ll; j++) {
            std::string col = row[j];

            if (col == "\\") {
                ss << "\"\\\\\"";
            } else if (col == "\"") {
                ss << "\"\\\"\"";
            } else {
                ss << "\"" << col << "\"";
            }

            ss << (j != ll - 1 ? "," : "");
        }
        ss << (i != l - 1 ? "]," : "]");

    }
    ss << "]";

    return ss.str();
}


void AsciiTable::formatTable()
{
    table_type formatted_table;

    row_type formatted_header;

    for(int i = 0; i < m_format; i++)
        for(std::string& s: m_table[0])
            formatted_header.push_back(s);

    formatted_table.push_back(formatted_header);

    double table_size = m_table.size() - 1;
    int row_size = std::ceil(table_size / m_format);

    for(int i = 1; i <= row_size; i++)
    {
        row_type row;
        for(int f = 0; f < m_format; f++)
        {
            int index = i + row_size * f;

            if (index <= table_size) {
                for(auto & c : m_table[index]) {
                    if (!c.empty()) {
                        row.push_back(c);
                    }
                }
            }
        }
        formatted_table.push_back(row);
    }
    m_table = formatted_table;
    recalculateColumns();
}

void AsciiTable::createTable(bool extended)
{
    if (extended) {
        m_table.push_back(header_extended);
    } else {
        m_table.push_back(header);
    }

    int size = DEFAULT_TABLE_SIZE;

    for(int i = 0; i < size; i++)
    {
        std::string s = std::to_string(i);
        std::string n8 = getStringFromInt(s, num_base::o);
        std::string n16 = getStringFromInt(s, num_base::h);
        std::string sc {};
        std::string desc = description[s];

        if (i <= 32 || i == 127) {
            sc = characters[s];
        } else {
            sc = char(i);
        }

        row_type row;

        if (extended) {
            std::string htmlEntity;
            std::string htmlCode = "&#" + std::to_string(i);

            std::unordered_map<std::string,std::string>::const_iterator got = htmlEntityNames.find (s);

            if (got == htmlEntityNames.end()) {
                htmlEntity = " ";
            } else {
                htmlEntity = got->second;
            }

            row = { s, n8, n16, binString(i), htmlCode, htmlEntity, sc, desc };
        } else {
            row = { s, n8, n16, binString(i), sc, desc};
        }

        m_table.push_back(row);
    }
    recalculateColumns();
}

void AsciiTable::printTable()
{
    for(const row_type& row: m_table)
    {
        for(const std::string& col: row)
            std::cout << col << " | ";
        std::cout << "\n";
    }
}

std::string AsciiTable::getStringFromInt(const std::string &s, num_base base)
{
    std::istringstream iss(s);
    std::ostringstream oss;

    int number;
    std::string result;
    iss >> std::dec >> number;

    switch (base) {
        case num_base::o:
            oss << std::oct << number;
            result = oss.str();
            break;
        case num_base::h:
            oss << std::hex << number;
            result = oss.str();
            break;
        default:
            iss >> std::dec >> result;
    }

    return result;
}

std::string AsciiTable::binString(char a)
{
    static char b[9];
    int i;

    i = 0;

    while(i<8)
    {
        b[i] = a&0x80 ? '1' : '0';
        a <<= 1;
        i++;
    }
    b[i] = '\0';

    return b;
}

void AsciiTable::setFormat(const int &val)
{
    m_format = val;
    formatTable();
}

void AsciiTable::recalculateColumns()
{
    m_columns = DEFAULT_COLUMN_SIZE * m_format;
}

int AsciiTable::getColumns()
{
    return m_columns;
}