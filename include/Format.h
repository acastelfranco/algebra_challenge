#pragma once

#include <ios>
#include <iomanip>
#include <ostream>
#include <iostream>

namespace fmt {
    /**
     * @brief class to format floating point numbers using operator<<
     * 
     */
    class fos {
    public:
        /**
         * @brief Construct a new fos object
         * 
         * @param filler 
         * @param width 
         * @param precision 
         */
        fos(char filler, int width, int precision) :
            filler(filler), width(width), precision(precision) { }

        char filler;
        int  width;
        int  precision;
    };

    /**
     * @brief output stream operator for fos class
     * 
     * @param os 
     * @param f 
     * @return std::ostream& 
     */
    std::ostream&
    operator<<(std::ostream& os, const fos& f);

    /**
     * @brief class to implement endl function for append
     * multiple new lines to the output stream using operator<<
     */
    class endl
    {
    public:
        /**
         * @brief Construct a new endl object
         * 
         * @param lines 
         */
        endl(unsigned lines) : lines(lines) { }

        unsigned lines;
    };

    /**
     * @brief output stream operator for fos class
     * 
     * @param os 
     * @param e 
     * @return std::ostream& 
     */
    std::ostream&
    operator<<(std::ostream& os, const endl& e);
}