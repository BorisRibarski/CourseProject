#pragma once

#include <span>
#include <string>

namespace cli {

class console {
  private:
    bool working = true;

  public:
    void show_home();
    void show_goodbye();
    void show_entity_mgmt();
    void show_list_menu();
    void show_list(std::span<std::string> items);
    std::string question(std::string_view);
    int get_answer();
    bool is_working();
    void quit();
};

} // namespace cli