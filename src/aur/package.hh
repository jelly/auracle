#ifndef PACKAGE_H
#define PACKAGE_H

#include <chrono>
#include <string>
#include <vector>

namespace aur {

struct Dependency {
  enum class Mod {
    ANY,
    EQ,
    GE,
    GT,
    LE,
    LT,
  };

  std::string depstring;
  std::string name;
  std::string version;
  Mod mod = Mod::ANY;
};

struct Package {
  std::string name;
  std::string description;
  std::string maintainer;
  std::string pkgbase;
  std::string upstream_url;
  std::string aur_urlpath;
  std::string version;

  int package_id = 0;
  int pkgbase_id = 0;
  int votes = 0;
  double popularity = 0.f;

  std::chrono::seconds out_of_date{0};
  std::chrono::seconds submitted_s{0};
  std::chrono::seconds modified_s{0};

  std::vector<std::string> conflicts;
  std::vector<std::string> groups;
  std::vector<std::string> keywords;
  std::vector<std::string> licenses;
  std::vector<std::string> optdepends;
  std::vector<std::string> provides;
  std::vector<std::string> replaces;

  std::vector<Dependency> depends;
  std::vector<Dependency> makedepends;
  std::vector<Dependency> checkdepends;
};

inline bool operator==(const Package& a, const Package& b) {
  return a.package_id == b.package_id && a.pkgbase_id == b.pkgbase_id;
}

}  // namespace aur

#endif  // PACKAGE_H
