// https://github.com/jibstack64/pretty
// a simple, lightweight, unix console-colouring library for C++, all in one header file!

#ifndef PRETTY_HPP
#define PRETTY_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#define TEMPLATE "\x1B[%dm"
#define RESET "\033[0m"

//#define MAX 5 // maximum no. of fg, bg & styles

namespace pty {

    // holds stylings for later use through the 'apply' function or paint(ColourSet)
    class ColourSet;

    // dims value
    const std::string dim(const char * value);

    // brightens value
    const std::string bright(const char * value);

    // removes all escape sequences from value
    const std::string normal(const char * value);

    // paints the given value with the the fore/back/style names provided
    template<typename T>
    const std::string paint(T value, std::vector<const char *> cns);
    //
    template<typename T>
    const std::string paint(T value, std::initializer_list<const char *> cns);
    //
    template<typename T>
    const std::string paint(T value, const char * cn);
    //
    template<typename T>
    const std::string paint(T value, ColourSet& cs);

    std::map<const char *, const int> colours {
        // foreground [0-14]
        {"black", 30}, {"red", 31}, {"green", 32},
        {"orange", 33}, {"blue", 34}, {"magenta", 35},
        {"cyan", 36}, {"white", 37}, {"grey", 90},
        {"lightred", 91}, {"lightgreen", 92}, {"yellow", 93},
        {"lightblue", 94}, {"lightmagenta", 95}, {"turqoise", 96},
        // background [15-29]
        {"blackbg", 40}, {"redbg", 41}, {"greenbg", 42},
        {"orangebg", 43}, {"bluebg", 44}, {"purplebg", 45},
        {"cyanbg", 46}, {"whitebg", 47}, {"greybg", 100},
        {"lightredbg", 101}, {"lightgreenbg", 102}, {"yellowbg", 103},
        {"lightbluebg", 104}, {"lightpurplebg", 105}, {"turquoisebg", 106},
        // style [30-35]
        {"normal", 0}, {"bold", 1}, {"dim", 2},
        {"italic", 3}, {"underlined", 4}, {"reversefield", 7},
        //{"riverced", 26}, {"framed", 51}, {"flashing", 5}
    };

    class ColourSet {
        private:
            const std::vector<const char *> _styles;

        public:
            ColourSet(std::initializer_list<const char *> cns);

            // applies stored stylings to value
            template<typename T>
            const std::string apply(T value);
    };

    ColourSet::ColourSet(std::initializer_list<const char *> cns) : _styles(cns) {}

    template<typename T>
    const std::string ColourSet::apply(T value) {
        return paint(value, this->_styles);
    }

    const std::string dim(const char * value) {
        return paint(value, "dim");
    }

    const std::string bright(const char * value) {
        return paint(value, "bright");
    }

    const std::string normal(const std::string value) {
        std::ostringstream oss;
        bool zon = false;
        for (int i = 0; i < value.size(); i++) {
            if (value[i] == '\x1B') {
                zon = true;
            }
            if (zon) {
                if (value[i] == 'm') {
                    zon = false;
                }
                continue;
            } else {
                oss << value[i];
            }
        }
        return oss.str();
    }

    template<typename T>
    const std::string paint(T value, std::vector<const char *> cns) {
        std::ostringstream oss;
        for (const auto& cn : cns) {
            char c[15];
            std::sprintf(c, TEMPLATE, colours.at(cn));
            oss << c;
        }
        oss << value << RESET;
        return oss.str();
    }
    //
    template<typename T>
    const std::string paint(T value, std::initializer_list<const char *> cns) {
        std::vector<const char *> s;
        for (const auto& cn : cns) {
            s.push_back(cn);
        }
        return paint(value, s);
    }
    //
    template<typename T>
    const std::string paint(T value, const char * cn) {
        return paint(value, {cn});
    }
    //
    template<typename T>
    const std::string paint(T value, ColourSet& cs) {
        return cs.apply(value);
    }
}

#endif
