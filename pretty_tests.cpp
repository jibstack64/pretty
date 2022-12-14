#include <iostream>
#include "pretty.hpp"

int main(int argc, char ** argv) {
    std::cout << pty::paint("T1 - paint(..., (char*)\"green\")", "green") << std::endl;
    std::cout << pty::paint("T2 - paint(..., initialiser_list<char *>{\"green\", \"bold\"})", {"green", "bold"}) << std::endl;
    pty::ColourSet cs({"greybg", "magenta"});
    std::cout << cs.apply("T3.1 - ColourSet::apply(...)") << std::endl;
    std::cout << pty::paint("T3.2 - paint(..., ColourSet)", cs) << std::endl;
    std::cout << pty::dim("T4.1 - paint(..., {'dim'}) alias (dim(...))") << std::endl;
    std::cout << pty::bright("T4.2 - paint(..., {'bold'}) alias (bright(...))") << std::endl;
    std::cout << pty::normal(pty::dim("T4.3 - normal(...) escape sequence remover")) << std::endl;
    std::cout << "T5 - colour validification" << std::endl;
    for (const auto& clr : pty::colours) {
        std::cout << pty::paint(clr.first, clr.first) << std::endl;
    }
    return 0;
}
