#include <Format.h>

std::ostream&
fmt::operator<<(std::ostream& os, const fmt::fos& f) {
    os.setf(std::ios_base::fixed);
    os.precision(f.precision);
    os.width(f.width);
    os.fill(f.filler);
    
    return os;
}

std::ostream&
fmt::operator<<(std::ostream& os, const fmt::endl& e) {
    for (auto i = e.lines; i--; os << std::endl);

    os.flush();

    return os;
}